#include "M5Atom.h"

void setup() {
  // put your setup code here, to run once:
  M5.begin(true,false,true);
  delay(50);
  M5.dis.drawpix(0,0x0);

}
int x =2 ;
int y =2 ;
void loop() {
  // put your main code here, to run repeatedly:

  if(M5.Btn.wasPressed()) {
    M5.dis.clear();
  }
  long col = random(0xffffff);
  M5.dis.drawpix(x+y*5,col); //0x00f000);
  delay(100);
  M5.dis.drawpix(x+y*5,0);
  int xmove = random(-1,1);
  int ymove = random(-1,1);  
    x = x + xmove;
    y = y + ymove ;
  if (x > 5) x = 0;
  if (x < 0) x = 4;
  if (y > 5) y = 0;
  if (y < 0) y = 4;
}
