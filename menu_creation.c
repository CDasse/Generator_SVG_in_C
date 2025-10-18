#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "creation_ellipse.h"
#include "creation_rectangle.h"
#include "creation_line.h"
#include "creation_polyline.h"
#include "creation_polygone.h"
#include "creation_path.h"


void choice_shape_for_creation(array_t *array, viewbox_t *viewbox) {
    system("clear");

    user_shape_choice_t choice_shape = ask_for_int_in_range("Quelle "
        "\033[32mforme\033[0m voulez-vous realiser ?\n"
        "\n1: Ellipse\n"
        "2: Rectangle\n"
        "3: Ligne\n"
        "4: Polyline\n"
        "5: Polygone\n"
        "6: Chemin\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 6.\033[0m",
        1,
        6
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
        case CHOICE_PATH:
            path_for_creation(array);
        break;
        default:
            printf("\033[31mUne erreur est survenue.\033[0m");
        break;
    }

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer.\033[0m");

    menu_for_user(array, viewbox);
}