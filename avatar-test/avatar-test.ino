#include <M5Stack.h>
#include <Avatar.h>

using namespace m5avatar;

Avatar avatar;

const Expression expressions[] = {
  Expression::Angry,
  Expression::Sleepy,
  Expression::Happy,
  Expression::Sad,
  Expression::Doubt,
  Expression::Neutral
};
const int expressionsSize = sizeof(expressions) / sizeof(Expression);
int idx = 0;

const char* phrases[] = {
  "How are you?",
  "Hungry...",
  "I'm bored."
  "What's time?",
  "Did you say something?",
  "It's time."
};
const int phrasesSize = sizeof(phrases) / sizeof(char*);
int phrase_idx = 0;

void setup()
{
  M5.begin();
  M5.Lcd.setBrightness(30);
  M5.Lcd.clear();

  avatar.init();
}

void loop()
{
  M5.update();
  idx = rand() % expressionsSize;
  Expression expression = expressions[idx];
  avatar.setExpression(expression);
  if (expression == Expression::Neutral) {
    phrase_idx = rand() % phrasesSize;
    avatar.setSpeechText(phrases[phrase_idx]);
  } else {
    avatar.setSpeechText("");
  }
  delay(30000);
}
