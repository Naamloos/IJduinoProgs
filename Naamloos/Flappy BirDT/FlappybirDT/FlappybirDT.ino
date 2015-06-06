/*This game has been built around an early version of
 "JumpGame" by pixel :) */

#include "LedControl.h"
LedControl lc = LedControl(20, 5, 21, 1);
bool jumping;

void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
  spawn();
}

int buttonState = HIGH;

void loop() {
  int reader = digitalRead(9);
  if (reader != buttonState) {
    buttonState = buttonState;
    jumping = jump();
  }
    if (!jumping) {
    fall();
    }

  jumping = false;
}

