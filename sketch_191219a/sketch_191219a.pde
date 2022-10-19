/***
  Capture and Compare pixels
  RGBを比較して影化
  
  Compiler: Processing 0124 Beta
  Date: 2007/4/27
  Author: Sho Hashimoto
  WebSite: http://shokai.org
  ***/

import processing.video.*;

color threshold = color(5, 5, 5); // RGBでしきい値を指定

Capture camera;
PImage bg;

void setup(){
  size(640, 480);
  camera =  new Capture(this, width, height, 12);
  bg = new PImage(width, height);
}

void draw(){
  loadPixels(); // pixelsに現在の表示を読み込み
  for(int i = 0; i < width*height; i++){
    int c = camera.pixels[i];
    int b = bg.pixels[i];
    if( abs(red(c) - red(b)) > red(threshold) &&
        abs(green(c) - green(b)) > green(threshold) &&
        abs(blue(c) - blue(b)) > blue(threshold) ){ // ピクセルに色の差がある時
      pixels[i] = color(0,0,0); // 黒
    }
    else{
      pixels[i] = color(255,255,255); // 白
    }
  }
  updatePixels(); // pixelsを表示に反映させる
}

void captureEvent(Capture camera){
  camera.read();
}

void mousePressed(){
  println("Save BG");
  bg.copy(camera,0,0,width,height,0,0,width,height); // 背景を保存
}
