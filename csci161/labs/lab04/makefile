lab4: main.o growing_array.o
	g++ main.o growing_array.o -o lab4
main.o: main.cc growing_array.h
	g++ -c main.cc
growing_array.o: growing_array.h growing_array.cc
	g++ -c growing_array.cc
clean:
	rm *.o main
