#include <iostream>
#include <string>
#include "timeslot.h"
#include "time.h"
#include "movie.h"

// Functions
void printMovie(Movie mv)
{
   std::string g;
   switch (mv.genre) {
      case ACTION   : g = "ACTION"; break;
      case COMEDY   : g = "COMEDY"; break;
      case DRAMA    : g = "DRAMA";  break;
      case ROMANCE  : g = "ROMANCE"; break;
      case THRILLER : g = "THRILLER"; break;
   }
   std::cout << mv.title << " " << g << " (" << mv.duration << " min) ";
}

std::string getTimeSlot(TimeSlot ts) 
{
   int etm, eth, temp = minutesSinceMidnight(ts.startTime) + ts.movie.duration;
   etm = temp % 60;
   eth = (temp-etm)/60;
   std::string r = "[starts at " + std::to_string(ts.startTime.h) +":"+ std::to_string(ts.startTime.m) +", ends by "+ std::to_string(eth) +":"+ std::to_string(etm) +"]";
   return r;
}
