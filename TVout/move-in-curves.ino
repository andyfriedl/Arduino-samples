#include <TVout.h>
#include <fontALL.h>
#include <math.h>

TVout TV;
//#undef PI

void setup()  {
  TV.begin(NTSC);
  Serial.begin(9600);

  randomSeed(analogRead(0));
}

struct Point {
  Point( double X, double Y ): x(X), y(Y) {};
  double x;
  double y;
};//Simple Point structure

Point Center(70, 50);
double radius = 41;
//const double PI = 3.14159;
double i = 0;
double j = 0;
float randNumber;


void loop() {


  randNumber = random(1, 100) * .1 * .10;
  Serial.println(randNumber);


  for (double angle = 0; angle <= 2 * PI; angle += 0.090) {//You are using radians so you will have to increase by a very small amount
    i += .0232432;
    j -= .03;



//    TV.draw_circle( Center.x + radius * cos( angle ), Center.y + radius * sin( angle  + randNumber), 1, 1 , 1);
//    TV.delay(33);
//    TV.draw_circle( Center.x + radius * cos( angle), Center.y + radius * sin( angle + randNumber), 1, 0 , 0);

    TV.draw_circle( Center.x + radius * cos( angle ), Center.y + radius * sin( angle  + i), 1, 1 , 1);
    TV.delay(11);
    TV.draw_circle( Center.x + radius * cos( angle ), Center.y + radius * sin( angle + i), 1, 0 , 0);

    //    TV.set_pixel( Center.x + radius * cos( angle ), Center.y + radius * sin( angle +i), 1 );
    //    TV.delay(11);
    //    TV.set_pixel( Center.x + radius * cos( angle ), Center.y + radius * sin( angle +i ), 0 );

  }
}
