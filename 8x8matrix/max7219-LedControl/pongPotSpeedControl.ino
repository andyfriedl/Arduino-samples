//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(11,13,10,1);
/* we always wait a bit between updates of the display */

unsigned long delaytime=3;
//int leftAndRight = random(5), upAndDown = random(5);
int leftAndRight = 7, upAndDown = 3;
int lrCount = 1, udCount = 1;

int potPin = 2;    // select the input pin for the potentiometer
int val = 0, vals;       // variable to store the value coming from the sensor
int range, time;



void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.begin(9600);
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
  Serial.println("Pong");

}


void loop() { 
  val = analogRead(potPin);    // read the value from the sensor

  bounce1();
}



void bounce1() {

  // val = val / 10;

  if (val >= 0 && val <=850) {
    range = 10;
  } 
  else if (val >= 851 && val <=900) {
    range = 20;
  } 
  else if ( val >= 901 && val <=920) {
    range = 40;
  }
  else if (val >= 921 && val <=940) {
    range = 80;
  }
  else if (val >= 941 && val <=950){
    range = 110;
  }
  else if (val >= 951 && val <=960) {
    range = 150;
  }
  else if ( val >= 961 && val <=970){
    range = 180;
  }
  else if (val >= 971 && val <=980) {
    range = 210;
  } 
  else if (val >= 981 && val <=990) {
    range = 240;
  }
  else if (val >= 991 && val <=1023) {
    range = 270;
  }
  // need better random start
  // ****************************************************

  if (leftAndRight == 7 || leftAndRight == 0) {
    lrCount = lrCount * -1;
  } 

  if(lrCount == 1) {
    leftAndRight++;
  }
  if(lrCount == -1) {
    leftAndRight--;
  }
  // ****************************************************

  if (upAndDown == 7 || upAndDown == 0) {
    udCount = udCount * -1;
  }

  if(udCount == 1) {
    upAndDown++;
  }
  if(udCount == -1) {
    upAndDown--;
  }

  lc.setLed(0, leftAndRight, upAndDown, true);
  Serial.println(range);
  Serial.println(val);

  delay(range);
  lc.setLed(0, leftAndRight, upAndDown, false);
}