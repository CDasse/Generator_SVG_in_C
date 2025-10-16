#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "creation_shapes.h"


void choice_shape_for_creation(array_t *array, viewbox_t *viewbox) {
    system("clear");

    user_shape_choice_t choice_shape = ask_for_int_in_range("Quelle \033[32mforme\033[0m voulez-vous realiser ?\n"
        "\n1: Ellipse\n"
        "2: Rectangle\n"
        "3: Ligne\n"
        "4: Polyline\n"
        "5: Polygone\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 5.\033[0m",
        1,
        5
    );

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
        case CHOICE_POLYLINE:
            polyline_for_creation(array);
        break;
        case CHOICE_POLYGONE:
            polygone_for_creation(array);
        break;
        default:
            printf("Une erreur est survenue");
        break;
    }

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void ellipse_for_creation(array_t *array) {
    ellipse_t *ellipse = create_ellipse();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.ellipse = ellipse;
    my_struc->enum_shape = SHAPE_ELLIPSE;

    array->table[array->index] = my_struc;
    array->index++;
}


void rect_for_creation(array_t *array) {
    rect_t *rectangle = create_rect();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.rectangle = rectangle;
    my_struc->enum_shape = SHAPE_RECTANGLE;

    array->table[array->index] = my_struc;
    array->index++;
}


void line_for_creation(array_t *array) {
    line_t *line = create_line();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.line = line;
    my_struc->enum_shape = SHAPE_LINE;

    array->table[array->index] = my_struc;
    array->index++;
}


void polyline_for_creation(array_t *array) {
    liste_t *polyline = create_polyline();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.polyline = polyline;
    my_struc->enum_shape = SHAPE_POLYLINE;

    array->table[array->index] = my_struc;
    array->index++;
}


void polygone_for_creation(array_t *array) {
    liste_t *polygone = create_polygone();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.polygone = polygone;
    my_struc->enum_shape = SHAPE_POLYGONE;

    array->table[array->index] = my_struc;
    array->index++;
}


void free_struct(shape_struct_t *struc) {
    free(struc);
}