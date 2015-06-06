/*This game has been built around an early version of
 "JumpGame" by pixel :) */

#include "LedControl.h"
// scroller from FLAPPIJ BIRD. more code wont be used :3
LedControl lc = LedControl(20, 5, 21, 1);
bool jumping;
bool atwall = false;
bool atplayer = false;
bool dead = true;
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
B00000000};

void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
}

int buttonState = HIGH;

void loop() {
  bool ended = isdead();
  int reader = digitalRead(9);
  if(!ended){
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
  }
  if (dead) {
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
  if(ended){
    render(ded,100000);
  }
}

int render(const byte* frame, long delaytime) {
    lc.clearDisplay(0);
  for (int r = 0; r < 8; r++) {
    lc.setColumn(0, 7 - r, pgm_read_byte(&frame[r]));
  }
  delay(delaytime);
}

bool firstroll = true;
bool isdead() {
  int ply = playery();
  bool wallplayb = wallplay();
  if (firstroll = false){
  if (wallplayb = true) {
    if (ply = 0) {
      return true;
    }
    if (ply = 1) {
      return true;
    }
    if (ply = 6) {
      return true;
    }
    if (ply = 7) {
      return true;
    }
    return false;
  }
  }
  firstroll = false;
    return false;
}



