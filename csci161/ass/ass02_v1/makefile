pex2: main.o record.o list.o menu.o
	g++ main.o record.o list.o menu.o -o pex2  
main.o: main.cc list.h menu.h
	g++ -c main.cc
list.o: list.cc record.h
	g++ -c list.cc
record.o: record.cc
	g++ -c record.cc
clean:
	rm *.o main
