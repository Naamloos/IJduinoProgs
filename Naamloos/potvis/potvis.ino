/*
 * i cant get pixels code to fucking work. 
 * i make my own lol.
 */
#include "LedControl.h"
int potpin = 0;
int potplus = 6;
int potmin = 3;
int pos;
LedControl lc=  LedControl(20, 5, 21, 1);

void setup() {
  // put your setup code here, to run once:
    pinMode(potplus, OUTPUT);
    digitalWrite(potplus, LOW);
    pinMode(potmin, INPUT_PULLUP);
    lc.shutdown(0,false);
    lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
int meetmij = analogRead(potpin);

if (meetmij>=500){
pos = 1;
}

if (meetmij<500){
pos = 0;
}
lc.clearDisplay(0);
lc.setRow( 0, pos, 255);

}
