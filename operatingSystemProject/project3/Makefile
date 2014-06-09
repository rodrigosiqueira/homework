INC := inc
SRC := src
BIN := bin
OBJ	:= obj

CC := gcc -Wall
FUSEFLAG := `pkg-config fuse --cflags --libs`

CSOURCE = $(wildcard src/*c)

all: ospFilesystem

ospFilesystem: $(CSOURCE:src/%.c=obj/%.o)
	$(CC) obj/*.o $(FUSEFLAG)-o bin/$@ -I./inc

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(FUSEFLAG) -I./inc

.PHONY: clean

clean:
	rm -rf bin/*
	fusermount -u temp
	mkdir bin/temp
