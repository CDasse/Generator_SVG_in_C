#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "show_shapes.h"


char *get_shape_type(shape_type_enum_t type) {
    switch (type) {
        case SHAPE_ELLIPSE:
            return "ELLIPSE";
        break;
        case SHAPE_RECTANGLE:
            return "RECTANGLE";
        break;
        case SHAPE_LINE:
            return "LIGNE";
        break;
        case SHAPE_POLYLINE:
            return "POLYLINE";
        break;
        case SHAPE_POLYGONE:
            return "POLYGONE";
        break;
        default:
            return "Forme inconnue";
        break;
    }
}


void show_shapes_in_table(array_t *array) {
    printf("\n");
    
    for (int i = 0; i < array->index; i++) {
        if (array->table[i] == NULL) {
            printf("[%d] \033[31mForme supprimée.\033[00m\n", i);
            continue;
        }

        switch (array->table[i]->enum_shape) {
            case SHAPE_ELLIPSE:
                show_ellipse_in_table(i, array->table[i]);
            break;
            case SHAPE_RECTANGLE:
                show_rectangle_in_table(i, array->table[i]);
            break;
            case SHAPE_LINE:
                show_line_in_table (i, array->table[i]);
            break;
            case SHAPE_POLYLINE:
                show_polyline_in_table (i, array->table[i]);
            break;
            case SHAPE_POLYGONE:
                show_polygone_in_table (i, array->table[i]);
            break;
            default:
                printf("[%d] \033[31mForme supprimée.\033[0m\n", i);
            break;
        }
    }
}


void show_ellipse_in_table(int i, shape_struct_t *shape) {
    printf("[%d] \033[33m%s\033[0m / coordo centre: \033[33m%d\033[0m/\033[33m%d\033[0m, rayons: \033[33m%dpx\033[0m/\033[33m%dpx\033[0m, couleur de trait: \033[33mrgba(%d,%d,%d,0.%d)\033[0m"
        ", couleur de fond: \033[33mrgba(%d,%d,%d,0.%d)\033[0m, angle: \033[33m%d°\033[0m\n",
        i,
        get_shape_type(shape->enum_shape),
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
        shape->union_shape.ellipse->color.fill.a,
        shape->union_shape.ellipse->angle
    );
}


void show_rectangle_in_table(int i, shape_struct_t *shape) {
    printf("[%d] \033[32m%s\033[0m / coordo premier point: \033[32m%d\033[0m/\033[32m%d\033[0m, largeur: \033[32m%dpx\033[0m, hauteur: \033[32m%dpx\033[0m"
        ", couleur de trait: \033[32mrgba(%d,%d,%d,0.%d)\033[0m, couleur de fond: \033[32mrgba(%d,%d,%d,0.%d)\033[0m"
        ", angle: \033[32m%d°\033[0m\n",
        i,
        get_shape_type(shape->enum_shape),
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
        shape->union_shape.rectangle->color.fill.a,
        shape->union_shape.rectangle->angle
    );
}


void show_line_in_table(int i, shape_struct_t *shape) {
    printf("[%d] \033[36m%s\033[0m / coordo premier point: \033[36m%d\033[0m/\033[36m%d\033[0m, coordo deuxieme point: \033[36m%d\033[0m/\033[36m%d\033[0m"
        ", couleur de trait: \033[36mrgba(%d,%d,%d,0.%d)\033[0m, angle: \033[36m%d°\033[0m\n",
        i,
        get_shape_type(shape->enum_shape),
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y,
        shape->union_shape.line->color.stroke.r,
        shape->union_shape.line->color.stroke.g,
        shape->union_shape.line->color.stroke.b,
        shape->union_shape.line->color.stroke.a,
        shape->union_shape.line->angle
    );
}


void show_polyline_in_table(int i, shape_struct_t *shape) {
    printf("[%d] \033[35m%s\033[0m / points :", i, get_shape_type(shape->enum_shape));

    liste_t *polyline = shape->union_shape.polyline;
    list_element_t *element = polyline->start;

    while (element != NULL) {
        printf(" (\033[35m%d\033[0m/\033[35m%d\033[0m) ", element->value1, element->value2);
        element = element->next;
    }

    printf(", couleur de trait: \033[35mrgba(%d,%d,%d,0.%d)\033[0m, angle: \033[35m%d°\033[0m\n",
        polyline->color.stroke.r,
        polyline->color.stroke.g,
        polyline->color.stroke.b,
        polyline->color.stroke.a,
        polyline->angle
    );
}


void show_polygone_in_table(int i, shape_struct_t *shape) {
    printf("[%d] \033[34m%s\033[0m / points :", i, get_shape_type(shape->enum_shape));

    liste_t *polygone = shape->union_shape.polygone;
    list_element_t *element = polygone->start;

    while (element != NULL) {
        printf(" (\033[34m%d\033[0m/\033[34m%d\033[0m) ", element->value1, element->value2);
        element = element->next;
    }
    printf(", couleur de trait: \033[34mrgba(%d,%d,%d,0.%d)\033[0m,"
        " couleur de fond: \033[34mrgba(%d,%d,%d,0.%d)\033[0m, angle: \033[34m%d°\033[0m\n",
        polygone->color.stroke.r,
        polygone->color.stroke.g,
        polygone->color.stroke.b,
        polygone->color.stroke.a,
        polygone->color.fill.r,
        polygone->color.fill.g,
        polygone->color.fill.b,
        polygone->color.fill.a,
        polygone->angle
    );
}