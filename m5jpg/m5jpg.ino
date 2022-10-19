#include <M5StickC.h>

#include <Adafruit_NeoPixel.h>

#define PIN 21
#define NUM 20
Adafruit_NeoPixel pixels(NUM, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.qrcode("http://www.aed-lab.net/");
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  pixels.clear();
  for (int i = 0; i < NUM; i++) {
    pixels.setPixelColor(i, random(255), random(255), random(255));
    pixels.show();
  }
  delay(100);

}
