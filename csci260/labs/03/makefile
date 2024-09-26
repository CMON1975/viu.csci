# CHRISTOPHER NILSSEN makefile for LAB 03 CSCI 260 F2402
# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets
all: lab03

lab03: lab03.o HashTable.o
	$(CXX) $(CXXFLAGS) -o lab03 lab03.o HashTable.o

main.o: lab03.cpp HashTable.h
	$(CXX) $(CXXFLAGS) -c lab03.cpp

HashTable.o: HashTable.cpp HashTable.h
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

# Clean target to remove object files and the executable
clean:
	rm -f *.o lab03
