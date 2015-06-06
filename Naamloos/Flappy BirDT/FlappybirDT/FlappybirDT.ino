/*This game has been built around an early version of
 "JumpGame" by pixel :) */

#include "LedControl.h"
// scroller from FLAPPIJ BIRD. more code wont be used :3
LedControl lc = LedControl(20, 5, 21, 1);
int wallx = 7;
bool jumping;
bool atwall = false;
bool atplayer = false;
bool dead = true;
int startx = 1;
int starty = 5;
int cury ;
int curx;

bool firstroll = true;
const byte homemen1[8] PROGMEM = {B00100100,
                                  B00100100,
                                  B00011000,
                                  B00000000,
                                  B00111100,
                                  B01000010,
                                  B11111111,
                                  B10000001
                                 };
const byte homemen2[8] PROGMEM = {B00100100,
                                  B00100100,
                                  B00100100,
                                  B00100100,
                                  B00011000,
                                  B01111110,
                                  B11111111,
                                  B10000001
                                 };

const byte ded[8] PROGMEM = {B01000010,
                             B01000010,
                             B01000010,
                             B00000000,
                             B00000000,
                             B01111110,
                             B10000001,
                             B00000000
                            };

void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
}

int buttonState = HIGH;

void loop() {
  int reader = digitalRead(9);
  if (!dead) {
    if (reader != buttonState) {
      buttonState = buttonState;
      jumping = jump();
    }
    if (!jumping) {
      fall();
    }
    wall();
    jumping = false;
    fixplayer;
    dead = isdead();
  }
  if (dead) {
    cury = starty;
    wallx = 7;
    render(homemen1, 150);
    if (reader != buttonState) {
      lc.clearDisplay(0);
      buttonState = buttonState;
      spawn();
      dead = false;
      return;
    }
    render(homemen2, 150);
    if (reader != buttonState) {
      lc.clearDisplay(0);
      buttonState = buttonState;
      spawn();
      dead = false;
      return;
    }
  }
}


int render(const byte* frame, long delaytime) {
  lc.clearDisplay(0);
  for (int r = 0; r < 8; r++) {
    lc.setColumn(0, 7 - r, pgm_read_byte(&frame[r]));
  }
  delay(delaytime);
}

bool isdead() {
  if (wallx <= 1) {
    if (cury <= 1) {
      return true;
      delay(200);
    }
    if (cury >= 6) {
      return true;
      delay(200);
    }
    else {
      return false;
    }
  }
  return false;
}

// Moving code to one script



void wall() {
  lc.setLed(0, wallx, 0, LOW);
  lc.setLed(0, wallx, 1, LOW);
  lc.setLed(0, wallx, 6, LOW);
  lc.setLed(0, wallx, 7, LOW);
  if (wallx > 0) {
    wallx = wallx - 1;
  }
  if (wallx <= 0) {
    wallx = 7 ;
  }
  lc.setLed(0, wallx, 0, HIGH);
  lc.setLed(0, wallx, 1, HIGH);
  lc.setLed(0, wallx, 6, HIGH);
  lc.setLed(0, wallx, 7, HIGH);

  delay(100);
}

bool jump() {
  if (cury < 7) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury + 1;
    lc.setLed(0, curx, cury, HIGH);
    //delay(60);
  }
  return true;
}

void fall() {
  if (cury > 0 ) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury - 1;
    lc.setLed(0, curx, cury, HIGH);
    //delay(80);
  }
}

void spawn() {
  lc.setLed(0, startx, starty, HIGH);
  cury = starty;
  curx = startx;
}

void fixplayer() {
  lc.setLed(0, curx, cury, LOW);
  lc.setLed(0, curx, cury, HIGH);
}

int playery() {
  return cury;
}

