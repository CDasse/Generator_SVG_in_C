#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "edition_ellipse.h"


void edition_ellipse_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: Les couleurs\n"
        "3: Deplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    choice_edition_ellipse(shape, choice_edition_user);

    printf("\nVotre nouvelle \033[33mellipse\033[0m aura un centre de coordonnees"
        " : x = \033[33m%d\033[0m / y = \033[33m%d\033[0m,"
        " un rayon x = \033[33m%dpx\033[0m, un rayon y = \033[33m%dpx\033[0m\n"
        "une couleur de trait = \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[33mrgba(%d,%d,%d,0.%d)\033[0m"
        " et un angle = \033[33m%d°\033[0m.\n\n", 
        shape->union_shape.ellipse->coordo_center_x,
        shape->union_shape.ellipse->coordo_center_y,
        shape->union_shape.ellipse->rayon_x,
        shape->union_shape.ellipse->rayon_y,
        shape->union_shape.ellipse->color.stroke.r,
        shape->union_shape.ellipse->color.stroke.g,
        shape->union_shape.ellipse->color.stroke.b,
        shape->union_shape.ellipse->color.stroke.a,
        shape->union_shape.ellipse->color.fill.r,
        shape->union_shape.ellipse->color.fill.g,
        shape->union_shape.ellipse->color.fill.b,
        shape->union_shape.ellipse->color.fill.a,
        shape->union_shape.ellipse->angle
    );
}


void choice_edition_ellipse(shape_struct_t *shape, int choice_edition_user) {
    switch (choice_edition_user) {
        case 1 :
            edition_coordo_ellipse(shape);
        break;
        case 2 :
            edition_color_ellipse(shape);
        break;
        case 3 :
            edition_position_ellipse(shape);
        break;
        case 4 :
            edition_angle_ellipse(shape);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
        break;
    }
}


void edition_coordo_ellipse(shape_struct_t *shape) {
    shape->union_shape.ellipse->coordo_center_x = ask_for_unsigned_int("\n- Coordo centre x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.ellipse->coordo_center_y = ask_for_unsigned_int("- Coordo centre y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.ellipse->rayon_x = ask_for_unsigned_int("- Rayon x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.ellipse->rayon_y = ask_for_unsigned_int("- Rayon y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_color_ellipse(shape_struct_t *shape) {
    shape->union_shape.ellipse->color.stroke.r = ask_color("\n- Couleur de trait "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.g = ask_color("- Couleur de trait "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.b = ask_color("- Couleur de trait "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.a = ask_opacity_color("- Opacite de "
        "trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
    shape->union_shape.ellipse->color.fill.r = ask_color("\n- Couleur de fond "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.g = ask_color("- Couleur de fond "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.b = ask_color("- Couleur de fond "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.a = ask_opacity_color("- Opacite de "
        "fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
}


void edition_position_ellipse(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer "
        "votre figure en x ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer "
        "votre figure en y ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");

    shape->union_shape.ellipse->coordo_center_x += edition_in_x;
    shape->union_shape.ellipse->coordo_center_y += edition_in_y;
}


void edition_angle_ellipse(shape_struct_t *shape) {
    shape->union_shape.ellipse->angle = ask_for_int("\nDe combien de degres "
        "voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
}