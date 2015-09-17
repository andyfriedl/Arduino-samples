const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int delayTime = 456;
#include <Adafruit_NeoPixel.h>

#define PIN 6


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(122);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    //rightCall();
    leftCall();
    //stopCall();

    //digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
      colorChangeStop(strip.Color(0, 0, 0), 50); // Red

    strip.show(); // Initialize all pixels to 'off'
  }
}



void stopCall() {
  colorChangeStop(strip.Color(255, 0, 0), 50); // Red
  //delay(delayTime);
  //colorChangeStop(strip.Color(0, 0, 0), 50); // Red
  //delay(delayTime);
}
void colorChangeStop(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    //delay(wait);
  }


}
void leftCall() {
  colorChangeLeft(strip.Color(195, 99, 0), 50); // Red
  delay(delayTime);
  colorChangeLeft(strip.Color(0, 0, 0), 50); // Red
  delay(delayTime);
}
void colorChangeLeft(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<6; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    //delay(wait);
  }
}
void rightCall() {
  colorChangeRight(strip.Color(195, 99, 0), 50); // Red
  delay(delayTime);
  colorChangeRight(strip.Color(0, 0, 0), 50); // Red
  delay(delayTime);
}
void colorChangeRight(uint32_t c, uint8_t wait) {
  for(uint16_t i=6; i<12; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    //delay(wait);
  }
}



