
#define LED1 16
#define LED2 17
#define SW1 39
#define SW2 38

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SW1) == LOW) {
    digitalWrite(LED1,HIGH);
  }else{
    digitalWrite(LED1,LOW);
  }

  if(digitalRead(SW2) == LOW) {
    digitalWrite(LED2,HIGH);
  }else{
    digitalWrite(LED2,LOW);
  }

}
