SRCDIR := src
INCDIR := include
BINDIR := bin
OBJDIR := obj

SRCFILES := $(shell find -name '*.cpp' -printf '%P ')
OBJFILES := $(notdir $(SRCFILES))

SDLFLAGS := `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL_image
CXX := g++
#CXXFLAGS := -g -std=c++11 -Wall -pedantic -Weffc++
CXXFLAGS := -g -std=c++11 -Wall -pedantic
GAMEKIOSKFLAGS := $(SDLFLAGS) -I./$(INCDIR)/window -I./$(INCDIR) -I./$(INCDIR)/widget -I./$(INCDIR)/layout

program_OBJS := $(foreach SUBDIRS, -I./, $(SUBDIRS))

all: prepare main

main:
	$(CXX) $(CXXFLAGS) $(SRCFILES) -o $(BINDIR)/$@ $(GAMEKIOSKFLAGS)

.PHONY: clean, prepare

prepare:
	mkdir -p $(BINDIR)
	mkdir -p $(OBJDIR)
	cp -r fonts/ bin/

clean:
	mv $(BINDIR)* /tmp
	mv $(OBJDIR)* /tmp
