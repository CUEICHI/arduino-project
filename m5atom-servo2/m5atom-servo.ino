#include "M5Atom.h"
// http://blog.robotakao.jp/blog-entry-387.html
const uint8_t Srv0 = 23;//GPIO No.
const uint8_t Srv1 = 33;//GPIO No.
const uint8_t srv_CH0 = 0; //チャンネル
const uint8_t srv_CH1 = 1; //チャンネル
const double PWM_Hz = 50;   //PWM周波数
const uint8_t PWM_level = 16; //PWM 16bit(0～65535)

bool IMU6886Flag = false;

int i, j;

#define SVMIN 1640
#define SVMAX 8190

void setup() {
  M5.begin();
  pinMode(Srv0, OUTPUT);
  pinMode(Srv1, OUTPUT);

  //モータのPWMのチャンネル、周波数の設定
  ledcSetup(srv_CH0, PWM_Hz, PWM_level);
  ledcSetup(srv_CH1, PWM_Hz, PWM_level);

  //モータのピンとチャンネルの設定
  ledcAttachPin(Srv0, srv_CH0);
  ledcAttachPin(Srv1, srv_CH1);
  i = random(SVMIN, SVMAX);
  j = random(SVMIN, SVMAX);
}
void loop0() {
  i = random(SVMIN, SVMAX);
  j = random(SVMIN, SVMAX);
  ledcWrite(srv_CH0, i);
  ledcWrite(srv_CH1, j);
  delay(2000);
  M5.update();
}
void loop() {
  if (M5.Btn.wasPressed()) {
    i = random(1640, 8190);
    j = random(1640, 8190);
    delay(10);
  }
  ledcWrite(srv_CH0, i);
  ledcWrite(srv_CH1, j);
  delay(100);
  M5.update();

}
