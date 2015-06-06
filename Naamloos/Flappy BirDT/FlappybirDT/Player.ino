int startx = 1;
int starty = 0;
int curx ;
int cury ;

bool jump() {
  if (cury < 7) {
    lc.setLed(0, curx, cury, LOW);
    cury = cury + 1;
    lc.setLed(0, curx, cury, HIGH);
    delay(60);
  }
  return true;
}

void fall(){
    if (cury > 0 ) {
      lc.setLed(0, curx, cury, LOW);
      cury = cury - 1;
      lc.setLed(0, curx, cury, HIGH);
      delay(80); 
    }
}

void spawn(){
  lc.setLed(0, startx, starty, HIGH);
  cury = starty;
  curx = startx;
}
