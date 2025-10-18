#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"


void free_viewbox(viewbox_t *viewbox) {
    free(viewbox);
}


void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


void free_rect(rect_t *rect) {
    free(rect);
}


void free_line(line_t *line) {
    free(line);
}


void free_liste(liste_t *liste) {
    free(liste);
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


void free_path(path_t *path) {
    free(path);
}


void free_elements_in_path(path_t *path) {
    path_element_t *element = path->start;
    path_element_t *temp = NULL;

    while (element != NULL) {
        temp = element->next;
        free(element);
        element = temp;
    }

    free_path(path);
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
        case SHAPE_PATH:
            free_elements_in_path(shape->union_shape.path);
        break;
        default :
            printf("\033[31mUne erreur est survenue\033[0m");
            break;
        }
        free(shape);
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