#include <TVout.h>
#include <fontALL.h>
// ****************************************************

TVout TV;

int leftAndRight = random(1, 100), upAndDown = random(1, 80);
int lnrCount = 1, undCount = 1;

float x = random(126);   // x location
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
  bounce();

}
void bounce() {
  TV.set_pixel(x, y, 2);
  TV.delay(1);
  TV.set_pixel(x, y, 2);



  // Add speed to location.
  y = y + speed;
  // Add gravity to speed.
  speed = speed + gravity;

  // Reverse speed
  if (y > height) {
    y = height;
    if ( speed < 1 ) {
      speed = 6;
 
    } 
    else {
      // Multiplying by -0.95 instead of -1 slows the square down each time it bounces (by decreasing speed).  
      // This is known as a "dampening" effect and is a more realistic simulation of the real world (without it, a ball would bounce forever).
      speed = speed * -0.80;  
    }
  }
}



