// Code by Pixel & Naamloos, DroidTeam

#include "LedControl.h"
//				LedControl(DATA_PIN, CLK_PIN, CS_PIN, DISPLAYS)
LedControl lc=	LedControl(20, 5, 21, 1);

unsigned int oldY;

void setup() {
	  lc.shutdown(0,false);
	  lc.clearDisplay(0);
	  pinMode(11, OUTPUT);
	  digitalWrite(11, LOW);
	  pinMode(9, INPUT_PULLUP);
   analogWrite(5, 0);
}

int buttonState = HIGH;

void loop(){
  int areader = analogRead(3);
  if (areader >= 500 && areader < 1000){
    lc.setColumn( 0, 0, 255);
  }
  
  if (digitalRead(9) != buttonState){
    analogWrite(5, 700);
  }
  
}
