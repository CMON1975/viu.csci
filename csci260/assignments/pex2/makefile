# CHRISTOPHER NILSSEN Makefile for ASSIGNMENT 02 CSCI 260 F2402

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = pex2

# Source files
SRCS = pex2.cpp Customer.cpp RBTree.cpp BST.cpp

# Header files
HDRS = Customer.h RBTree.h BST.h

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to prevent conflicts with files named 'all' or 'clean'
.PHONY: all clean
