#include <TVout.h>
#include <fontALL.h>

#include "DMG.h"

TVout TV;


void setup() {
  TV.begin(NTSC, 120, 96);
  TV.select_font(font6x8);

  TV.bitmap(13, 31, DMG);
}

void loop() {

}


