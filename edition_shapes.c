#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "cli.h"
#include "menu.h"
#include "show_shapes.h"
#include "edition_shapes.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox) {
    if (array->index == 0) {
        printf("Aucune forme n'est creee!\n\n");
    } else {
        show_shapes_in_table(array);
        int choice_user_edition = ask_for_int_in_table("\nQuelle forme voulez-vous modifier "
            "(indiquer son index) ?\n",
            "Merci d'entrer un index valide.",
            array
        );

        if (array->table[choice_user_edition] == NULL) {
            printf("Cette forme a ete supprimee.\n\n");
            menu_for_user(array, viewbox);
            return;
        }
    
        switch (array->table[choice_user_edition]->enum_shape) {
            case SHAPE_ELLIPSE:
                edition_ellipse_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_RECTANGLE:
                edition_rectangle_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_LINE:
                edition_line_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_POLYLINE:
                edition_polyline_in_table(array->table[choice_user_edition]);
            break;
            case SHAPE_POLYGONE:
                edition_polygone_in_table(array->table[choice_user_edition]);
            break;
            default:
                printf("Forme inconnue.\n");
            break;
        }
    }

    menu_for_user(array, viewbox);
}


void edition_ellipse_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "(1: les coordonnees / 2: les couleurs / 3: déplacement en x et y)\n",
        "Merci d'entrer un nombre entre 1 et 3.\n",
        1,
        3
    );

    if (choice_edition_user == 1) {
        edition_coordo_ellipse(shape);
    } else if (choice_edition_user == 2) {
        edition_color_ellispe(shape);
    } else {
        edition_position_ellipse(shape);
    }

    printf("\nVotre nouvelle ellipse aura un centre de coordonnees : x = %d / y = %d,"
        " un rayon x = %dpx, un rayon y = %dpx\nune couleur de trait = rgba(%d,%d,%d,0.%d)"
        " et une couleur de fond = rgba(%d,%d,%d,0.%d).\n\n", 
        shape->union_shape.ellipse->coordo_center_x,
        shape->union_shape.ellipse->coordo_center_y,
        shape->union_shape.ellipse->rayon_x,
        shape->union_shape.ellipse->rayon_y,
        shape->union_shape.ellipse->color.stroke.r,
        shape->union_shape.ellipse->color.stroke.g,
        shape->union_shape.ellipse->color.stroke.b,
        shape->union_shape.ellipse->color.stroke.a,
        shape->union_shape.ellipse->color.fill.r,
        shape->union_shape.ellipse->color.fill.g,
        shape->union_shape.ellipse->color.fill.b,
        shape->union_shape.ellipse->color.fill.a
    );
}


void edition_coordo_ellipse(shape_struct_t *shape) {
    shape->union_shape.ellipse->coordo_center_x = ask_for_unsigned_int("coordo centre x: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->coordo_center_y = ask_for_unsigned_int("coordo centre y: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->rayon_x = ask_for_unsigned_int("rayon x: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.ellipse->rayon_y = ask_for_unsigned_int("rayon y: ",
        "Merci d'entrer un nombre entier.");
}


void edition_color_ellispe(shape_struct_t *shape) {
    shape->union_shape.ellipse->color.stroke.r = ask_color("couleur de trait (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    shape->union_shape.ellipse->color.fill.r = ask_color("couleur de fond (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.ellipse->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
}


void edition_position_ellipse(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "Merci d'entrer un nombre entier");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "Merci d'entrer un nombre entier");

    shape->union_shape.ellipse->coordo_center_x += edition_in_x;
    shape->union_shape.ellipse->coordo_center_y += edition_in_y;
}


void edition_rectangle_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "(1: les coordonnees / 2: les couleurs / 3: déplacement en x et y)\n",
        "Merci d'entrer un nombre entre 1 et 3.\n",
        1,
        3
    );

    if (choice_edition_user == 1) {
        edition_coordo_rectangle(shape);
    } else if (choice_edition_user == 2) {
        edition_color_rectangle(shape);
    } else {
        edition_position_rectangle(shape);
    }

    printf("\nVotre nouveau rectangle aura son premier point aux coordonnees : x = %d / y = %d,"
        " une largeur de %dpx et une hauteur de %dpx,\nune couleur de trait = rgba(%d,%d,%d,0.%d)"
        " et une couleur de fond = rgba(%d,%d,%d,0.%d).\n\n", 
        shape->union_shape.rectangle->coordo_start_x,
        shape->union_shape.rectangle->coordo_start_y,
        shape->union_shape.rectangle->width,
        shape->union_shape.rectangle->height,
        shape->union_shape.rectangle->color.stroke.r,
        shape->union_shape.rectangle->color.stroke.g,
        shape->union_shape.rectangle->color.stroke.b,
        shape->union_shape.rectangle->color.stroke.a,
        shape->union_shape.rectangle->color.fill.r,
        shape->union_shape.rectangle->color.fill.g,
        shape->union_shape.rectangle->color.fill.b,
        shape->union_shape.rectangle->color.fill.a
    );
}


