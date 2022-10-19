// servotester
#include <ArduinoOSC.h>

const uint8_t Srv0 = 23, Srv1 = 33;
const uint8_t srv_CH0 = 0, srv_CH1 = 1;
const double PWM_Hz = 50;   //PWM周波数
const uint8_t PWM_level = 12; //PWM 10bit(0～4096==4000)
// およそ 200-400くらいでは

// WIFI
#define SSID "HOME11g"
#define WIFIPW "hadahisakazu"

// OSC
#define PORT 5005
#define SEC 1000

// servo value
int xval, yval, ox=95,oy=95;

void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, WIFIPW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n Connected. IPAddr:");
  Serial.println(WiFi.localIP());
  delay(SEC);
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
  ledcWrite(srv_CH0, 300);
  delay(10);
  ledcWrite(srv_CH1, 300);

}

void loop() {
  if (!(ox == xval && oy == yval )) {
    int x = map(xval,-90,90,120,530);
    ledcWrite(srv_CH0, x);
    delay(100);
    int y = map(yval,90,-90,100,475);
    ledcWrite(srv_CH1, y);
    ox = xval ;
    oy = yval;
    Serial.print("SV1:");
    Serial.print(xval);
    Serial.print("\t SV2:");
    Serial.println(yval);
  }
  OscWiFi.update();
}
