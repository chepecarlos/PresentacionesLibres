int Led = 13;

void setup() {
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char data = (char)Serial.read();
    if ( data == 'H')
      digitalWrite(Led, 1);
    else if ( data == 'L')
      digitalWrite(Led, 0);
  }
}
