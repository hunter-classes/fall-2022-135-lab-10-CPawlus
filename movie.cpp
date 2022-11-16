#include <iostream>
#include "movie.h"
#include "timeslot.h"
#include "time.h"

// Functions
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) 
{
   TimeSlot newTime;
   int nm, nh, nT, tsT = ts.movie.duration;
   nT = (minutesSinceMidnight(ts.startTime)) + tsT;
   nm = nT % 60;
   nh = (nT-nm)/60;
   newTime = {nextMovie, {nh, nm}};
   return newTime;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) 
{
   int ts1T = minutesSinceMidnight(ts1.startTime) + ts1.movie.duration;
   int ts2T = (ts2.startTime.h*60) + ts2.startTime.m;
   if(ts1T > ts2T) 
   {
      return true;
   }
   else 
   {
      return false;
   }
} 