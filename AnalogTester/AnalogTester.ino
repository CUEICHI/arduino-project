// Analog Tester
// analog testing tool for Arduino MEGA / UNO
// Please View by Serial Plotter

#define MAX 12
#define SPACE 1000
#define DELAY 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < MAX; i++) {
      int data = analogRead(i);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < MAX; i++) {
    int data = analogRead(i);
    Serial.print(data + i * SPACE );
    Serial.print(",");
  }
  Serial.println("*");
  delay(DELAY);

}
