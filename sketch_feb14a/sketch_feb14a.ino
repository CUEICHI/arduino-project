void setup() {
  // put your setup code here, to run once:
  // 5,6 でモーター
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(6,LOW);
  delay(2000);
  digitalWrite(5,LOW);
  delay(2000);
  digitalWrite(6,HIGH);
  delay(2000);
  digitalWrite(5,HIGH);
  delay(2000);

}
