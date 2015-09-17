/*

 takes what is in the var text and scrolls it. 76F
 * SplitSplit sketch
 * split a comma-separated string  
 SCROLL <-------------------------
 SCROLL <-------------------------
 SCROLL <-------------------------
 SCROLL <-------------------------
 */
#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

int y, z, x, cx, cy;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

String  text = "76F";  // an example string
String  message = text; // holds text not yet split
int     commaPosition;  // the position of the next comma in the string

void setup()
{
  Serial.println("split Test");
  matrix.setRotation(1);
  matrix.begin(0x70);  // pass in the address
  Serial.begin(9600);
}

void loop(){

  Serial.println(message);          // print the message string to serial

  matrix.clear();
  matrix.setBrightness(1);  // 1 = dimmest, 15 = brightest
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);

  for (int8_t x=10; x>=-20; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(message);
    matrix.writeDisplay();
    delay(77);
  }

}

/*

 takes what is in the var text and scrolls it. 76F
 * SplitSplit sketch
 * split a comma-separated string  
 SCROLL <-------------------------
 SCROLL <-------------------------
 SCROLL <-------------------------
 SCROLL <-------------------------
 */
/*
#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

int y, z, x, cx, cy;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

String  text = "76F";  // an example string
String  message = text; // holds text not yet split
int     commaPosition;  // the position of the next comma in the string

void setup()
{
  Serial.println("split Test");
  matrix.setRotation(1);
  matrix.begin(0x70);  // pass in the address
  Serial.begin(9600);
}

void loop(){

  Serial.println(message);          // print the message string to serial

  matrix.clear();
  matrix.setBrightness(1);  // 1 = dimmest, 15 = brightest
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);

  for (int8_t x=10; x>=-20; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(message);
    matrix.writeDisplay();
    delay(77);
  }

}
 
 
 */
