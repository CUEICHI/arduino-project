#include "M5Atom.h"

void setup() {
  // put your setup code here, to run once:
  M5.begin(true,false,true);
  pinMode(33, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(33,HIGH);
  delay(1000);
  digitalWrite(33,LOW);
  delay(1000);
  M5.update();
  }
  
