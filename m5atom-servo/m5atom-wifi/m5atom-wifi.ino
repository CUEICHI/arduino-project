#include <M5Atom.h>
#include <WiFi.h>

#define SSID "HOME11g"
#define SSPW "hadahisakazu"


void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.dis.drawpix(0, 0xf00000);

  Serial.begin(115200);
  WiFi.begin(SSID,SSPW);
  while(WiFi.status() != WL_CONNECTED) {
    M5.dis.drawpix(0, 0x000000);
    delay(250);
    M5.dis.drawpix(0, 0xf00000);
    delay(250);
    Serial.print(".");
  }
  Serial.print("\n Wifi COnnected.\n IP Address:");
  Serial.println(WiFi.localIP());
  M5.dis.drawpix(0,0x0000f0);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
