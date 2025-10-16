#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "shapes.h"
#include "cli.h"
#include "show_shapes.h"
#include "remove_shapes.h"


void choice_shape_for_remove(array_t *array, viewbox_t *viewbox) {
    printf("\n");

    if (array->index == 0) {
        printf("Aucune forme n'est creee! \n\n");
    } else {
        show_shapes_in_table(array);
        int choice_user_remove = ask_for_int_in_table("\nQuelle forme voulez-vous supprimer"
            "(indiquer son index) ?\n",
            "Merci d'entrer un index valide.",
            array
        );

        if (array->table[choice_user_remove] == NULL) {
            printf("Cette forme a deja ete supprimee.\n\n");
            menu_for_user(array, viewbox);
            return;
        }

        int choice_user = ask_for_confirmation();

        if (choice_user == 1) {
            free_shape_in_table(array->table[choice_user_remove]);

            array->table[choice_user_remove] = NULL;
        } else {
            menu_for_user(array, viewbox);
        }
    }

    menu_for_user(array, viewbox);
}


int ask_for_confirmation() {
    int choice_user = ask_for_int_in_range ("Etes-vous sur de vouloir supprimer cette forme ?\n"
    "(1: OUI / 2: NON)\n",
    "Merci d'entrer 1 ou 2.\n",
    1,
    2
    );

    return choice_user;
}