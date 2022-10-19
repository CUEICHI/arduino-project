//#include <M5Stack.h>
#include <M5StickC.h>

#include "Seeed_BME280.h"
#include <Wire.h>

BME280 bme280;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(0);
  M5.Lcd.setTextSize(2);
  if(!bme280.init()){
    while(true);
  }
}

void loop() {
  uint32_t pres = bme280.getPressure();
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.printf("Temp:%5.1fC\n", bme280.getTemperature());
  M5.Lcd.printf("Humi:%5d%%\n", bme280.getHumidity());
  M5.Lcd.printf("Pres:%5dhPa\n", pres/100 );
  //M5.Lcd.printf("Alti:%5.1fm\n", bme280.calcAltitude(pres));
  delay(500);
}
