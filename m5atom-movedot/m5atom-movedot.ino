#include "M5Atom.h"

void setup() {
  // put your setup code here, to run once:
  M5.begin(true,false,true);
  delay(50);
  M5.dis.drawpix(0,0x0);

}
int i =0 ;
void loop() {
  // put your main code here, to run repeatedly:

  if(M5.Btn.wasPressed()) {
    M5.dis.clear();
  }
  M5.dis.drawpix(i,0x00f000);
  delay(200);
  M5.dis.drawpix(i,0);
  i++;
  if (i>25) {
    i=0;
  }
    
}
