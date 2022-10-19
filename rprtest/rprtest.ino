
#define IOPIN 22
void setup() {
  // put your setup code here, to run once:
  pinMode(IOPIN,INPUT);
  Serial.begin(115200);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(IOPIN);
  Serial.print(data);
  delay(100);
}
