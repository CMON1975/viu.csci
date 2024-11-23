# CHRISTOPHER NILSSEN - makefile for LAB 09 CSCI 260 F2402

CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = StringMatch
SRC = StringMatch.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)