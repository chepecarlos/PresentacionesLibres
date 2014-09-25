
void DibujarFormulario() {
  textSize(50);
  textAlign(CENTER, CENTER);
  rectMode(CORNER);
  background(ColorFondo);
  fill(0);
  text(Titulo, width/2, height/8);
  fill(ColorBoton);
  rect(width/8, 3*height/16, 3*width/4, height/8);
  fill(0);
  text(BotonT, width/2, 2*height/8);
  text("Rojo", width/2 - width/4, 3*height/8);
  text("Azul", width/2 - width/4, 4*height/8);
  text("Verde", width/2 - width/4, 5*height/8);

  text(CantidadR, width - width/4, 3*height/8);
  text(CantidadA, width - width/4, 4*height/8);
  text(CantidadB, width - width/4, 5*height/8);

  fill(ColorBotonA);
  rect(width/8, 6*height/8- height/16, 3*width/4, height/8);
  fill(0);
  text(BotonR, width/2, 6*height/8);
}

void mousePressed() {
  switch(estado)
  {
  case 3:
    if (mouseX > width/8 && mouseX < width/8 +  3*width/4 &&
      mouseY >  3*height/16 && mouseY <  3*height/16 + height/8
      ) {
      if (ColorBoton == ColorBotonA) {
        ColorBoton = ColorBotonD;
        BotonT = BotonD;
        println("Desactivar");
      } else {
        ColorBoton = ColorBotonA;
        BotonT = BotonA;
        println("Activar");
      }
    }
    if ( mouseX > width/8 && mouseX < width/8 +  3*width/4 &&
      mouseY > 6*height/8- height/16 && mouseY < 6*height/8- height/16 +  height/8
      ) {
      CantidadR = 0;
      CantidadA = 0;
      CantidadB = 0;
      println("Reiniciando");
    }
    break;
  }
}

