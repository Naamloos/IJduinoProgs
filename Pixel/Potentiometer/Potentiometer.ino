// Code by Pixel, DroidTeam
// Little Potentiometer test
// - Attatch the middle wire of the Potmeter to "analog input 0" / PC0. Or change the PotmeterPIN variable
// - Other two wires are + and -

#include "LedControl.h"
//				LedControl(DATA_PIN, CLK_PIN, CS_PIN, DISPLAYS)
LedControl lc=	LedControl(20, 5, 21, 2);
int PotmeterPIN = 0;

int columns = true;
unsigned int oldY;
unsigned int wait;

void setup() {
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  lc.shutdown(1,false);
  lc.clearDisplay(1);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
  
  updateDisplays(height());
}

int buttonState = HIGH;

void loop(){
	if (wait >= 100){
		int reader = digitalRead(9);
		if (digitalRead(9) != buttonState){
			wait = 0;
			rotate();
		}
	}
	else{
		wait = wait+1;
	}
	updateDisplays(height());
	delay(10);
	
}

int height(){
	int meter = analogRead(PotmeterPIN);
	if (meter >= 1000				 )	return 7;
	if (meter >=  750 && meter < 1000) 	return 6;
	if (meter >=  625 && meter <  750)	return 5;
	if (meter >=  500 && meter <  625)	return 4;
	if (meter >=  375 && meter <  500) 	return 3;
	if (meter >=  250 && meter <  375)	return 2;
	if (meter >=  125 && meter <  250) 	return 1;
	if (meter >=    0 && meter <  125) 	return 0;
}

void updateDisplays(int newY){
	if (newY != oldY){
		if (columns){
			lc.setColumn( 0, oldY, 0);
			lc.setColumn( 1, 7-oldY, 0);
			oldY = newY;
			lc.setColumn( 0, newY, 255);
			lc.setColumn( 1, 7-newY, 255);
		}else{
			lc.setRow( 0, oldY, 0);
			lc.setRow( 1, 7-oldY, 0);
			oldY = newY;
			lc.setRow( 0, newY, 255);
			lc.setRow( 1, 7-newY, 255);			
		}
	}
}

void rotate(){
	if (columns){
		lc.setColumn( 0, oldY, 0);
		lc.setColumn( 1, 7-oldY, 0);
		columns = false;
	}
	else{
		lc.setRow( 0, oldY, 0);
		lc.setRow( 1, 7-oldY, 0);
		columns = true;
	}
	updateDisplays(height());
	oldY = 0;
}