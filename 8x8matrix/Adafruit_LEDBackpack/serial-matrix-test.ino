#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

int y, z, x, cx, cy;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
byte incomingByte;


// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// broken !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void setup()
{
  Serial.begin(9600);

  Serial.println("8x8 Test");

  matrix.setBrightness(0);
  matrix.setRotation(1);
  matrix.begin(0x70);  // pass in the address
}

void loop()
{
  matrix.clear();

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();


    matrix.clear();
    matrix.setCursor(x,0);
    Serial.println(incomingByte);
    matrix.setTextSize(1);
    matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
    matrix.setTextColor(LED_ON);
    if (incomingByte == 32) {
      for (int8_t x=0; x>=-60; x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print(" GAME OVER!");
        matrix.writeDisplay();
        delay(66);
      }
      //matrix.print('y'); // only prints first character
      //matrix.writeDisplay();
    } 
    else {
      for (int8_t x=0; x>=-30; x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print(':' + incomingByte);
        matrix.writeDisplay();
        delay(66);
      }

    }
    delay(66);

    // Serial.print("I received: ");
    // Serial.println(incomingByte, DEC);
  }


}

