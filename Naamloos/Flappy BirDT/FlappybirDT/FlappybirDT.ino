// This game has been built around an early version of
// "JumpGame" by pixel :)
#include "LedControl.h"
LedControl lc = LedControl(20, 5, 21, 1);

int startx = 1;
int starty = 0;
int curx ;
int cury ;
int jumpHeight = 4;
bool jumping;

bool jump() {
  if (cury < 7) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury + 1;
    lc.setLed(0, curx, cury, HIGH);
    delay(60);
  }
  return true;
}

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);

  lc.setLed(0, startx, starty, HIGH);
  cury = starty;
  curx = startx;
}

int buttonState = HIGH;

void loop() {
  int reader = digitalRead(9);
  if (reader != buttonState) {
    buttonState = buttonState;
    jumping = jump();
    //delay(1000);
  }
  if (cury > 0 ) {
    if (!jumping) {
      lc.setLed(0, curx, cury, LOW);
      cury = cury - 1;
      lc.setLed(0, curx, cury, HIGH);
      delay(80);
    }
  }
  jumping = false;
}

