#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "functions.h"


int main(void) {
    
    printf("\nBienvenue dans cette super application de création de SVG !!\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes, svg_viewbox);

    free_all(array_of_shapes, svg_viewbox);

    return 0;
}



// mettre le code sur plusieurs ligne pour qu'il ne soit pas trop long  (alt-z)

// Faire readme !!!!!

// faire javadoc !!!!

// verifier les .h que toutes les fonctions soient bien presentes

// faire des fonctions plus petites !!
