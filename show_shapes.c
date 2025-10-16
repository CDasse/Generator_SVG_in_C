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
            case SHAPE_POLYGONE:
                show_polygone_in_table (i, array->table[i]);
            break;
            default:
                printf("[%d] Forme supprimée.\n", i);
            break;
        }
    }
}


void show_ellipse_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo centre: %d/%d, rayons: %dpx/%dpx, couleur de trait: rgba(%d,%d,%d,0.%d)"
        ", couleur de fond: rgba(%d,%d,%d,0.%d)\n",
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
        shape->union_shape.ellipse->color.fill.a
    );
}


void show_rectangle_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo premier point: %d/%d, largeur: %dpx, hauteur: %dpx"
        ", couleur de trait: rgba(%d,%d,%d,0.%d), couleur de fond: rgba(%d,%d,%d,0.%d)\n",
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
        shape->union_shape.rectangle->color.fill.a
    );
}


void show_line_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / coordo premier point: %d/%d, coordo deuxieme point: %d/%d"
        ", couleur de trait: rgba(%d,%d,%d,0.%d)\n",
        i,
        get_shape_type(shape->enum_shape),
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


void show_polyline_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / points :", i, get_shape_type(shape->enum_shape));

    liste_t *polyline = shape->union_shape.polyline;
    list_element_t *element = polyline->start;

    while (element != NULL) {
        printf(" (%d/%d) ", element->value1, element->value2);
        element = element->next;
    }

    printf(", couleur de trait: rgba(%d,%d,%d,0.%d)\n",
        polyline->color.stroke.r,
        polyline->color.stroke.g,
        polyline->color.stroke.b,
        polyline->color.stroke.a
    );
}


void show_polygone_in_table(int i, shape_struct_t *shape) {
    printf("[%d] %s / points :", i, get_shape_type(shape->enum_shape));

    liste_t *polygone = shape->union_shape.polygone;
    list_element_t *element = polygone->start;

    while (element != NULL) {
        printf(" (%d/%d) ", element->value1, element->value2);
        element = element->next;
    }
    printf(", couleur de trait: rgba(%d,%d,%d,0.%d),"
        " couleur de fond: rgba(%d,%d,%d,0.%d))\n",
        polygone->color.stroke.r,
        polygone->color.stroke.g,
        polygone->color.stroke.b,
        polygone->color.stroke.a,
        polygone->color.fill.r,
        polygone->color.fill.g,
        polygone->color.fill.b,
        polygone->color.fill.a
    );
}