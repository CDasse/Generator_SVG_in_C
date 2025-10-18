#ifndef DEF_FREE_MALLOC
#define DEF_FREE_MALLOC

#include "shapes.h"


void free_viewbox(viewbox_t *viewbox);


void free_ellipse(ellipse_t *ellipse);


void free_rect(rect_t *rect);


void free_line(line_t *line);


void free_liste(liste_t *liste);


void free_elements_in_liste(liste_t *liste);


void free_path(path_t *path);


void free_elements_in_path(path_t *path);


void free_shape_in_table(shape_struct_t *shape);


void free_all(array_t *array, viewbox_t *viewbox);


#endif