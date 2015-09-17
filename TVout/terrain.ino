#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i = 1, u = 1;
int rndX = 0, rndY = 0;
int setX = 15, setY = 15;
int setXX =40, setYY = 40;


void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
  rndY = random(2);
  //cavern();

}

void loop() {
  lightning();

}

void lightning() {
  for(int i = 0; i < 128; i += 1){

    //rndX = random(2);

    // cols
    rndY = random(2);
    if (rndY == 1) {
      setYY++;
      if (setYY >= 90) {
        setYY--;
      }
    } 
    else if (rndY == 0){
      setYY--;
      if (setYY <= 1) {
        setYY++;
      }
    } 
    else  if (rndY >= 2){
      //setYY = setYY;
    }

    TV.set_pixel(i,setYY,2);
    //TV.delay(1);
  } 
  TV.clear_screen();


}

void cavern() {
  for(int i = 0; i < 128; i += 1){

    rndX = random(2);

    // cols
    rndY = random(2);
    if (rndY == 1) {
      setY++;
      if (setY >= 21) {
        setY-=15;
      }
    } 
    else {
      setY--;
      if (setY <= 1) {
        setY+=15;
      }
    }


    int num = i;
    //int rnd = random(10, 20);
    int rnd = setY;
    int yNum =  95 - rnd;
    TV.draw_column(i,75,20,0);
    TV.draw_column(i,yNum,rnd,1);
    TV.delay(1);
  } 


}



