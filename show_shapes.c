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
            return "POLYLIGNE";
        break;
        default:
            return "Forme inconnue";
        break;
    }
}


void show_shapes_in_table(array_t *array) {
    for (int i = 0; i < array->index; i++) {
        if (array->table[i] == NULL) {
            printf("[%d] Forme supprimée.\n", i);
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
            default:
                printf("[%d] Forme supprimée.\n", i);
            break;
        }
    }
}


void show_ellipse_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo centre: %d/%d, rayons: %dpx/%dpx\n",
        i,
        get_shape_type(shape->enum_shape),
        shape->union_shape.ellipse->coordo_center_x,
        shape->union_shape.ellipse->coordo_center_y,
        shape->union_shape.ellipse->rayon_x,
        shape->union_shape.ellipse->rayon_y
    );
}


void show_rectangle_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo premier point: %d/%d, largeur: %dpx, hauteur: %dpx\n",
        i,
        get_shape_type(shape->enum_shape),
        shape->union_shape.rectangle->coordo_start_x,
        shape->union_shape.rectangle->coordo_start_y,
        shape->union_shape.rectangle->width,
        shape->union_shape.rectangle->height
    );
}


void show_line_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo premier point: %d/%d, coordo deuxieme point: %d/%d\n",
        i,
        get_shape_type(shape->enum_shape),
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y
    );
}


void show_polyline_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / points :", i, get_shape_type(shape->enum_shape));

    liste_t *polyline = shape->union_shape.polyline;
    list_element_t *element = polyline->start;

    while (element != NULL) {
        printf(" (%d/%d) ", element->value1, element->value2);
        element = element->next;
    }
    printf("\n");
}