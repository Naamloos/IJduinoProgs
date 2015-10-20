// Code by Pixel, DroidTeam
// Naamloos edition :P
// Little Potentiometer test
// - Attatch the middle wire of the Potmeter to "analog input 0" / PC0. Or change the PotmeterPIN variable
// - Other two wires are + and -

#include "LedControl.h"
LedControl lc=LedControl(20, 5, 21, 1);

int PotmeterPIN = 0;

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
}

void loop(){
  int Y = 0;
  int meter = analogRead(PotmeterPIN);
  unsigned int oldmeter;
  
  if (meter != oldmeter){
	  if (meter >= 1000){
		Y = 7;
	  }
	  
	  if (meter >= 750 && meter < 1000){
		Y = 6; 
	  }
	  
	  if (meter >= 625 && meter < 750){
		Y = 5;
	  }
	  
	  if (meter >= 500 && meter < 625){
		Y = 4;
		}
	  
	  if (meter >= 375 && meter < 500){
		Y = 3; 
		}
	  
	  if (meter >= 250 && meter < 375){
		Y = 2;
	  }
	  
	  if (meter >= 125 && meter < 250){
		Y = 1;
	  }
	  
	  if (meter >= 0 && meter < 125){
		Y = 0;
	  }
    lc.setColumn( 0, Y, 255);
    lc.clearDisplay(0);
  }
}
