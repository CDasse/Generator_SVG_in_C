CC = gcc
FLAGS = -std=c99 -Wall -Wextra -Werror

build:
	$(CC) $(FLAGS) -c main.c 
	$(CC) $(FLAGS) -c functions.c 
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c cli.c
	$(CC) $(FLAGS) main.o functions.o shapes.o cli.o -o bin/main

	rm main.o
	rm functions.o
	rm cli.o
	rm shapes.o

clean:
	rm bin/*