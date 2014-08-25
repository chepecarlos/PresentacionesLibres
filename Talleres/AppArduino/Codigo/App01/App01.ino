
// I/O del LED RGB
const int PinRojo = 9;
const int PinVerde = 10;
const int PinAzul = 11;

//
bool Rojo = false;
bool Verde = false;
bool Azul = false;

// Tiempo de espera en milisegundos
int Espera = 100;

void setup() {

  // I/O en salida
  pinMode(PinRojo, OUTPUT);
  pinMode(PinVerde, OUTPUT);
  pinMode(PinAzul, OUTPUT);

  // Empieza la comunicacion serial
  Serial.begin(9600);

}

void loop() {

  Leer();

  ActualizarRGB();

  delay(Espera);

}

void Leer() {

  char Op;

  while (Serial.available() > 0) {
    Op = Serial.read();
    if ( Op ==  'R') {
      Rojo = !Rojo;
    }
    else if ( Op == 'G') {
      Verde = !Verde;
    }
    else if ( Op == 'B') {
      Azul = !Azul;
    }
  }

}

void ActualizarRGB()
{

  analogWrite(PinRojo, Rojo);
  analogWrite(PinVerde, Verde);
  analogWrite(PinAzul, Azul);

}
