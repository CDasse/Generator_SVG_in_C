#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "edition_polyline.h"


void edition_polyline_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("\n Que souhaitez-vous modifier ? "
        "\n1: Les coordonnees\n"
        "2: La couleur\n"
        "3: Deplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    choice_edition_polyline(shape, choice_edition_user);

    list_element_t *element = shape->union_shape.polyline->start;

    printf("\nVotre nouvelle \033[35mpolyline\033[0m aura pour points:");

    while (element != NULL) {
        printf(" (\033[35m%d\033[0m/\033[35m%d\033[0m)",
            element->value1,
            element->value2
        );
        element = element->next;
    }

    printf(", couleur de trait: \033[35mrgba(%d,%d,%d,0.%d)\033[0m, "
        "angle: \033[35m%d°\033[0m\n",
        shape->union_shape.polyline->color.stroke.r,
        shape->union_shape.polyline->color.stroke.g,
        shape->union_shape.polyline->color.stroke.b,
        shape->union_shape.polyline->color.stroke.a,
        shape->union_shape.polyline->angle
    );
}


void choice_edition_polyline(shape_struct_t *shape, int choice_edition_user) {
    switch (choice_edition_user) {
        case 1 :
            edition_or_remove_coordo_polyline(shape);
        break;
        case 2 :
            edition_color_polyline(shape);
        break;
        case 3 :
            edition_position_polyline(shape);
        break;
        case 4 :
            edition_angle_polyline(shape);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
        break;
    }
}


void edition_or_remove_coordo_polyline(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("\nQue souhaitez-vous faire ? "
        "\n1: Modifier des coordonnees\n"
        "2: Supprimer des coordonnees\n",
        "\033[31mMerci d'entrer 1 ou 2.\033[0m\n",
        1,
        2
    );

    switch (choice_edition_user) {
        case 1 :
            edition_coordo_polyline(shape);
        break;
        case 2 :
            remove_coordo_polyline(shape);
        break;
    }
}


void edition_coordo_polyline(shape_struct_t *shape) {
    list_element_t *element = get_position_in_liste(shape->union_shape.polyline);

    element->value1 = ask_for_unsigned_int("\n- Coordo x: ", "\033[31mMerci d'entrer "
        "un nombre entier.\033[0m");
    element->value2 = ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer un "
        "nombre entier.\033[0m");
}


void remove_coordo_polyline(shape_struct_t *shape) {
    liste_t *polyline = shape->union_shape.polyline;

    int position_user_choice = ask_for_int_in_liste(
        "\nQuel point souhaitez-vous supprimer ?\n",
        "\033[31mMerci d'entrer un index correct.\033[0m",
        polyline
    );

    if (position_user_choice == 1) {
        list_element_t *tmp = polyline->start;
        polyline->start = tmp->next;
        free(tmp);
        polyline->length--;
        printf("Point numéro \033[35m%d\033[0m supprimé.\n", position_user_choice);
        return;
    }

    list_element_t *prev = polyline->start;
    for (int i = 1; i < position_user_choice - 1; i++) {
        prev = prev->next;
    }

    list_element_t *to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);
    polyline->length--;

    printf("Point numéro \033[35m%d\033[0m supprimé.\n", position_user_choice);
}


void edition_color_polyline(shape_struct_t *shape) {
    shape->union_shape.polyline->color.stroke.r = ask_color("\n- Couleur de trait "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.g = ask_color("- Couleur de trait "
        "\033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.b = ask_color("- Couleur de trait "
        "\033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.a = ask_opacity_color("- Opacite de "
        "trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_polyline(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer "
        "votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer "
        "votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );

    list_element_t *element = shape->union_shape.polyline->start;

    for (int i = 0; i < shape->union_shape.polyline->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


void edition_angle_polyline(shape_struct_t *shape) {
    shape->union_shape.polyline->angle = ask_for_int("\nDe combien de degres "
        "voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m"
    );
}


list_element_t *get_position_in_liste(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("\nQuel point souhaitez "
        "vous modifier ?\n",
        "\033[31mMerci d'entrer un index correct.\033[0m",
        liste
    );

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}