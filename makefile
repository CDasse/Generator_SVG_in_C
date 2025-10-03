CC = gcc
FLAGS = -std=c99 -Wall -Wextra -Werror

build:
	$(CC) $(FLAGS) main.c -o bin/main

clean:
	rm bin/