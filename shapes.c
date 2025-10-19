#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"


viewbox_t *create_viewbox() {
    printf("Pour commencer, veuillez preciser la dimension "
        "de votre \033[32mfenetre de visualisation\033[0m.\n"
        "(la largeur puis la hauteur en pixels)\n\n");

    viewbox_t *viewbox = malloc(sizeof(viewbox_t));

    viewbox->coordo_min_x = 0;
    viewbox->coordo_min_y = 0;
    viewbox->width = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    viewbox->height = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre \033[32mfenetre de visualisation\033[0m aura une largeur "
        "de \033[32m%upx\033[0m et une hauteur de \033[32m%upx\033[0m.\n\n", 
        viewbox->width,
        viewbox->height
    );

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    return viewbox;
}


array_t *create_array() {
    array_t *array = malloc(sizeof(array_t));
    array->index = 0;

    initialize_array(array);
    
    return array;
}


void initialize_array(array_t *array) {
    for (int i = 0; i < 40; i++) {
        array->table[i] = NULL;
    }
}