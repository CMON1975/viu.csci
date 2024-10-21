pex3: main.o set.o
	g++ main.o set.o -o Pex3
main.o: main.cc set.h
	g++ -c main.cc
set.o: set.cc
	g++ -c set.cc
clean:
	rm *.o main