void edition_coordo_rectangle(shape_struct_t *shape) {
    shape->union_shape.rectangle->coordo_start_x = ask_for_unsigned_int("coordo x: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->coordo_start_y = ask_for_unsigned_int("coordo y: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->width = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.rectangle->height = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");
}


void edition_color_rectangle(shape_struct_t *shape) {
    shape->union_shape.rectangle->color.stroke.r = ask_color("couleur de trait (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    shape->union_shape.rectangle->color.fill.r = ask_color("couleur de fond (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.rectangle->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
}


void edition_position_rectangle(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "Merci d'entrer un nombre entier");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "Merci d'entrer un nombre entier");

    shape->union_shape.rectangle->coordo_start_x += edition_in_x;
    shape->union_shape.rectangle->coordo_start_y += edition_in_y;
}


void edition_line_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "(1: les coordonnees / 2: la couleur / 3: déplacement en x et y)\n",
        "Merci d'entrer un nombre entre 1 et 3.\n",
        1,
        3);

    if (choice_edition_user == 1) {
        edition_coordo_line(shape);
    } else if (choice_edition_user == 2) {
        edition_color_line(shape);
    } else {
        edition_position_line(shape);
    }

    printf("\nVotre nouvelle ligne aura son premier point aux coordonnees : x = %d / y = %d,"
        " et son deuxieme point aux coordonnees : x = %d / y = %d,\nune couleur de trait = rgba(%d,%d,%d,0.%d)\n\n", 
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y,
        shape->union_shape.line->color.stroke.r,
        shape->union_shape.line->color.stroke.g,
        shape->union_shape.line->color.stroke.b,
        shape->union_shape.line->color.stroke.a
    );
}


void edition_coordo_line(shape_struct_t *shape) {
    shape->union_shape.line->coordo_start_x = ask_for_unsigned_int("coordo x: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_start_y = ask_for_unsigned_int("coordo y: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_end_x = ask_for_unsigned_int("largeur: ",
        "Merci d'entrer un nombre entier.");
    shape->union_shape.line->coordo_end_y = ask_for_unsigned_int("hauteur: ",
        "Merci d'entrer un nombre entier.");
}


void edition_color_line(shape_struct_t *shape) {
    shape->union_shape.line->color.stroke.r = ask_color("couleur de trait (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.line->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.line->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.line->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
}


void edition_position_line(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "Merci d'entrer un nombre entier");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "Merci d'entrer un nombre entier");

    shape->union_shape.line->coordo_start_x += edition_in_x;
    shape->union_shape.line->coordo_start_y += edition_in_x;
    shape->union_shape.line->coordo_end_x += edition_in_y;
    shape->union_shape.line->coordo_end_y += edition_in_y;
}


