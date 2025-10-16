#ifndef DEF_EDITION_SHAPES
#define DEF_EDITION_SHAPES

#include "shapes.h"


void choice_shape_for_edition(array_t *array, viewbox_t *viewbox);


void edition_ellipse_in_table(shape_struct_t *shape);

void edition_coordo_ellipse(shape_struct_t *shape);

void edition_color_ellipse(shape_struct_t *shape);

void edition_position_ellipse(shape_struct_t *shape);

void edition_angle_ellipse(shape_struct_t *shape);


void edition_rectangle_in_table(shape_struct_t *shape);

void edition_coordo_rectangle(shape_struct_t *shape);

void edition_color_rectangle(shape_struct_t *shape);

void edition_position_rectangle(shape_struct_t *shape);

void edition_angle_rectangle(shape_struct_t *shape);


void edition_line_in_table(shape_struct_t *shape);

void edition_coordo_line(shape_struct_t *shape);

void edition_color_line (shape_struct_t *shape);

void edition_position_line(shape_struct_t *shape);

void edition_angle_line(shape_struct_t *shape);


void edition_polyline_in_table(shape_struct_t *shape);

void edition_coordo_polyline(shape_struct_t *shape);

void edition_color_polyline(shape_struct_t *shape);

void edition_position_polyline(shape_struct_t *shape);

void edition_angle_polyline(shape_struct_t *shape);

list_element_t *get_position_in_polyline(liste_t *liste);


void edition_polygone_in_table(shape_struct_t *shape);

void edition_coordo_polygone(shape_struct_t *shape);

void edition_color_polygone(shape_struct_t *shape);

void edition_position_polygone(shape_struct_t *shape);

void edition_angle_polygone(shape_struct_t *shape);

list_element_t *get_position_in_polygone(liste_t *liste);


#endif