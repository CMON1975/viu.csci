test: main.o linked_list.o my_class.o
	g++ main.o linked_list.o my_class.o -o test
  
main.o: main.cc linked_list.h my_class.h
	g++ -c main.cc

linked_list.o: linked_list.cc linked_list.h my_class.h
	g++ -c linked_list.cc

my_class.o: my_class.cc my_class.h
	g++ -c my_class.cc
  
clean:
	rm *.o main
