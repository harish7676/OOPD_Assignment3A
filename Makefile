# Makefile for compiling and managing the project with MinGW32

# Compiler and flags for MinGW32
CXX = g++
CXXFLAGS_DEBUG = -Wall -Wextra -g
CXXFLAGS_RELEASE = -O2 -Wall -Wextra

# Linker flags (if needed)
LDFLAGS =

# Source files and object files for each program
SRC_MAIN = main.cpp
SRC_TEST = test.cpp
OBJ_MAIN = main.o
OBJ_TEST = test.o
DEPS = library.h

# Binary names for debug and release versions
BIN_MAIN_DEBUG = main_debug.exe
BIN_MAIN_RELEASE = main_release.exe
BIN_TEST_DEBUG = test_debug.exe
BIN_TEST_RELEASE = test_release.exe

# Default target: build both debug and release versions
all: $(BIN_MAIN_DEBUG) $(BIN_MAIN_RELEASE) $(BIN_TEST_DEBUG) $(BIN_TEST_RELEASE)

# Rule to compile and link for the main program in debug mode
$(BIN_MAIN_DEBUG): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS_DEBUG) $(OBJ_MAIN) -o $(BIN_MAIN_DEBUG)

# Rule to compile and link for the main program in release mode
$(BIN_MAIN_RELEASE): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS_RELEASE) $(OBJ_MAIN) -o $(BIN_MAIN_RELEASE)

# Rule to compile and link for the test program in debug mode
$(BIN_TEST_DEBUG): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS_DEBUG) $(OBJ_TEST) -o $(BIN_TEST_DEBUG)

# Rule to compile and link for the test program in release mode
$(BIN_TEST_RELEASE): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS_RELEASE) $(OBJ_TEST) -o $(BIN_TEST_RELEASE)

# Rule to compile main.cpp (debug version)
main.o: $(SRC_MAIN) $(DEPS)
	$(CXX) $(CXXFLAGS_DEBUG) -c $(SRC_MAIN) -o main.o

# Rule to compile test.cpp (debug version)
test.o: $(SRC_TEST) $(DEPS)
	$(CXX) $(CXXFLAGS_DEBUG) -c $(SRC_TEST) -o test.o

# Clean up generated files
clean:
	del /Q $(BIN_MAIN_DEBUG) $(BIN_MAIN_RELEASE) $(BIN_TEST_DEBUG) $(BIN_TEST_RELEASE) *.o
