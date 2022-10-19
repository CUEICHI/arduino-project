#include <M5CoreInk.h>

#include <WiFi.h>
#include <time.h>

#define SEC 1000
#define SSID "HOME11g"
#define PASSWORD "hadahisakazu"


//M5 Ink
Ink_Sprite InkPageSprite(&M5.M5Ink);


void setup() {
  // put your setup code here, to run once:

  M5.begin();
  Serial.print("\n\nStart\n");
  //  if (ntpDataFlag == false) {
  //    ntpDataFlag = true;
  if (!M5.M5Ink.isInit())
  {
    Serial.printf("Ink Init faild");
    while (1)
      delay(100);
  }
  M5.M5Ink.clear();
  delay(1 * SEC);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println(" ");
  Serial.printf("Connected, IP address: ");
  Serial.println(WiFi.localIP());


  if ( InkPageSprite.creatSprite(0, 0, 200, 200, true) != 0 )
  {
    Serial.printf("Ink Sprite creat faild");
  }

  Serial.printf("Ink Sprite creat successful");
  InkPageSprite.clear();

  InkPageSprite.drawString(5, 20, "Hada"); //, &AsciiFont12x24);
  InkPageSprite.drawString(5, 70, "Hisakazu", &AsciiFont24x48);
  InkPageSprite.pushSprite();

}

void loop() {
}
