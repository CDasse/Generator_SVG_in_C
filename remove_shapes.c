#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "shapes.h"
#include "cli.h"
#include "show_shapes.h"
#include "remove_shapes.h"


void choice_shape_for_remove(array_t *array, viewbox_t *viewbox) {
    if (array->index == 0) {
        printf("Aucune forme n'est creee.\n");
    } else {
        show_shapes_in_table(array);
        int choice_user_remove = ask_for_int_in_table("\nQuelle forme voulez-vous supprimer"
        "(indiquer son index) ?\n", "Merci d'entrer un index valide.", array);

        free_shape_in_table(array->table[choice_user_remove]);

        array->table[choice_user_remove] = NULL;
    }

    menu_for_user(array, viewbox);
}