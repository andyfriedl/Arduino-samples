
#include <FastLED.h>
 
#define LED_DT 12                                             // Data pin to connect to the strip.
#define COLOR_ORDER GRB                                       // It's GRB for WS2812 and BGR for APA102.
#define LED_TYPE WS2812                                       // Using APA102, WS2812, WS2801. Don't forget to change LEDS.addLeds.
#define NUM_LEDS 8                                           // Number of LED's.
 
uint8_t max_bright = 111;                                      // Overall brightness definition. It can be changed on the fly.
 
struct CRGB leds[NUM_LEDS];                                   // Initialize our LED array.
 
uint8_t speedy = 192;                                         // Low value = greater delay, up to 255 for no delay.
uint8_t intensity = 192;                                      // Higher value = more flashes per strike.
 
 
 
void setup() {
  Serial.begin(115200);
  delay(1000);
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(max_bright);  
} // setup()
 
 
 
void loop() {
  wledlightning();
  FastLED.show();
} // loop()
 
 
 
void wledlightning(){
 
  uint16_t ledstart = random16(NUM_LEDS);                     // Determine starting location of flash.
  uint16_t ledlen = 1 + random16(NUM_LEDS - ledstart);        // Determine length of flash.
  uint8_t bri = 255/random8(1, 3);                            // Brightness.
  static long step;
  
  static uint16_t segDelay;                                   // Delay between strikes (was SEGMENT.aux0).
  static uint16_t numFlash = 0;                               // Flash stepper (was SEGMENT.aux1).
  
  if (numFlash == 0)                                          // Initialize the leader flash.
  {
    numFlash = random8(4, 4 + intensity/20);                  // Number of flashes.
    numFlash *= 2;
    bri = 52;                                                 // Leader has lower brightness.
    segDelay = 200;                                           // 200ms delay after leader.
  }
 
  fill_solid(leds,NUM_LEDS,0);                                // Fill the led's with black
  
  if (numFlash > 3 && !(numFlash & 0x01))                     // Flash on even number > 2.
  {                       
    for (int i = ledstart; i < ledstart + ledlen; i++)
    {
      leds[i] = CRGB::Gray;                                   // Fill ledstart to ledstart+ledlen with gray.
    }
    numFlash--;
    step = millis();
  } else {
    if (millis() - step > segDelay)
    {
      numFlash--;
      if (numFlash < 2) numFlash = 0;
      segDelay = (50 + random8(100));                               // Delay between flashes.
      if (numFlash == 2) segDelay = (random8(255 - speedy) * 100);  // Delay between strikes.
      step = millis();
    }
  }
} // wledlightning()
