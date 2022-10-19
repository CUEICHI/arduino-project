#include <M5Atom.h>  // ----A
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 sht3x;
Adafruit_BMP280 bme;

void setup() {
  M5.begin();
  Serial.begin(115200);

  Wire.begin(26, 32);
  while (!bme.begin(0x76)) {
    Serial.println("BMP280 init fail");
    delay(1000);
  }
  while (!sht3x.begin(0x44)) {
    Serial.println("SHT3x init fail");
    delay(1000);
  }
}

void loop() {
  float tmp = sht3x.readTemperature();
  float hum = sht3x.readHumidity();
  float pressure = bme.readPressure();
  //  double vbat = M5.Axp.GetVbatData() * 1.1 / 1000;  // バッテリー電圧を取得 ---bbb-D

  Serial.printf("temp: %4.1f'C\r\n", tmp);
  Serial.printf("humid:%4.1f%%\r\n", hum);
  Serial.printf("press:%4.0fhPa\r\n", pressure / 100);
  //  Serial.printf("vbat: %4.2fV\r\n", vbat);
  Serial.println("----------");
  delay(1000);
}
