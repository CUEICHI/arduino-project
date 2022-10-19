#include <M5StickC.h>  // ----A
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 sht3x;
Adafruit_BMP280 bme;

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(10);    // 画面の輝度を少し下げる ----B
  M5.Lcd.setRotation(3);      // 左を上にする         ----C
  M5.Lcd.setTextSize(2);      // 文字サイズを2にする
  M5.Lcd.fillScreen(BLUE);   // 背景を黒にする

  Wire.begin();
  while (!bme.begin(0x76)) {
    Serial.println("BMP280 init fail");
  }
  while (!sht3x.begin(0x44)) {
    Serial.println("SHT3x init fail");
  }
}

void loop() {
  float tmp = sht3x.readTemperature();
  float hum = sht3x.readHumidity();
  float pressure = bme.readPressure();
  double vbat = M5.Axp.GetVbatData() * 1.1 / 1000;  // バッテリー電圧を取得 ----D

  M5.Lcd.setCursor(0, 0, 1);
  M5.Lcd.printf("temp: %4.1f'C\r\n", tmp);
  M5.Lcd.printf("humid:%4.1f%%\r\n", hum);
  M5.Lcd.printf("press:%4.0fhPa\r\n", pressure / 100);
  M5.Lcd.printf("vbat: %4.2fV\r\n", vbat);
  delay(10 * 1000);
}
