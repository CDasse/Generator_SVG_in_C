#ifndef DEF_SAVE_SHAPES
#define DEF_SAVE_SHAPES

#include "shapes.h"


void save_ellipse(shape_struct_t *shape, FILE *file);


void save_rectangle(shape_struct_t *shape, FILE *file);


void save_line(shape_struct_t *shape, FILE *file);


void save_polyline(shape_struct_t *shape, FILE *file);


void save_polygone(shape_struct_t *shape, FILE *file);


void save_path(shape_struct_t *shape, FILE *file);


#endif