# Makefile for building 'my_app' using clang++ and raylib on macOS

# Compiler
CXX := clang++

# Compiler flags
CXXFLAGS := -std=c++11

# Frameworks
FRAMEWORKS := -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# Source files
SOURCES := $(wildcard ./src/*.cpp)

# Raylib library
RAYLIB := ./lib/libraylib.a

# Output binary
TARGET := gameOfLife

# Build rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(FRAMEWORKS) $(RAYLIB) $(SOURCES) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean