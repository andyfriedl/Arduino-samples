#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i = 1, u = 1;

void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
for (int i = 1; i < 114; i++) {

    int a = i;
    char b[4];

    String str;

    str = String(a);

    str.toCharArray(b, 4);



    TV.delay(88);
    TV.select_font(font6x8);
    TV.print(10, 10, b);
  }
}

void loop() {

  




  //TV.clear_screen();


}
