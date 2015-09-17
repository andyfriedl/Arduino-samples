#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#define ENTRIES(ARRAY)  (sizeof(ARRAY) / sizeof(ARRAY[0]))

uint8_t pattern[] =
{
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
    , 0x17, 0x27, 0x37, 0x47, 0x57, 0x67, 0x77
    , 0x76, 0x75, 0x74, 0x73, 0x72, 0x71, 0x70
    , 0x60, 0x50, 0x40, 0x30, 0x20, 0x10
    , 0x11, 0x12, 0x13, 0x14, 0x15, 0x16
    , 0x26, 0x36, 0x46, 0x56, 0x66
    , 0x65, 0x64, 0x63, 0x62, 0x61
    , 0x51, 0x41, 0x31, 0x21
    , 0x22, 0x23, 0x24, 0x25
    , 0x35, 0x45, 0x55
    , 0x54, 0x53, 0x52
    , 0x42, 0x32
    , 0x33, 0x34
    , 0x44
    , 0x43
};

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void loop()
{
    matrix.clear();
    
    for (int i = 0; i < ENTRIES(pattern); i++ )
    {
        int x = pattern[i] >> 4;
        int y = pattern[i]  & 7;
    
        matrix.drawPixel(x, y, LED_ON);
        matrix.writeDisplay();
        delay(22);
    }
    
        for (int i = 0; i < ENTRIES(pattern); i++ )
    {
        int x = pattern[i] >> 4;
        int y = pattern[i]  & 7;
    
        matrix.drawPixel(x, y, LED_OFF);
        matrix.writeDisplay();
        delay(22);
    }

    for (int i = 0; i < ENTRIES(pattern); i++ )
    {
        int x = pattern[i] >> 4;
        int y = pattern[i]  & 7;
    
        matrix.drawPixel(x, y, LED_ON);
        matrix.writeDisplay();
        delay(44);
        matrix.clear();
    }
    //delay(400);
    
}

void setup()
{
    Serial.begin(9600);

    Serial.println("8x8 Test");

    matrix.setBrightness(0);
    matrix.setRotation(1);
    matrix.begin(0x70);  // pass in the address
}
