lab7: main.o complexnum.o
	g++ main.o complexnum.o -o lab7
main.o: main.cc complexnum.h
	g++ -c main.cc
complexnum.o: complexnum.cc complexnum.h
	g++ -c complexnum.cc
clean:
	rm *.o main
