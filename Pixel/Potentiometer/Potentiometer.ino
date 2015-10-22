// Code by Pixel, DroidTeam
// Little Potentiometer test
// - Attatch the middle wire of the Potmeter to "analog input 0" / PC0. Or change the PotmeterPIN variable
// - Other two wires are + and -
// Any kind of button on "digital pin 9" / PB1 (the -) and on "digital pin 11" / PB3 (the +)

#include "LedControl.h"
//				LedControl(DATA_PIN, CLK_PIN, CS_PIN, DISPLAYS)
LedControl lc=	LedControl(20, 5, 21, 2);
int PotmeterPIN = 0;

#define DEBUG false

int changed = false;
int columns = true;
unsigned int oldY;
unsigned int wait;

void setup() {
	if (DEBUG) Serial.begin(57600);
	
	lc.shutdown(0,false);
	lc.clearDisplay(0);
	lc.setIntensity(0, 15);
	lc.shutdown(1,false);
	lc.clearDisplay(1);
	lc.setIntensity(1, 15);
	pinMode(11, OUTPUT);
	digitalWrite(11, LOW);
	pinMode(9, INPUT_PULLUP);
	delay(100);
	updateDisplays(height());
}

int buttonState = HIGH;

void loop(){
	if (wait >= 100){
		int reader = digitalRead(9);
		if (digitalRead(9) != buttonState){
			if (DEBUG) Serial.println("Button Pressed");
			wait = 0;
			rotate();
			changed = true;
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
	if (meter >=  950				 )	return 7;
	if (meter >=  750 && meter <  950) 	return 6;
	if (meter >=  625 && meter <  750)	return 5;
	if (meter >=  500 && meter <  625)	return 4;
	if (meter >=  375 && meter <  500) 	return 3;
	if (meter >=  250 && meter <  375)	return 2;
	if (meter >=  125 && meter <  250) 	return 1;
	if (meter <   125				 ) 	return 0;
}

void updateDisplays(int newY){
	if (newY != oldY || changed){
		if (DEBUG) Serial.println(analogRead(PotmeterPIN));
		changed = false;
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
	if (DEBUG) Serial.print("Columns = ");
	if (columns){
		lc.setColumn( 0, oldY, 0);
		lc.setColumn( 1, 7-oldY, 0);
		columns = false;
		if (DEBUG) Serial.println(columns);
	}
	else{
		lc.setRow( 0, oldY, 0);
		lc.setRow( 1, 7-oldY, 0);
		columns = true;
		if (DEBUG) Serial.println(columns);
	}
}