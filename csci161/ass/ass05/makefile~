dict: main.o
	g++ main.o -o dict
main.o: main.cc dictionary.h dict_except.h
	g++ -c main.cc
clean:
	rm *.o main
