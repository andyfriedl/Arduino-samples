/*
 * SplitSplit sketch
 * split a comma-separated string NO SCROLL
 */
#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

int y, z, x, cx, cy;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
byte incomingByte;

//String  text = "xxx,78F,Partly Cloudy,Peter,Paul,Mary";  // an example string
String  text = ":::::";  // an example string
String  message = text; // holds text not yet split
int     commaPosition;  // the position of the next comma in the string


void setup()
{
  Serial.println("split Test");

  //matrix.setBrightness(1);
  matrix.setRotation(1);
  matrix.begin(0x70);  // pass in the address
  Serial.begin(9600);

}

void loop(){
  matrix.clear();
  matrix.setBrightness(1);

  Serial.println(message);          // show the source string

  matrix.clear();
  matrix.setBrightness(1);
  matrix.setCursor(x,0);
  Serial.println(message);
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);


  matrix.setCursor(x,0);

  matrix.print(message);
  matrix.writeDisplay();
  delay(66);



  //matrix.clear();



}

