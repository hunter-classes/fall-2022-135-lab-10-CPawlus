main: main.o time.o timeslot.o movie.o
	g++ -o main main.o time.o timeslot.o movie.o

tests: tests.o
	g++ -o tests tests.o

main.o: main.cpp 
	g++ -c main.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

time.o: time.cpp time.h
	g++ -c time.cpp

timeslot.o: timeslot.cpp timeslot.h
	g++ -c timeslot.cpp

movie.o: movie.cpp movie.h
	g++ -c movie.cpp

clean:
	rm -f main time timeslot movie tests main.o time.o tests.o timeslot.o movie.o