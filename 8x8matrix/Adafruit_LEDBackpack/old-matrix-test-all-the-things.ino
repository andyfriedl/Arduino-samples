/*************************************************** 
 *
 * This is a library for our I2C LED Backpacks
 *
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
int y, z, x, cx, cy, timer;
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
int setX = 4, setY = 4;
int rndX = 0, rndY = 0;
int setBrightness = 7;
void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address
}
/*
static const uint8_t PROGMEM
 smile_bmp[] =
 { B00111100,
 B01000010,
 B10100101,
 B10000001,
 B10100101,
 B10011001,
 B01000010,
 B00111100 },
 neutral_bmp[] =
 { B00111100,
 B01000010,
 B10100101,
 B10000001,
 B10111101,
 B10000001,
 B01000010,
 B00111100 },
 frown_bmp[] =
 { B00111100,
 B01000010,
 B10100101,
 B10000001,
 B10011001,
 B10100101,
 B01000010,
 B00111100 };
 */
 static const uint8_t PROGMEM
 run_right1[] =
 { 
    B00000000,
    B00001100,
    B00011000,
    B00011100,
    B00111100,
    B00011100,
    B01100100,
    B01000011
 };
  static const uint8_t PROGMEM
  run_right2[] =
 { 
    B00000000,
    B00001100,
    B0001000,
    B00111100,
    B01011010,
    B00011100,
    B01100100,
    B00000110
 };
  static const uint8_t PROGMEM
  run_right3[] =
 { 
    B00000000,
    B00001100,
    B0011000,
    B0011000,
    B0011000,
    B0011000,
    B0111000,
    B0011000
 };
   static const uint8_t PROGMEM
  run_right4[] =
 { 
    B00001100,
    B00011000,
    B00011100,
    B00111100,
    B00011100,
    B00100100,
    B00101000,
    B00100000
 };
 
