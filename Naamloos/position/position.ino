#include <LedControl.h>
int potpin = 0;
int potpindos = 1;
int speakerpin = 10;
int posx;
int posy;
int mode = 0;
int x;
int y;
int buttonState = HIGH;
int posoldx;
int posoldy;
LedControl lc = LedControl(20, 5, 21, 1);

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  posx = getposx();
  posy = getposy();
  if (posoldx != posx) {
    lc.clearDisplay(0);
  }
    if (posoldy != posy) {
    lc.clearDisplay(0);
  }
  if (mode == 0) {
    lc.setRow(0, posx, 255);
    lc.setColumn(0, posy, 255);
    int reader = digitalRead(9);
    if (digitalRead(9) != buttonState) {
      tone (speakerpin, 1000);
      delay(300);
      noTone(speakerpin);
      x = posx;
      y = posy;
      lc.clearDisplay(0);
      mode = mode + 1;
    }
  }
  if (mode == 1) {
    lc.setLed(0, x, y, true);
    int reader = digitalRead(9);
    if (digitalRead(9) != buttonState) {
      delay(300);
      lc.clearDisplay(0);
      mode = 0;
    }
  }
  posoldx = posx;
  posoldy = posy;
}

int getposx() {
  int xypos = analogRead(potpin);
  if (xypos < 125) {
    return 0;
  }
  if (xypos >= 125 && xypos < 250) {
    return 1;
  }
  if (xypos >= 250 && xypos < 375) {
    return 2;
  }
  if (xypos >= 375 && xypos < 500) {
    return 3;
  }
  if (xypos >= 500 && xypos < 625) {
    return 4;
  }
  if (xypos >= 625 && xypos < 750) {
    return 5;
  }
  if (xypos >= 750 && xypos < 875) {
    return 6;
  }
  if (xypos >= 875) {
    return 7;
  }
}

int getposy() {
  int xypos = analogRead(potpindos);
  if (xypos < 125) {
    return 0;
  }
  if (xypos >= 125 && xypos < 250) {
    return 1;
  }
  if (xypos >= 250 && xypos < 375) {
    return 2;
  }
  if (xypos >= 375 && xypos < 500) {
    return 3;
  }
  if (xypos >= 500 && xypos < 625) {
    return 4;
  }
  if (xypos >= 625 && xypos < 750) {
    return 5;
  }
  if (xypos >= 750 && xypos < 875) {
    return 6;
  }
  if (xypos >= 875) {
    return 7;
  }
}
