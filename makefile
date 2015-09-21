CC=gcc
CFLAGS= -g -Wall


test_data: test_data.o data.o
	$(CC) -o test_data test_data.o data.o $(CFLAGS)

test_entry: test_entry.o data.o entry.o
	$(CC) -o test_entry test_entry.o data.o entry.o $(CFLAGS)

test_list: test_list.o list.o entry.o data.o
	$(CC) -o test_list test_list.o list.o entry.o data.o $(CFLAGS)


compile: main.o data.o entry.o list.o
	$(CC) -o projecto_1 main.o data.o entry.o list.o $(CFLAGS)

main.o: main.c data.h entry.h list.h
	$(CC) -c main.c $(CFLAGS)

data.o: data.c data.h
	$(CC) -c data.c $(CFLAGS)

entry.o: entry.c data.h entry.h
	$(CC) -c entry.c $(CFLAGS)

list.o: list.c list-private.h list.h
	$(CC) -c list.c $(CFLAGS)

clean:
	rm -f *.o