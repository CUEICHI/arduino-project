#include <FastLED.h>

#define NUM_LEDS 25
#define DATA_PIN 27
#define MAX_BRIGHTNESS 40

unsigned long cnt = 0 ;
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 25; i++) {
    leds[i].setRGB(random(120), random(120), random(120));
  }
  FastLED.show();
  cnt ++ ;
  delay(50);
}
