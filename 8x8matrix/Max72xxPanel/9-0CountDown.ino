#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void setup() {

  matrix.setIntensity(7); // Use a value between 0 and 15 for brightness
}

void loop() {
  for(int i = 57; i > 47; i--) {
    matrix.fillScreen(LOW);
    char c=char(i);
    matrix.drawChar(1, 0, c, HIGH, LOW, 1);

    matrix.write(); // Send bitmap to display
    delay(1000);
  }


}