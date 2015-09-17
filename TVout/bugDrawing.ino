#include <TVout.h>
#include <fontALL.h>
// ****************************************************

TVout TV;



int setX = 44, setY = 44;
int rndX = 0, rndY = 0;
int count = 1;

void setup() {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));

  TV.clear_screen();

}

void loop() {

  rndX = random(2);

  if (rndX == 1) {
    setX++;
    if (setX >= 123) {
      setX--;
    }
  } 
  else {
    setX--;
    if (setX <= -1) {
      setX++;
    }
  }
  // cols
  rndY = random(2);
  if (rndY == 1) {
    setY++;
    if (setY >= 94) {
      setY--;
    }
  } 
  else {
    setY--;
    if (setY <= -1) {
      setY++;
    }
  }

  TV.set_pixel(setX, setY, 1);
  //TV.delay(2);
  //TV.set_pixel(setX, setY, 2);
  count++;
  if(count == 20000){
    count = 1;
    TV.clear_screen();
  }

}






