#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void setup() {
  matrix.setIntensity(0);
  matrix.fillScreen(1);
  matrix.write();
  randomSeed(analogRead(0));
}
int rotater = 0;
int wait = 50;
int inc = -2;

int setX = 4, setY = 4;
int rndX = 0, rndY = 0;
int setBrightness = 7;
int y, z, x, cx, cy, timer;

String message = "Warning!";
int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels
int looper = 1;

void loop() {

  //strobe(44, 15, 6);//------ [strobeSpeed = strobeSpeed - 0 == random], [strobeBrightness =  0 low - 15 high], [strobes = number of strobes]

  radar(2, 0, 33); //------ sweeps, brightness 0 - 15, timer = (speed avarage=33)

  //randomDot();

  //bug();

  //pulser2(111, 22, 4);//------ pulser(pulseSpeed, offDelay, pulses);

  scrollText(29); //------ scrollText(scrollSpeed);

}
void bug() {
  // ---------------- bug -------------------------------
  matrix.setIntensity(15);

  for (x = 0; x < 364; x++) {
    matrix.fillScreen(0);
    matrix.write();
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
    matrix.drawPixel(setX, setY, 1);
    matrix.write();  // write the changes we just made to the display
    delay(11);
  }
  matrix.fillScreen(0);
  matrix.write();
  //matrix.setIntensity(setBrightness);
}

void randomDot() {
  // ----------------random dot -------------------------------
  matrix.fillScreen(0);
  matrix.write();
  for (int x = 0; x < 164; x++) {
    matrix.fillScreen(0);
    matrix.write();
    //matrix.setIntensity(random(15));
    matrix.setIntensity(random(15));

    matrix.drawPixel(random(8), random(8), 1);
    matrix.write();  // write the changes we just made to the display
    delay(22);
  }
  matrix.fillScreen(0);
  matrix.write();
}

void radar(int sweeps, int strobeBrightness, int timer) {
  matrix.setIntensity(strobeBrightness);
  // ---------------RADAR SWEEP---------------------
  //int timer = random(22)+33;
  matrix.setRotation(0, 0);

  int radarRotate = 3;
  sweeps = sweeps * 4;
  for (int x = 0; x < sweeps; x++) {
    matrix.setRotation(radarRotate);
    radarRotate++;


    matrix.drawLine(4, 3, 7, 3, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    matrix.drawLine(4, 3, 7, 4, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    matrix.drawLine(4, 4, 7, 5, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 7, 6, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 7, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 6, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 5, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 5, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();

    matrix.drawLine(4, 4, 4, 7, 1);
    matrix.write();
    delay(timer);
    matrix.fillScreen(0);
    matrix.write();


    // rotate dispaly
    if (radarRotate > 3) {
      radarRotate = 0;
    }
  }
}

void strobe(int strobeSpeed, int strobeBrightness, int strobes) {
  // strobeSpeed = strobeSpeed - 0 == random
  // strobeBrightness = 15 high - 0 low
  // strobes = number of strobes
  for (int i = 0; i < strobes; i++) {
    matrix.setIntensity(strobeBrightness);

    matrix.fillScreen(0);
    matrix.write();
    delay(strobeSpeed);
    matrix.fillScreen(1);
    matrix.write();
    delay(strobeSpeed);
  }
}

void pulser(int pulseSpeed, int offDelay, int pulses) {
  // pulseSpeed = speed of pulse
  // offDelay = how long to stay off between pulse - 0 = random
  // pulses = number of pulses
  for (int i = 0; i < pulses; i++) {
    matrix.fillScreen(1);
    matrix.setIntensity(0);
    matrix.write();

    for (int i = 0; i < 15; i++) {
      matrix.setIntensity(i);
      delay(pulseSpeed);
    }

    for (int i = 15; i > 0; i--) {
      matrix.setIntensity(i);
      delay(pulseSpeed);
    }

    matrix.fillScreen(0);
    matrix.write();

    if (offDelay == 0) {
      delay(random(2000));
    }
    else {
      delay(offDelay);
    }
  }
}

void scrollText(int scrollSpeed) {
  matrix.setRotation(0, 2);
  delay(666);

  matrix.setIntensity(15);

  for ( int i = 0 ; i < width * message.length() + matrix.width() - 1 - spacer; i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < message.length() ) {
        matrix.drawChar(x, y, message[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(scrollSpeed);
  }
  delay(666);
  matrix.setRotation(0, 2);

}

void pulser2(int pulseSpeed, int offDelay, int pulses) {

  for (int i = 0; i < pulses; i++) {
    matrix.fillScreen(1);
    matrix.setIntensity(0);
    matrix.write();

    for (int i = 0; i < 5; i++) {
      matrix.setIntensity(i);
      delay(pulseSpeed);
    }

    for (int i = 5; i > 0; i--) {
      matrix.setIntensity(i);
      delay(pulseSpeed);
    }

    matrix.fillScreen(0);
    matrix.write();

    if (offDelay == 0) {
      delay(random(2000));
    }
    else {
      delay(offDelay);
    }
  }
}




