#include <Arduino_JSON.h>
#include <Arduino.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <M5Atom.h>
#include "time.h"

#include "slack-cert.h"


//wifi の設定
WiFiMulti wifi;
#define WIFI_SSID "HOME11g"
#define WIFI_PASS "hadahisakazu"

// NTPの設定
const char* ntpServer =  "ntp.jst.mfeed.ad.jp";
const long  gmtOffset_sec = 9 * 3600;
const int   daylightOffset_sec = 0;
struct tm timeinfo;

HTTPClient http;
JSONVar msg;

void setup() {

  Serial.begin(115200);
  M5.begin(true,true,true); // Serial,I2C,LED を起動するかどうか
  M5.dis.drawpix(0, 0xcc0000) ;

  // put your setup code here, to run once:
  wifi.addAP(WIFI_SSID, WIFI_PASS);
  Serial.println("send slack");

  while (wifi.run() != WL_CONNECTED) {
    delay(500);
    Serial.printf(".");
  }
  Serial.println("wifi connect ok");
  M5.dis.drawpix(0,0x000088);
  // set clock from ntp
  configNtp() ;

  // send  slack message
  String mtext = asctime(&timeinfo) ;
  mtext += "鵠沼ハウス: 起動" ;
  msg["text"] = mtext;
  msg["username"] = "M5bot おうち" ;
  msg["icon_emoji"] = ":dog:" ;
  msg["channel"] = "envdata" ;
  sendMsg(msg);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.dis.drawpix(0, 0x440044) ;
  M5.update();
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
