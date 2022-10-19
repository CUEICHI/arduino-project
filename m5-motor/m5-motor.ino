#include "M5Atom.h"

#define MOT_A 19
#define MOT_B 22

void setup() {
  // put your setup code here, to run once:
  M5.begin(true, false, true);
  pinMode(MOT_A, OUTPUT);
  pinMode(MOT_B, OUTPUT);
}

bool dir = true;

void loop() {
  // put your main code here, to run repeatedly:

  if (dir) {
    digitalWrite(MOT_A, HIGH);
    digitalWrite(MOT_B, LOW);
  } else {
    digitalWrite(MOT_A, LOW);
    digitalWrite(MOT_B, HIGH);
  }
  if (M5.Btn.wasPressed()) {
    dir = !dir;
  }
  M5.update();
}
