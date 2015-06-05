// This game has been built around an early version of
// "JumpGame" by pixel :)
#include "LedControl.h"
LedControl lc = LedControl(20, 5, 21, 1);

int starty1 = 0;
int starty2 = 7;
int cury1 ;
int cury2 ;
int jumpHeight = 4;
bool jumping;

bool jump() {
  if (cury1 < 7) {
    lc.setLed(0, 0, cury1, LOW);
    lc.setLed(0, 1, cury2, LOW);
    lc.setLed(0, 2, cury1, LOW);
    lc.setLed(0, 3, cury2, LOW);
    lc.setLed(0, 4, cury1, LOW);
    lc.setLed(0, 5, cury2, LOW);
    lc.setLed(0, 6, cury1, LOW);
    lc.setLed(0, 7, cury2, LOW);
    
    cury2 = cury2 - 1;
    cury1 = cury1 + 1;
    
    lc.setLed(0, 0, cury1, HIGH);
    lc.setLed(0, 1, cury2, HIGH);
    lc.setLed(0, 2, cury1, HIGH);
    lc.setLed(0, 3, cury2, HIGH);
    lc.setLed(0, 4, cury1, HIGH);
    lc.setLed(0, 5, cury2, HIGH);
    lc.setLed(0, 6, cury1, HIGH);
    lc.setLed(0, 7, cury2, HIGH);
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
  //0
  lc.setLed(0, 0, starty1, HIGH);
  //1
  lc.setLed(0, 1, starty2, HIGH);
  //2
  lc.setLed(0, 2, starty1, HIGH);
  //3
  lc.setLed(0, 3, starty2, HIGH);
  //4
  lc.setLed(0, 4, starty1, HIGH);
  //5
  lc.setLed(0, 5, starty2, HIGH);
  //6
  lc.setLed(0, 6, starty1, HIGH);
  //7
  lc.setLed(0, 7, starty2, HIGH);
  
  
  cury1 = starty1;
  cury2 = starty2;

}

int buttonState = HIGH;

void loop() {
  int reader = digitalRead(9);
  if (reader != buttonState) {
    buttonState = buttonState;
    jumping = jump();
    //delay(1000);
  }
  if (cury1 > 0 ) {
    if (!jumping) {
      lc.setLed(0, 0, cury1, LOW);
      lc.setLed(0, 1, cury2, LOW);
      lc.setLed(0, 2, cury1, LOW);
      lc.setLed(0, 3, cury2, LOW);
      lc.setLed(0, 4, cury1, LOW);
      lc.setLed(0, 5, cury2, LOW);
      lc.setLed(0, 6, cury1, LOW);
      lc.setLed(0, 7, cury2, LOW);

      cury1 = cury1 - 1;
      cury2 = cury2 + 1;

      lc.setLed(0, 7, cury2, HIGH);
      lc.setLed(0, 6, cury1, HIGH);
      lc.setLed(0, 5, cury2, HIGH);
      lc.setLed(0, 4, cury1, HIGH);
      lc.setLed(0, 3, cury2, HIGH);
      lc.setLed(0, 2, cury1, HIGH);
      lc.setLed(0, 1, cury2, HIGH);
      lc.setLed(0, 0, cury1, HIGH);

      
      delay(80);
    }
  }
  jumping = false;
}

