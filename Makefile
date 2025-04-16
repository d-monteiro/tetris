CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -lSDL2_gfx -lSDL2
LDFLAGS = -lSDL -lSDL_gfx
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
TARGET = build/main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build/*
