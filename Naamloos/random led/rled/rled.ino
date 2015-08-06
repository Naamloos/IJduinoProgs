#include <LedControl.h>
LedControl lc=LedControl(20, 5, 21, 1);

/* 
got bored. decided to make something for fun.
it doesnt use the button only the led display. 
*/

void setup() {
  lc.shutdown(0,false);
  lc.clearDisplay(0);
}

void loop() {
  int randNumber1 = random(0, 8);
  int randNumber2 = random(0, 8);
  lc.setLed(0,randNumber1,randNumber2, true);
  delay(200);
}
