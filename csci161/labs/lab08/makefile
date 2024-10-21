lab8: main.o person.o student.o
	g++ main.o person.o student.o -o lab8
main.o: main.cc person.h
	g++ -c main.cc
person.o: person.cc person.h
	g++ -c person.cc
student.o: student.cc student.h person.h
	g++ -c student.cc
clean:
	rm *.o main 
