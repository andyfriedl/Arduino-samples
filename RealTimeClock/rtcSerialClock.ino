#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <DS3232RTC.h>    //http://github.com/JChristensen/DS3232RTC
#include <Time.h>
#include <Wire.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void setup() {
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet)
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");


  Serial.begin(57600);

  matrix.setIntensity(0);
  matrix.fillScreen(1);
  matrix.write();
  randomSeed(analogRead(0));

}
int rotater = 0;
int wait = 50;
int inc = -2;

int setX = 4, setY = 4;
int rndX = 0, rndY = 0;
int setBrightness = 7;
int y, z, x, cx, cy, timer;

String message = ".oOo.";
int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels
int looper = 1;
int scrollSpeed = 57;
int secondy;
String hours, minutes, seconds;
int hint;
int dst = + 1; // 1 for summer, 0 for winter



void loop() {
  //DateTime now = rtc.now();
  // hour ----------------------------------
  hint = 0;
  hint = (int) hour();
  hint += 6;

  if (hint > 12) {
    hint = hint - 12;
    if (hint > 12) {
      hint = hint - 12;
    }
    if (hint > 12) {
      hint = hint - 12;
    }

    //hint = hint - 12 ;
    hours = String(hint + dst);

  }
  else {
    hours = String(hint + dst);
  }

  // minute ----------------------------------
  if (minute() > -1 && minute() < 10) {
    minutes = "0" + String(minute());
  }
  else {
    minutes = String(minute());
  }

  // second ----------------------------------
  if (second() > -1 && second() < 10) {
    seconds = "0" + String(second());
  }
  else {
    seconds = String(second());
  }
  //message = second();
  message = hours + ":" + minutes + " ";
  //message = String(hour()) + ":" + minutes + " ";
  delay(99);
  randomDot();
  //radar(1, 0, 22); //------ sweeps, brightness 0 - 15, timer = (speed avarage=44)
  delay(222);
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
  delay(10);
}


void radar(int sweeps, int strobeBrightness, int timer) {
  matrix.setIntensity(strobeBrightness);
  // ---------------RADAR SWEEP---------------------
  //int timer = random(22)+33;
  matrix.setRotation(0, 0);

  int radarRotate = 3;
  sweeps = sweeps * 4;
  for (int x = 0; x < sweeps; x++) {
    matrix.setRotation(radarRotate);
    radarRotate++;


    matrix.drawLine(4, 3, 7, 3, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    matrix.drawLine(4, 3, 7, 4, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    matrix.drawLine(4, 4, 7, 5, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 7, 6, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 7, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 6, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 5, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 5, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 4, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    // rotate dispaly
    if (radarRotate > 3) {
      radarRotate = 0;
    }
  }
  matrix.setRotation(0, 2);
}


void randomDot() {
  // ----------------random dot -------------------------------
  matrix.fillScreen(0);
  matrix.write();
  for (int x = 0; x < 55; x++) {
    matrix.fillScreen(0);
    matrix.write();
    //matrix.setIntensity(random(15));
    matrix.setIntensity(random(15));

    matrix.drawPixel(random(8), random(8), 1);
    matrix.write();  // write the changes we just made to the display
    delay(22);
  }
  matrix.fillScreen(0);
  matrix.write();
}
