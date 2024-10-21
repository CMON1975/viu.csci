Lab11: main.o familytree.o
	g++ main.o familytree.o -o Lab11
main.o: main.cc familytree.h
	g++ -c main.cc
familytree.o: familytree.cc familytree.h
	g++ -c familytree.cc
clean:
	rm *.o main
