#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "show_shapes.h"
#include "edition_shapes.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox) {
    if (array->index == 0) {
        printf("Aucune forme n'est creee! \n\n");
    } else {
        show_shapes_in_table(array);
        int choice_user_edition = ask_for_int_in_table("\nQuelle forme voulez-vous modifier"
            "(indiquer son index) ?\n", "Merci d'entrer un index valide.", array);

        if (array->table[choice_user_edition] == NULL) {
            printf("Cette forme a ete supprimee.\n");
            menu_for_user(array, viewbox);
            return;
        }
    
        switch (array->table[choice_user_edition]->enum_shape) {
            case SHAPE_ELLIPSE:
                edition_ellipse_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_RECTANGLE:
                edition_rectangle_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_LINE:
                edition_line_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_POLYLINE:
                edition_polyline_in_table(array->table[choice_user_edition]);
            break;
            default:
                printf("Forme inconnue.\n");
            break;
        }
    }

    menu_for_user(array, viewbox);
}


void edition_ellipse_in_table(shape_struct_t *shape) {
    shape->union_shape.ellipse->coordo_center_x = ask_for_unsigned_int("coordo centre x: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->coordo_center_y = ask_for_unsigned_int("coordo centre y: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->rayon_x = ask_for_unsigned_int("rayon x: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->rayon_y = ask_for_unsigned_int("rayon y: ",
    "Merci d'entrer un nombre entier.");

    printf("Votre nouvelle ellipse aura un centre de coordonnees : x = %d / y = %d,"
    " un rayon x = %dpx et un rayon y = %dpx.\n\n", 
    shape->union_shape.ellipse->coordo_center_x, shape->union_shape.ellipse->coordo_center_y,
    shape->union_shape.ellipse->rayon_x, shape->union_shape.ellipse->rayon_y);
}


void edition_rectangle_in_table(shape_struct_t *shape) {
    shape->union_shape.rectangle->coordo_start_x = ask_for_unsigned_int("coordo x: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->coordo_start_y = ask_for_unsigned_int("coordo y: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->width = ask_for_unsigned_int("largeur: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->height = ask_for_unsigned_int("hauteur: ",
    "Merci d'entrer un nombre entier.");

    printf("Votre nouveau rectangle aura son premier point aux coordonnees : x = %d / y = %d,"
    " une largeur de %dpx et une hauteur de %dpx.\n\n", 
    shape->union_shape.rectangle->coordo_start_x, shape->union_shape.rectangle->coordo_start_y,
    shape->union_shape.rectangle->width, shape->union_shape.rectangle->height);
}


void edition_line_in_table(shape_struct_t *shape) {
    shape->union_shape.line->coordo_start_x = ask_for_unsigned_int("coordo x: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_start_y = ask_for_unsigned_int("coordo y: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_end_x = ask_for_unsigned_int("largeur: ",
    "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_end_y = ask_for_unsigned_int("hauteur: ",
    "Merci d'entrer un nombre entier.");

    printf("Votre nouvelle ligne aura son premier point aux coordonnees : x = %d / y = %d,"
    " et son deuxieme point aux coordonnees : x = %d / y = %d.\n\n", 
    shape->union_shape.line->coordo_start_x, shape->union_shape.line->coordo_start_y,
    shape->union_shape.line->coordo_end_x, shape->union_shape.line->coordo_end_y);
}


void edition_polyline_in_table(shape_struct_t *shape) {
    list_element_t *element = get_position_in_polyline(shape->union_shape.polyline);

    element->value1 = ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier.");
    element->value2 = ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.");
}


list_element_t *get_position_in_polyline(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("Quel point souhaitez vous modifier ?\n",
    "Merci d'entrer un index correct.", liste);

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}