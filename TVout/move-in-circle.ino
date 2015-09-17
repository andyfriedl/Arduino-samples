#include <TVout.h>
#include <fontALL.h>
#include <math.h>

TVout TV;
//#undef PI

void setup()  {
  TV.begin(NTSC); 
  
  randomSeed(analogRead(0));
}

struct Point {
  Point( double X, double Y ): x(X), y(Y) {};
  double x;
  double y;
};//Simple Point structure

Point Center(70, 50);
double radius = 31;
//const double PI = 3.14159;

void loop() {

  for (double angle = 0; angle <= 2 * PI; angle += 0.160) {//You are using radians so you will have to increase by a very small amount

    TV.draw_circle( Center.x + radius * cos( angle ), Center.y + radius * sin( angle ),9, 1 ,1);
    TV.delay(33);
    TV.draw_circle( Center.x + radius * cos( angle ), Center.y + radius * sin( angle ), 9, 0 ,0);

    //TV.set_pixel( Center.x + radius * cos( angle ), Center.y + radius * sin( angle ), 1 );
    //TV.delay(33);
    //TV.set_pixel( Center.x + radius * cos( angle ), Center.y + radius * sin( angle ), 0 );
    
  }
}