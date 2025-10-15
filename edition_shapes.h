#ifndef DEF_EDITION_SHAPES
#define DEF_EDITION_SHAPES

#include "shapes.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox);


void edition_ellipse_in_table(shape_struct_t *shape);


void edition_rectangle_in_table(shape_struct_t *shape);


void edition_line_in_table(shape_struct_t *shape);


void edition_polyline_in_table(shape_struct_t *shape);


list_element_t *get_position_in_polyline(liste_t *liste);


#endif