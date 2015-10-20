// Code by Pixel, DroidTeam
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
  int meter = analogRead(PotmeterPIN);
  unsigned int oldmeter;
  
  if (meter != oldmeter){
	  if (meter >= 1000){
		oldmeter = meter;
		lc.setColumn( 0, 7, 255);
	  }
	  else{
		oldmeter = meter;
		lc.setColumn( 0, 7, 0);
	  }
	  
	  if (meter >= 750 && meter < 1000){
		oldmeter = meter;	
		lc.setColumn( 0, 6, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 6, 0);
	  }
	  
	  if (meter >= 625 && meter < 750){
		oldmeter = meter;	
		lc.setColumn( 0, 5, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 5, 0);
	  }
	  
	  if (meter >= 500 && meter < 625){
		oldmeter = meter;	
		lc.setColumn( 0, 4, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 4, 0);
	  }
	  
	  if (meter >= 375 && meter < 500){
		oldmeter = meter;	
		lc.setColumn( 0, 3, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 3, 0);
	  }
	  
	  if (meter >= 250 && meter < 375){
		oldmeter = meter;	
		lc.setColumn( 0, 2, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 2, 0);
	  }
	  
	  if (meter >= 125 && meter < 250){
		oldmeter = meter;	
		lc.setColumn( 0, 1, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 1, 0);
	  }
	  
	  if (meter >= 0 && meter < 125){
		oldmeter = meter;	
		lc.setColumn( 0, 0, 255);
	  }
	  else{
		oldmeter = meter;	
		lc.setColumn( 0, 0, 0);
	  }
  }
}