#include <M5Stack.h>

// the setup routine runs once when M5Stack starts up
void setup() {

  // Initialize the M5Stack object
  M5.begin();
  // LCD display
  M5.Lcd.setRotation(1); 
  M5.Lcd.loadFont("/font.ttf",SD);
    M5.Lcd.setTextSize(2);
  M5.Lcd.println("はろー世界");
  M5.Lcd.setTextSize(3);
  M5.Lcd.println("Good morining TUT");
  M5.Lcd.setTextSize(4);
  M5.Lcd.println("M5Stack");
  M5.Lcd.setTextSize(5);
  M5.Lcd.println("M5Stack");
  M5.Lcd.setTextSize(6);
  M5.Lcd.println("M5Stack");
  M5.Lcd.setTextSize(7);
  M5.Lcd.println("M5Stack");
}

// the loop routine runs over and over again forever
void loop() {

}
