#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
      strip.setBrightness(88);
  randomSeed(analogRead(0));

}

void loop() {
  // Some example procedures showing how to display to the pixels:

  //colorFill(strip.Color(random(55, 225), random(55, 225), random(55, 225)), 22); // Red
  colorFill(strip.Color(255, 0, 0), 22); // Red
  delay(10);
  colorFill(strip.Color(0, 0, 0), 22); // Red
    //delay(random(2,10)*1000);
    delay(random(2222));


}

// Fill the dots with the same color
void colorFill(uint32_t c, int wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}
