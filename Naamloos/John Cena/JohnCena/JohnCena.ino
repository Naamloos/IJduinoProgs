#include "LedControl.h"
LedControl lc = LedControl(20, 5, 21, 1);
int speakerpin = 10;
bool first = true;

byte J[8] = {B01111111,
B00000010,
B00000010,
B00000010,
B00000010,
B01000010,
B01000010,
B00111100};

byte O[8] = {B01111110,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B10000001,
B01111110};

byte H[8] = {B10000001,
B10000001,
B10000001,
B11111111,
B10000001,
B10000001,
B10000001,
B10000001};

byte N[8] = {B10000001,
B11000001,
B10100001,
B10010001,
B10001001,
B10000101,
B10000011,
B10000001};

byte C[8] = {B01111110,
B10000001,
B10000000,
B10000000,
B10000000,
B10000000,
B10000001,
B01111110};

byte E[8] = {B01111110,
B10000001,
B10000000,
B10000000,
B11111000,
B10000000,
B10000001,
B01111110};

byte A[8] = {B01111110,
B10000001,
B10000001,
B10000001,
B11111111,
B10000001,
B10000001,
B10000001};

byte CENA[8] = {B01111110,
B11000001,
B10111101,
B10110001,
B10101001,
B10111101,
B10000011,
B01111110};

void setup() {
  lc.shutdown(0, false);
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (first){
    render(J);
    delay(500);
      lc.clearDisplay(0);
        render(O);
    delay(500);
      lc.clearDisplay(0);
        render(H);
    delay(500);
      lc.clearDisplay(0);
        render(N);
    delay(500);
      lc.clearDisplay(0);
        render(C);
    delay(500);
      lc.clearDisplay(0);
        render(E);
    delay(500);
      lc.clearDisplay(0);
        render(N);
    delay(500);
      lc.clearDisplay(0);
        render(A);
    delay(500);
      lc.clearDisplay(0);
      first = false;
  }
    render(CENA);  
    tone(speakerpin, 294);
    delay(170);
    tone(speakerpin, 330);
    delay(150);
    tone(speakerpin, 262);
    delay(150);
    tone(speakerpin, 294);
    delay(1000);
    tone(speakerpin, 0);
    delay(1250);

        tone(speakerpin, 349);
    delay(170);
    tone(speakerpin, 330);
    delay(150);
    tone(speakerpin, 262);
    delay(150);
    tone(speakerpin, 294);
    delay(1000);
    tone(speakerpin, 0);
    delay(1250);
          tone(speakerpin, 294);
    delay(170);
    tone(speakerpin, 330);
    delay(150);
    tone(speakerpin, 262);
    delay(150);
    tone(speakerpin, 294);
        delay(1000);
    tone(speakerpin, 0);
    delay(1250);

        tone(speakerpin, 349);
    delay(170);
    tone(speakerpin, 330);
    delay(150);
    tone(speakerpin, 262);
    delay(150);
    tone(speakerpin, 294);
    delay(1000);
    tone(speakerpin, 0);
    delay(1250);
}
