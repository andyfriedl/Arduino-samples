#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i = 1, u = 1;

void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));

}

void loop() {
  TV.select_font(font4x6);
  TV.println("4/6");
  TV.delay(2500);
  TV.select_font(font6x8);
  TV.println("6/8");
  TV.delay(2500);  
  TV.select_font(font8x8);
  TV.println("8/8");
  TV.delay(2500);
  TV.print(9,44,"Draw Basic Shapes");
  TV.delay(2500);

  TV.clear_screen();


}
