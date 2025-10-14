#ifndef DEF_SAVE_SHAPES
#define DEF_SAVE_SHAPES

#include "shapes.h"

void save_projet(array_t *array, viewbox_t *viewbox);


void save_ellipse(shape_struct_t *shape, FILE *file);


void save_rectangle(shape_struct_t *shape, FILE *file);


void save_line(shape_struct_t *shape, FILE *file);


#endif