#include <M5Atom.h>

#define STEPS 360
#define DIV 32
#define EN 22
#define DIR 23
#define STEP 19


void setup() {
  // put your setup code here, to run once:
  pinMode(EN, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(STEP, OUTPUT);
  digitalWrite(EN, LOW);
  digitalWrite(DIR, LOW);
  digitalWrite(STEP, LOW);

  // ON
  digitalWrite (EN, LOW);

}

void loop() {
  digitalWrite(DIR, HIGH);
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 1000; i++) {
    digitalWrite(STEP, HIGH);
    delay(1);
    digitalWrite(STEP, LOW);
    delay(1);
  }
  delay(2*1000);
  digitalWrite(DIR,LOW);
  for (int i = 0; i < 1000; i++) {
    digitalWrite(STEP, HIGH);
    delay(1);
    digitalWrite(STEP, LOW);
    delay(1);
  }
delay(2*1000);

}
