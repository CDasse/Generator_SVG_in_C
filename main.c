#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "cli.h"
#include "functions.h"



int main(void) {
    
    printf("\nBienvenue dans cette super application de création de SVG !!\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes, svg_viewbox);

    return 0;
}



// mettre le code sur plusieurs ligne pour qu'il ne soit pas trop long  (alt-z)

// utiliser les fonction free malloc !!!!!!!!!!!!!!!!!

// Faire readme !!!!!

// faire javadoc !!!!

// tableau a allocation dynamique

// verifier les .h que toutes les fonctions soient bien presentes

// faire des fonctions plus petites !!
