/*
    OSC Test -- for M5Atom

*/
#include <ArduinoOSC.h>
#include <FastLED.h>

#define SEC 1000

#define NUM_LEDS 24
#define DATA_PIN 25
#define MAX_BRIGHTNESS 40
CRGB leds[NUM_LEDS];

// WIFI
#define SSID "HOME11g"
#define WIFIPW "hadahisakazu"

// OSC
#define PORT 5005


void onOscReceived(const OscMessage& m)
{
  Serial.print(m.remoteIP()); Serial.print(" ");
  Serial.print(m.remotePort()); Serial.print(" ");
  Serial.print(m.size()); Serial.print(" ");
  Serial.print(m.address()); Serial.print(" ");
  Serial.print(m.arg<int>(0)); Serial.print(" ");
  Serial.print(m.arg<int>(1)); Serial.print(" ");
  Serial.print(m.arg<int>(2)); Serial.print(" ");
  Serial.print(m.arg<int>(3)); Serial.println();
}

int pos, r, g, b;

void onClnMsg(const OscMessage& m) {
  Serial.println("Clean buffer");
  fill_solid(&leds[0], 25, CRGB::Black);
  FastLED.show();
}


void setup() {
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  fill_solid(leds, 24, CRGB(25, 0, 0));
  FastLED.show();
  WiFi.begin(SSID, WIFIPW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n Connected. IPAddr:");
  Serial.println(WiFi.localIP());
  delay(SEC);
  OscWiFi.subscribe(PORT, "/msg", onOscReceived);
  OscWiFi.subscribe(PORT, "/clean", onClnMsg) ;
  OscWiFi.subscribe(PORT, "/led", pos, r, g, b);
  fill_solid(leds, 24, CRGB(0, 0, 0));
  FastLED.show();
}
int opos = -1, og = -1 ;
void loop() {
  // put your main code here, to run repeatedly:
  if ( opos != pos && og != g ) {
    leds[pos].setRGB(r, g, b);
    Serial.print("LED: ");
    FastLED.show();
    Serial.print(pos); Serial.print(" ");
    Serial.print(r); Serial.print(" ");
    Serial.print(g); Serial.print(" ");
    Serial.println(b);
    opos = pos;
    og = g ;
  }
  OscWiFi.update();
}
