#include "M5Atom.h"

const uint8_t Srv0 = 21, Srv1 = 25, Srv2 = 19, Srv3 = 22;//GPIO No.
const uint8_t srv_CH0 = 0, srv_CH1 = 1, srv_CH2 = 2, srv_CH3 = 3; //チャンネル
const double PWM_Hz = 50;   //PWM周波数
const uint8_t PWM_level = 16; //PWM 16bit(0～65535)

bool IMU6886Flag = false;  //今回はなくても良い

void setup() {
  M5.begin();
  pinMode(Srv0, OUTPUT);
  pinMode(Srv1, OUTPUT);
  pinMode(Srv2, OUTPUT);
  pinMode(Srv3, OUTPUT);
  
  //モータのPWMのチャンネル、周波数の設定
  ledcSetup(srv_CH0, PWM_Hz, PWM_level);
  ledcSetup(srv_CH1, PWM_Hz, PWM_level);
  ledcSetup(srv_CH2, PWM_Hz, PWM_level);
  ledcSetup(srv_CH3, PWM_Hz, PWM_level);

  //モータのピンとチャンネルの設定
  ledcAttachPin(Srv0, srv_CH0);
  ledcAttachPin(Srv1, srv_CH1);
  ledcAttachPin(Srv2, srv_CH2);
  ledcAttachPin(Srv3, srv_CH3);
}

void loop() {
  for (int i = 1640; i <= 8190; i=i+50) {  //500μsec -> 2500μsec -90deg -> 90deg
    ledcWrite(srv_CH0, i);
    ledcWrite(srv_CH1, i);
    ledcWrite(srv_CH2, i);
    ledcWrite(srv_CH3, i);
    delay(10);
  }
  for (int i = 8190; i > 1640; i=i-50) {   //2500μsec -> 500μsec 90deg -> -90deg
    ledcWrite(srv_CH0, i);
    ledcWrite(srv_CH1, i);
    ledcWrite(srv_CH2, i);
    ledcWrite(srv_CH3, i);
    delay(10);
  }
}
