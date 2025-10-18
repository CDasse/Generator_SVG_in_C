#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"
#include "cli.h"
#include "menu_creation.h"
#include "menu_edition.h"
#include "menu_remove.h"
#include "menu_save.h"


void menu_for_user(array_t *array, viewbox_t *viewbox) {
    system("clear");

    user_menu_choice_t choice_menu = ask_for_int_in_range("Que voulez-vous"
        " \033[35mfaire\033[0m ?\n"
        "\n1: Creation\n"
        "2: Edition\n"
        "3: Suppression\n"
        "4: Sauvegarde\n"
        "5: Quitter\n",
        "\033[31mMerci d'entrer un nombre entre 1 et 5.\033[0m",
        1,
        5
    );
    
    switch (choice_menu) {

        case CHOICE_CREATION:
            choice_shape_for_creation(array, viewbox);
        break;
        case CHOICE_EDITION:
            choice_shape_for_edition(array, viewbox);
        break;
        case CHOICE_REMOVE:
            choice_shape_for_remove(array, viewbox);
        break;
        case CHOICE_SAVE:
            save_projet(array, viewbox);
        break;
        case CHOICE_EXIT:
            printf("\n\e[1m\033[34mMerci d'avoir utilise l'application.\n"
                "A bientot !\e[1m\033[0m\n\n");
        break;
        default:
            printf("\033[31mErreur dans votre choix de menu\033[0m");
        break;
    }
}