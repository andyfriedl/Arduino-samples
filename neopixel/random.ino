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
int Brightness = 60;  // Brightness of the pixels is about 60%
                      // I ended up not using the Brightness variable.
int BlinkDelay = 222;
int i = 0;




Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, LED_PIN, NEO_GRB +NEO_KHZ800);

void setup()
{
strip.begin();
//strip.setBrightness(Brightness);  // I ended up not using this.

}  // end of setup()

void loop()
{
RandomBlinky = random(12);  // Choose a random NeoPixel.
red = random(35);  // Choose a random NeoPixel.
green = random(35);  // Choose a random NeoPixel.
blue = random(35);  // Choose a random NeoPixel.
redOff = random(2);  // Choose a random NeoPixel.
greenOff = random(2);  // Choose a random NeoPixel.
blueOff = random(2);  // Choose a random NeoPixel.
// set the random pixel to white
strip.setPixelColor( RandomBlinky, red, green, blue);  //It's a dim White.
strip.show();
//delay(BlinkDelay);  //Let the White show for a little bit.
delay(random(666));  //Let the White show for a little bit.
//Set the random pixel back to the color it was, Red or Green

  //strip.setPixelColor( RandomBlinky, redOff, greenOff, blueOff);
  strip.setPixelColor( RandomBlinky, 0, 0, 0);
  strip.show();
delay(2);  //Don't do another White blinky for a little bit.
             // Use a lower number to make the blinks happen faster.
} // End of loop()

/*
Instead of doing the brightness using the "strip.setBrightness(Brightness);",
how about setting Red to 150, 0, 0 and Green to 0, 150, 0?
And set the sparkle to 200,200,200.
This way the flash of the sparkle will be brighter than the brightness of the 
rest of the colors on the ring.

Well, that was too bright.  I used lower numbers for the colors in the sketch.
*/

