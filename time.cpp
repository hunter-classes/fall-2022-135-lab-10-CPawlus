#include <iostream>
#include "time.h"

// Functions
void printTime(Time time) 
{
   std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time) 
{
   if(time.h < 1) 
   {
      return time.m;
   }
   else 
   {
      return (time.h * 60) + time.m;
   }
}

int minutesUntil(Time earlier, Time later) 
{
   return minutesSinceMidnight(later)-minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min)
{
   int a, temp = minutesSinceMidnight(time0) + min, tot = 0;
   a = temp % 60;
   temp = temp - a;
   tot = temp/60;
   return {tot, a};
}


