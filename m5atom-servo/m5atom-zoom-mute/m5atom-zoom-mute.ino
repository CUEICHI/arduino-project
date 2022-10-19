#include "M5Atom.h"
#include <BleKeyboard.h>  // https://github.com/T-vK/ESP32-BLE-Keyboard

BleKeyboard bleKeyboard("M5ATOM KB");  //デバイス名

const int longPress_ms = 300;  // 長押し判定時間(単位 msec)

void setup() {
  // M5.begin(SerialEnable, I2CEnable, DisplayEnable);
  M5.begin(true, false, true);
  M5.dis.drawpix(0, 0x000000);  // LED OFF

  //Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  M5.update();
  if (bleKeyboard.isConnected()) {
    if (M5.Btn.wasPressed()) {
      M5.dis.drawpix(0, 0x00f0f0);  // LED MAGENTA
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('a');
      delay(100);
    }
    M5.dis.drawpix(0, 0x0000f0);  // LED BLUE
  } else {
    M5.dis.drawpix(0, 0x00f000);  // LED RED
  }
  delay(10);
}
