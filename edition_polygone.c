#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "edition_polygone.h"
#include "edition_polyline.h"


void edition_polygone_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: Les couleurs\n"
        "3: Deplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    choice_edition_polygone(shape, choice_edition_user);

    list_element_t *element = shape->union_shape.polygone->start;

    printf("\nVotre nouvelle \033[34mpolygone\033[0m aura pour points:");

    while (element != NULL) {
        printf(" (\033[34m%d\033[0m/\033[34m%d\033[0m)",
            element->value1,
            element->value2
        );
        element = element->next;
    }

    printf(", couleur de trait: \033[34mrgba(%d,%d,%d,0.%d)\033[0m, "
        "angle: \033[34m%d°\033[0m\n",
        shape->union_shape.polygone->color.stroke.r,
        shape->union_shape.polygone->color.stroke.g,
        shape->union_shape.polygone->color.stroke.b,
        shape->union_shape.polygone->color.stroke.a,
        shape->union_shape.polygone->angle
    );
}


void choice_edition_polygone(shape_struct_t *shape, int choice_edition_user) {
    switch (choice_edition_user) {
        case 1 :
            edition_coordo_polygone(shape);
        break;
        case 2 :
            edition_color_polygone(shape);
        break;
        case 3 :
            edition_position_polygone(shape);
        break;
        case 4 :
            edition_angle_polygone(shape);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
        break;
    }
}


void edition_coordo_polygone(shape_struct_t *shape) {
    list_element_t *element = get_position_in_liste(shape->union_shape.polygone);

    element->value1 = ask_for_unsigned_int("\n- Coordo x: ", "\033[31mMerci d'entrer "
        "un nombre entier.\033[0m");
    element->value2 = ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer "
        "un nombre entier.\033[0m");
}


void edition_color_polygone(shape_struct_t *shape) {
    shape->union_shape.polygone->color.stroke.r = ask_color("\n- Couleur de trait "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.g = ask_color("- Couleur de trait "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.b = ask_color("- Couleur de trait "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.a = ask_opacity_color("- Opacite de "
        "trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
    shape->union_shape.polygone->color.fill.r = ask_color("\n- Couleur de fond "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.g = ask_color("- Couleur de fond "
        "\033[32m(g)\033[0m: ",  "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.b = ask_color("- Couleur de fond "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.a = ask_opacity_color("- Opacite de "
        "fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
}


void edition_position_polygone(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer "
        "votre figure en x ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer "
        "votre figure en y ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");

    list_element_t *element = shape->union_shape.polygone->start;

    for (int i = 0; i < shape->union_shape.polygone->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


void edition_angle_polygone(shape_struct_t *shape) {
    shape->union_shape.polygone->angle = ask_for_int("\nDe combien de degres "
        "voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
}