
#define SW 37
#define LED 10

void setup() {
  // put your setup code here, to run once:
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sw = digitalRead(SW);
  if ( sw == LOW) {
    digitalWrite(LED,LOW);
  }else{
    digitalWrite(LED,HIGH);
  }

}
