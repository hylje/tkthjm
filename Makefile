CC=gcc
CFLAGS = -std=c99 -Wextra -Werror -pedantic -Wall -g -O1

build: main.o functions.o avl_tree.o # new object names here
	$(CC) $(CFLAGS) main.o functions.o avl_tree.o -o tkthjm
avl_test: avl_test.o avl_tree.o
	$(CC) $(CFLAGS) avl_test.o avl_tree.o -o avl_test
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c
avl_tree.o: avl_tree.c avl_tree.h
	$(CC) $(CFLAGS) -c avl_tree.c
avl_test.o: avl_test.c
	$(CC) $(CFLAGS) -c avl_test.c
# add new source files to create new objects