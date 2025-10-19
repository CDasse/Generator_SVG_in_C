CC = gcc
FLAGS = -std=c99 -Wall -Wextra -Werror -Iinclude

build:
	$(CC) $(FLAGS) -c main.c 
	$(CC) $(FLAGS) -c menu.c 
	$(CC) $(FLAGS) -c menu_creation.c 
	$(CC) $(FLAGS) -c menu_edition.c 
	$(CC) $(FLAGS) -c menu_remove.c
	$(CC) $(FLAGS) -c menu_save.c
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c cli.c
	$(CC) $(FLAGS) -c creation_ellipse.c
	$(CC) $(FLAGS) -c creation_rectangle.c
	$(CC) $(FLAGS) -c creation_line.c
	$(CC) $(FLAGS) -c creation_polyline.c
	$(CC) $(FLAGS) -c creation_polygone.c
	$(CC) $(FLAGS) -c creation_path.c
	$(CC) $(FLAGS) -c show_shapes.c
	$(CC) $(FLAGS) -c edition_ellipse.c
	$(CC) $(FLAGS) -c edition_rectangle.c
	$(CC) $(FLAGS) -c edition_line.c
	$(CC) $(FLAGS) -c edition_polyline.c
	$(CC) $(FLAGS) -c edition_polygone.c
	$(CC) $(FLAGS) -c edition_path.c
	$(CC) $(FLAGS) -c save_shapes.c
	$(CC) $(FLAGS) -c free_malloc.c
	$(CC) $(FLAGS) main.o menu.o menu_creation.o menu_edition.o menu_remove.o menu_save.o shapes.o cli.o creation_ellipse.o creation_rectangle.o creation_line.o creation_polyline.o creation_polygone.o creation_path.o show_shapes.o edition_ellipse.o edition_rectangle.o edition_line.o edition_polyline.o edition_polygone.o edition_path.o save_shapes.o free_malloc.o -o bin/main

	rm main.o
	rm menu.o
	rm menu_creation.o
	rm menu_edition.o
	rm menu_remove.o
	rm menu_save.o
	rm cli.o
	rm shapes.o
	rm creation_ellipse.o
	rm creation_rectangle.o
	rm creation_line.o
	rm creation_polyline.o
	rm creation_polygone.o
	rm creation_path.o
	rm show_shapes.o
	rm edition_ellipse.o
	rm edition_rectangle.o
	rm edition_line.o
	rm edition_polyline.o
	rm edition_polygone.o
	rm edition_path.o
	rm save_shapes.o
	rm free_malloc.o

clean:
	rm bin/*


valgrind:

	valgrind --leak-check=full --show-reachable=no ./bin/main