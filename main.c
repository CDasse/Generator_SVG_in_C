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


// supprimer point dans poly ou path ?

// ajouter fonctionnalite inversion axe x / y

// mettre les fichiers dans des sous-dossiers

// tester le code a fond !!!!!

// Faire readme !!!!!

// faire javadoc !!!!!

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! preparer l'oral  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!