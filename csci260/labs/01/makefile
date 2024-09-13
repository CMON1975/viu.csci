CC = g++
CFLAGS = -std=c++11

all: lab01

lab01: lab01.o spans.o
	$(CC) $(CFLAGS) lab01.o spans.o -o lab01

lab01.o: lab01.cpp spans.h
	$(CC) $(CFLAGS) -c lab01.cpp

spans.o: spans.cpp spans.h
	$(CC) $(CFLAGS) -c spans.cpp

clean:
	rm -f *.o lab01
