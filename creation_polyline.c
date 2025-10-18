#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "creation_polyline.h"
#include "cli.h"


void polyline_for_creation(array_t *array) {
    liste_t *new_polyline = create_polyline();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.polyline = new_polyline;
    my_struc->enum_shape = SHAPE_POLYLINE;

    array->table[array->index] = my_struc;
    array->index++;
}


liste_t *create_polyline() {
    system("clear");
    
    printf ("Veuillez preciser les informations concernant votre "
        "\033[35mpolyline\033[0m.\n"
    "(coordo x des points / coordo y des points / couleur en rbga "
    "/ angle de rotation)\n\n");

    liste_t *liste = malloc(sizeof(liste_t));
    liste->length = 0;
    liste->start = NULL;

    int choice_user = 1;

    printf("\n\033[35mCOORDONNEES\033[0m\n");
    do {
        list_element_t *liste_element = malloc(sizeof(list_element_t));

        push_in_list(
            liste,
            liste_element,
            ask_for_unsigned_int("- Coordo x: ", "\033[31mMerci d'entrer "
                "un nombre entier.\033[0m"), 
            // probleme de buffering du stdout probable (affichage y avant x)
            ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer "
                "un nombre entier.\033[0m")
        );

        choice_user = ask_for_int_in_range(
            "Voulez-vous ajouter un point a votre \033[35mpolyline"
            "\033[0m ? (1: oui / 2: non)\n",
            "\033[31mMerci d'entrer 1 ou 2.\033[0m",
            1,
            2
        );
    } while (choice_user == 1);

    printf("\n\033[35mCOULEURS\033[0m\n");
    liste->color.stroke.r = ask_color("- Couleur de trait en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[35mANGLE\033[0m\n");
    liste->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    list_element_t *element = liste->start;

    printf("\nVotre \033[35mpolyline\033[0m aura pour points:");

    while (element != NULL) {
        printf(" (\033[35m%d\033[0m/\033[35m%d\033[0m) ",
            element->value1,
            element->value2
        );
        element = element->next;
    }

    printf(", couleur de trait: \033[35mrgba(%d,%d,%d,0.%d)\033[0m, "
        "angle: \033[35m%d°\033[0m\n",
        liste->color.stroke.r,
        liste->color.stroke.g,
        liste->color.stroke.b,
        liste->color.stroke.a,
        liste->angle
    );

    return liste;
}


void push_in_list(liste_t *list, list_element_t *element, int x, int y) {
    element->value1 = x;
    element->value2 = y;
    element->next = NULL;
    list->length++;

    list_element_t *cursor = list->start;
    if (cursor == NULL) {
        list->start = element;
        return;
    }

    while (cursor->next != NULL) {
        cursor = cursor->next;
    }

    cursor->next = element;
}