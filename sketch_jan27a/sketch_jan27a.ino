void setup() {
  // put your setup code here, to run once:

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(2000);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
  delay(1000);

}
