#include <Process.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <FileIO.h>

Process Fecha;
int hours, minutes, seconds;
int lastSecond = -1;
int lastLikes = -1;
int likes = 0;
int Buzzer = 10;
bool heartStatus = false;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
  Bridge.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Me gusta FB ALSW");
  FileSystem.begin();
  uploadScript();

  if (!Fecha.running())  {
    Fecha.begin("date");
    Fecha.addParameter("+%T");
    Fecha.run();
  }
}

void loop() {
  if (lastSecond != seconds) {
    updateTimeLCD();

    if ((seconds % 30) == 0) {
      likes = runScript();
      lcd.setCursor(2, 1);
      lcd.print(likes);
      if (lastLikes != likes ) {
        lastLikes = likes;
        digitalWrite(Buzzer, HIGH);
        delay(250);
        digitalWrite(Buzzer, LOW);
      }
    }
  }
  updateData();
}

void updateTimeLCD() {
  lcd.setCursor(10, 1);
  if (hours <= 9) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes <= 9) lcd.print("0");
  lcd.print(minutes);
  lcd.setCursor(0, 1);
  if (heartStatus)
    lcd.write(byte(0));
  else
    lcd.print(" ");
  lcd.print(" ");
  heartStatus = !heartStatus;
  if (!Fecha.running())  {
    Fecha.begin("date");
    Fecha.addParameter("+%T");
    Fecha.run();
  }
}

void updateData() {
  while (Fecha.available() > 0) {
    String FechaString = Fecha.readString();
    int PrimeraColuna = FechaString.indexOf(":");
    int SegundaColuna = FechaString.lastIndexOf(":");
    String hourString = FechaString.substring(0, PrimeraColuna);
    String minString = FechaString.substring(PrimeraColuna + 1, SegundaColuna);
    String secString = FechaString.substring(SegundaColuna + 1);
    hours = hourString.toInt();
    minutes = minString.toInt();
    lastSecond = seconds;
    seconds = secString.toInt();
  }
}

void uploadScript() {
  File script = FileSystem.open("/tmp/MeGustaFB.py", FILE_WRITE);

  script.print("#!/usr/bin/python\n");
  script.print("import urllib2,json \n");
  script.print("data = urllib2.urlopen(");
  script.print("'http://graph.facebook.com/alswblog/'";
  Script.print(").read() \n");
  script.print("json_data = json.loads(data)\n");
  script.print("print ('%s') % (json_data['likes'])\n");
  script.close();

  Process chmod;
  chmod.begin("chmod");
  chmod.addParameter("+x");
  chmod.addParameter("/tmp/MeGustaFB.py");
  chmod.run();
}

int runScript() {
  Process myscript;
  myscript.begin("/tmp/MeGustaFB.py");
  myscript.run();
  String output = "";
  while (myscript.available()) {
    output += (char)myscript.read();
  }
  output.trim();
  return output.toInt() ;
}
