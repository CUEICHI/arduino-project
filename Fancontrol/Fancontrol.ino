#include <M5Atom.h>

#define FAN 26
void setup() {
  // put your setup code here, to run once:
  M5.begin();
  pinMode(FAN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(FAN,1);
  delay(3000);
  digitalWrite(FAN,0);
  delay(3000);
  
}
