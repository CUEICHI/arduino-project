#define LEDpin 5

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i = 0;i<100;i++) {
    pwmLED(i,100);
  }
  delay(1000);
}

void pwmLED(int duty, int time) {
  int i = 0;
  int j = 0;
  for (j = 1; j < time; j++) {
    for (i = 0; i < 100; i++) {
      if (i < duty) {
        digitalWrite(LEDpin, HIGH);
      } else {
        digitalWrite(LEDpin, LOW);
      }
      delayMicroseconds(10);
    }
  }
}
