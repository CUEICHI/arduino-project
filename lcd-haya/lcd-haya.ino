#include <M5Stack.h>

#define SW1 21
#define SW2 22
#define SW3 23
#define SW4 19
#define SW5 18

boolean flag = false;
char ans = ' ';

void setup() {
  // put your setup code here, to run once:
  M5.begin(true,false,true);
  M5.Lcd.setTextSize(7);
  M5.Lcd.print("HELLO");
  delay(2000);
  M5.Lcd.fillScreen(0);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  M5.Lcd.setCursor(0,0);
  M5.Lcd.print("WAITING");
  interrupt_setup();
}

void interrupt_setup() {
  attachInterrupt(SW1, abutton, FALLING);
  attachInterrupt(SW2, bbutton, FALLING);
  attachInterrupt(SW3, cbutton, FALLING);
  attachInterrupt(SW4, dbutton, FALLING);
  attachInterrupt(SW5, ebutton, FALLING);
}

void interrupt_stop() {
  detachInterrupt(SW1);
  detachInterrupt(SW2);
  detachInterrupt(SW3);
  detachInterrupt(SW4);
  detachInterrupt(SW5);
}


void abutton() {
  noInterrupts();
  ans = 'A';
  flag = true;
}

void bbutton() {
  noInterrupts();
  ans = 'B';
  flag = true;
}
void cbutton() {
  noInterrupts();
  ans = 'C';
  flag = true;
}
void dbutton() {
  noInterrupts();
  ans = 'D';
  flag = true;
}
void ebutton() {
  noInterrupts();
  ans = 'E';
  flag = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag == true) {
    interrupt_stop();
    interrupts();
    M5.Lcd.fillScreen(0);
    M5.Lcd.setCursor(2, 4);
    M5.Lcd.println(ans);
    delay(2000);
    flag = false;
    ans = ' ';
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println("WAITING");
    interrupt_setup();
  }
}
