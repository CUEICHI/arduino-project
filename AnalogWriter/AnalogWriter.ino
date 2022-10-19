void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(10, 255);
  analogWrite(11, 150);
  digitalWrite(13, HIGH);
  delay(5000);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(3000);
  analogWrite(10, 120);
  analogWrite(11, 255);
  digitalWrite(13, LOW);
  delay(3000);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(3000);

}
