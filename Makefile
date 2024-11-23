
# Compiler and flags
CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -I. 

# Source directory
SRC_DIR = src

# Automatically find all .cc files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cc)

# Object files
OBJS = $(SRCS:.cc=.o)

# Target shared library
TARGET = libmaterialyou.so

# Default rule
all: $(TARGET)

# Rule to build the shared library
$(TARGET): $(OBJS)
	$(CXX) -shared -o $@ $(OBJS)

# Rule to build object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(wildcard $(SRC_DIR)/*.gch)

