#include <M5Stack.h>

// filename
// onair.png cam.png mic.png null.png red.png standby.png white.png

// the setup routine runs once when M5Stack starts up
void setup() {

  // Initialize the M5Stack object
  M5.begin();

  /*
    Power chip connected to gpio21, gpio22, I2C device
    Set battery charging voltage and current
    If used battery, please call this function in your project
  */
  M5.Power.begin();
  M5.Lcd.drawPngFile(SD, "/png/white.png");
  
}

// the loop routine runs over and over again forever
void loop() {
  M5.update();

  if(M5.BtnA.wasPressed()){
    M5.Lcd.drawPngFile(SD,"/png/cam.png");
  }
  if(M5.BtnB.wasPressed()){
    M5.Lcd.drawPngFile(SD,"/png/onair.png");
  }
  if(M5.BtnC.wasPressed()){
    M5.Lcd.drawPngFile(SD,"/png/mic.png");
  }
}
