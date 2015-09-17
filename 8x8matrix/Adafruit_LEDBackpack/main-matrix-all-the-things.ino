/*************************************************** 
 *
 * This is a library for our I2C LED Backpacks
 * 
 * 
 * Wiring
 *[1][2][3][4]
 * red = 3v = [4]
 * black = gnd = [3]
 * a5 = [1]
 * a4 = [2]
*
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
int y, z, x, cx, cy, timer;
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
int setX = 4, setY = 4;
int rndX = 0, rndY = 0;
int setBrightness = 15;
void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address
}
// -----------------------------------------------

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
run_stand[] =
{ 
  B00000000,
  B00011000,
  B00011000,
  B00111100,
  B00111100,
  B00111100,
  B00011000,
  B00011000
};

static const uint8_t PROGMEM
run_standdA0[] =
{ 
  B00011000,
  B00011000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00011000,
  B00011000
};

static const uint8_t PROGMEM
run_standdA1[] =
{ 
  B00001100,
  B00001100,
  B00011000,
  B00011000,
  B00011100,
  B00011000,
  B00111000,
  B00001000
};

static const uint8_t PROGMEM
run_standdA2[] =
{ 
  B00001100,
  B00001100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00010000
};

static const uint8_t PROGMEM
run_standdA3[] =
{ 
  B00001100,
  B00001100,
  B00011000,
  B00111000,
  B00111100,
  B00011100,
  B00100100,
  B00100000
};

static const uint8_t PROGMEM
run_standdA4[] =
{ 
  B00001100,
  B00001100,
  B00111000,
  B01011110,
  B00011000,
  B00100100,
  B01000100,
  B00000100
};


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
  // -------------------====================----------
static const uint8_t PROGMEM
fire1[] =
{ 
  B00010000,
  B01000000,
  B10010100,
  B11011101,
  B11111110,
  B01101110,
  B11111111,
  B11111111 };
  static const uint8_t PROGMEM
fire2[] =
{ 
  B00000000,
  B10110100,
  B11111001,
  B01011110,
  B11101110,
  B11111111,
  B11111111,
  B01111111 };
    static const uint8_t PROGMEM
fire3[] =
{ 
  B10010100,
  B10011001,
  B00110010,
  B00111111,
  B11101111,
  B11111111,
  B01111110,
  B01111110 };
      static const uint8_t PROGMEM
fire4[] =
{ 
  B10011001,
  B00010010,
  B00111001,
  B00100011,
  B11101110,
  B11111110,
  B01111110,
  B01111111 };
        static const uint8_t PROGMEM
fire5[] =
{ 
  B00010010,
  B00011101,
  B01100010,
  B01100110,
  B11110110,
  B01111110,
  B01111111,
  B11111111 };
          static const uint8_t PROGMEM
fire6[] =
{ 
  B00010101,
  B10000000,
  B11100000,
  B01110010,
  B01101110,
  B01111111,
  B11111111,
  B11111111 };
            static const uint8_t PROGMEM
fire7[] =
{ 
  B10000000,
  B10110000,
  B01000010,
  B00100111,
  B11110111,
  B11111110,
  B11111111,
  B01111111 };
  
void loop() {
  matrix.setRotation(1);
  matrix.setBrightness(setBrightness);

  randomDot();
  //randomDots();
  //bug();
  //randomLine();
  //orbitSpiralizer();
  //orbit();
  //radar();
  //crosshatch();
  //strobe();
  //runner();
  //run_standy();
  //fire();

}
void fire() {
  //---------------- runner 1----------------------
  matrix.setRotation(1);

  for (x=0; x<10; x++) {
   /**/ matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire1, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire2, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire3, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire4, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
        matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire5, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
        matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire6, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
      /*  matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, fire7, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(199);*/

  }
}
void run_standy() {
  //---------------- runner 1----------------------
  matrix.setRotation(1);

  for (x=0; x<10; x++) {
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_standdA1, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_standdA2, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_standdA3, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);
    matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_standdA4, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(99);

  }
      matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_standdA0, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(2000);
}

void runner() {
  //---------------- runner 1----------------------
  matrix.setRotation(1);

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
      matrix.clear(); // clear the display
    matrix.drawBitmap(0, 0, run_stand, 8, 8, LED_ON); // setup the image to display
    matrix.writeDisplay(); // display the image
    delay(2000);
}
void randomDot() {
  // ----------------random dot -------------------------------
  matrix.clear();      // clear display

  for (x=0; x<164; x++) {
    matrix.clear();      // clear display
    matrix.setBrightness(random(15));

    matrix.drawPixel(random(8), random(8), LED_ON);  
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(22);
  }
}

void randomDots() {
  // ----------------random dots-------------------------------
  matrix.clear();      // clear display

  for (x=0; x<164; x++) {
    matrix.drawPixel(random(8), random(8), LED_ON);  
    matrix.drawPixel(random(8), random(8), LED_OFF);  
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(random(33)+22);
  }
}
void bug(){
  // ---------------- bug -------------------------------
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
}

void randomLine() {
  // --------------LINE----------------------------
  matrix.clear();      // clear display

  for (x=0; x<10; x++) {
    matrix.clear();
    matrix.drawLine(random(8),0, random(8),7, LED_ON);
    matrix.drawLine(0,random(8), 7,random(8), LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(222);
  }
}

void orbitSpiralizer() {
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
    // rotate view
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
    // rotate view
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
    // rotate view
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
    // rotate view
    if (y > 3) {
      y = 0;
    }


  }
}

void orbit() {
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
    // rotate view
    if (y > 3) {
      y = 0;
    }
  }

}

void radar() {

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

    // rotate dispaly
    if (y > 3) {
      y = 0;
    }
  }
}
/*
void crosshatch() {
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
  }
}
*/
void strobe() {
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
  }
}



