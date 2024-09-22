# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra
# Output executable name
TARGET = pex1

# Source files for pex1
PEX1_SRCS = pex1.cpp JobUtils.cpp CommandHandler.cpp

# Object files for pex1
PEX1_OBJS = $(PEX1_SRCS:.cpp=.o)

# Source files for unit_tests
UNIT_TEST_SRCS = unit_tests.cpp JobUtils.cpp CommandHandler.cpp

# Object files for unit_tests
UNIT_TEST_OBJS = $(UNIT_TEST_SRCS:.cpp=.o)

# Header files
HEADERS = Job.h PriorityQueue.h CommandHandler.h JobUtils.h

# Include directories
INCLUDES = -I.

# Rule to build the executable pex1
$(TARGET): $(PEX1_OBJS)
	$(CXX) $(CXXFLAGS) $(PEX1_OBJS) -o $(TARGET)

# Rule to build the unit tests executable
unit_tests: $(UNIT_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(UNIT_TEST_OBJS) -o unit_tests

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to clean up build files
clean:
	rm -f *.o $(TARGET) unit_tests

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Declare phony targets
.PHONY: clean run