void edition_polyline_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ? "
        "(1: les coordonnees / 2: la couleur / 3: déplacement en x et y)\n",
        "Merci d'entrer un nombre entre 1 et 3.\n",
        1,
        3
    );

    if (choice_edition_user == 1) {
        edition_coordo_polyline(shape);
    } else if (choice_edition_user == 2) {
        edition_color_polyline(shape);
    } else {
        edition_position_polyline(shape);
    }

    // ajouter possibilite de deplacer en x et y

    printf("\nLes modifications ont été enregistrées\n\n");
}


void edition_coordo_polyline(shape_struct_t *shape) {
    list_element_t *element = get_position_in_polyline(shape->union_shape.polyline);

    element->value1 = ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier.");
    element->value2 = ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.");
}


void edition_color_polyline(shape_struct_t *shape) {
    shape->union_shape.polyline->color.stroke.r = ask_color("couleur de trait (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polyline->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polyline->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polyline->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
}


void edition_position_polyline(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "Merci d'entrer un nombre entier");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "Merci d'entrer un nombre entier");

    list_element_t *element = shape->union_shape.polyline->start;

    for (int i = 0; i < shape->union_shape.polyline->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


list_element_t *get_position_in_polyline(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("Quel point souhaitez vous modifier ?\n",
        "Merci d'entrer un index correct.",
        liste
    );

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}


void edition_polygone_in_table(shape_struct_t *shape) {
    int choice_edition_user = ask_for_int_in_range("Que souhaitez-vous-modifier ?"
        "(1: les coordonnees / 2: la couleur / 3: déplacement en x et y)\n",
        "Merci d'entrer un nombre entre 1 et 3.\n",
        1,
        3
    );

    if (choice_edition_user == 1) {
        edition_coordo_polygone(shape);
    } else if (choice_edition_user == 2) {
        edition_color_polygone(shape);
    } else {
        edition_position_polygone(shape);
    }

    printf("\nLes modifications ont été enregistrées\n\n");
}


void edition_coordo_polygone(shape_struct_t *shape) {
    list_element_t *element = get_position_in_polygone(shape->union_shape.polygone);

    element->value1 = ask_for_unsigned_int("coordo x: ", "Merci d'entrer un nombre entier.");
    element->value2 = ask_for_unsigned_int("coordo y: ", "Merci d'entrer un nombre entier.");
}


void edition_color_polygone(shape_struct_t *shape) {
    shape->union_shape.polygone->color.stroke.r = ask_color("couleur de trait (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.stroke.g = ask_color("couleur de trait (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.stroke.b = ask_color("couleur de trait (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.stroke.a = ask_opacity_color("opacite de trait (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
    shape->union_shape.polygone->color.fill.r = ask_color("couleur de fond (r): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.fill.g = ask_color("couleur de fond (g): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.fill.b = ask_color("couleur de fond (b): ",
        "Merci d'entrer un nombre entre 0 et 255.");
    shape->union_shape.polygone->color.fill.a = ask_opacity_color("opacite de fond (decimal de a) entre 0 et 9: ",
        "Merci d'entrer un nombre entre 0 et 9.");
}


void edition_position_polygone(shape_struct_t *shape) {
    int edition_in_x = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en x ?\n",
        "Merci d'entrer un nombre entier");
    int edition_in_y = ask_for_int("De combien de pixels voulez-vous deplacer votre figure en y ?\n",
        "Merci d'entrer un nombre entier");

    list_element_t *element = shape->union_shape.polygone->start;

    for (int i = 0; i < shape->union_shape.polygone->length; i++) {
        element->value1 += edition_in_x;
        element->value2 += edition_in_y;

        element = element->next;
    }
}


list_element_t *get_position_in_polygone(liste_t *liste) {
    int position_user_choice = ask_for_int_in_liste("Quel point souhaitez vous modifier ?\n",
        "Merci d'entrer un index correct.",
        liste
    );

    list_element_t *element = liste->start;

    for (int i = 0; i < position_user_choice - 1; i++) {
        element = element->next;
    }

    return element;
}