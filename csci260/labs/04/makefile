# CHRISTOPHER NILSSEN makefile for LAB 04 CSCI 260 F2402

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = NaryTreeApp

# Source files
SRCS = NaryTree.cpp

# Object files (will be generated from .cpp files)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target executable
all: $(TARGET)

# Rule to link the object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp NaryTree.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)
