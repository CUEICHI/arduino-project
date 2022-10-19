// Analog Tester 
// analog testing tool for Arduino MEGA / UNO
// Please View by Serial Plotter

#ifdef ARDUINO_AVR_MEGA || ARDUINO_AVR_MEGA2560
#define MAX 16
#else
#define MAX 6
#endif
#define SPACE 1000
#define DELAY 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<MAX;i++){
    int data = analogRead(i);
    Serial.print(data+i*SPACE );
    Serial.print(",");
  }
  Serial.println("*");
  delay(DELAY);
  
}
