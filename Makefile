CC = gcc
INCLUDES = -I /ficheiros_h
O_FILES = ficheiros_o
C_FILES = ficheiros_c
H_FILES = ficheiros_h
CFLAGS = -g -Wall -I$(H_FILES)

default: compile

clean:
	rm -f *.o


test_data: test_data.o data.o
	$(CC) $(CFLAGS) -o test_data $(O_FILES)/test_data.o $(O_FILES)/data.o

test_entry: test_entry.o data.o entry.o
	$(CC) $(CFLAGS) -o test_entry $(O_FILES)/test_entry.o $(O_FILES)/data.o $(O_FILES)/entry.o

test_list: test_list.o list.o
	$(CC) $(CFLAGS) -o test_entry $(O_FILES)/test_entry.o $(O_FILES)/data.o $(O_FILES)/entry.o

compile: main.o data.o entry.o list.o
	$(CC) -o projecto_1 ficheiros_o/main.o ficheiros_o/data.o ficheiros_o/entry.o ficheiros_o/list.o $(CFLAGS)



test_data.o: $(C_FILES)/test_data.c $(H_FILES)/data.h
	$(CC) $(CFLAGS) -c $(C_FILES)/test_data.c -o $(O_FILES)/test_data.o

test_entry.o: $(C_FILES)/test_entry.c $(H_FILES)/data.h
	$(CC) $(CFLAGS) -c $(C_FILES)/test_entry.c -o $(O_FILES)/test_entry.o

test_list.o: $(C_FILES)/test_list.c $(H_FILES)/list.h
	$(CC) $(CFLAGS) -c $(C_FILES)/test_entry.c -o $(O_FILES)/test_entry.o

data.o: $(C_FILES)/data.c $(H_FILES)/data.h
	$(CC) $(CFLAGS) -c $(C_FILES)/data.c -o $(O_FILES)/data.o

entry.o: $(C_FILES)/entry.c $(H_FILES)/data.h $(H_FILES)/entry.h
	$(CC) $(CFLAGS) -c $(C_FILES)/entry.c -o $(O_FILES)/entry.o

list.o: $(C_FILES)/list.c $(H_FILES)/list-private.h $(H_FILES)/list.h
	$(CC) $(CFLAGS) -c ficheiros_c/list.c -o $(O_FILES)/list.o

main.o: main.c data.h entry.h list.h
	$(CC) -c ficheiros_c/main.c $(CFLAGS)
