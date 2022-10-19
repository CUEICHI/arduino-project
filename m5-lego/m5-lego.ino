void setup() {
  // put your setup code here, to run once:
  pinMode(26, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(39, INPUT_PULLUP);
  digitalWrite(26, LOW);
  digitalWrite(32, LOW);
}

boolean dir = true;

void loop() {
  // put your main code here, to run repeatedly:
  if (dir == true) {
    digitalWrite(26, HIGH);
    digitalWrite(32, LOW);
  } else {
    digitalWrite(26, LOW);
    digitalWrite(32, HIGH);
  }
  int sw = digitalRead(39);
  if (sw == 0 ) {
    dir = !dir ;
  }

}
