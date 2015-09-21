CC=gcc
CFLAGS= -g -Wall


test_data: test_data.o data.o
	$(CC) -o test_data test_data.o data.o

test_entry: test_entry.o data.o entry.o
	$(CC) -o test_entry test_entry.o data.o entry.o

test_list: test_list.o list.o entry.o data.o
	$(CC) -o test_list test_list.o list.o entry.o data.o


compile: main.o data.o entry.o list.o
	gcc -o projecto_1 main.o data.o entry.o list.o

main.o: main.c data.h entry.h list.h
	gcc -c main.c

data.o: data.c data.h
	gcc -c data.c

entry.o: entry.c data.h entry.h
	gcc -c entry.c

list.o: list.c list-private.h list.h
	gcc -c list.c