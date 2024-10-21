main: main.o queue.o
	g++ main.o queue.o -o main

main.o: main.cc queue.h
	g++ -c main.cc

queue.o: queue.cc queue.h
	g++ -c queue.cc

clean:
	rm *.o main
