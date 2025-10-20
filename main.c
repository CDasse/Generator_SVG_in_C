#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"
#include "free_malloc.h"


int main(void) {

    system("clear");
    
    printf("\e[1m\033[34mBienvenue dans cette super application "
        "de creation de SVG !!\033[0m\e[0m\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes, svg_viewbox);

    free_all(array_of_shapes, svg_viewbox);

    return 0;
}


// ATTENTION erreur de tableau dans le readme

// faire javadoc !!!!! commenter tous les types et les fonctions (dans les .h)

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! preparer l'oral  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!