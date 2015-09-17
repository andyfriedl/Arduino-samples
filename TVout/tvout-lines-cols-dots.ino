#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i, u, randNumber, randNumber1, randNumber2, randNumber3,randNumber4,randNumber5;

void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));

}

void loop() {
  randNumber = random(88);
  randNumber1 = random(88);
    randNumber2 = random(88);
  randNumber3 = random(88);

  randNumber4 = random(88);

  randNumber5 = random(88);
  //TV.draw_line(0,0,11,11,1);

  /*
for (i=0; i < randNumber; i++) {
   //TV.draw_line(0,i,0,88,1);
   TV.draw_line(0,i,0,88,1);
   TV.delay(1);
   
   TV.draw_line(0,i,0,88,0);
   }
   for (i=randNumber; i > 0; i--) {
   //TV.draw_line(0,i,0,88,1);
   TV.draw_line(0,i,0,88,1);
   TV.delay(1);
   
   TV.draw_line(0,i,0,88,0);
   
   }*/
   
   /*
  for (i=0; i < randNumber; i++) {
    //TV.draw_line(0,i,0,88,1);
    TV.draw_rect(0,0,11,i,1,1);
    TV.delay(1);

    TV.draw_rect(0,0,11,i,0,0);
  }

  for (i=randNumber; i > 0; i--) {
    //TV.draw_line(0,i,0,88,1);
    TV.draw_rect(0,0,11,i,1,1);
    TV.delay(1);

    TV.draw_rect(0,0,11,i,0,0);
  }
 for (i=0; i < randNumber1; i++) {
    //TV.draw_line(0,i,0,88,1);
    TV.draw_rect(12,0,11,i,1,1);
    TV.delay(1);

    TV.draw_rect(12,0,11,i,0,0);
  }

  for (i=randNumber1; i > 0; i--) {
    //TV.draw_line(0,i,0,88,1);
    TV.draw_rect(12,0,11,i,1,1);
    TV.delay(1);

    TV.draw_rect(12,0,11,i,0,0);
  }
*/

     TV.draw_line(randNumber1,randNumber,randNumber2,randNumber3,2);
     TV.draw_line(randNumber,randNumber2,randNumber3,randNumber1,2);
     TV.draw_line(randNumber3,randNumber3,randNumber,randNumber2,2);
     TV.draw_line(randNumber2,randNumber1,randNumber1,randNumber,2);
     TV.set_pixel(randNumber4,randNumber5,2);
     TV.set_pixel(randNumber5,randNumber4,2);

     TV.set_pixel(randNumber+4,randNumber2,2);


        TV.delay(0);

  //TV.clear_screen();
/*
for (i=0; i < 88; i++) {
   //TV.draw_line(0,i,0,88,1);
   TV.draw_line(randNumber1,randNumber,randNumber2,randNumber3,1);
   //TV.draw_line(randNumber1,randNumber,44,44,0);
   TV.delay(666);
   
   //TV.draw_line(i,i,,88,0);
   }*/

}
