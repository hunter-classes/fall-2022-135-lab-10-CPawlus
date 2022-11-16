/*
Author: Christopher Pawlus
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Classes, enums, and movies, main.cpp, Lab 10.

This program uses classes that are used to 
maniplutate times of movies.
*/

#include <iostream>
#include "time.h"
#include "timeslot.h"
#include "movie.h"

int main() 
{
   // A
   std::cout << minutesUntil({10, 20}, {12, 42}) << " minutes." << "\n";
   // B
   Time a = {8, 10};
   a = addMinutes(a, 75);
   std::cout << "{" << a.h << ", " << a.m << "}\n";
   // C
   Movie movie1 = {"Back to the Future", COMEDY, 116};
   Movie movie2 = {"Black Panther", ACTION, 134};
   Movie movie3 = {"Home Alone 2: Lost in New York", COMEDY, 115};
   Movie movie4 = {"Full Metal Jacket", ACTION, 116};;
   TimeSlot morning = {movie1, {9, 15}};  
   TimeSlot morning2 = {movie3, {7, 15}};  
   TimeSlot daytime = {movie2, {12, 15}}; 
   TimeSlot evening = {movie2, {16, 45}}; 
   TimeSlot evening2 = {movie4, {19, 15}};
   printMovie(movie1);
   std::cout << getTimeSlot(morning) << "\n";
   printMovie(movie3);
   std::cout << getTimeSlot(morning2) << "\n";
   printMovie(movie2);
   std::cout << getTimeSlot(daytime) << "\n";
   printMovie(movie2);
   std::cout << getTimeSlot(evening) << "\n";
   printMovie(movie4);
   std::cout << getTimeSlot(evening2) << "\n";
   // D
   Movie movie = {"Some Funny Movie", COMEDY, 120};
   Movie movier = {"Some Funny Movie 2", COMEDY, 120};
   TimeSlot first = {movie, {14, 10}};
   TimeSlot second = scheduleAfter(first, movier);
   std::cout << second.startTime.h << ":" << second.startTime.m << "\n";
   // E
   Movie m = {"Home Alone 2: Lost in New York", COMEDY, 115};
   Movie m2 = {"Full Metal Jacket", ACTION, 116};;
   TimeSlot mov = {m, {8, 15}};  
   TimeSlot mov2 = {m2, {9, 15}};  
   std::cout << std::boolalpha << timeOverlap(mov, mov2) << "\n";
   return 0;
}