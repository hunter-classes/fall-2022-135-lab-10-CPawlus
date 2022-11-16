#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.cpp"
#include "timeslot.cpp"
#include "movie.cpp"

TEST_CASE("Time Function Test Cases") 
{
   CHECK(minutesSinceMidnight({0, 0}) == 0);
   CHECK(minutesSinceMidnight({0, 1}) == 1);
   CHECK(minutesSinceMidnight({1, 0}) == 60);
   CHECK(minutesSinceMidnight({30, 15}) == 1815);
   CHECK(minutesSinceMidnight({10, 15}) == 615);
   CHECK(minutesUntil({8, 15}, {8, 15}) == 0);
   CHECK(minutesUntil({8, 15}, {8, 16}) == 1);
   CHECK(minutesUntil({8, 15}, {8, 14}) == -1);
   CHECK(minutesUntil({8, 15}, {9, 15}) == 60);
   CHECK(minutesUntil({8, 15}, {20, 15}) == 720);
}

TEST_CASE("TimeSlot Function Test Cases") 
{
   Movie movie = {"Full Metal Jacket", ACTION, 116};;
   TimeSlot m = {movie, {9, 15}};  
   CHECK(getTimeSlot(m) == "[starts at 9:15, ends by 11:11]");
   movie = {"A really cool movie!", ACTION, 110};;
   m = {movie, {6, 5}};  
   CHECK(getTimeSlot(m) == "[starts at 6:5, ends by 7:55]");
   movie = {"A funny movie.", ACTION, 120};;
   m = {movie, {10, 15}};  
   CHECK(getTimeSlot(m) == "[starts at 10:15, ends by 12:15]");
   movie = {"A interesting movie!", ACTION, 100};;
   m = {movie, {12, 15}};  
   CHECK(getTimeSlot(m) == "[starts at 12:15, ends by 13:55]");
}

TEST_CASE("Movie Function Test Cases") 
{
   Movie movie = {"Some movie.", ACTION, 116};;
   TimeSlot m = {movie, {9, 15}}; 
   Movie movie2 = {"Another movie.", DRAMA, 116};;
   TimeSlot m2 = {movie2, {9, 30}}; 
   CHECK(timeOverlap(m, m2) == true);
   movie = {"Some movie.", ACTION, 116};;
   m = {movie, {9, 15}}; 
   movie2 = {"Another movie.", DRAMA, 116};;
   m2 = {movie2, {9, 15}};
   CHECK(timeOverlap(m, m2) == true);
   movie = {"Some movie.", ACTION, 116};;
   m = {movie, {9, 15}}; 
   movie2 = {"Another movie.", DRAMA, 116};;
   m2 = {movie2, {12, 15}}; 
   CHECK(timeOverlap(m, m2) == false);
   movie = {"Some movie.", ACTION, 116};;
   m = {movie, {9, 15}}; 
   movie2 = {"Another movie.", DRAMA, 116};;
   m2 = {movie2, {11, 11}}; 
   CHECK(timeOverlap(m, m2) == false);
}


