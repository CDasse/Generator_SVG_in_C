CC = gcc
FLAGS = -std=c99 -Wall -Wextra -Werror

build:
	$(CC) $(FLAGS) -c main.c 
	$(CC) $(FLAGS) -c menu.c 
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c cli.c
	$(CC) $(FLAGS) -c creation_shapes.c
	$(CC) $(FLAGS) -c show_shapes.c
	$(CC) $(FLAGS) -c edition_shapes.c
	$(CC) $(FLAGS) -c save_shapes.c
	$(CC) $(FLAGS) -c remove_shapes.c
	$(CC) $(FLAGS) main.o menu.o shapes.o cli.o creation_shapes.o show_shapes.o edition_shapes.o save_shapes.o remove_shapes.o -o bin/main

	rm main.o
	rm menu.o
	rm cli.o
	rm shapes.o
	rm creation_shapes.o
	rm show_shapes.o
	rm edition_shapes.o
	rm save_shapes.o
	rm remove_shapes.o

clean:
	rm bin/*