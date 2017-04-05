CFLAGS := `apr-1-config --cflags` -std=gnu99 -Wall
CPPFLAGS := `apr-1-config --cppflags`
LINK := `apr-1-config --link-ld`
INCLUDES := `apr-1-config --includes`
CC := gcc

all:
	$(CC)  main.c -o main $(CFLAGS) $(CPPFLAGS) $(LINK) $(INCLUDES)
