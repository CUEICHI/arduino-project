#include <ArduinoOSC.h>
#include <M5Stack.h>

WiFiUDP udp;
const int recv_port = 10000;

#define SSID "aedexp"
#define WIFIPW "c425c425"

int i;
float f;
String s;

int bind_port = 9999;
int publish_port = 9998;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  Serial.begin(115200);
  M5.Lcd.setBrightness(200);
  //M5.Lcd.loadFont("filename", SD);

  WiFi.begin(SSID, WIFIPW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  M5.Lcd.fillScreen(WHITE);
  delay(1000);

  OscWiFi.subscribe(bind_port, "/bind/values", i, f, s);
  OscWiFi.publish("127.0.0.1", publish_port, "/publish/value", i, f, s);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("%d,%f",i,f);
  Serial.println(s);
  M5.update();
  OscWiFi.update();

}
