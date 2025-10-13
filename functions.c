#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "functions.h"


void menu_for_user (array_t array[], viewbox_t *viewbox) {
    user_menu_choice_t choice_menu = ask_for_int_in_range_1_to_5("Que voulez-vous faire ?\n"
    "(1: creation / 2: edition / 3: suppression / 4: sauvegarde / 5: quitter)\n", "Merci d'entrer un nombre entre 1 et 5.");
    
    switch (choice_menu)
    {
    case CHOICE_CREATION:
        choice_shape_for_creation (array, viewbox);
        break;
    case CHOICE_EDITION:
        choice_shape_for_edition (array, viewbox);
    break;
    case CHOICE_REMOVE:
        choice_shape_for_remove(array, viewbox);
    break;
    case CHOICE_SAVE:
        save_projet (array, viewbox);
    break;
    case CHOICE_EXIT:
        printf("Merci d'avoir utilisé l'application.\nA bientot !\n");
    break;
    default:
        printf("Erreur dans votre choix de menu");
        break;
    }
}


void choice_shape_for_creation (array_t array[], viewbox_t *viewbox) {
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

    menu_for_user(array, viewbox);
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
            printf("[%d] Forme supprimée.\n", i);
        break;
        }
    }
}

void choice_shape_for_edition(array_t array[], viewbox_t *viewbox) {
    show_shapes_in_table(array);
    int choice_user_edition = ask_for_int_in_table("Quelle forme voulez-vous modifier (indiquer son index) ?\n", "Merci d'entrer un index valide.", array);
    shape_struct_t *shape = array->table[choice_user_edition];

    switch (shape->enum_shape) {
        case SHAPE_ELLIPSE:
            shape->union_shape.ellipse->coordo_center_x = ask_for_unsigned_int("coordo centre x: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.ellipse->coordo_center_y = ask_for_unsigned_int("coordo centre y: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.ellipse->rayon_x = ask_for_unsigned_int("rayon x: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.ellipse->rayon_y = ask_for_unsigned_int("rayon y: ", "Merci d'entrer un nombre entier.");

            printf("Votre nouvelle ellipse aura un centre de coordonnées : x = %d / y = %d,"
            " un rayon x = %dpx et un rayon y = %dpx.\n\n", 
            shape->union_shape.ellipse->coordo_center_x, shape->union_shape.ellipse->coordo_center_y, shape->union_shape.ellipse->rayon_x, shape->union_shape.ellipse->rayon_y);
        break;

        case SHAPE_RECTANGLE:
            shape->union_shape.rectangle->coordo_start_x = ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.rectangle->coordo_start_y = ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.rectangle->width = ask_for_unsigned_int("largeur: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.rectangle->height = ask_for_unsigned_int("hauteur: ", "Merci d'entrer un nombre entier.");

            printf("Votre rectangle aura son premier point aux coordonnées : x = %d / y = %d,"
            " une largeur de %dpx et une hauteur de %dpx.\n\n", 
            shape->union_shape.rectangle->coordo_start_x, shape->union_shape.rectangle->coordo_start_y, shape->union_shape.rectangle->width, shape->union_shape.rectangle->height);
        break;

        case SHAPE_LINE:
            shape->union_shape.line->coordo_start_x = ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.line->coordo_start_y = ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.line->coordo_end_x = ask_for_unsigned_int("largeur: ", "Merci d'entrer un nombre entier.");
            shape->union_shape.line->coordo_end_y = ask_for_unsigned_int("hauteur: ", "Merci d'entrer un nombre entier.");

            printf("Votre ligne aura son premier point aux coordonnées : x = %d / y = %d,"
            " et son deuxieme point aux coordonnées : x = %d / y = %d.\n\n", 
            shape->union_shape.line->coordo_start_x, shape->union_shape.line->coordo_start_y, shape->union_shape.line->coordo_end_x, shape->union_shape.line->coordo_end_y);
        break;

        default:
            printf("Forme inconnue.\n");
        break;
        }

    menu_for_user(array, viewbox);
}


void choice_shape_for_remove(array_t array[], viewbox_t *viewbox) {
    show_shapes_in_table(array);
    int choice_user_remove = ask_for_int_in_table("Quelle forme voulez-vous supprimer (indiquer son index) ?\n", "Merci d'entrer un index valide.", array);

    shape_struct_t *shape = array->table[choice_user_remove];
    free_shape_in_table(shape);

    shape = NULL;
    menu_for_user(array, viewbox);
}


void save_projet (array_t array[], viewbox_t *viewbox) {

    char end_viewbox[] = "\n</svg>";

    FILE *saved_file = fopen("projet.svg", "w");

    fprintf(saved_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        viewbox->width, viewbox->height);
    
    for (int i = 0; i < array->index; i++) {
        shape_struct_t *shape = array->table[i];

    switch (shape->enum_shape) {
        case SHAPE_ELLIPSE:
            fprintf(saved_file,"<ellipse cx='%d' cy='%d' rx='%d' ry='%d' fill='#ff000080' />",
            shape->union_shape.ellipse->coordo_center_x, shape->union_shape.ellipse->coordo_center_y,
            shape->union_shape.ellipse->rayon_x, shape->union_shape.ellipse->rayon_y);
        break;

        case SHAPE_RECTANGLE:
            fprintf(saved_file,"<rect x='%d' y='%d' width='%d' height='%d' fill='#00ff0080' />",
            shape->union_shape.rectangle->coordo_start_x, shape->union_shape.ellipse->coordo_center_y,
            shape->union_shape.rectangle->width, shape->union_shape.rectangle->height);
        break;

        case SHAPE_LINE:
            fprintf(saved_file,"<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='#0000ff80' />",
            shape->union_shape.line->coordo_start_x, shape->union_shape.line->coordo_start_y,
            shape->union_shape.line->coordo_end_x, shape->union_shape.line->coordo_end_y);
        break;

        default:
        break;
        }
    }
    
    fprintf(saved_file, "%s", end_viewbox);
    
    fclose(saved_file);

    printf("Vous pouvez maintenant ouvrir votre sauvegarde projet.svg dans vos fichiers.\n");

    menu_for_user(array, viewbox);
}