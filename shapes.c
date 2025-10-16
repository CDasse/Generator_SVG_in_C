#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"


viewbox_t *create_viewbox() {
    printf("Pour commencer, veuillez préciser la dimension "
        "de votre \033[32mfenetre de visualisation\033[0m\n"
        "(la largeur puis la hauteur).\n\n");

    viewbox_t *viewbox = malloc(sizeof(viewbox_t));

    viewbox->coordo_min_x = 0;
    viewbox->coordo_min_y = 0;
    viewbox->width = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    viewbox->height = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre fenetre de visualisation aura une largeur "
        "de \033[32m%upx\033[0m et une hauteur de \033[32m%upx\033[0m.\n\n", 
        viewbox->width,
        viewbox->height
    );

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    return viewbox;
}


void free_viewbox(viewbox_t *viewbox) {
    free(viewbox);
}


array_t *create_array() {
    array_t *array = malloc(sizeof(array_t));
    array->index = 0;

    initialize_array(array);
    
    return array;
}


void initialize_array(array_t *array) {
    for (int i = 0; i < 40; i++) {
        array->table[i] = NULL;
    }
}


void free_shape_in_table(shape_struct_t *shape) {
        switch (shape->enum_shape) {
        case SHAPE_ELLIPSE:
            free_ellipse(shape->union_shape.ellipse);
        break;
        case SHAPE_RECTANGLE:
            free_rect(shape->union_shape.rectangle);
        break;
        case SHAPE_LINE:
            free_line(shape->union_shape.line);
        break;
        case SHAPE_POLYLINE:
            free_elements_in_liste(shape->union_shape.polyline);
        break;
        case SHAPE_POLYGONE:
            free_elements_in_liste(shape->union_shape.polygone);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
            break;
        }
        free(shape);
}


