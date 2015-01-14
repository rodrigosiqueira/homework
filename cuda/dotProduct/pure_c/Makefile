BIN := bin/
OBJ := obj/
SRC := src/
INC := inc/

CSOURCES = $(wildcard src/*c)

all: dot_product

dot_product: $(CSOURCES:src/%.c=obj/%.o)
	gcc -Wall $^ -o bin/$@ -I./inc

obj/%.o: src/%.c
	gcc -c $< -o $@ -I./inc

clean:
	rm -rf obj/*
	rm -rf bin/*
