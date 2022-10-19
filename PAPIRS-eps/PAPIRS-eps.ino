#define PIN 18

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN,INPUT_PULLDOWN);

}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(PIN);
  Serial.print(data);
  delay(10);
 

}
