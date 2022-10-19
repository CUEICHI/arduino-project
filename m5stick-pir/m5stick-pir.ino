#include <M5StickC.h>
 
void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.println("PIR TEST");
 
  pinMode(GPIO_NUM_10, OUTPUT);
  pinMode(36,INPUT_PULLUP);
}
 
void loop() {
  M5.Lcd.setCursor(60, 20, 4);
  int pir = digitalRead(36);
  M5.Lcd.println(pir);
  digitalWrite(GPIO_NUM_10, !pir);
}
