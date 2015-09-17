#include <TVout.h>
#include <fontALL.h>
// ****************************************************

TVout TV;

int leftAndRight = random(1, 100), upAndDown = random(1, 80);
int lnrCount = 1, undCount = 1;

float x = 63;   // x location
float y = 0;     // y location 
float height = 90;

float speed = 0;   // speed 

float gravity = 0.1;  

void setup() {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));

  TV.clear_screen();

}

void loop() {
  //randomDot();
  randomDotStay();
}

void randomDot() {
x = random(1, 126);
y = random(1, 90);

  TV.set_pixel(x, y, 2);
  TV.delay(222);
  TV.set_pixel(x, y, 2);


}

void randomDotStay() {
x = random(1, 126);
y = random(1, 90);

  TV.set_pixel(x, y, 2);
  TV.delay(1);
  


}




