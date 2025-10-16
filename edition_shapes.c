#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "show_shapes.h"
#include "edition_shapes.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox) {
    if (array->index == 0) {
        printf("\n\033[31mAucune forme n'est creee!\033[0m\n\n");

        ask_for_1("Tapez '1' pour continuer ...",
            "\033[31mMerci d'entrer 1 pour continuer\033[0m");
    } else {
        system("clear");
        show_shapes_in_table(array);
        int choice_user_edition = ask_for_int_in_table("\nQuelle \033[31mforme\033[0m voulez-vous modifier "
            "(indiquer son index) ?\n",
            "\033[31mMerci d'entrer un index valide.\033[0m",
            array
        );

        if (array->table[choice_user_edition] == NULL) {
            printf("\033[31mCette forme a ete supprimee.\033[0m\n\n");
            ask_for_1("Tapez '1' pour continuer ...",
                "\033[31mMerci d'entrer 1 pour continuer\033[0m");

            menu_for_user(array, viewbox);
            return;
        }
    
        switch (array->table[choice_user_edition]->enum_shape) {
            case SHAPE_ELLIPSE:
                edition_ellipse_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_RECTANGLE:
                edition_rectangle_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_LINE:
                edition_line_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_POLYLINE:
                edition_polyline_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_POLYGONE:
                edition_polygone_in_table(array->table[choice_user_edition]);
            break;
            default:
                printf("\033[31mForme inconnue.\033[0m\n");
            break;
        }
    }

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void edition_ellipse_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: Les couleurs\n"
        "3: Déplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

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

    printf("\nVotre nouvelle \033[33mellipse\033[0m aura un centre de coordonnees : x = \033[33m%d\033[0m / y = \033[33m%d\033[0m,"
        " un rayon x = \033[33m%dpx\033[0m, un rayon y = \033[33m%dpx\033[0m\nune couleur de trait = \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[33mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[33m%d°\033[0m.\n\n", 
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
    shape->union_shape.ellipse->color.stroke.r = ask_color("\n- Couleur de trait \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    shape->union_shape.ellipse->color.fill.r = ask_color("\n- Couleur de fond \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.ellipse->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_ellipse(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    shape->union_shape.ellipse->coordo_center_x += edition_in_x;
    shape->union_shape.ellipse->coordo_center_y += edition_in_y;
}


void edition_angle_ellipse(shape_struct_t *shape) {
    shape->union_shape.ellipse->angle = ask_for_int("\nDe combien de degres voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_rectangle_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: Les couleurs\n"
        "3: Déplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    switch (choice_edition_user) {
        case 1 :
            edition_coordo_rectangle(shape);
        break;
        case 2 :
            edition_color_rectangle(shape);
        break;
        case 3 :
            edition_position_rectangle(shape);
        break;
        case 4 :
            edition_angle_rectangle(shape);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
        break;
    }

    printf("\nVotre nouveau \033[32mrectangle\033[0m aura son premier point aux coordonnees : x = \033[32m%d\033[0m / y = \033[32m%d\033[0m,"
        " une largeur de \033[32m%dpx\033[0m et une hauteur de \033[32m%dpx\033[0m,\nune couleur de trait = \033[32mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[32mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[32m%d°\033[0m.\n\n", 
        shape->union_shape.rectangle->coordo_start_x,
        shape->union_shape.rectangle->coordo_start_y,
        shape->union_shape.rectangle->width,
        shape->union_shape.rectangle->height,
        shape->union_shape.rectangle->color.stroke.r,
        shape->union_shape.rectangle->color.stroke.g,
        shape->union_shape.rectangle->color.stroke.b,
        shape->union_shape.rectangle->color.stroke.a,
        shape->union_shape.rectangle->color.fill.r,
        shape->union_shape.rectangle->color.fill.g,
        shape->union_shape.rectangle->color.fill.b,
        shape->union_shape.rectangle->color.fill.a,
        shape->union_shape.rectangle->angle
    );
}


void edition_coordo_rectangle(shape_struct_t *shape) {
    shape->union_shape.rectangle->coordo_start_x = ask_for_unsigned_int("\n- Coordo x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.rectangle->coordo_start_y = ask_for_unsigned_int("- Coordo y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.rectangle->width = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    shape->union_shape.rectangle->height = ask_for_unsigned_int("- Lauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_color_rectangle(shape_struct_t *shape) {
    shape->union_shape.rectangle->color.stroke.r = ask_color("\n- Couleur de trait \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    shape->union_shape.rectangle->color.fill.r = ask_color("\n- Couleur de fond \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.rectangle->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_rectangle(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    shape->union_shape.rectangle->coordo_start_x += edition_in_x;
    shape->union_shape.rectangle->coordo_start_y += edition_in_y;
}


void edition_angle_rectangle(shape_struct_t *shape) {
    shape->union_shape.rectangle->angle = ask_for_int("\nDe combien de degres voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_line_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: La couleur\n"
        "3: Déplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

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

    printf("\nVotre nouvelle \033[36mligne\033[0m aura son premier point aux coordonnees : x = \033[36m%d\033[0m / y = \033[36m%d\033[0m,"
        " et son deuxieme point aux coordonnees : x = \033[36m%d\033[0m / y = \033[36m%d\033[0m,\n"
        "une couleur de trait = \033[36mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[36m%d°\033[0m\n\n", 
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
    shape->union_shape.line->color.stroke.r = ask_color("\n- Couleur de trait \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.line->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_line(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    shape->union_shape.line->coordo_start_x += edition_in_x;
    shape->union_shape.line->coordo_start_y += edition_in_x;
    shape->union_shape.line->coordo_end_x += edition_in_y;
    shape->union_shape.line->coordo_end_y += edition_in_y;
}


void edition_angle_line(shape_struct_t *shape) {
    shape->union_shape.line->angle = ask_for_int("\nDe combien de degres voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_polyline_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: La couleur\n"
        "3: Déplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

    switch (choice_edition_user) {
        case 1 :
            edition_coordo_polyline(shape);
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

    printf("\nLes modifications ont ete enregistrees.\n\n");
}


void edition_coordo_polyline(shape_struct_t *shape) {
    list_element_t *element = get_position_in_polyline(shape->union_shape.polyline);

    element->value1 = ask_for_unsigned_int("\n- Coordo x: ", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    element->value2 = ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_color_polyline(shape_struct_t *shape) {
    shape->union_shape.polyline->color.stroke.r = ask_color("\n- Couleur de trait \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polyline->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_polyline(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    list_element_t *element = shape->union_shape.polyline->start;

    for (int i = 0; i < shape->union_shape.polyline->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


void edition_angle_polyline(shape_struct_t *shape) {
    shape->union_shape.polyline->angle = ask_for_int("\nDe combien de degres voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


list_element_t *get_position_in_polyline(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("\nQuel point souhaitez vous modifier ?\n",
        "\033[31mMerci d'entrer un index correct.\033[0m",
        liste
    );

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}


void edition_polygone_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "\n1: Les coordonnees\n"
        "2: Les couleurs\n"
        "3: Déplacement en x et y\n"
        "4: La rotation\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 4.\033[0m\n",
        1,
        4
    );

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

    printf("\nLes modifications ont ete enregistrees.\n\n");
}


void edition_coordo_polygone(shape_struct_t *shape) {
    list_element_t *element = get_position_in_polygone(shape->union_shape.polygone);

    element->value1 = ask_for_unsigned_int("\n- Coordo x: ", "\033[31mMerci d'entrer un nombre entier.\033[0m");
    element->value2 = ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


void edition_color_polygone(shape_struct_t *shape) {
    shape->union_shape.polygone->color.stroke.r = ask_color("\n- Couleur de trait \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    shape->union_shape.polygone->color.fill.r = ask_color("\n- Couleur de fond \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    shape->union_shape.polygone->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
}


void edition_position_polygone(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("\nDe combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    list_element_t *element = shape->union_shape.polygone->start;

    for (int i = 0; i < shape->union_shape.polygone->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


void edition_angle_polygone(shape_struct_t *shape) {
    shape->union_shape.polygone->angle = ask_for_int("\nDe combien de degres voulez-vous faire pivoter votre figure ?\n",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
}


list_element_t *get_position_in_polygone(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("\nQuel point souhaitez vous modifier ?\n",
        "\033[31mMerci d'entrer un index correct.\033[0m",
        liste
    );

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}