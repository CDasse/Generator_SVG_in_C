#ifndef DEF_CREATION_SHAPES
#define DEF_CREATION_SHAPES

#include "shapes.h"

void choice_shape_for_creation(array_t *array, viewbox_t *viewbox);


void ellipse_for_creation(array_t *array);


void rect_for_creation(array_t *array);


void line_for_creation(array_t *array);


void polyline_for_creation(array_t *array);


void free_struct(shape_struct_t *struc);


#endif