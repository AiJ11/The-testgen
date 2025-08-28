# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Source files
SRC = test_libapplication.cpp jsCodeGenerator/jsCodegen.cpp

# Output binary
TARGET = test_libapplication

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
