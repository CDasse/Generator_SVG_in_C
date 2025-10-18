#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "edition_line.h"


void edition_line_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: La couleur\n"
        "3: Deplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    choice_edition_line(shape, choice_edition_user);

    printf("\nVotre nouvelle \033[36mligne\033[0m aura son premier point aux "
        "coordonnees : x = \033[36m%d\033[0m / y = \033[36m%d\033[0m,"
        " et son deuxieme point aux coordonnees : x = \033[36m%d\033[0m / y = "
        "\033[36m%d\033[0m,\nune couleur de trait = \033[36mrgba(%d,%d,%d,0.%d)\033[0m"
        " et un angle = \033[36m%d°\033[0m\n\n", 
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y,
        shape->union_shape.line->color.stroke.r,
        shape->union_shape.line->color.stroke.g,
        shape->union_shape.line->color.stroke.b,
        shape->union_shape.line->color.stroke.a,
        shape->union_shape.line->angle
    );
}


void choice_edition_line(shape_struct_t *shape, int choice_edition_user) {
    switch (choice_edition_user) {
        case 1 :
            edition_coordo_line(shape);
        break;
        case 2 :
            edition_color_line(shape);
        break;
        case 3 :
            edition_position_line(shape);
        break;
        case 4 :
            edition_angle_line(shape);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
        break;
    }
}


void edition_coordo_line(shape_struct_t *shape) {
    shape->union_shape.line->coordo_start_x = ask_for_unsigned_int("\n- Coordo x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.line->coordo_start_y = ask_for_unsigned_int("- Coordo y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.line->coordo_end_x = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.line->coordo_end_y = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_color_line(shape_struct_t *shape) {
    shape->union_shape.line->color.stroke.r = ask_color("\n- Couleur de trait "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.g = ask_color("- Couleur de trait "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.b = ask_color("- Couleur de trait "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.a = ask_opacity_color("- Opacite de "
        "trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
}


void edition_position_line(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer "
        "votre figure en x ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer "
        "votre figure en y ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");

    shape->union_shape.line->coordo_start_x += edition_in_x;
    shape->union_shape.line->coordo_start_y += edition_in_x;
    shape->union_shape.line->coordo_end_x += edition_in_y;
    shape->union_shape.line->coordo_end_y += edition_in_y;
}


void edition_angle_line(shape_struct_t *shape) {
    shape->union_shape.line->angle = ask_for_int("\nDe combien de degres "
        "voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
}