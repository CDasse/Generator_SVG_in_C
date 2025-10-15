#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"


int main(void) {
    
    printf("\nBienvenue dans cette super application de création de SVG !!\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes, svg_viewbox);

    free_all(array_of_shapes, svg_viewbox);

    return 0;
}


// ajouter fonctionnalite couleur ??

// tester le code a fond !!!!!

// Faire readme !!!!!

// faire javadoc !!!!