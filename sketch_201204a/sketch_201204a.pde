void setup() {
  size(800, 800);
  colorMode(HSB, 100);
  frameRate(10);
  noStroke();
  background(0);
}

void draw() {
  for (int x =20; x<width; x+=40) {
    for (int y =20; y<width; y+=40) {
      fill(random(20,50), 100, 80);
      rectMode(CENTER);
      rect(x, y, 40, 40);
    }
  }
}
