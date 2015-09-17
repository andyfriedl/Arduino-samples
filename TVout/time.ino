#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

#include <TVout.h>
#include <fontALL.h>

TVout TV;
int i = 1, u = 1;
int hours;
void setup()  {
 
  setSyncProvider(RTC.get);
  TV.begin(NTSC);  //for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  //TV.begin(_NTSC,128,56);
  randomSeed(analogRead(0));
   setTime(10,58,0,10,29,14);
}


void loop() {

  TV.select_font(font8x8);



  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;     
  // subtract seventy years:
  unsigned long epoch = now() - seventyYears;  

  /*
  TV.print(0,22,((epoch  % 86400L) / 3600));
   TV.print(22,22,(epoch  % 3600) / 60);
   if(second() < 10) {
   //TV.draw_rect(35,23,41,35,0,0);
   TV.print(50,22, (epoch %60));
   } 
   else {
   TV.print(50,22, (epoch %60));
   }*/
  if(hour() >=12) {
    hours = hour() -12;
  } 
  else {
    hours = hour();
  }
  TV.print(0,22,hours);
  TV.print(22,22,minute());
  if(second() < 10) {
    //TV.draw_rect(35,23,41,35,0,0);
    TV.print(44,22, second());
  } 
  else {
    TV.print(44,22, second());
  }

  TV.print(69, 22, year());
  
  TV.print(1, 55,dayOfWeek( now() ));
  /*
  dayOfWeek( now() );           // the day of the week (Sunday is day 1)
elapsedSecsToday( now() );    // returns the number of seconds since the start
                              // of today
nextMidnight( now() );        // how much time to the end of the day
elapsedSecsThisWeek( now() ); // how much time has elapsed since the start of
                              // the week
                              */
}