static const uint8_t PROGMEM
crosshatch[] =
{ 
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101 };
static const uint8_t PROGMEM
crosshatchx[] =
{ 
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010 };
//-------------------------------------------------
static const uint8_t PROGMEM
alien1a[] = 
{
  B00011000, // This is the first frame for alien #1
  B00111100, // If you squint you can kind of see the
  B01111110, // image in the 0's and 1's.
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101,
};
static const uint8_t PROGMEM
alien1b[] = 
{
  B00011000, // This is the second frame for alien #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};
//-----------------------------------------
static const uint8_t PROGMEM
alien2a[] = 
{
  B00000000, // First frame for alien #2
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B11000011
};
static const uint8_t PROGMEM
alien2b[] = 
{
  B00111100, // Second frame for alien #2
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B00100100,
  B00100100
};
//-----------------------------------
static const uint8_t PROGMEM
alien3a[] = 
{
  B00100100, // First frame for alien #3
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

static const uint8_t PROGMEM
alien3b[] = 
{
  B00100100, // Second frame for alien #3
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};
//-------------------------------
static const uint8_t PROGMEM
alien4a[] = 
{
  B00111100, // First frame for alien #4
  B01111110,
  B00110011,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00000000
};

static const uint8_t PROGMEM
alien4b[] = 
{
  B00111100, // Second frame for alien #4
  B01111110,
  B10011001,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00001000
};
static const uint8_t PROGMEM
alien4c[] = 
{
  B00111100, // Third frame for alien #4 (NOT a repeat of frame 1)
  B01111110,
  B11001100,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00001000
};
static const uint8_t PROGMEM
alien4d[] = 
{
  B00111100, // Fourth frame for alien #4 (NOT a repeat of frame 2)
  B01111110,
  B01100110,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00000000
};
//-------------------------------------
static const uint8_t PROGMEM
sevena[] = 
{
  B00000000, // Second frame for alien #2
  B11100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00000000,
  B00000000
};
static const uint8_t PROGMEM
nineb[] = 
{
  B00000000, // Second frame for alien #2
  B00001110,
  B00001010,
  B00001110,
  B00000010,
  B00001110,
  B00000000,
  B00000000
};
// -----------------------------------------------

static const uint8_t PROGMEM
strobeOn[] = 
{
  B11111111, // 1 frame on
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};


static const uint8_t PROGMEM
strobeOff[] = 
{
  B00000000, // 1 frame off
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

void loop() {
  matrix.setRotation(1);
  matrix.setBrightness(setBrightness);

  /* matrix.clear();
   matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
   matrix.writeDisplay();
   delay(500);
   
   matrix.clear();
   matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
   matrix.writeDisplay();
   delay(500);
   
   matrix.clear();
   matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
   matrix.writeDisplay();
   delay(500);
   */  
  // ----------------random dots-------------------------------
   matrix.clear();      // clear display
   
   for (x=0; x<164; x++) {
   matrix.drawPixel(random(8), random(8), LED_ON);  
   matrix.drawPixel(random(8), random(8), LED_OFF);  
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(random(33)+22);
   }
   
   // ----------------random dot -------------------------------
   matrix.clear();      // clear display
   
   for (x=0; x<164; x++) {
   matrix.clear();      // clear display
   matrix.setBrightness(random(15));
   
   matrix.drawPixel(random(8), random(8), LED_ON);  
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(22);
   }
   matrix.setBrightness(setBrightness);
   
  
  // ---------------- bug -------------------------------
   //matrix.clear();      // clear display
   
   
   for (x=0; x<364; x++) {
   matrix.clear();      // clear display
   //matrix.setBrightness(random(15));
   // rows
   rndX = random(2);
   
   if (rndX == 1) {
   setX++;
   if (setX >= 8) {
   setX--;
   }
   } 
   else {
   setX--;
   if (setX <= -1) {
   setX++;
   }
   }
   // cols
   rndY = random(2);
   if (rndY == 1) {
   setY++;
   if (setY >= 8) {
   setY--;
   }
   } 
   else {
   setY--;
   if (setY <= -1) {
   setY++;
   }
   }
   matrix.drawPixel(setX, setY, LED_ON);  
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(11);
   }
   matrix.setBrightness(setBrightness);
   
  // --------------LINE----------------------------

  /*
  for (x=0; x<10; x++) {
   matrix.clear();
   matrix.drawLine(random(8),0, random(8),7, LED_ON);
   matrix.drawLine(0,random(8), 7,random(8), LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(222);
   }
   */
   
  // ---------------circle SWEEP 8---------------------
  timer = 33;//random(22)+33;
  for (x=0; x<27; x++) {
    matrix.setRotation(y);
    y++;

    matrix.drawPixel(7,3, LED_ON);
    matrix.writeDisplay();
    delay(timer);
    matrix.clear();

    matrix.drawPixel(7,4, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(7,5, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(6,6, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(5,7, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    if (y > 3) {
      y = 0;
    }


  }
  // ---------------circle SWEEP 6---------------------
  timer = 33;//random(22)+33;
  for (x=0; x<2; x++) {
    matrix.setRotation(y);
    y++;

    matrix.drawPixel(6,4, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(5,5, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(4,6, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    if (y > 3) {
      y = 0;
    }


  }

  // ---------------circle SWEEP 4---------------------
  timer = 33;//random(22)+33;
  for (x=0; x<2; x++) {
    matrix.setRotation(y);
    y++;

    matrix.drawPixel(5,4, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();

    matrix.drawPixel(4,5, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();


    if (y > 3) {
      y = 0;
    }


  }
   // ---------------circle SWEEP 2---------------------
  timer = 33;//random(22)+33;
  for (x=0; x<4; x++) {
    matrix.setRotation(y);
    y++;

    matrix.drawPixel(4,4, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(timer);
    matrix.clear();



    if (y > 3) {
      y = 0;
    }


  }


  
  // ---------------RADAR SWEEP---------------------
   timer = random(22)+33;
   for (x=0; x<17; x++) {
       matrix.setRotation(y);
       y++;
       
       
       matrix.drawLine(4,3, 7,3, LED_ON);
       matrix.writeDisplay();
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,3, 7,4, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 7,5, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 7,6, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 7,7, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 6,7, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 5,7, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 5,7, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       matrix.drawLine(4,4, 4,7, LED_ON);
       matrix.writeDisplay();  // write the changes we just made to the display
       delay(timer);
       matrix.clear();
       
       
       if (y > 3) {
       y = 0;
       }
   
   }
   
   
   
  //---------------------------------
  //---------------- runner 1----------------------
    matrix.setRotation(2);

   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, run_right1, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
     matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, run_right2, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
     matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, run_right3, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
     matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, run_right4, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }
   
  // --------------Rect----------------------------
  /*
  matrix.clear();
   matrix.drawRect(0,0, 8,8, LED_ON);
   matrix.fillRect(2,2, 4,4, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);
   // --------------circle----------------------------
   
   matrix.clear();
   matrix.drawCircle(3,3, 3, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(500);
   
   //matrix.blinkRate(1); //-----------------------------------------
   */  /*
  // -------------crosshatch-------------------------------------
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, crosshatch, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, crosshatchx, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }*/
  /*
  // --------------strobe-----------------
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(1);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(7);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(11);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(15);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(11);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(7);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOn, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(33);
   matrix.setBrightness(1);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, strobeOff, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   } */
  matrix.setRotation(1);
  matrix.setBrightness(setBrightness);

  /*
  for (y=0; y<=5; y++)
   {
   // ---------------- rectangles --------------------------
   matrix.clear();
   
   matrix.drawRect(0, 0, 4, 4, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(99);
   matrix.clear();
   
   matrix.drawRect(4, 0, 4, 4, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(99);
   matrix.clear();
  
   
   matrix.fillRect(4, 4, 7, 7, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(99);
   matrix.clear();
   
   matrix.fillRect(0, 4, 4, 7, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(99);
   }
   */
  /*
  
  //---------------------------------
  //----------------alien 1----------------------
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien1a, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien1b, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }
   //----------------alien 2----------------------
   
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien2a, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien2b, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }
   //----------------alien 3----------------------
   
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien3a, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien3b, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }
   //----------------alien 4----------------------
   
   for (x=0; x<10; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien4a, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien4b, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien4c, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, alien4d, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(99);
   }
   */  /*
  // ---------------------circles------------------
   for (y=0; y<15; y++)
   {
   cx = random(7);
   cy = random(7);
   for (z=0; z<8; z++)
   {
   matrix.clear();
   matrix.drawCircle(cx,cy, z, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(44);
   }
   }*/
  /*
    // ---------------------rect fill------------------
   for (y=0; y<6; y++)
   {
   cx = random(7);
   cy = random(7);
   for (z=0; z<8; z++)
   {
   matrix.clear();
   matrix.(cx,cy, z, LED_ON);
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(44);
   }
   }
   */
  //----------------2 digit number flash---------------------

  /*
for (x=0; x<160; x++) {
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, sevena, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(11);
   matrix.clear(); // clear the display
   matrix.drawBitmap(0, 0, nineb, 8, 8, LED_ON); // setup the image to display
   matrix.writeDisplay(); // display the image
   delay(11);
   }
   */
  //---------------- text ----------------------
  /*
  matrix.setTextSize(1);
   matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
   matrix.setTextColor(LED_ON);
   for (int8_t x=0; x>=-125; x--) {
   matrix.clear();
   matrix.setCursor(x,0);
   matrix.print(" USC - parsing team");
   matrix.writeDisplay();
   delay(66);
   }
   */
  /*
  matrix.setRotation(3);
   for (int8_t x=7; x>=-36; x--) {
   matrix.clear();
   matrix.setCursor(x,0);
   matrix.print("World");
   matrix.writeDisplay();
   delay(100);
   }*/
  //matrix.setRotation(0);

  matrix.setBrightness(setBrightness);

}

