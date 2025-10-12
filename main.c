#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "cli.h"
#include "functions.h"



int main(void) {
    
    printf("\nBienvenue dans ma super application de création de SVG !!\n\n");

    viewbox_t *svg_viewbox = create_viewbox();
    
    array_t *array_of_shapes = create_array();
    
    menu_for_user(array_of_shapes);





    char end_viewbox[] = "\n</svg>";

    FILE *my_file = fopen("test.svg", "w");

    if (fprintf(my_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        svg_viewbox->width, svg_viewbox->height) &&
    fprintf(my_file, "%s", end_viewbox) <0) {
        printf("Something went wrong");
    }
    
    fclose(my_file);
    

    return 0;
}

// system("clear");


// typedef struct style_s {
//     // creer la structure pour les couleurs RGBA
// } style_t;

// style_t *create_style(){
//     // initialiser toutes les valeurs de style
// }

// polyline et polygon est une suite de point !!!  --->  liste chainée



// mettre le code sur plusieurs ligne pour qu'il ne soit pas trop long  (alt-z)


// creer fonction pour tester valeurs entrer par l'utilisateur (uint)
// boucler une structure à fond (avec menu creer (pas possible sinon liste) / modifier / imprimer)
// appeler jerem à l'aide pour les listes
// creer des listes pour juste un type / avoir des id fixes pour les nodes
// ajouter au menu la possibilite de creer et supprimer
// ajouter les autres struct


// utiliser les fonction free malloc ??
// ATTENTION si suppression de figure, penser mettre l'index à NULL
