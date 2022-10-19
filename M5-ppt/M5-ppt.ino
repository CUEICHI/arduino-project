/**
   This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
*/
#include <BleKeyboard.h>
#include "M5CoreInk.h"

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  M5.begin(true, false);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (M5.BtnUP.wasPressed()) {
      bleKeyboard.write(KEY_LEFT_ARROW);
      Serial.println("LEFT");
    } else if (M5.BtnDOWN.wasPressed()) {
      bleKeyboard.write(KEY_RIGHT_ARROW);
      Serial.println("RIGHT");
    } else if (M5.BtnMID.wasPressed()) {
      bleKeyboard.write('b');
      Serial.println("Black");
    }
    delay(100);
  }
  M5.update();
}
