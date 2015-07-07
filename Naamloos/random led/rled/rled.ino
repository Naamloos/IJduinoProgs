#include <LedControl.h>
LedControl lc=LedControl(20, 5, 21, 1);

/* got bored. decided to make something for fun.
it doesnt use the button only the led display. 
before using, please choose what mode you want to use.
modes:
0: random leds
1: vertical row
2: horizontal row

also: please choose the delay time.
*/

int mode = 1;
int delaytime = 200;

//
//


int leds;

void setup() {
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  if (mode == 0){
    leds = 64;
  }
  if (mode == 1){
    leds = 8;
  }
    if (mode == 2){
    leds = 8;
  }
}

void loop() {
if (mode == 1){
  int randNumber = random(0, 7);
  lc.setColumn(0,randNumber,B11111111);
}
delay(delaytime);
}
