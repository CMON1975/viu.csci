# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
# Output executable name
TARGET = pex1

# Source files
SRCS = pex1.cpp JobUtils.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)

# Include directories
INCLUDES = -I.

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)
