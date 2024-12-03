# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -O2 -std=c++11

# Target executable
TARGET = network_analysis

# Source files
SRCS = network_analysis.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET) techAnalysisResult.txt

# Phony targets
.PHONY: all clean
