//We always have to include the library
#include "LedControl.h"

// pongBall

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
int lrCount = 1, udCount = 1, col = 3, colNum = 0;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  randomSeed(analogRead(0));

}


void loop() { 
  bounce1();
}


void bounce1 () {
  // need better random start
  // ****************************************************
  if(col == 8) {
    col = -1;

  } 


  if(upAndDown % 2 == 0) {
    lc.setLed(0, 4, col, false);
    col++;
    lc.setLed(0, 4, col, true);

    
  } 


  /*
  if(col == 7) {
   col = 0;
   
   } else {
   col++;
   }
   */
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
  delay(77);
  

  lc.setLed(0, leftAndRight, upAndDown, false);
}




