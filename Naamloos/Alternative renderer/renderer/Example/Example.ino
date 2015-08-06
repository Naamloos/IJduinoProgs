#include <LedControl.h>
int fdelay = 500;
int INTENSITY = 5;
static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;
LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);
byte smiley [8]= {B11000011,
B10000001,
B00100100,
B00100100,
B00000000,
B01000010,
B01000010,
B00111100};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
}

void loop() {
render(smiley);
delay(500);
}

