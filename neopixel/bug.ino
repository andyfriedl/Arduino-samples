/*Random blinky NeoPixel Ring
Red and Green with a sparkle for Christmas
By fid */

#include <Adafruit_NeoPixel.h>

#define N_PIXELS 12
#define LED_PIN 6  //You might have to change this if you didn't use
// pin 0 on the Gemma.

int RandomBlinky = 0;
int red = 0;
int green = 0;
int blue = 0;
int redOff = 0;
int greenOff = 0;
int blueOff = 0;
int Brightness = 66;  // Brightness of the pixels is about 60%
// I ended up not using the Brightness variable.
int BlinkDelay = 222;
int i = 0;

int mover = 1;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  //strip.setBrightness(Brightness);  // I ended up not using this.
  RandomBlinky = random(12);  // Choose a random NeoPixel.
    randomSeed(analogRead(0));

}  // end of setup()

void loop()
{
  //RandomBlinky = random(12);  // Choose a random NeoPixel.
  red = random(35);  // Choose a random NeoPixel.
  green = random(35);  // Choose a random NeoPixel.
  blue = random(35);  // Choose a random NeoPixel.
  redOff = random(22);  // Choose a random NeoPixel.
  greenOff = random(22);  // Choose a random NeoPixel.
  blueOff = random(22);  // Choose a random NeoPixel.
  // set the random pixel to white
  
  mover = random(1, 3);
  
  if (mover == 1) {
    RandomBlinky--;
    
    if (RandomBlinky < 0) {
      
      RandomBlinky = 11;
    }
    strip.setPixelColor( RandomBlinky, 0, 0, 33); 
    
  } else {
    
    RandomBlinky++;
    if (RandomBlinky > 11) {
      RandomBlinky = 0;
    }
    strip.setPixelColor( RandomBlinky, 0, 0, 33);  
    
  }

  //strip.setPixelColor( RandomBlinky, red, green, blue);  
  strip.show();
  
  delay(random(177));  
 // delay(22);  

  //strip.setPixelColor( RandomBlinky, redOff, greenOff, blueOff);
  strip.setPixelColor( RandomBlinky, 0, 0, 0);

  strip.show();
  
  
} 

