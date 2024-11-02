# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = TF_test

# Build target
all: $(TARGET)

$(TARGET): TF_test.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) TF_test.cpp

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
