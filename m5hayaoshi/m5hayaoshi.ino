#include <M5Stack.h>

#define MAX_SW 5
#define SW1 21
#define SW2 22
#define SW3 23
#define SW4 19
#define SW5 18

int sw[MAX_SW] = {SW1, SW2, SW3, SW4, SW5};
char msg[MAX_SW] = {'A','B','C','D','E'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("HELLO");
  for (int i; i < 5; i++) {
    pinMode(sw[i], INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int data;
  for(int i=0;i<MAX_SW;i++) {
    data = digitalRead(sw[i]);
    if (data == 0) {
      Serial.println(msg[i]);
      delay(1000);
      break;
    }
  }
}
