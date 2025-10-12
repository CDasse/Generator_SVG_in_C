#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "functions.h"


void menu_for_user (array_t array[]) {
    user_menu_choice_t choice_menu = ask_for_int_in_range_1_to_3("Que voulez-vous faire ?\n"
    "(1: creation / 2: edition / 3: visualisation)\n", "Merci d'entrer un nombre entre 1 et 3.");
    
    switch (choice_menu)
    {
    case CHOICE_CREATION:
        choice_shape_for_creation (array);
        break;
    case CHOICE_EDITION:
        printf("Désolée, cette fonction n'existe pas encore. Wait and see ;)\n\n");
    break;
    case CHOICE_VISUALISATION:
        printf("Désolée, cette fonction n'existe pas encore. Wait and see ;-)\n\n");
    break;
    default:
        printf("Erreur dans votre choix de menu");
        break;
    }
}


void choice_shape_for_creation (array_t array[]) {
    user_shape_choice_t choice_shape = ask_for_int_in_range_1_to_3("Quelle forme voulez-vous realiser ?\n"
    "(1: ellipse / 2: rectangle / 3: ligne)\n", "Merci d'entrer un nombre entre 1 et 3.");

    switch (choice_shape) {
    case CHOICE_ELLIPSE:
        ellipse_for_creation(array);
    break;
    case CHOICE_RECTANGLE:
        rect_for_creation(array);
    break;
    case CHOICE_LINE:
        line_for_creation(array);
    break;
    default:
    printf("Une erreur est survenue");
        break;
    }

    menu_for_user(array);
}



void ellipse_for_creation(array_t array[]) {
    ellipse_t *ellipse = create_ellipse();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.ellipse = ellipse;
    my_struc->enum_shape = SHAPE_ELLIPSE;

    array->table[array->index] = my_struc;
    array->index++;
}


void rect_for_creation(array_t array[]) {
    rect_t *rectangle = create_rect();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.rectangle = rectangle;
    my_struc->enum_shape = SHAPE_RECTANGLE;

    array->table[array->index] = my_struc;
    array->index++;
}


void line_for_creation(array_t array[]) {
    line_t *line = create_line();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.line = line;
    my_struc->enum_shape = SHAPE_LINE;

    array->table[array->index] = my_struc;
    array->index++;
}


char *get_shape_type(shape_type_enum_t type) {
    switch (type) {
        case SHAPE_ELLIPSE:
        return "ELLIPSE";
        case SHAPE_RECTANGLE:
        return "RECTANGLE";
        case SHAPE_LINE:
        return "LIGNE";
        default:
        return "Forme inconnue";
    }
}


void show_shapes_in_table(array_t array[]) {

    for (int i = 0; i < array->index; i++) {
        shape_struct_t *shape = array->table[i];

        switch (shape->enum_shape) {
        case SHAPE_ELLIPSE:
            printf("[%d] %s / coordo centre: %d/%d, rayons: %dpx/%dpx\n",
            i,
            get_shape_type(shape->enum_shape),
            shape->union_shape.ellipse->coordo_center_x,
            shape->union_shape.ellipse->coordo_center_y,
            shape->union_shape.ellipse->rayon_x,
            shape->union_shape.ellipse->rayon_y);
        break;

        case SHAPE_RECTANGLE:
            printf("[%d] %s coordo premier point: %d/%d, largeur: %dpx, hauteur: %dpx\n",
            i,
            get_shape_type(shape->enum_shape),
            shape->union_shape.rectangle->coordo_start_x,
            shape->union_shape.rectangle->coordo_start_y,
            shape->union_shape.rectangle->width,
            shape->union_shape.rectangle->height);
        break;

        case SHAPE_LINE:
            printf("[%d] %s coordo premier point: %d/%d, coordo deuxieme point: %d/%d\n",
            i,
            get_shape_type(shape->enum_shape),
            shape->union_shape.line->coordo_start_x,
            shape->union_shape.line->coordo_start_y,
            shape->union_shape.line->coordo_end_x,
            shape->union_shape.line->coordo_end_y);
        break;

        default:
            printf("Forme inconnue.\n");
        break;
        }
    }
}

void choice_shape_for_edition(array_t array[]) {
    printf("Quelle forme voulez-vous modifier ?");
    show_shapes_in_table(array);

    // switch avec choix
    // free shape d'indice choix
    //ajouter dans l'option 2 de menu for user
}