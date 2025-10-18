#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "creation_path.h"
#include "cli.h"


void path_for_creation(array_t *array) {
    path_t *new_path = create_path();
    shape_struct_t *my_struc = malloc(sizeof(shape_struct_t));
    my_struc->union_shape.path = new_path;
    my_struc->enum_shape = SHAPE_PATH;

    array->table[array->index] = my_struc;
    array->index++;
}


path_t *create_path() {
    system("clear");
    
    printf("Veuillez preciser les informations concernant votre "
        "\033[33mpath\033[0m.\n"
        "(commande SVG / coordonnees associees / couleur en rgba / angle de rotation)\n"
        "M: Move To\n"
        "L: Line To\n"
        "H: Horizontale Line To\n"
        "V: Verticale Line To\n"
        "C: Cubic Bézier Curve\n"
        "Q: Quadratic Bézier Curve\n"
        "Z: Close Path\n\n");

    path_t *path = malloc(sizeof(path_t));
    path->length = 0;
    path->start = NULL;

    int choice_user = 1;

    printf("\n\033[33mCOMMANDES\033[0m\n");
    do {
        path_element_t *element = malloc(sizeof(path_element_t));

        int is_command_valid = 0;

        do {
            printf("- Commande (M, L, H, V, C, Q, Z) : ");
            scanf("%c", &element->command);

            switch (element->command) {
                case 'M': 
                case 'L': 
                case 'H': 
                case 'V': 
                case 'C': 
                case 'Q': 
                case 'Z':
                    is_command_valid = 1;
                break;
                default:
                    printf("\033[31mVeuillez entrer une commande SVG valide.\033[0m");
                break;
            }
        } while (is_command_valid == 0);

        initialization_points_path (element);

        push_in_path(path, element);

        choice_user = ask_for_int_in_range(
            "Voulez-vous ajouter une autre commande a votre \033[33mpath\033[0m ? "
            "(1: oui / 2: non)\n",
            "\033[31mMerci d'entrer 1 ou 2.\033[0m",
            1,
            2
        );

    } while (choice_user == 1);

    printf("\n\033[33mCOULEURS\033[0m\n");
    path->color.stroke.r = ask_color("- Couleur de trait en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.stroke.g = ask_color("- Couleur de trait \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.stroke.b = ask_color("- Couleur de trait \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.stroke.a = ask_opacity_color("- Opacite de trait (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");
    path->color.fill.r = ask_color("\n- Couleur de fond en rgba "
        "\033[31m(r)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.fill.g = ask_color("- Couleur de fond \033[32m(g)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.fill.b = ask_color("- Couleur de fond \033[34m(b)\033[0m: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 255.\033[0m");
    path->color.fill.a = ask_opacity_color("- Opacite de fond (decimal de a) "
        "entre 0 et 9: ",
        "\033[31mMerci d'entrer un nombre entre 0 et 9.\033[0m");

    printf("\n\033[33mANGLE\033[0m\n");
    path->angle = ask_for_int("- Angle de rotation: ",
        "\033[31mMerci d'entrer un nombre entier.\033[0m");

    show_created_path(path);

    return path;
}


void show_created_path(path_t *path) {
    path_element_t *element = path->start;
    printf("\nVotre \033[33mchemin\033[0m aura pour commandes:");

    while (element != NULL) {
        printf(" (\033[33m%c\033[0m", element->command);

        switch (element->command) {
            case 'M':
            case 'L':
                printf(" %d,%d", element->x, element->y);
            break;
            case 'H':
                printf(" %d", element->x);
            break;
            case 'V':
                printf(" %d", element->y);
            break;
            case 'Q':
                printf(" %d,%d %d,%d",
                    element->x, element->y,
                    element->x1, element->y1);
            break;
            case 'C':
                printf(" %d,%d %d,%d %d,%d",
                    element->x, element->y,
                    element->x1, element->y1,
                    element->x2, element->y2);
            break;
            default:
            break;
        }
        printf(")");
        element = element->next;
    }

    printf(", couleur de trait: \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
           " couleur de fond: \033[33mrgba(%d,%d,%d,0.%d)\033[0m,"
           " et angle: \033[33m%d°\033[0m\n\n",
        path->color.stroke.r,
        path->color.stroke.g,
        path->color.stroke.b,
        path->color.stroke.a,
        path->color.fill.r,
        path->color.fill.g,
        path->color.fill.b,
        path->color.fill.a,
        path->angle
    );
}


void initialization_points_path (path_element_t *element) {
    switch (element->command) {
            case 'M':
            case 'L':
                element->x = ask_for_unsigned_int("- Coordo x: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y = ask_for_unsigned_int("- Coordo y: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->x1 = element->y1 = element->x2 = element->y2 = 0;
            break;
            case 'H':
                element->x = ask_for_unsigned_int("- Coordo x: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y = element->x1 = element->y1 = element->x2 = element->y2 = 0;
            break;
            case 'V':
                element->y = ask_for_unsigned_int("- Coordo y: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->x = element->x1 = element->y1 = element->x2 = element->y2 = 0;
            break;
            case 'C':
                element->x1 = ask_for_unsigned_int("- Coordo x1: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y1 = ask_for_unsigned_int("- Coordo y1: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->x2 = ask_for_unsigned_int("- Coordo x2: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y2 = ask_for_unsigned_int("- Coordo y2: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->x = ask_for_unsigned_int("- Coordo x fin: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y = ask_for_unsigned_int("- Coordo y fin: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
            break;
            case 'Q':
                element->x1 = ask_for_unsigned_int("- Coordo x1: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y1 = ask_for_unsigned_int("- Coordo y1: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->x = ask_for_unsigned_int("- Coordo x fin: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");
                element->y = ask_for_unsigned_int("- Coordo y fin: ",
                    "\033[31mMerci d'entrer un nombre entier.\033[0m");  
                element->x2 = element->y2 = 0;
            break;
            default:
                element->x = element->y = element->x1 = element->y1 = element->x2 = element->y2 = 0;
            break;
        }
}


void push_in_path(path_t *path, path_element_t *element) {
    element->next = NULL;
    path->length++;

    path_element_t *cursor = path->start;
    if (cursor == NULL) {
        path->start = element;
        return;
    }

    while (cursor->next != NULL) {
        cursor = cursor->next;
    }

    cursor->next = element;
}