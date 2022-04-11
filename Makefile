CXX_FLAG = --std=c++11

all: game tests

cards.o: cards.h cards.cpp
	g++ ${CXX_FLAG} -Wall -c cards.h cards.cpp

main.o: main.cpp cards.h cards.cpp
	g++ ${CXX_FLAG} -Wall -c main.cpp cards.h cards.cpp

game: main.o cards.o
	g++ ${CXX_FLAG} -Wall cards.o main.o -o game

tests: cards.h cards.cpp tests.cpp
	g++ ${CXX_FLAG} -Wall cards.o tests.cpp -o tests

clean:
	rm -f *.o *~ game tests main test
