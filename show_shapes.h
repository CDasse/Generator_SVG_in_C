#ifndef DEF_SHOW_SHAPES
#define DEF_SHOW_SHAPES

#include "shapes.h"


char *get_shape_type(shape_type_enum_t type);


void show_shapes_in_table(array_t *array);


void show_ellipse_in_table(int i, shape_struct_t *shape);


void show_rectangle_in_table(int i, shape_struct_t *shape);


void show_line_in_table(int i, shape_struct_t *shape);


void show_polyline_in_table(int i, shape_struct_t *shape);


void show_polygone_in_table(int i, shape_struct_t *shape);


void show_path_in_table(int i, shape_struct_t *shape);


#endif