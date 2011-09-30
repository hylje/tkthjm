CC=gcc
CFLAGS = -std=c99 -Wextra -Werror -pedantic -Wall -g -O1

build: main.o functions.o # new object names here
	$(CC) $(CFLAGS) main.o functions.o -o exercise1
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
# add new source files to create new objects
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c