ellipse_t *create_ellipse() {
    system("clear");

    printf ("Veuillez préciser les informations concernant votre \033[33mellipse\033[0m.\n"
        "(coordo x / y du point central / rayon en x / rayon en y /"
        " couleurs en rgba / angle de rotation)\n\n"
    );

    ellipse_t *ellipse = malloc(sizeof(ellipse_t));

    printf("\n\033[33mCOORDONNEES\033[0m\n");
    ellipse->coordo_center_x = ask_for_unsigned_int("- Coordo centre x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->coordo_center_y = ask_for_unsigned_int("- Coordo centre y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->rayon_x = ask_for_unsigned_int("- Rayon x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    ellipse->rayon_y = ask_for_unsigned_int("- Rayon y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    
    printf("\n\033[33mCOULEURS\033[0m\n");
    ellipse->color.stroke.r = ask_color("- Couleur de trait en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    ellipse->color.fill.r = ask_color("\n- Couleur de fond en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    ellipse->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[33mANGLE\033[0m\n");
    ellipse->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre \033[33mellipse\033[0m aura un centre de coordonnées : x = \033[33m%d\033[0m / y = \033[33m%d\033[0m,"
        " un rayon x = \033[33m%dpx\033[0m, un rayon y = \033[33m%dpx\033[0m, \nune couleur de trait = \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[33mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[33m%d°\033[0m.\n\n", 
        ellipse->coordo_center_x,
        ellipse->coordo_center_y,
        ellipse->rayon_x,
        ellipse->rayon_y,
        ellipse->color.stroke.r,
        ellipse->color.stroke.g,
        ellipse->color.stroke.b,
        ellipse->color.stroke.a,
        ellipse->color.fill.r,
        ellipse->color.fill.g,
        ellipse->color.fill.b,
        ellipse->color.fill.a,
        ellipse->angle
    );

    return ellipse;
}


void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


rect_t *create_rect() {
    system("clear");

    printf ("Veuillez préciser les informations concernant votre \033[32mrectangle\033[0m.\n"
        " (coordo x du premier point / coordo y du premier point"
        " / largeur / hauteur / couleurs en rgba / angle de rotation)\n\n");
    
    rect_t *rect = malloc(sizeof(rect_t));

    printf("\n\033[32mCOORDONNEES\033[0m\n");
    rect->coordo_start_x = ask_for_unsigned_int("- Coordo x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->coordo_start_y = ask_for_unsigned_int("- Coordo y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->width = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    rect->height = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\n\033[32mCOULEURS\033[0m\n");
    rect->color.stroke.r = ask_color("- Couleur de trait en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    rect->color.fill.r = ask_color("\n- Couleur de fond en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    rect->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[32mANGLE\033[0m\n");
    rect->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre rectangle aura son premier point aux coordonnées : x = \033[32m%d\033[0m / y = \033[32m%d\033[0m,"
        " une largeur de \033[32m%dpx\033[0m, une hauteur de \033[32m%dpx\033[0m, \nune couleur de trait = \033[32mrgba(%d,%d,%d,0.%d)\033[0m,"
        " une couleur de fond = \033[32mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[32m%d°\033[0m.\n\n", 
        rect->coordo_start_x,
        rect->coordo_start_y,
        rect->width,
        rect->height,
        rect->color.stroke.r,
        rect->color.stroke.g,
        rect->color.stroke.b,
        rect->color.stroke.a,
        rect->color.fill.r,
        rect->color.fill.g,
        rect->color.fill.b,
        rect->color.fill.a,
        rect->angle
    );
    
    return rect;
}


void free_rect(rect_t *rect) {
    free(rect);
}


line_t *create_line() {
    system("clear");
    
    printf ("Veuillez préciser les informations concernant votre \033[36mligne\033[0m.\n"
        " (x du premier point / y du premier point / x du deuxieme point"
        " / y du deuxieme point / couleur en rgba / angle de rotation)\n\n"
    );
    
    line_t *line = malloc(sizeof(line_t));

    printf("\n\033[36mCOORDONNEES\033[0m\n");
    line->coordo_start_x = ask_for_unsigned_int("- Coordo x: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    line->coordo_start_y = ask_for_unsigned_int("- Coordo y: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    line->coordo_end_x = ask_for_unsigned_int("- Largeur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");
    line->coordo_end_y = ask_for_unsigned_int("- Hauteur: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\n\033[36mCOULEURS\033[0m\n");
    line->color.stroke.r = ask_color("- Couleur de trait en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[36mANGLE\033[0m\n");
    line->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre ligne aura son premier point aux coordonnées : x = \033[36m%d\033[0m / y = \033[36m%d\033[0m,"
        " son deuxieme point aux coordonnées : x = \033[36m%d\033[0m / y = \033[36m%d\033[0m,\n"
        " une couleur de trait = \033[36mrgba(%d,%d,%d,0.%d)\033[0m et un angle = \033[36m%d°\033[0m.\n\n", 
        line->coordo_start_x,
        line->coordo_start_y,
        line->coordo_end_x,
        line->coordo_end_y,
        line->color.stroke.r,
        line->color.stroke.g,
        line->color.stroke.b,
        line->color.stroke.a,
        line->angle
    );
    
    return line;
}


void free_line(line_t *line) {
    free(line);
}


void free_all(array_t *array, viewbox_t *viewbox) {
    for (int i = 0; i < 40; i++) {
        if (array->table[i] != NULL) {
            free_shape_in_table(array->table[i]);
        }
    }
    free(array);
    free_viewbox(viewbox);
}


liste_t *create_polyline() {
    system("clear");
    
    printf ("Veuillez préciser les informations concernant votre \033[35mpolyline\033[0m.\n"
    "(coordo x des points / coordo y des points / couleur en rbga / angle de rotation)\n\n");

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
            ask_for_unsigned_int("- Coordo x: ", "\033[31mMerci d'entrer un nombre entier.\033[0m"), 
            // probleme de buffering du stdout probable (affichage y avant x)
            ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer un nombre entier.\033[0m")
        );

        choice_user = ask_for_int_in_range(
            "Voulez-vous ajouter un point à votre \033[35mpolyline\033[0m ? (1: oui / 2: non)\n",
            "\033[31mMerci d'entrer 1 ou 2.\033[0m",
            1,
            2
        );
    } while (choice_user == 1);

    printf("\n\033[35mCOULEURS\033[0m\n");
    liste->color.stroke.r = ask_color("- Couleur de trait en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[35mANGLE\033[0m\n");
    liste->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre polyline aura \033[35m%d\033[0m points.\n\n", liste->length);

    return liste;
}


liste_t *create_polygone() {
    system("clear");
    
    printf ("Veuillez préciser les informations concernant votre \033[34mpolygone\033[0m.\n"
    "(coordo x des points / coordo y des points / couleurs en rgba / angle de rotation)\n\n");

    liste_t *liste = malloc(sizeof(liste_t));
    liste->length = 0;
    liste->start = NULL;

    int choice_user = 1;

    printf("\n\033[34mCOORDONNEES\033[0m\n");
    do {
        list_element_t *liste_element = malloc(sizeof(list_element_t));

        push_in_list(
            liste,
            liste_element,
            ask_for_unsigned_int("- Coordo x: ", "\033[31mMerci d'entrer un nombre entier.\033[0m"), 
            // probleme de buffering du stdout probable (affichage y avant x)
            ask_for_unsigned_int("- Coordo y: ", "\033[31mMerci d'entrer un nombre entier.\033[0m")
        );

        choice_user = ask_for_int_in_range(
            "Voulez-vous ajouter un point à votre \033[34mpolygone\033[0m ? (1: oui / 2: non)\n",
            "\033[31mMerci d'entrer 1 ou 2.\033[0m",
            1,
            2
        );
    } while (choice_user == 1);

    printf("\n\033[34mCOULEURS\033[0m\n");
    liste->color.stroke.r = ask_color("- Couleur de trait en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    liste->color.fill.r = ask_color("\n- Couleur de fond en rgba \033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    liste->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[34mANGLE\033[0m\n");
    liste->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre polygone aura \033[34m%d\033[0m points.\n\n", liste->length);

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


void free_liste(liste_t *liste) {
    free(liste);
}


void free_element(list_element_t *element) {
    free(element);
}


void free_elements_in_liste(liste_t *liste) {
    list_element_t *element = liste->start;
    list_element_t *temp = NULL;

    while (element != NULL) {
        temp = element->next;
        free(element);
        element = temp;
    }

    free_liste(liste);
}