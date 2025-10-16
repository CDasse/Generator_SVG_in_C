#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"


int main(void) {

    system("clear");
    
    printf("\nBienvenue dans cette super application de création de SVG !!\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes, svg_viewbox);

    free_all(array_of_shapes, svg_viewbox);

    return 0;
}


// system("clear"); ajouter des ("voulez-vous continuer" scanf(1:oui))

// tester le code a fond !!!!!

// Faire readme !!!!!

// faire javadoc !!!!!