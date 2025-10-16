#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"


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
        case SHAPE_POLYGONE:
            free_elements_in_liste(shape->union_shape.polygone);
        break;
        default :
            printf("Une erreur est survenue");
            break;
        }
        free(shape);
}


ellipse_t *create_ellipse() {
    printf ("\nVeuillez préciser les informations concernant votre ellipse.\n"
        "(coordo x du point central / coordo y du point central"
        " / rayon en x / rayon en y / couleurs en rgba)\n\n"
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
    
    ellipse->color.stroke.r = ask_color("couleur de trait en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    ellipse->color.fill.r = ask_color("couleur de fond en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    ellipse->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");

    printf("Votre ellipse aura un centre de coordonnées : x = %d / y = %d,"
        " un rayon x = %dpx, un rayon y = %dpx, \nune couleur de trait = rgba(%d,%d,%d,0.%d)"
        " et une couleur de fond = rgba(%d,%d,%d,0.%d).\n\n", 
        ellipse->coordo_center_x,
        ellipse->coordo_center_y,
        ellipse->rayon_x,
        ellipse->rayon_y,
        ellipse->color.stroke.r,
        ellipse->color.stroke.g,
        ellipse->color.stroke.b,
        ellipse->color.stroke.a,
        ellipse->color.fill.r,
        ellipse->color.fill.g,
        ellipse->color.fill.b,
        ellipse->color.fill.a
    );

    return ellipse;
}


void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


rect_t *create_rect() {
    printf ("\nVeuillez préciser les informations concernant votre rectangle.\n"
        " (coordo x du premier point / coordo y du premier point"
        " / largeur / hauteur / couleurs en rgba)\n\n");
    
    rect_t *rect = malloc(sizeof(rect_t));

    rect->coordo_start_x = ask_for_unsigned_int("coordo x: ",
        "Merci d'entrer un nombre entier.");
    rect->coordo_start_y = ask_for_unsigned_int("coordo y: ",
        "Merci d'entrer un nombre entier.");
    rect->width = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    rect->height = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");
    rect->color.stroke.r = ask_color("couleur de trait en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    rect->color.fill.r = ask_color("couleur de fond en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    rect->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");

    printf("Votre rectangle aura son premier point aux coordonnées : x = %d / y = %d,"
        " une largeur de %dpx, une hauteur de %dpx, \nune couleur de trait = rgba(%d,%d,%d,0.%d)"
        " et une couleur de fond = rgba(%d,%d,%d,0.%d).\n\n", 
        rect->coordo_start_x,
        rect->coordo_start_y,
        rect->width,
        rect->height,
        rect->color.stroke.r,
        rect->color.stroke.g,
        rect->color.stroke.b,
        rect->color.stroke.a,
        rect->color.fill.r,
        rect->color.fill.g,
        rect->color.fill.b,
        rect->color.fill.a
    );
    
    return rect;
}


void free_rect(rect_t *rect) {
    free(rect);
}


line_t *create_line() {
    printf ("\nVeuillez préciser les informations concernant votre ligne.\n"
        " (x du premier point / y du premier point / x du deuxieme point"
        " / y du deuxieme point / couleur en rgba)\n\n"
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
    line->color.stroke.r = ask_color("couleur de trait en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    line->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    line->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    line->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");

    printf("Votre ligne aura son premier point aux coordonnées : x = %d / y = %d,"
        " son deuxieme point aux coordonnées : x = %d / y = %d et\n"
        " une couleur de trait = rgba(%d,%d,%d,0.%d).\n\n", 
        line->coordo_start_x,
        line->coordo_start_y,
        line->coordo_end_x,
        line->coordo_end_y,
        line->color.stroke.r,
        line->color.stroke.g,
        line->color.stroke.b,
        line->color.stroke.a
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
    printf ("\nVeuillez préciser les informations concernant votre polyline.\n"
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

    liste->color.stroke.r = ask_color("couleur de trait en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");

    printf("\nVotre polyline aura %d points.\n\n", liste->length);

    return liste;
}


liste_t *create_polygone() {
    printf ("\nVeuillez préciser les informations concernant votre polygone.\n"
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
            "Voulez-vous ajouter un point à votre polygone ? (1: oui / 2: non)\n",
            "Merci d'entrer 1 ou 2.",
            1,
            2
        );
    } while (choice_user == 1);

    liste->color.stroke.r = ask_color("couleur de trait en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    liste->color.fill.r = ask_color("couleur de fond en rgba (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    liste->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");

    printf("\nVotre polygone aura %d points.\n\n", liste->length);

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