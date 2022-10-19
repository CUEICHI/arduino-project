#include <M5Atom.h>
#include <stdio.h>

#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SHT31.h>
#include <Adafruit_SGP30.h>

Adafruit_SHT31 sht3x;
Adafruit_BMP280 bme;
Adafruit_SGP30 sgp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Sensor Test...");

  Wire.begin();
  while ( !sgp.begin()) {
    Serial.println("SGP Sensor not found");
    delay(1000);
  }

  while (!bme.begin(0x76)) {
    Serial.println("BMP280 init fail");
    delay(1000);
  }
  while (!sht3x.begin(0x44)) {
    Serial.println("SHT3x init fail");
    delay(1000);
  }

  Serial.println("All Sensors are ready.");
}

int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  float tmp = sht3x.readTemperature();
  float hum = sht3x.readHumidity();
  float pressure = bme.readPressure();
  sgp.setHumidity(getAbsoluteHumidity(tmp, hum));


  if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
  }
  Serial.print("TVOC "); Serial.print(sgp.TVOC); Serial.print(" ppb\t");
  Serial.print("eCO2 "); Serial.print(sgp.eCO2); Serial.println(" ppm");

  if (! sgp.IAQmeasureRaw()) {
    Serial.println("Raw Measurement failed");
    return;
  }
  Serial.print("Raw H2 "); Serial.print(sgp.rawH2); Serial.print(" \t");
  Serial.print("Raw Ethanol "); Serial.print(sgp.rawEthanol); Serial.println("");

  delay(1000);

  counter++;
  if (counter == 30) {
    counter = 0;

    uint16_t TVOC_base, eCO2_base;
    if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x"); Serial.print(eCO2_base, HEX);
    Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);
  }

  Serial.print("Temp: "); Serial.println(tmp);
  Serial.print("Humidity: "); Serial.println(hum);

}

uint32_t getAbsoluteHumidity(float temperature, float humidity) {
  // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
  const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
  const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
  return absoluteHumidityScaled;
}
