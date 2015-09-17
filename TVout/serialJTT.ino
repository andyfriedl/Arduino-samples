#include <TVout.h>
#include <pollserial.h>
#include <fontALL.h>
int charSpace = 1;
int clearScreen = 0, waitForIdle = 1;
unsigned long currentMillis = 1;
long previousMillis = 0;
long interval = 20000;

TVout TV;
pollserial pserial;

void setup()  {
  TV.begin(_NTSC);
  TV.select_font(font6x8);
  TV.println(7,7,"Just the Temp ");
  TV.println("-- Version 0.2 --");
  TV.set_hbi_hook(pserial.begin(9600));
}


void loop() {
 
  
  if (pserial.available()) {
    if(clearScreen == 1) {
      TV.draw_rect(0,40,120,30,0,0);
      //TV.clear_screen();
      clearScreen = 0;
      waitForIdle = 1;
    }
      TV.print(charSpace += 6, 44,(char)pserial.read());
      currentMillis = millis();
    
  } 
  else {
    waitForIdle++;
    if((currentMillis - previousMillis) > interval) {
      previousMillis = currentMillis; 
      //Serial.flush();
      clearScreen = 1;
    }
  }

}


