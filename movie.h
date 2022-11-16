#pragma once
#include "time.h"

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
class Movie {public: std::string title; Genre genre; int duration;};
class TimeSlot {public: Movie movie; Time startTime;};
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 