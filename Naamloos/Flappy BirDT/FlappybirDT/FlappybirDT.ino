/*
 This game has been built around an early version of
 "JumpGame" by pixel :)
 a lot of stuff has been added here that hasn't been added there.. wow xD
 my code: 98%
 pixels code: 1%
 ijhack's code: 1% xD
 */

#include "LedControl.h"
LedControl lc = LedControl(20, 5, 21, 1);
int wallx = 7;
bool boot = true;
bool jumping;
bool atwall = false;
bool atplayer = false;
bool dead = true;
int startx = 1;
int starty = 4;
int cury ;
int curx;
int score;
int diff = 250;

const byte homes[8] PROGMEM = {B00000010,
                               B00000010,
                               B00000010,
                               B00000000,
                               B01000000,
                               B00000000,
                               B00000010,
                               B00000010
                              };

bool firstroll = true;

void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
  score = 0;
}

int buttonState = HIGH;

void loop() {
  if (boot) {
    render(homes, 0);
    boot = false;
  }
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
    if (reader != buttonState) {
      lc.clearDisplay(0);
      buttonState = buttonState;
      spawn();
      dead = false;
      score = 0;
      return;
    }
  }
  difficulty();
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
      delay(400);
      return true;
    }
    if (cury >= 5) {
      delay(400);
      return true;

    }
    else {
      score = score + 1;
      return false;
    }
  }
  return false;
}

// Moving code to one script



void wall() {
  lc.setLed(0, wallx, 0, LOW);
  lc.setLed(0, wallx, 1, LOW);
  lc.setLed(0, wallx, 5, LOW);
  lc.setLed(0, wallx, 6, LOW);
  lc.setLed(0, wallx, 7, LOW);
  if (wallx > 0) {
    wallx = wallx - 1;
  }
  if (wallx <= 0) {
    lc.setLed(0, wallx, 0, HIGH);
    lc.setLed(0, wallx, 1, HIGH);
    lc.setLed(0, wallx, 5, HIGH);
    lc.setLed(0, wallx, 6, HIGH);
    lc.setLed(0, wallx, 7, HIGH);
    delay(25);
    wallx = 7 ;
    lc.setLed(0, 0, 0, LOW);
    lc.setLed(0, 0, 1, LOW);
    lc.setLed(0, 0, 5, LOW);
    lc.setLed(0, 0, 6, LOW);
    lc.setLed(0, 0, 7, LOW);

  }
  lc.setLed(0, wallx, 0, HIGH);
  lc.setLed(0, wallx, 1, HIGH);
  lc.setLed(0, wallx, 5, HIGH);
  lc.setLed(0, wallx, 6, HIGH);
  lc.setLed(0, wallx, 7, HIGH);

  delay(diff);
}

bool jump() {
  if (cury < 7) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury + 1;
    lc.setLed(0, curx, cury, HIGH);
  }
  return true;
}

void fall() {
  if (cury > 0 ) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury - 1;
    lc.setLed(0, curx, cury, HIGH);
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

void difficulty(){
  if (score == 0) {
    diff = 150;
  }
  if (score == 5) {
    diff = 100;
  }
  if (score == 10) {
    diff = 70;
  }
  if (score == 15) {
    diff = 50;
  }
    if (score == 20) {
    diff = 45;
  }
      if (score == 25) {
    diff = 40;
  }
      if (score == 30) {
    diff = 35;
  }
      if (score == 35) {
    diff = 30;
  }
      if (score == 40) {
    diff = 25;
  }
}

