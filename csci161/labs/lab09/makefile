lab9: main.o person.o student.o
	g++ main.o person.o student.o -o lab9
main.o: main.cc person.h student.h queue.h queue_exception.h 
	g++ -c main.cc
person.o: person.cc person.h
	g++ -c person.cc
student.o: student.cc student.h person.h
	g++ -c student.cc
clean:
	rm *.o main 
