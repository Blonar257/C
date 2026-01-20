CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o
    $(CC) $(LDFLAGS) -o main main.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c