BINPACK := bin
INCPACK := inc
SRCPACK := src
OBJPACK := obj

SRCFILES := $(wildcard src/*cpp)

#Flags
CC := g++
OPENGL 	:= -L /usr/lib/i386-linux-gnu/libGL.so -lGL -lGLU -lglut
INCFILE	:= -I./$(INCPACK)

#Target
all: solarSystem

solarSystem: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) obj/*.o -o bin/$@ $(OPENGL) $(INCFILE)

obj/%.o: src/%.cpp
	$(CC) -c $< -o $@ $(OPENGL) $(INCFILE)

clean:
	rm -f obj/*
	rm -fr bin/*
	cp other/earth.raw bin/
