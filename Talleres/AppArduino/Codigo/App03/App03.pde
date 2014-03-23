int Ancho;
int Posicion;
color CP;

void setup() {
  // Aqui va el codigo que se ejecuta solo una ves
  noStroke();
  size(420, 640);
  textAlign(CENTER);
  Ancho = width/4;
  Posicion = height/4;
  CP = #FFFFFF;
}

void draw() {
  // Aqui va el codigo que se ejecuta repetidas, permanentemente
  background(CP);
  fill(#000000);
  textSize(40);//Esto lo escrivira los alumnos 
  text("AppArduino", width/2, 75);
  DibujarCuadrados();
}

void DibujarCuadrados() {

  DibujarCuadrado(1, "Rojo", #FF0000);
  DibujarCuadrado(2, "Verde", #00FF00);
  DibujarCuadrado(3, "Azul", #0000FF);
}

void DibujarCuadrado(int i, String Palabra,color C) {
  fill(C, 200);
  float Distancia = (0.375)*width;
  text(Palabra, width/2, i*Distancia);
  rect(Distancia, i*Posicion, Ancho, Ancho);
}

boolean SobreCuadro(int i) {
  float Distancia = (0.375)*width;
  if ( Distancia < mouseX && Distancia + Ancho > mouseX
    &&  i*Posicion < mouseY &&  i*Posicion +Ancho > mouseY) {
    return true;
  }
  return false;
}

void mouseMoved() 
{
  if (SobreCuadro(1)) {
    CP= #FF0000;
  }
  else if (SobreCuadro(2)) {
    CP= #00FF00;
  }
  else if (SobreCuadro(3)) {
    CP= #0000FF;
  }
  else {
    CP= #FFFFFF;
  }
}

void mouseClicked() {
}

