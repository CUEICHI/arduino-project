
#include <ArduinoOSC.h>
#include <FastLED.h>

const uint8_t Srv0 = 23, Srv1 = 33;
const uint8_t srv_CH0 = 0, srv_CH1 = 1;
const double PWM_Hz = 50;   //PWM周波数
const uint8_t PWM_level = 16; //PWM 16bit(0～65535)



#define SEC 1000

#define NUM_LEDS 25
#define DATA_PIN 27
#define MAX_BRIGHTNESS 40
CRGB leds[NUM_LEDS];

// WIFI
#define SSID "HOME11g"
#define WIFIPW "hadahisakazu"

// OSC
#define PORT 5005

// servo setting
#define S1_MIN 1640
#define S1_MAX 8190
#define S2_MIN 1440
#define S2_MAX 8190
#define SV ledcWrite 


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

// LED value
int pos, r, g, b;
int opos = -1, og = -1 ;

void onClnMsg(const OscMessage& m) {
  Serial.println("Clean buffer");
  fill_solid(&leds[0], 25, CRGB::Black);
  FastLED.show();
}

// servo value
int xval, yval, ox, oy ;

void setup() {
  Serial.begin(115200);
  Serial.println("OSC-Servoarm with NeoPixel.");
  Serial.println("Ver. 1.0");
  Serial.println("HELP: \n /msg -- msgtest\n /clean -- Clear LED");
  Serial.println(" /led Pos,R,G,B -- light LED\n /ch1 val -- servo1\n /ch2 val --servo2") ;

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

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
  OscWiFi.subscribe(PORT, "/ch1", xval);
  OscWiFi.subscribe(PORT, "/ch2", yval);

  pinMode(Srv0, OUTPUT);
  pinMode(Srv1, OUTPUT);

  //モータのPWMのチャンネル、周波数の設定
  ledcSetup(srv_CH0, PWM_Hz, PWM_level);
  ledcSetup(srv_CH1, PWM_Hz, PWM_level);

  //モータのピンとチャンネルの設定
  ledcAttachPin(Srv0, srv_CH0);
  ledcAttachPin(Srv1, srv_CH1);
  SV(srv_CH0, (S1_MIN+S1_MAX)/2 );
  SV(srv_CH1, (S2_MIN+S2_MAX)/2 );

}

void loop() {
  if (ox != xval || oy != yval) {
    int i = map(xval, 0, 180, S1_MIN, S1_MAX);
    SV(srv_CH0, i);
    int j = map(yval, 0, 180, S2_MIN, S2_MAX);
    SV(srv_CH1, j);
    ox = xval;
    oy = yval;
    Serial.print("SV1:");
    Serial.println(xval);
    Serial.print("SV1:");
    Serial.println(xval);
    Serial.print("SV2:");
    Serial.println(yval);
  }
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
