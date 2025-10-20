#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "menu_save.h"
#include "save_shapes.h"
#include "shapes.h"
#include "cli.h"


void save_projet(array_t *array, viewbox_t *viewbox) {
    printf("\n");
    char end_viewbox[] = "\n</svg>";

    FILE *saved_file = fopen("projet.svg", "w");

    fprintf(saved_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        viewbox->width, viewbox->height);
    
    save_shapes_in_projet(array, saved_file);
    
    fprintf(saved_file, "%s", end_viewbox);
    
    fclose(saved_file);

    printf("Vous pouvez maintenant ouvrir votre sauvegarde "
        "\033[35mprojet.svg\033[0m dans vos fichiers.\n\n");

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void save_shapes_in_projet(array_t *array, FILE *saved_file) {
    for (int i = 0; i < array->index; i++) {

        if (array->table[i] == NULL) {
            continue;
        }

        switch (array->table[i]->enum_shape) {
            case SHAPE_ELLIPSE:
                save_ellipse(array->table[i], saved_file);
            break;
            case SHAPE_RECTANGLE:
                save_rectangle(array->table[i], saved_file);
            break;
            case SHAPE_LINE:
                save_line(array->table[i], saved_file);
            break;
            case SHAPE_POLYLINE:
                save_polyline(array->table[i], saved_file);
            break;
            case SHAPE_POLYGONE:
                save_polygone(array->table[i], saved_file);
            break;
            case SHAPE_PATH:
                save_path(array->table[i], saved_file);
            break;
            default:
                printf("\033[31mUne erreur est survenue.\033[0m\n");
            break;
        }
    }
}