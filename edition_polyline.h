#ifndef DEF_EDITION_POLYLINE
#define DEF_EDITION_POLYLINE

#include "shapes.h"


void edition_polyline_in_table(shape_struct_t *shape);


void choice_edition_polyline(shape_struct_t *shape, int choice_edition_user);


void edition_coordo_polyline(shape_struct_t *shape);


void edition_color_polyline(shape_struct_t *shape);


void edition_position_polyline(shape_struct_t *shape);


void edition_angle_polyline(shape_struct_t *shape);


list_element_t *get_position_in_liste(liste_t *liste);


#endif