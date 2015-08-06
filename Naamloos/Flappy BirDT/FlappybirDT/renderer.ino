/*
  I know IJhack has already made a render code, but its
  always nice to make your own.
  its easier to understand for new programmers

  Pros: Easier to understand, you can use normal byte instead of const byte and PROGMEM
  cons: More code, uses more space.
*/

void render(byte* frame){
  lc.setColumn(0,7,frame[0]);
  lc.setColumn(0,6,frame[1]);
  lc.setColumn(0,5,frame[2]);
  lc.setColumn(0,4,frame[3]);
  lc.setColumn(0,3,frame[4]);
  lc.setColumn(0,2,frame[5]);
  lc.setColumn(0,1,frame[6]);
  lc.setColumn(0,0,frame[7]);
}
