#include "LedControl.h"
LedControl lc=LedControl(20, 5, 21, 1);

int x = 1;
int y = 0;
int jumpHeight = 4;

void fall(){
  for (y = jumpHeight-1; y >= 0; y--){
    lc.clearDisplay(0);
    lc.setLed(0, x, y, HIGH);
    lc.setLed(0, x+1, y, HIGH);
    lc.setLed(0, x, y+1, HIGH);
    lc.setLed(0, x+1, y+1, HIGH);
    lc.setLed(0, x+1, y+2, HIGH);
    lc.setLed(0, x, y+2, HIGH);
    delay(50);
  }
}
void jump(){
  for (y=1; y < jumpHeight; y++){
    lc.clearDisplay(0);
    lc.setLed(0, x, y, HIGH);
    lc.setLed(0, x+1, y, HIGH);
    lc.setLed(0, x, y+1, HIGH);
    lc.setLed(0, x+1, y+1, HIGH);
    lc.setLed(0, x+1, y+2, HIGH);
    lc.setLed(0, x, y+2, HIGH);
    delay(50);
  }
  fall();
}

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
  
  lc.setLed(0, x, y, HIGH);
  lc.setLed(0, x+1, y, HIGH);
  lc.setLed(0, x, y+1, HIGH);
  lc.setLed(0, x+1, y+1, HIGH);
  lc.setLed(0, x+1, y+2, HIGH);
  lc.setLed(0, x, y+2, HIGH);  
}

int buttonState = HIGH;

void loop() {
  int reader = digitalRead(9);
  if (reader != buttonState){
    buttonState = buttonState;
    jump();
    //delay(1000);
  }
}



