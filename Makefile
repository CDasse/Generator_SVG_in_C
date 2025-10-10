CC = gcc
FLAGS = -std=c99 -Wall -Wextra -Werror

build:
	$(CC) $(FLAGS) -c main.c 
	$(CC) $(FLAGS) -c models.c
	$(CC) $(FLAGS) -c cli.c
	$(CC) $(FLAGS) main.o models.o cli.o -o bin/main

	rm main.o
	rm cli.o
	rm models.o

clean:
	rm bin/*