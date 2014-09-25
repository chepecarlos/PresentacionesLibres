int AnchoBarra;
int UltimaBarra = -1;

void setup() {
  size(displayWidth, displayHeight);
  AnchoBarra  = width/50;
  colorMode(HSB, height, height, height);  
  noStroke();
  background(0);
}

void draw() {
  int ActivaBarra = mouseX / AnchoBarra;
  if (ActivaBarra != UltimaBarra) {
    int BarraX = ActivaBarra * AnchoBarra;
    fill(mouseY, height, height);
    rect(BarraX, 0, AnchoBarra, height);
    ActivaBarra = UltimaBarra;
  }
}

