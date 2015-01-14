BIN := bin/
OBJ := obj/
SRC := src/
INC := inc/

CSOURCES = $(wildcard src/*c)
CUDASOURCE = $(wildcard src/*cu)

all: dot_product

dot_product: $(CSOURCES:src/%.c=obj/%.o)
	nvcc -c src/dotProductStub.cu -o obj/dotProductStub.o -I./inc
	nvcc obj/*.o -o bin/$@ -I./inc

obj/%.o: src/%.c
	nvcc -c $< -o $@ -I./inc

clean:
	rm -rf obj/*
	rm -rf bin/*
