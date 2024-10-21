Pex4: main.o 
	g++ main.o -o Pex4
Pex4d: main.o
	g++ -g -fPIC main.o -o Pex4d
main.o: main.cc stack.h
	g++ -c main.cc
clean:
	rm -f *.o
