# Folders
SRCFOLDER := src/
INCFOLDER := inc/
OBJFOLDER := obj/
BINFOLDER := bin/
TESTFOLDER := test/

# Flags
CC = g++ $(ALLWARNINGS)
ALLWARNINGS := -Wall -Wextra -pedantic -Wshadow -Wredundant-decls -Woverloaded-virtual -Wsynth
GOOGLETEST := -lgtest -lgtest_main
IFLAG := -I./inc/

# Files
CPPFILES = $(wildcard src/*.cpp)
TESTFILES = $(wildcard test/*.cpp)

all: sample

sample: objectFiles
	$(CC) obj/*.o main.cpp -o bin/$@ $(IFLAG)

objectFiles: $(CPPFILES:src/%.cpp=obj/%.o)

obj/%.o: src/%.cpp
	$(CC) -c $< -o $@ $(IFLAG)

# Compile tests
test: testFiles

testFiles: $(TESTFILES:test/%Test.cpp=bin/%Test)

bin/%Test: test/*Test.cpp src/*.cpp
	$(CC) $^ -o $@ $(GOOGLETEST) $(IFLAG)

PHONY: clean

clean:
	rm -rf obj/*.o
	rm -rf obj/test/*.o
	rm -rf bin/*
