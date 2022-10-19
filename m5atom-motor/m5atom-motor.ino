// #include <M5Atom.h>

//Motor and Switch

#define M1 19
#define M2 22
#define SW  21

#define DLY 2000

void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(M1,HIGH);
  delay(DLY);
  digitalWrite(M2,HIGH);
  delay(DLY);
  digitalWrite(M1,LOW);
  delay(DLY);
  digitalWrite(M2,LOW);
  delay(DLY);
}
