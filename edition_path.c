#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "edition_path.h"


void edition_path_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous modifier ? "
        "\n1: Les commandes et coordonnees\n"
        "2: Les couleurs\n"
        "3: Deplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    choice_edition_path(shape, choice_edition_user);

    path_element_t *element = shape->union_shape.path->start;

    printf("\nVotre nouveau \033[33mchemin\033[0m aura pour commandes:");

    while (element != NULL) {
        printf(" (\033[33m%c\033[0m", element->command);

        switch (element->command) {
            case 'M':
            case 'L':
                printf(" %d,%d", element->x, element->y);
            break;
            case 'H':
                printf(" %d", element->x);
            break;
            case 'V':
                printf(" %d", element->y);
            break;
            case 'Q':
                printf(" %d,%d %d,%d",
                    element->x, element->y,
                    element->x1, element->y1);
            break;
            case 'C':
                printf(" %d,%d %d,%d %d,%d",
                    element->x, element->y,
                    element->x1, element->y1,
                    element->x2, element->y2);
            break;
            default:
            break;
        }
        printf(")");
        element = element->next;
    }

    printf(", couleur de trait: \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
           " couleur de fond: \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
           " et angle: \033[33m%d°\033[0m\n\n",
        shape->union_shape.path->color.stroke.r,
        shape->union_shape.path->color.stroke.g,
        shape->union_shape.path->color.stroke.b,
        shape->union_shape.path->color.stroke.a,
        shape->union_shape.path->color.fill.r,
        shape->union_shape.path->color.fill.g,
        shape->union_shape.path->color.fill.b,
        shape->union_shape.path->color.fill.a,
        shape->union_shape.path->angle
    );
}


void choice_edition_path(shape_struct_t *shape, int choice_edition_user) {
    switch (choice_edition_user) {
        case 1:
            edition_coordo_path(shape);
            break;
        case 2:
            edition_color_path(shape);
            break;
        case 3:
            edition_position_path(shape);
            break;
        case 4:
            edition_angle_path(shape);
            break;
        default:
            printf("\033[31mUne erreur est survenue\033[0m\n");
            break;
    }
}


void edition_coordo_path(shape_struct_t *shape) {
    path_element_t *element = get_position_in_path(shape->union_shape.path);

    switch (element->command) {
        case 'M':
        case 'L':
            element->x = ask_for_unsigned_int("- Coordo x : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y = ask_for_unsigned_int("- Coordo y : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
        break;
        case 'H':
            element->x = ask_for_unsigned_int("- Coordo x : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
        break;
        case 'V':
            element->y = ask_for_unsigned_int("- Coordo y : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
        break;
        case 'Q':
            element->x1 = ask_for_unsigned_int("- Coordo x1 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y1 = ask_for_unsigned_int("- Coordo y1 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->x = ask_for_unsigned_int("- Coordo x fin : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y = ask_for_unsigned_int("- Coordo y fin : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
        break;
        case 'C':
            element->x1 = ask_for_unsigned_int("- Coordo x1 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y1 = ask_for_unsigned_int("- Coordo y1 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->x2 = ask_for_unsigned_int("- Coordo x2 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y2 = ask_for_unsigned_int("- Coordo y2 : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->x = ask_for_unsigned_int("- Coordo x fin : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
            element->y = ask_for_unsigned_int("- Coordo y fin : ",
                "\033[31mMerci d'entrer un nombre entier.\033[0m");
        break;
        case 'Z':
            printf("\033[31mCette commande ne contient pas de coordonnees.\033[0m\n");
        break;
    }
}


void edition_color_path(shape_struct_t *shape) {
    shape->union_shape.path->color.stroke.r = ask_color("\n- Couleur de trait "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.stroke.g = ask_color("- Couleur de trait "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.stroke.b = ask_color("- Couleur de trait "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.stroke.a = ask_opacity_color("- Opacite de "
        "trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
    shape->union_shape.path->color.fill.r = ask_color("\n- Couleur de fond "
        "\033[31m(r)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.fill.g = ask_color("- Couleur de fond "
        "\033[32m(g)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.fill.b = ask_color("- Couleur de fond "
        "\033[34m(b)\033[0m: ", "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.path->color.fill.a = ask_opacity_color("- Opacite de "
        "fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m"
    );
}


void edition_position_path(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer "
        "votre path en x ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer "
        "votre path en y ?\n", "\033[31mMerci d'entrer un nombre entier.\033[0m");

    path_element_t *element = shape->union_shape.path->start;

    for (int i = 0; i < shape->union_shape.polyline->length; i++) {
        while (element != 0) {
        element->x  += edition_in_x;
        element->y  += edition_in_y;
        element->x1 += edition_in_x;
        element->y1 += edition_in_y;
        element->x2 += edition_in_x;
        element->y2 += edition_in_y;
        }

        element = element->next;
    }
}


void edition_angle_path(shape_struct_t *shape) {
    shape->union_shape.path->angle = ask_for_int("\nDe combien de degres "
        "voulez-vous faire pivoter votre path ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
}


path_element_t *get_position_in_path(path_t *path) {
    int position_user_choice = ask_for_int_in_path("\nQuelle commande souhaitez-vous modifier ?\n",
        "\033[31mMerci d'entrer un index correct.\033[0m",
        path
    );

    path_element_t *element = path->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}