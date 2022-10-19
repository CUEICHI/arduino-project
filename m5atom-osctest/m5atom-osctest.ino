#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <ArduinoOSC.h>
//#include <M5Atom.h>
#include <FastLED.h>

//WiFiUDP udp;

// Change Here
#define HOME
#if defined(HOME)
#define SSID "HOME11g"
#define WIFIPW "hadahisakazu"
#else
#define SSID "aedexp"
#define WIFIPW "c425c425"
#endif

int bind_port = 5005;
int pos, r, g, b;
int oldr = -1 ;

//FastLED
#define NUM_LEDS 25
#define DATA_PIN 27
#define MAX_BRIGHTNESS 40
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  //  M5.begin(true, false, true);
  Serial.begin(115200);
  Serial.print("SSID: ");
  Serial.println(SSID);
  Serial.print("KEY: ");

  Serial.println(WIFIPW);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

  WiFi.begin(SSID, WIFIPW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n Connected! IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
  OscWiFi.subscribe(bind_port, "/led", [](constOscMessage & m) {
    Serial.print(m.remoteIP()); Serial.print(" ");
    Serial.print(m.remotePort()); Serial.print(" ");
    Serial.print(m.size()); Serial.print(" ");
    Serial.print(m.address()); Serial.print(" ");
    Serial.print(m.arg<int>(0)); Serial.print(" ");
    Serial.print(m.arg<int>(1)); Serial.print(" ");
    Serial.print(m.arg<int>(2)); Serial.print(" ");
    Serial.print(m.arg<int>(3)); Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (oldr != r) {
    CRGB col = CRGB(r, g, b);
    Serial.printf("%lu\tPOS:%d\tRGB:%d,%d,%d\n", millis(), pos, r, g, b);
    oldr = r ;
    leds[pos] = col ;
  }
  FastLED.show();
  OscWiFi.update();

}
