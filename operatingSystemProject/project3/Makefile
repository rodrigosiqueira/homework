INC := inc
SRC := src
BIN := bin
OBJ	:= obj

CC := gcc -Wall
FUSEFLAG := `pkg-config fuse --cflags --libs`

CSOURCE = $(wildcard src/*c)

all: ospFilesystem

ospFilesystem: $(CSOURCE)
	$(CC) $< $(FUSEFLAG)-o bin/$@ -I./inc

.PHONY: clean

clean:
	rm -rf bin/*
