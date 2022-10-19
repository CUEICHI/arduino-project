//#include<ESP32-Chimera-Core.h>
#include<LovyanGFX.hpp>
#include<algorithm>

static LGFX tft;
static LGFX_Sprite base(&tft);
static LGFX_Sprite sp1(&base);
static LGFX_Sprite sp2(&base);
static LGFX_Sprite sp3(&base);
static LGFX_Sprite sp4(&base);

void drawStr(const char* str, bool drawCursor = false) {
  int i = 0;
  do {
    delay(25);
    tft.print(str[i]);
    tft.setCursor(tft.getCursorX() - 1, tft.getCursorY());
    if (drawCursor) tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 4, 12, 0xFFFFFFU);
  } while (str[++i] != 0);
}

void blinkCursor(int loop) {
  tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 5, 12, 0);
  for (int i = 0 ; i < loop; ++i) {
    delay(130); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 4, 12, 0xFFFFFFU);
    delay(200); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 5, 12, 0);
  }
}

void setup(void) {
//M5.begin();
  tft.init();

  tft.startWrite();

  tft.drawFastHLine(0, (tft.height() - 1) >> 1, tft.width(), tft.color888(80,80,80));

  base.setColorDepth(4);
  sp1.setColorDepth(4);
  sp2.setColorDepth(4);
  sp3.setColorDepth(4);
  sp4.setColorDepth(4);

  base.createSprite(239, 239);
  sp1.createSprite(193, 199);
  sp1.clear(1);
  sp1.drawRect(  0,   0, 193, 199, 14);
  sp1.fillRect(  0,   0,  16,  18, 15);
  sp1.fillRect(177,   0,  16,  18, 15);
  sp1.fillRect(177, 181,  16,  18, 15);
  sp1.fillRect(  0, 181,  16,  18, 15);
  sp1.fillRect(  2,   2, 189, 195,  1);
  sp1.drawFastHLine(  0, 99, 195, 14);
  sp1.drawFastVLine( 96,  0, 197, 14);

  sp2.createSprite( 71, 75);
  sp2.clear(2);
  sp2.drawFastVLine( 35,  0, 75, 14);
  sp2.drawRect(  0,  0, 71, 75, 14);
  sp2.fillRect(  0,  0,  3, 75, 13);
  sp2.fillRect( 68,  0,  3, 75, 13);
  sp2.fillRect(  0, 36, 71,  3, 13);

  sp3.createSprite( 59, 59);
  sp3.clear(3);
  sp3.drawRect( 0, 0, 59, 59, 14);
  sp3.drawFastHLine(  0, 29, 59, 14);
  sp3.drawFastVLine( 29,  0, 59, 14);
  sp3.fillCircle( 29, 29, 29, 13);
  sp3.fillCircle( 29, 29, 26,  3);
  sp3.drawLine( 12, 10, 29, 27, 14);

  sp4.createSprite( 103, 105);
  sp4.clear(4);
  sp4.drawRect( 0,  0, 103, 105, 14);

  sp4.fillRect( 0,  0,  16,  18, 15);
  sp4.fillRect(87,  0,  16,  18, 15);
  sp4.fillRect(87, 87,  16,  18, 15);
  sp4.fillRect( 0, 87,  16,  18, 15);
  sp4.fillRect( 2,  2,  99, 101,  4);

  sp4.drawFastHLine(  0, 52, 103, 14);
  sp4.drawFastVLine( 25,  0, 52, 14);
  sp4.drawFastVLine( 77, 52, 52, 14);

  sp4.setClipRect(0, 0, 51, 107);
  sp4.fillCircle( 52, 26, 27, 13);
  sp4.fillCircle( 52, 26, 24,  4);
  sp4.setClipRect(51, 0, 51, 107);
  sp4.fillCircle( 50, 78, 27, 13);
  sp4.fillCircle( 50, 78, 24,  4);
  sp4.clearClipRect();
  sp4.drawFastVLine( 51,  0, 107, 14);
  sp4.drawLine( 34, 10, 51, 27, 14);

  base.setPaletteColor( 1, 207,   0,   0);
  base.setPaletteColor( 4, 223,  31,  47);
  base.setPaletteColor( 2, 239,  63,  95);
  base.setPaletteColor( 3, 255,  95, 143);
  base.setPaletteColor(13,   0,   0,   0);
  base.setPaletteColor(14,  80,  80,  80);
  base.setPaletteColor(15, 191, 191, 191);

  for (int i = 0; i <= 80; ++i) {
    base.clear();
    base.drawFastHLine(  0, 119, 17, 14);
    base.drawFastHLine(222, 119, 17, 14);
    base.drawFastVLine(119,   0, 14, 14);
    base.drawFastVLine(119, 225, 14, 14);

    float r1 = 0;
    float r2 = 0;
    float r3 = 0;
    float r4 = 0;

    float z1 = 1;
    if (i <= 20) z1 = 0;
    else if (i <= 50) {
      r1 = (i - 50) * 6;
      z1 = (float)(i - 20) / 30.0;
    }
    float z2 = 1;
    if (i <= 30) z2 = 0;
    else if (i <= 60) {
      r2 = (i - 60) * 6;
      z2 = (float)(i - 30) / 30.0;
    }
    
    float z3 = 1;
    if (i <= 42) z3 = 0;
    else if (i <= 72) {
      r3 = (i - 72) * 6;
      z3 = (float)(i - 42) / 30.0;
    }
    
    float z4 = 1;
    if (i <= 50) z4 = 0;
    else if (i <= 75) {
      r4 = (i - 75) * 7;
      z4 = (float)(i - 50) / 25.0;
    }
    
    sp1.pushRotateZoom(r1, z1, z1);
    sp4.pushRotateZoom(r4, z4, z4);
    sp2.pushRotateZoom(r2, z2, z2);
    sp3.pushRotateZoom(r3, z3, z3);
    sp1.pushRotateZoom(r1, z1, z1, 1);
    sp4.pushRotateZoom(r4, z4, z4, 4);
    sp2.pushRotateZoom(r2, z2, z2, 2);
    sp3.pushRotateZoom(r3, z3, z3, 3);
    base.pushSprite((tft.width() - base.width()) >> 1, (tft.height() - base.height()) >> 1);
  }
  for (int i = 0; i < 512; i += 4) {
    base.setPaletteColor( 1, std::max(0, std::min(207, 237 - i)), 0, 0);
    base.setPaletteColor( 4, std::max(0, std::min(223, 272 - i)), std::max(0, 31 - i), std::max(0,  47 - i));
    base.setPaletteColor( 2, std::max(0, std::min(239, 307 - i)), std::max(0, 63 - i), std::max(0,  95 - i));
    base.setPaletteColor( 3, std::max(0, std::min(255, 352 - i)), std::max(0, 95 - i), std::max(0, 143 - i));
    base.setPaletteColor(13, std::min(255, i>>1), 0, 0);
    base.pushSprite((tft.width() - base.width()) >> 1, (tft.height() - base.height()) >> 1);
  }

  int px = tft.width() >> 1;
  int py = tft.height() >> 1;
  tft.setTextFont(2);
  tft.setTextColor(0xFF0000U);

  tft.setCursor( px - 63, py - 99 );  drawStr("Hyper Operating System");
  delay(50);
  tft.setCursor( px - 18, py - 87 );  drawStr("Ver1.0");
  delay(50);
  tft.setCursor( px - 48, py - 76 );  drawStr("for ALL LABORS");

  delay(900);

  tft.setCursor( px - 24, py + 64 );  drawStr("(c)1999");
  delay(50);
  tft.setCursor( px - 68, py + 79 );  drawStr("Shinohara Heavy Industry");

  delay(2000);

  tft.clear();
  tft.setTextColor(0xFFFFFFU, 0);
  tft.setCursor( px - 64, py    );  drawStr("attach cd 01 /", true);

  blinkCursor(9);

  tft.scroll(0, -14);

  tft.setCursor( px - 64, py    );  drawStr("enter author password", true);
  blinkCursor(1);

  tft.scroll(0, -14);

  tft.setCursor( px - 64, py    );  drawStr("pass : ", true);

  blinkCursor(24);

  blinkCursor(1);  drawStr("E.", true);
  blinkCursor(3);  drawStr("HO", true);
  blinkCursor(1);  drawStr("BA", true);

  blinkCursor(16);

  tft.clear();

  delay(1300);
  tft.setCursor(px - 120, 100);  drawStr(" Go to, let us go down, and there confound");
  delay(700);
  tft.setCursor(px - 120, 114);  drawStr("their language, that they may not understand");
  delay(700);
  tft.setCursor(px - 120, 128);  drawStr("one another's speech .");

  delay(8000);

  tft.setTextColor(0xFF0000U);
  tft.setTextWrap(false, false);
}

void loop(void)
{
  tft.setCursor(0, tft.height() - 14);
  tft.print("BABEL BABEL BABEL BABEL BABEL BABEL BABEL BABEL ");
  tft.scroll(0, -15);
  tft.setCursor(0, tft.height() - 14);
  tft.print(" BABEL BABEL BABEL BABEL BABEL BABEL BABEL BABEL");
  tft.scroll(0, -15);
}
