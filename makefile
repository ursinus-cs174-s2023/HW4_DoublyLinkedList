CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver tester mazetester

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

driver: linkedlist.o driver.cpp
	$(CC) $(CFLAGS) -o driver driver.cpp linkedlist.o

tester: linkedlist.o tester.cpp
	$(CC) $(CFLAGS) -o tester tester.cpp linkedlist.o

maze.o: maze.h maze.cpp
	$(CC) $(CFLAGS) -c maze.cpp

mazetester: mazetester.cpp maze.o linkedlist.o
	$(CC) $(CFLAGS) -o mazetester mazetester.cpp maze.o linkedlist.o

clean:
	rm *.o driver tester mazetester