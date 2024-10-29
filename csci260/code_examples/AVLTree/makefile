# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = avl_test

# Source files
SOURCES = AVLTree.cpp test.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Link object files to create the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the target executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean
