#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LED_COUNT 12
#define SEAHAWKS_GREEN strip.Color(50, 0, 5)
#define SEAHAWKS_BLUE strip.Color(0, 11, 44)
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
 
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
 
void setup() {
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    strip.setBrightness(88);

}
 
void loop() {
  
  runningLights(SEAHAWKS_BLUE, SEAHAWKS_GREEN, 4, 50);
  colorWipe(SEAHAWKS_GREEN, 50); // Green
  colorWipe(SEAHAWKS_BLUE, 50); // Blue
  colorWipe(SEAHAWKS_GREEN, 50); // Green
  colorWipe(SEAHAWKS_BLUE, 50); // Blue
  theaterChaseDuo(SEAHAWKS_GREEN, SEAHAWKS_BLUE, 100); //blue & green
  colorWipe(SEAHAWKS_GREEN, 50); // Green
  colorWipe(SEAHAWKS_BLUE, 50); // Blue
  colorWipe(SEAHAWKS_GREEN, 50); // Green
 
  //rainbow(20);
  //skittles(20);
  //theaterChaseRainbow(50);
}
 
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
 
void rainbow(uint8_t wait) {
  uint16_t i, j;
 
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
 
// Slightly different, this makes the rainbow equally distributed throughout
void skittles(uint8_t wait) {
  uint16_t i, j;
 
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
 
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
 
//Theatre-style crawling lights.
void theaterChaseDuo(uint32_t c1, uint32_t c2, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c1);    //turn every other pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+2) {
        strip.setPixelColor(i+q, c2);        //turn every third pixel off
      }
    }
  }
}
 
void runningLights(uint32_t base, uint32_t chase, uint32_t chaseLength, uint8_t wait){
  //set the base for the pixels
  colorWipe(base, wait);
  int startChase = 0;
  int endChase = chaseLength;
  int steps = (strip.numPixels() * 5) - chaseLength;
 
  //start the runner
  for(int i= startChase; i<endChase; i++){
    strip.setPixelColor(i, chase);
    strip.show();
    delay(wait);
  }
 
  //run the runner around the strip
  for(int j=0; j<steps; j++){
    uint32_t oldStart = startChase;
    startChase = (startChase + 1) % strip.numPixels();
    endChase = (endChase + 1) % strip.numPixels();
    strip.setPixelColor(oldStart, base);
    strip.setPixelColor(endChase, chase);
    strip.show();
    delay(wait);
  }
  //end runner
  for(int i= startChase; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i, base);
    strip.show();
    delay(wait);
  }
}
 
 
//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}
 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}