#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"


viewbox_t *create_viewbox() {
    printf("Pour commencer, veuillez préciser la dimension "
        "de votre fenetre de visualisation\n"
        "(la largeur puis la hauteur).\n\n");

    viewbox_t *viewbox = malloc(sizeof(viewbox_t));

    viewbox->coordo_min_x = 0;
    viewbox->coordo_min_y = 0;
    viewbox->width = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    viewbox->height = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");

    printf("Votre fenetre de visualisation aura une largeur "
        "de %upx et une hauteur de %upx.\n\n", 
        viewbox->width,
        viewbox->height
    );

    return viewbox;
}


void free_viewbox(viewbox_t *viewbox) {
    free(viewbox);
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


void free_shape_in_table(shape_struct_t *shape) {
    switch (shape->enum_shape) {
    case SHAPE_ELLIPSE:
        free_ellipse(shape->union_shape.ellipse);
    break;
    case SHAPE_RECTANGLE:
        free_rect(shape->union_shape.rectangle);
    break;
    case SHAPE_LINE:
        free_line(shape->union_shape.line);
    break;
    case SHAPE_POLYLINE:
        free_elements_in_liste(shape->union_shape.polyline);
    break;
    default :
        printf("Une erreur est survenue");
        break;
    }
    free(shape);
}


ellipse_t *create_ellipse() {
    printf ("Veuillez préciser les informations concernant votre ellipse.\n"
        "(coordo x du point central / coordo y du point central"
        " / rayon en x / rayon en y)\n\n"
    );

    ellipse_t *ellipse = malloc(sizeof(ellipse_t));

    ellipse->coordo_center_x = ask_for_unsigned_int("coordo centre x: ",
        "Merci d'entrer un nombre entier.");
    ellipse->coordo_center_y = ask_for_unsigned_int("coordo centre y: ",
        "Merci d'entrer un nombre entier.");
    ellipse->rayon_x = ask_for_unsigned_int("rayon x: ",
        "Merci d'entrer un nombre entier.");
    ellipse->rayon_y = ask_for_unsigned_int("rayon y: ",
        "Merci d'entrer un nombre entier.");

    printf("Votre ellipse aura un centre de coordonnées : x = %d / y = %d,"
        " un rayon x = %dpx et un rayon y = %dpx.\n\n", 
        ellipse->coordo_center_x,
        ellipse->coordo_center_y,
        ellipse->rayon_x,
        ellipse->rayon_y
    );

    return ellipse;
}


void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


rect_t *create_rect() {
    printf ("Veuillez préciser les informations concernant votre rectangle.\n"
        " (coordo x du premier point / coordo y du premier point"
        " / largeur / hauteur)\n\n");
    
    rect_t *rect = malloc(sizeof(rect_t));

    rect->coordo_start_x = ask_for_unsigned_int("coordo x: ",
        "Merci d'entrer un nombre entier.");
    rect->coordo_start_y = ask_for_unsigned_int("coordo y: ",
        "Merci d'entrer un nombre entier.");
    rect->width = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    rect->height = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");

    printf("Votre rectangle aura son premier point aux coordonnées : x = %d / y = %d,"
        " une largeur de %dpx et une hauteur de %dpx.\n\n", 
        rect->coordo_start_x,
        rect->coordo_start_y,
        rect->width,
        rect->height
    );
    
    return rect;
}


void free_rect(rect_t *rect) {
    free(rect);
}


line_t *create_line() {
    printf ("Veuillez préciser les informations concernant votre ligne.\n"
        " (x du premier point / y du premier point / x du deuxieme point"
        " / y du deuxieme point)\n\n"
    );
    
    line_t *line = malloc(sizeof(line_t));

    line->coordo_start_x = ask_for_unsigned_int("coordo x: ",
        "Merci d'entrer un nombre entier.");
    line->coordo_start_y = ask_for_unsigned_int("coordo y: ",
        "Merci d'entrer un nombre entier.");
    line->coordo_end_x = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    line->coordo_end_y = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");

    printf("Votre ligne aura son premier point aux coordonnées : x = %d / y = %d,"
        " et son deuxieme point aux coordonnées : x = %d / y = %d.\n\n", 
        line->coordo_start_x,
        line->coordo_start_y,
        line->coordo_end_x,
        line->coordo_end_y
    );
    
    return line;
}


void free_line(line_t *line) {
    free(line);
}


void free_all(array_t *array, viewbox_t *viewbox) {
    for (int i = 0; i < 40; i++) {
        if (array->table[i] != NULL) {
            free_shape_in_table(array->table[i]);
        }
    }
    free(array);
    free_viewbox(viewbox);
}


liste_t *create_polyline() {
    printf ("Veuillez préciser les informations concernant votre polyline.\n"
    "(coordos x des points / coordos y des points)\n\n");

    liste_t *liste = malloc(sizeof(liste_t));
    liste->length = 0;
    liste->start = NULL;

    int choice_user = 1;

    do {
        list_element_t *liste_element = malloc(sizeof(list_element_t));

        push_in_list(
            liste,
            liste_element,
            ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier."), 
            // probleme de buffering du stdout probable (affichage y avant x)
            ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.")
        );

        choice_user = ask_for_int_in_range(
            "Voulez-vous ajouter un point à votre polyline ? (1: oui / 2: non)\n",
            "Merci d'entrer 1 ou 2.",
            1,
            2
        );
    } while (choice_user == 1);

    printf("Votre polyline aura %d points.\n\n", liste->length);

    return liste;
}


void push_in_list(liste_t *list, list_element_t *element, int x, int y) {
    element->value1 = x;
    element->value2 = y;
    element->next = NULL;
    list->length++;

    list_element_t *cursor = list->start;
    if (cursor == NULL) {
        list->start = element;
        return;
    }

    while (cursor->next != NULL) {
        cursor = cursor->next;
    }

    cursor->next = element;
}


void free_liste(liste_t *liste) {
    free(liste);
}


void free_element(list_element_t *element) {
    free(element);
}


void free_elements_in_liste(liste_t *liste) {
    list_element_t *element = liste->start;
    list_element_t *temp = NULL;

    while (element != NULL) {
        temp = element->next;
        free(element);
        element = temp;
    }

    free_liste(liste);
}