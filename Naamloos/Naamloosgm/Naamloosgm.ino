#include <LedControl.h>
LedControl lc = LedControl(20, 5, 21, 1);
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);

  
void setup() {
  // Code for initializing program
  lc.shutdown(0, false);
  lc.clearDisplay(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  // Code that should be looped throughout the whole game.

}

// TO BE CONTINUED :)
