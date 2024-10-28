# CHRISTOPHER NILSSEN makefile for LAB 06 CSCI 260 F2402
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = TT_test

# Source files
SRCS = ThreadTree.cpp TT_test.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the test program
run: $(TARGET)
	./$(TARGET)
