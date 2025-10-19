#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "menu_remove.h"
#include "shapes.h"
#include "cli.h"
#include "show_shapes.h"
#include "free_malloc.h"


void choice_shape_for_remove(array_t *array, viewbox_t *viewbox) {
    printf("\n");

    if (array->index == 0) {
        printf("\033[31mAucune forme n'est creee!\033[0m\n\n");
    } else {
        system("clear");
        show_shapes_in_table(array);
        int choice_user_remove = ask_for_int_in_table("\nQuelle "
            "forme voulez-vous \033[31msupprimer\033[0m ? "
            "(indiquer son index) ?\n",
            "\033[31mMerci d'entrer un index valide.\033[0m",
            array
        );

        remove_shape(array, viewbox, choice_user_remove);
    }

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void remove_shape(array_t *array, viewbox_t *viewbox, int choice_user_remove) {
    if (array->table[choice_user_remove] == NULL) {
        printf("\033[31mCette forme a deja ete supprimee.\033[0m\n\n");

        ask_for_1("Tapez '1' pour continuer ...",
            "\033[31mMerci d'entrer 1 pour continuer\033[0m");

        menu_for_user(array, viewbox);

        return;
    }

    int choice_user = ask_for_confirmation_remove();

    if (choice_user == 1) {
        free_shape_in_table(array->table[choice_user_remove]);

        array->table[choice_user_remove] = NULL;

        printf("\nLa forme a bien ete suprimee !\n\n");
    } else {
        menu_for_user(array, viewbox);
    }
}


int ask_for_confirmation_remove() {
    int choice_user = ask_for_int_in_range ("Etes-vous sur de vouloir "
        "supprimer cette forme ?\n(1: \033[32mOUI\033[0m / 2: \033[31mNON\033[0m)\n",
        "\033[31mMerci d'entrer 1 ou 2.\033[0m\n",
    1,
    2
    );

    return choice_user;
}