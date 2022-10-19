#include "M5CoreInk.h"
#include <efontEnableAll.h>
#include <efontFontData.h>
#include <LovyanGFX.hpp>

Ink_Sprite inkPageSprite(&M5.M5Ink);
static LGFX_Sprite sprite;

void pushSprite(Ink_Sprite *coreinkSprite, LGFX_Sprite *lgfxSprite);

void setup() {
  M5.begin();
  M5.M5Ink.isInit();
  M5.M5Ink.clear();
  inkPageSprite.creatSprite(0, 0, 200, 200, false);

  // スプライト作成
  sprite.setColorDepth(2);
  sprite.createPalette();
  sprite.createSprite(200, 200);
  sprite.clear(TFT_WHITE);
  sprite.setFont(&fonts::efont);
  sprite.setTextColor(TFT_BLACK, TFT_WHITE);

  // 描画テスト
  sprite.print("Hello\n");
  sprite.print("こんにちは\n");
  sprite.print("你好\n");
  sprite.print("안녕하세요\n");
  sprite.print("Доброе утро\n");
  sprite.print("Päivää\n");
  sprite.print("Здравствуйте\n");

  sprite.setCursor(0, 130);
  sprite.setTextSize(2);
  sprite.setTextColor(TFT_WHITE, TFT_BLACK);
  sprite.print("LovyanGFX\nPrint Test");

  pushSprite(&inkPageSprite, &sprite);
}

void loop() {
  delay(1);
}

void pushSprite(Ink_Sprite *coreinkSprite, LGFX_Sprite *lgfxSprite) {
  coreinkSprite->clear();
  for (int y = 0; y < 200; y++) {
    for (int x = 0; x < 200; x++) {
      uint16_t c = lgfxSprite->readPixel(x, y);
      if (c == 0x0000) {
        coreinkSprite->drawPix(x, y, 0);
      }
    }
  }
  coreinkSprite->pushSprite();
}
