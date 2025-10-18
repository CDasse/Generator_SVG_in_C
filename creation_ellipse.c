#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "creation_ellipse.h"
#include "cli.h"


void ellipse_for_creation(array_t *array) {
    ellipse_t *new_ellipse = create_ellipse();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.ellipse = new_ellipse;
    my_struc->enum_shape = SHAPE_ELLIPSE;

    array->table[array->index] = my_struc;
    array->index++;
}


ellipse_t *create_ellipse() {
    system("clear");

    printf ("Veuillez preciser les informations concernant votre "
        "\033[33mellipse\033[0m.\n"
        "(coordo x-y du point central / rayon en x / rayon en y /"
        " couleurs en rgba / angle de rotation)\n\n"
    );

    ellipse_t *ellipse = malloc(sizeof(ellipse_t));

    printf("\n\033[33mCOORDONNEES\033[0m\n");
    ellipse->coordo_center_x = ask_for_unsigned_int("- Coordo centre x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->coordo_center_y = ask_for_unsigned_int("- Coordo centre y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->rayon_x = ask_for_unsigned_int("- Rayon x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->rayon_y = ask_for_unsigned_int("- Rayon y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    
    printf("\n\033[33mCOULEURS\033[0m\n");
    ellipse->color.stroke.r = ask_color("- Couleur de trait en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    ellipse->color.fill.r = ask_color("\n- Couleur de fond en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[33mANGLE\033[0m\n");
    ellipse->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre \033[33mellipse\033[0m aura un centre de coordonnees : "
        "x = \033[33m%d\033[0m / y = \033[33m%d\033[0m,"
        " un rayon x = \033[33m%dpx\033[0m, un rayon y = \033[33m%dpx\033[0m, "
        "\nune couleur de trait = \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[33mrgba(%d,%d,%d,0.%d)\033[0m et un angle "
        "= \033[33m%d°\033[0m.\n\n", 
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
        ellipse->color.fill.a,
        ellipse->angle
    );

    return ellipse;
}