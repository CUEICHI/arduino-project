#include <M5Atom.h>

#define L1 25
#define L2 21
void setup() {
  // put your setup code here, to run once:
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(L1,LOW);
  delay(10);
  digitalWrite(L2,LOW);
  delay(10);
  digitalWrite(L1,HIGH);
  delay(10);
  digitalWrite(L2,HIGH);  
  delay(10);

}
