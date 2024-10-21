test: main.o flag.o 
	g++ main.o flag.o -o test
  
main.o: main.cc flag.h
	g++ -c main.cc

flag.o: flag.cc flag.h
	g++ -c flag.cc
 
clean:
	rm *.o main
