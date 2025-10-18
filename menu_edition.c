#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "show_shapes.h"
#include "menu_edition.h"
#include "edition_ellipse.h"
#include "edition_rectangle.h"
#include "edition_line.h"
#include "edition_polyline.h"
#include "edition_polygone.h"
#include "edition_path.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox) {
    if (array->index == 0) {
        printf("\n\033[31mAucune forme n'est creee!\033[0m\n\n");
    } else {
        system("clear");
        show_shapes_in_table(array);
        int choice_user_edition = ask_for_int_in_table("\nQuelle"
            " \033[31mforme\033[0m voulez-vous modifier "
            "(indiquer son index) ?\n",
            "\033[31mMerci d'entrer un index valide.\033[0m",
            array
        );

        edition_shape_in_table(array, viewbox, choice_user_edition);
    }

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void edition_shape_in_table(array_t *array, viewbox_t *viewbox, int choice_user_edition) {
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
        case SHAPE_PATH:
            edition_path_in_table(array->table[choice_user_edition]);
        break;
        default:
            printf("\033[31mForme inconnue.\033[0m\n");
        break;
        }
}