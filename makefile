# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -std=c++11

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable
TARGET = main

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild