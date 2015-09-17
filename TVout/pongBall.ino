#include <TVout.h>
#include <fontALL.h>
#include <math.h>
// ****************************************************

TVout TV;

//int leftAndRight = random(1, 126), upAndDown = random(1, 90);
int leftAndRight = 3, upAndDown = 1;
int lrCount = 1, udCount = 1;


#define BALLS    10 // Number of balls to bounce.
#define BALLSIZE 20  // Size of balls.



void setup()  {
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
  TV.clear_screen();
  TV.select_font(font8x8);

  //TV.println(25,0,"USC pong");
}

void loop() {
 /* uint8_t  x[BALLS], y[BALLS];    // X and Y position of ball
  int8_t   xm[BALLS], ym[BALLS];  // X and Y movement of ball
  uint8_t  i;       // counter

  // Initialize balls.
  for (i=0; i<BALLS; i++)
  {
    // Random position
    x[i] = random(BALLSIZE, TV.hres()-BALLSIZE-1);
    y[i] = random(BALLSIZE, TV.vres()-BALLSIZE-1);

    // Start moving to the right, and down.

    // Random direction
    xm[i] = random(2)*2 - 1;
    ym[i] = random(2)*2 - 1;
  }

  // We will do our own control loop here.
  while(1)
  {
    // Wait for end of screen to be drawn.
    TV.delay_frame(1);

    for (i=0; i<BALLS; i++)
    {
      // Erase balls.
      TV.draw_circle(x[i], y[i], BALLSIZE, BLACK);

      x[i] = x[i] + xm[i];
      if (x[i]<=BALLSIZE || x[i]>TV.hres()-BALLSIZE-2) xm[i] = -xm[i];

      y[i] = y[i] + ym[i];
      if (y[i]<=BALLSIZE || y[i]>=TV.vres()-BALLSIZE-2) ym[i] = -ym[i];

      TV.draw_circle(x[i], y[i], BALLSIZE, WHITE);
    }
  }*/
  bounce1();
}


void circle() {


  uint8_t  x, y;    // X and Y position of ball
  int8_t   xm, ym;  // X and Y movement of ball

  // Center of screen
  x = TV.hres()/2;
  y = TV.vres()/2;

  // Start moving to the right, and down.
  xm = 1;
  ym = 1;

  // We will do our own control loop here.
  while(1)
  {
    // Wait for end of screen to be drawn.
    TV.delay_frame(1);

    // Erase circle
    TV.draw_circle(x, y, 2, 0);

    x = x + xm;
    if (x<4 || x>=TV.hres()-4) xm = -xm;
    y = y + ym;
    if (y<4 || y>=TV.vres()-4) ym = -ym;

    TV.draw_circle(x, y, 2, 1);
  }
}


void bounce1 () {
  // ****************************************************

  if (leftAndRight == 125 || leftAndRight == 0) {
    lrCount = lrCount * -1;
  } 

  if(lrCount == 1) {
    leftAndRight++;
  }
  if(lrCount == -1) {
    leftAndRight--;
  }
  // ****************************************************

  if (upAndDown == 88 || upAndDown == 0) {
    udCount = udCount * -1;
  }

  if(udCount == 1) {
    upAndDown++;
  }
  if(udCount == -1) {
    upAndDown--;
  }

  // ****************************************************


  TV.set_pixel(leftAndRight, upAndDown, 2);
  TV.delay(1);
  //TV.set_pixel(leftAndRight, upAndDown, 2);
}


