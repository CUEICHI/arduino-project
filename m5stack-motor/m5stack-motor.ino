void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
  Serial.println("Start");
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(2, HIGH);
  digitalWrite(5, LOW);
  delay(3000);
  digitalWrite(2, LOW);
  digitalWrite(5, HIGH);
  delay(3000);

}
