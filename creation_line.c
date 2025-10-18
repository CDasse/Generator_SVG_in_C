#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "creation_line.h"
#include "cli.h"


void line_for_creation(array_t *array) {
    line_t *new_line = create_line();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.line = new_line;
    my_struc->enum_shape = SHAPE_LINE;

    array->table[array->index] = my_struc;
    array->index++;
}


line_t *create_line() {
    system("clear");
    
    printf ("Veuillez preciser les informations concernant votre "
        "\033[36mligne\033[0m.\n"
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
    line->color.stroke.r = ask_color("- Couleur de trait en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    line->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[36mANGLE\033[0m\n");
    line->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    printf("\nVotre ligne aura son premier point aux coordonnees : x = "
        "\033[36m%d\033[0m / y = \033[36m%d\033[0m,"
        " son deuxieme point aux coordonnees : x = \033[36m%d\033[0m / y = "
        "\033[36m%d\033[0m,\n"
        " une couleur de trait = \033[36mrgba(%d,%d,%d,0.%d)\033[0m et un angle "
        "= \033[36m%d°\033[0m.\n\n", 
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