// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// Version 2.0 now using RTClib.h
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1,
    numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void setup () {
  Serial.begin(57600);
  Wire.begin();
  //RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  matrix.setIntensity(0);
  matrix.fillScreen(1);
  matrix.write();
  randomSeed(analogRead(0));
}
int rotater = 0;

int inc = -2,
    setX = 4, setY = 4,
    rndX = 0, rndY = 0,
    setBrightness = 7,
    y, z, x, cx, cy, timer;

String message = ".oOo.";
int spacer = 1,
    width = 5 + spacer; // The font width is 5 pixels
int looper = 1,
    scrollSpeed = 57;

String hours, minutes, seconds;

int hint,
    dst = + 1; // 1 for summer, 0 for winter

void loop () {
  DateTime now = RTC.now();

//    Serial.print(now.year(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.day(), DEC);
//    Serial.print(' ');
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();

  hours = String(now.hour());

  
//  daylight savings
  // if (now.hour() > 12) {
  //   hours = String(now.hour() - 12);
  // } else {
  //   //hours = String(now.hour() - 1);
  //   }
  if (now.hour() > 12) {
    hours = String(now.hour() - 13);
  } else {
     hours = String(now.hour() - 1);
    }

  
  if (now.minute() > -1 && now.minute() < 10) {
    minutes = "0" + String(now.minute());
  } else {
    minutes = String(now.minute());
  }

  message = hours + ":" + minutes + " ";
  //message = String(hour()) + ":" + minutes + " ";
  //delay(11);
  randomDot(66);
  delay(99);
  matrix.setIntensity(5);

  for ( int i = 0 ; i < width * message.length() + matrix.width() - 1 - spacer; i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < message.length() ) {
        matrix.drawChar(x, y, message[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(scrollSpeed);
    hint = 0;
    hours;

  }
  //delay(10);
}

void randomDot(int dots) {
  // ----------------random dot -------------------------------
  matrix.fillScreen(0);
  matrix.write();
  for (int x = 0; x < dots; x++) {
    matrix.fillScreen(0);
    matrix.write();
    //matrix.setIntensity(random(15));
    matrix.setIntensity(2);

    matrix.drawPixel(random(8), random(8), 1);
    matrix.write();  // write the changes we just made to the display
    delay(11);
  }
  matrix.fillScreen(0);
  matrix.write();
}
