# CHRISTOPHER NILSSEN - makefile for LAB B CSCI 260 F2402

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable name
TARGET = topological_sort

# Source files
SRC = topological_sort.cpp

# Default rule to build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up generated files
clean:
	rm -f $(TARGET)
