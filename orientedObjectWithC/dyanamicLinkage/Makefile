INCFOLDER := inc/
SRCFOLDER := src/
BINFOLDER := bin/
OBJFOLDER := obj/

CSOURCES := $(wildcard src/*.c)

all: stringBin

stringBin: $(CSOURCES:src/%.c=obj/%.o)
	$(CC) obj/*.o -o bin/$@ -I./inc

obj/%.o: src/%.c
	$(CC) -c $< -o $@ -I./inc
	
clean:
	rm -rf obj/*
	rm -rf bin/*
