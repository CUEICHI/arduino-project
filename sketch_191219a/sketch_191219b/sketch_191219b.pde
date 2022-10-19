import gab.opencv.*;  //ライブラリをインポート
import processing.video.*;
import java.awt.*;

Capture video;
OpenCV opencv;

void setup() {
  size(640, 480);
  video = new Capture(this, 640, 480);
  opencv = new OpenCV(this, 640, 480);

  video.start();  //キャプチャを開始

  background(0);
}

void draw() {
  fill(0);
  rect(0, 0, 640, 480);
  video.filter(GRAY);
  image(video, 0, 0 );  //表示
  opencv.loadImage(video);  //ビデオ画像をメモリに展開
  opencv.updateBackground();

  opencv.dilate();
  opencv.erode();

  noFill();
  stroke(255, 0, 0);
  strokeWeight(10);
  for (Contour contour : opencv.findContours()) {
    contour.draw();
  }
}

void captureEvent(Capture c) {
  c.read();
}
