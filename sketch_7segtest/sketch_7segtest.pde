/**
 * Words. 
 * 
 * The text() function is used for writing words to the screen.
 * The letters can be aligned left, center, or right with the 
 * textAlign() function. 
 */
  
PFont f;
  
void setup() {
  size(640, 360);
  
  // Create the font
  printArray(PFont.list());
  f = createFont("DSEG7Classic-Regular.ttf", 48);
  textFont(f);
}

void draw() {
  background(102);
  textAlign(RIGHT);
  drawType(width * 0.25);
  textAlign(CENTER);
  drawType(width * 0.5);
  textAlign(LEFT);
  drawType(width * 0.75);
}

void drawType(float x) {
  line(x, 0, x, 65);
  line(x, 220, x, height);
  fill(0);
  text("12345", x, 95);
  fill(51);
  text("67890", x, 130);
  fill(204);
  text("abcde", x, 165);
  fill(255);
  text("fghij", x, 210);
}
