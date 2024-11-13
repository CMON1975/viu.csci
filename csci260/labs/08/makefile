# CHRISTOPHER NILSSEN - makefile for LAB 08 CSCI 260 F2402

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: SL_test

SL_test: SkipList.o SL_test.o
	$(CXX) $(CXXFLAGS) -o SL_test SkipList.o SL_test.o

SkipList.o: SkipList.cpp
	$(CXX) $(CXXFLAGS) -c SkipList.cpp

SL_test.o: SL_test.cpp
	$(CXX) $(CXXFLAGS) -c SL_test.cpp

clean:
	rm -f *.o SL_test
