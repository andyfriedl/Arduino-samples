#include <TVout.h>
#include <fontALL.h>
// ****************************************************

TVout TV;
int i = 1, u = 1;
int x = 2, srlLen, srtLenNum;
String content = "test";   
char characters; 
long randNumber;


void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
  Serial.begin(9600);  // Initialize serial port
  Serial.flush();
  TV.clear_screen();

  TV.select_font(font8x8);

  //TV.select_font(font4x6);
  TV.println(25,0,"U.niversal");
  TV.println(25,8,"S.hopping");
  TV.println(25,16,"C.art\n");
  TV.select_font(font6x8);

  TV.print(0,35,"BUG COUNT: ");

  for(int i = 0; i < 126; i+= 10) {
    if(i < 101) {
      TV.select_font(font4x6);
      TV.print(i,48,i);
    }

  }

  for(int i = 0; i < 126; i+= 10) {
    TV.draw_line(i,57,i,54,1);
  }
  for(int i = 0; i < 126; i+= 5) {
    TV.draw_line(i,57,i,57,1);
  }
  TV.select_font(font6x8);

}


void loop() {
  /*
   if (Serial.available()) {
   content = ""; // Clear content before using
   while(Serial.available() > 0) {
   //Serial.print(Serial.read());
   characters = Serial.read();
   content.concat(characters);
   //delay (10);
   }
   //content.trim(); // Trim what was sent
   }*/
  randNumber = random(1, 42) * 2;
  TV.print(62,35, randNumber);

  TV.draw_row(60,0,randNumber,2);
  TV.draw_row(61,0,randNumber,2);
  TV.draw_row(62,0,randNumber,2);
  TV.draw_row(63,0,randNumber,2);
  TV.draw_row(64,0,randNumber,2);
  TV.draw_row(65,0,randNumber,2);



  //TV.println(0,0,x);
  /*
  TV.delay(2500);
   TV.select_font(font6x8);
   TV.println("6/8");
   TV.delay(2500);  
   TV.select_font(font8x8);
   TV.println("8/8");
   TV.delay(2500);
   TV.print("Draw Basic Shapes");*/
  TV.delay(5300);
  TV.draw_row(60,0,126,0);
  TV.draw_row(61,0,126,0);
  TV.draw_row(62,0,126,0);
  TV.draw_row(63,0,126,0);
  TV.draw_row(64,0,126,0);
  TV.draw_row(65,0,126,0);
  //TV.delay(200);

  //TV.clear_screen();


}



