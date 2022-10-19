#include <M5CoreInk.h>
// BLE Remote
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;


void setup() {
  // put your setup code here, to run once:
  bleKeyboard.begin();
  M5.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  if (bleKeyboard.isConnected()) {

    if (M5.BtnUP.wasPressed()) {
      Serial.println("Up");
      bleKeyboard.write(KEY_RIGHT_ARROW);
    }
    else if ( M5.BtnDOWN.wasPressed()) {
      Serial.println("DOWN");
      bleKeyboard.write(KEY_LEFT_ARROW);

    } else if (M5.BtnMID.wasPressed()) {
      Serial.println("MIDD");
      bleKeyboard.write(KEY_ESC);

    }

  }
  M5.update();

}
