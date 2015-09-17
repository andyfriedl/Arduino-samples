#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i = 1, u = 1;
int rndX = 0, rndY = 0;
int setX = 15, setY = 15;


void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
  TV.shift(19,1);
  
  
    TV.select_font(font8x8);

  //TV.select_font(font4x6);
  TV.println(25,0,"U.niversal");
  TV.println(25,8,"S.hopping");
  TV.println(25,16,"C.art\n");
  TV.select_font(font6x8);
  TV.print(0,35,"Ebates BUY NOW app ");
  //TV.select_font(font6x8);

  TV.print(0,49,"Request Processing: ");
  
  
}


void loop() {

  TV.select_font(font8x8);

  /* TV.select_font(font6x8);
   TV.select_font(font8x8);
   TV.select_font(font4x6);
   
   TV.println(1,22,"Status: LVL 9");
   
   int delayTime = 100;
   
   TV.select_font(font6x8);
   TV.println(1,2,"Alert!");
   TV.delay(delayTime); 
   TV.draw_rect(0,0,50,10,0,0);
   //TV.clear_screen();
   TV.delay(delayTime); */
/*
  
// top down bars
   for(int i = 0; i < 120; i += 3){
   //TV.draw_rect(0,0,random(80),i,1,1);
   //TV.draw_rect(0,0,10,80,1,1);
   int num = i;
   //TV.println(22,22,i);
   TV.draw_rect(i,0,1,20,0,0);
   TV.draw_rect(i,0,1,random(20),1,1);
   //TV.delay(44);
   
   
   } 
*/
  // bottom bars
  
  for(int i = 0; i < 128; i += 2){
      
      rndX = random(2);

  // cols
  rndY = random(2);
  if (rndY == 1) {
    setY++;
    if (setY >= 21) {
      setY--;
    }
  } 
  else {
    setY--;
    if (setY <= 1) {
      setY++;
    }
  }
      
      
    int num = i;
    //int rnd = random(10, 20);
    int rnd = setY;
    int yNum =  95 - rnd;
    TV.draw_rect(i,75,0,20,0,0);
    TV.draw_rect(i,yNum,0,rnd,1,1);
    TV.delay(111);
  } 
      TV.draw_rect(0,75,128,20,0,0);

  
    //TV.delay(555);

  //TV.clear_screen();
  /*
   TV.select_font(font6x8);
   TV.println("6/8");
   TV.delay(222); 
   TV.select_font(font6x8);
   TV.println("6/8");
   TV.delay(222); 
   
   TV.select_font(font8x8);
   TV.println("8/8");
   TV.delay(2500);
   TV.print(9,44,"Draw Basic Shapes");
   TV.delay(2500);
   
   TV.clear_screen();*/


}



