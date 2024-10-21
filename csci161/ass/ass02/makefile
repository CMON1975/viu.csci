pex2: main.o record.o list.o  
	g++ main.o record.o list.o -o pex2
main.o: main.cc list.h 
	g++ -c main.cc
order_list.o: list.cc record.h
	g++ -c list.cc
order.o: record.cc
	g++ -c record.cc
clean:
	rm *.o main
