#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "menu.h"
#include "cli.h"
#include "creation_shapes.h"
#include "edition_shapes.h"
#include "remove_shapes.h"
#include "save_shapes.h"


void menu_for_user(array_t *array, viewbox_t *viewbox) {
    user_menu_choice_t choice_menu = ask_for_int_in_range("Que voulez-vous faire ?\n"
        "(1: creation / 2: edition / 3: suppression / 4: sauvegarde / 5: quitter)\n",
        "Merci d'entrer un nombre entre 1 et 5.",
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
            printf("Merci d'avoir utilisé l'application.\nA bientot !\n");
        break;
        default:
            printf("Erreur dans votre choix de menu");
        break;
    }
}