#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "creation_rectangle.h"
#include "cli.h"


void rect_for_creation(array_t *array) {
    rect_t *new_rectangle = create_rect();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.rectangle = new_rectangle;
    my_struc->enum_shape = SHAPE_RECTANGLE;

    array->table[array->index] = my_struc;
    array->index++;
}


rect_t *create_rect() {
    system("clear");

    printf ("Veuillez preciser les informations concernant votre "
        "\033[32mrectangle\033[0m.\n"
        "(coordo x du premier point / coordo y du premier point"
        " / largeur / hauteur / couleurs en rgba / angle de rotation)\n\n");
    
    rect_t *rect = malloc(sizeof(rect_t));

    printf("\n\033[32mCOORDONNEES\033[0m\n");
    rect->coordo_start_x = ask_for_unsigned_int("- Coordo x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->coordo_start_y = ask_for_unsigned_int("- Coordo y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->width = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->height = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\n\033[32mCOULEURS\033[0m\n");
    rect->color.stroke.r = ask_color("- Couleur de trait en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    rect->color.fill.r = ask_color("\n- Couleur de fond en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[32mANGLE\033[0m\n");
    rect->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre rectangle aura son premier point aux coordonnees : x ="
        " \033[32m%d\033[0m / y = \033[32m%d\033[0m,"
        " une largeur de \033[32m%dpx\033[0m, une hauteur de \033[32m%dpx"
        "\033[0m, \nune couleur de trait = \033[32mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[32mrgba(%d,%d,%d,0.%d)\033[0m et un angle "
        "= \033[32m%d°\033[0m.\n\n", 
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
        rect->color.fill.a,
        rect->angle
    );
    
    return rect;
}