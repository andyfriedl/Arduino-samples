#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i, u, randNumber, randNumber1, randNumber2, randNumber3,randNumber4,randNumber5;
int rndX = 0, rndY = 0;
int setX = 15, setY = 15;

void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
  //TV.fill(1);
TV.draw_circle(60,40,3, 2, -1);
//TV.draw_circle(60,40,7, 2, -1);
//TV.draw_circle(60,40,20, 2, -1);
//TV.draw_circle(60,40,40, 2, -1);
}

void loop() {
  randNumber = 60;
  randNumber1 = 40;
  

  int space = 2;

  for(int i = 0; i < 128; i += space){
    TV.draw_line(randNumber,randNumber1,i,1,2);
    TV.delay(1);
    TV.draw_line(randNumber,randNumber1,i,1,2);


  }
  for(int i = 0; i < 95; i += space){
    TV.draw_line(randNumber,randNumber1,127,i,2);
    TV.delay(1);
    TV.draw_line(randNumber,randNumber1,127,i,2);



  }

  for(int i = 128; i > 1; i -= space){
    TV.draw_line(randNumber,randNumber1,i,95,2);
    TV.delay(1);
    TV.draw_line(randNumber,randNumber1,i,95,2);


  }
  for(int i = 95; i > 0; i -= space){
    TV.draw_line(randNumber,randNumber1,0,i,2);
    TV.delay(1);
    TV.draw_line(randNumber,randNumber1,0,i,2);


  }
  //TV.clear_screen();

}




