#include <LedControl.h>
// This is basically a small program that allows you to easily make animations on your
// ijduino. A small tutorial how to make animations:
// First, lets set the time that your ijduino will wait between each frame. (in milliseconds!)
int fdelay = 500;
// As a default, i have set the time to 500. this means it will wait 0.5 seconds.
// Now we will have to set the intensity of your LED. I recommend 5. I don't know what happens when you put it higher.
int INTENSITY = 5;
// After setting the intensity, lets put all the frames below! :)
// To generate frames, i recommend the LED matrix generator by IJhack :) http://ijhack.nl/en/page/led-matrix-generator/ //
// Now put every frame in a BYTE variable.

const byte frame1[8] PROGMEM = {B01000010,
                                B01000010,
                                B01000010,
                                B00000000,
                                B00000000,
                                B10000001,
                                B01000010,
                                B00111100
                               };

const byte frame2[8] PROGMEM = {B01000000,
                                B01000000,
                                B01001110,
                                B00000000,
                                B00000000,
                                B10000001,
                                B01000010,
                                B00111100
                               };
                     // Scroll down to the loop :)

                     static const int DATA_PIN = 20;
static const int CLK_PIN  = 5;
static const int CS_PIN   = 21;

LedControl lc = LedControl(DATA_PIN, CLK_PIN, CS_PIN, 1);

void setup() {

  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 15);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  // Now here we are going to display each frame.
  // first input: frame, second input: delay.
  render(frame1, fdelay);
  render(frame2, fdelay);
}


// Why writing your own code when a open source solution has already been written?
// Thanks IJHack! :)


int render(const byte* frame, long delaytime) {
  for (int r = 0; r < 8; r++) {
    lc.setColumn(0, 7 - r, pgm_read_byte(&frame[r]));
  }
  delay(delaytime);
}

