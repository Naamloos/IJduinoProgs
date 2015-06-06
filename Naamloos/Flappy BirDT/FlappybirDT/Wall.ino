// code to be written soonish.
int wallx = 7;
bool first;
bool second;
bool third;
void wall() {
        lc.setLed(0, wallx, 0, LOW);
        lc.setLed(0, wallx, 1, LOW);
        lc.setLed(0, wallx, 6, LOW);
        lc.setLed(0, wallx, 7, LOW);
        if (wallx > 0) {
          wallx = wallx - 1;
        }
        if (wallx <= 0) {
          wallx = 7 ;
        }
        lc.setLed(0, wallx, 0, HIGH);
        lc.setLed(0, wallx, 1, HIGH);
        lc.setLed(0, wallx, 6, HIGH);
        lc.setLed(0, wallx, 7, HIGH);
  
  delay(150);
}

