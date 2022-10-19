//
// M5stack/stickC   + Env2 で絶対湿度を算出する
//
#include <M5StickCPlus.h>
#include <stdio.h>

#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SHT31.h>

#include <WiFiMulti.h>
#include <Arduino_JSON.h>
#include <HTTPClient.h>
#include "time.h"

#include "slackcert.h"

Adafruit_SHT31 sht3x;
Adafruit_BMP280 bme;

#define SEC 1000

//wifiとメッセージ の設定
WiFiMulti wifi;

#define KUGE 
// C411,C425, KUGE のどれかを設定・WIFIとメッセージを選択する

#if defined(C411)
#define WIFI_SSID "aedexp"
#define WIFI_PASS "c425c425"
#define BOOTMSG "M5BOT C411起動"
#define CHANNEL "envdata"
#define BOTNAME "M5BOT-C411"
#define BOTICON ":sushi:"
#define MSG "研C411の様子は "

#elif defined(C425)
#define WIFI_SSID "AEDC425g"
#define WIFI_PASS "c425c425"
#define BOOTMSG "M5BOT C425起動"
#define CHANNEL "c425"
#define BOTNAME "M5BOT-C425"
#define BOTICON ":CAT:"
#define MSG "研C425の様子は "

#elif defined(KUGE)
#define WIFI_SSID "homelan"
#define WIFI_PASS "hadahisakazu"
#define BOOTMSG "M5BOT KUGEHOUSE起動"
#define CHANNEL "kugehouse"
#define BOTNAME "M5BOT-KUGE"
#define BOTICON ":tiger:"
#define MSG "鵠沼ベッドルームの様子は "
// #define MSG "鵠沼ハウスの様子は "
#define MSG "鵠沼玄関の様子は"

#endif


// NTPの設定
const char* ntpServer =  "ntp.jst.mfeed.ad.jp";
const long  gmtOffset_sec = 9 * 3600;
const int   daylightOffset_sec = 0;
struct tm timeinfo;

HTTPClient http;
JSONVar msg;

unsigned int cnt = 0;

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(10);
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextSize(3);

  Wire.begin(32,33); // GROVEの場合
  //Wire.begin(0,26); // HATの場合(ENV-II) 
  while (!bme.begin(0x76)) {
    Serial.println("BMP280 init fail");
    delay(1000);
  }
  while (!sht3x.begin(0x44)) {
    Serial.println("SHT3x init fail");
    delay(1000);
  }

  // put your setup code here, to run once:
  wifi.addAP(WIFI_SSID, WIFI_PASS);
  Serial.print("Try to Connect: ");
  Serial.print(WIFI_SSID);
  Serial.print("/");
  Serial.print(WIFI_PASS);
  Serial.println("*");
  
  while (wifi.run() != WL_CONNECTED) {
    delay(500);
    Serial.printf(".");
  }
  Serial.println("wifi connect ok");
  // set clock from ntp
  configNtp() ;

  // send  slack message
  String mtext = asctime(&timeinfo) ;
  mtext += BOOTMSG ;
  msg["text"] = mtext;
  msg["username"] = BOTNAME;
  msg["icon_emoji"] = BOTICON ;
  msg["channel"] = CHANNEL ;
  //sendMsg(msg);

}


float calc_hv(float temp, float humi) {
  float t = (7.5 * temp) / (temp + 237.3);
  float ps = 6.1078 * pow(10, t);
  float pv = humi * ps / 100 ;
  float hv = 216.7 * pv / (temp + 273.15) ;
  return hv ;
}

void loop() {
  float tmp = sht3x.readTemperature();
  float hum = sht3x.readHumidity();
  float pressure = bme.readPressure();
  float hv = calc_hv(tmp, hum);
  double vbat = M5.Axp.GetVbatData() * 1.1 / 1000;  // バッテリー電圧を取得 ----D

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
  } else {
    //    Serial.print(&timeinfo);
    //Serial.println(asctime(&timeinfo));
    if( timeinfo.tm_hour > 7 ) {
        M5.Axp.ScreenBreath(10);
    }else{
      M5.Axp.ScreenBreath(7);
    }
  }

  M5.Lcd.setCursor(0, 0, 1);
  M5.Lcd.printf("%02i/%02i %02i:%02i\r\n", timeinfo.tm_mon + 1, timeinfo.tm_mday,
                timeinfo.tm_hour, timeinfo.tm_min);
  M5.Lcd.printf("temp: %4.1f*C\r\n", tmp);
  M5.Lcd.printf("humi: %4.1f%%\r\n", hum);
  M5.Lcd.printf("pres: %4.0fhPa\r\n", pressure / 100.0 );
  M5.Lcd.printf("HV: %4.2fg/m3\r\n", hv);
  //  M5.Lcd.printf("vbat: %4.2fV\r\n", vbat);

  delay( SEC );
  if (cnt % 900 == 0) {
    cnt = 0;

    String mtext = asctime(&timeinfo) ;
    char data[128];
    sprintf(data, "\ttemp: %4.1f'C\tHum:%4.1f%%\tPres:%4.0fhPa\tHV:%4.2fg/m3", tmp, hum, pressure / 100, hv);
    mtext += MSG ;
    mtext += data;
    msg["text"] = mtext;
    msg["username"] = BOTNAME ;
    msg["icon_emoji"] = BOTICON ;
    msg["channel"] = CHANNEL ;
    //sendMsg(msg);
  }
  cnt ++;

}


void configNtp() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
  } else {
    Serial.print(&timeinfo);
    Serial.println(asctime(&timeinfo));
  }
}

void sendMsg(JSONVar message) {
  String content = JSON.stringify(message);
  Serial.print("Connect to");
  Serial.println(SERVER);
  http.begin( SERVER, 443, HOOKPATH , slack_root_ca );
  http.addHeader("Content-Type", "application/json" );
  http.POST(content);
  Serial.println("post hooks.slack.com");
}
