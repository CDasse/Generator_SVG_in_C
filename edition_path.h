#ifndef DEF_EDITION_PATH
#define DEF_EDITION_PATH

#include "shapes.h"


void edition_path_in_table(shape_struct_t *shape);


void choice_edition_path(shape_struct_t *shape, int choice_edition_user);


void edition_coordo_path(shape_struct_t *shape);


void edition_color_path(shape_struct_t *shape);


void edition_position_path(shape_struct_t *shape);


void edition_angle_path(shape_struct_t *shape);


path_element_t *get_position_in_path(path_t *liste);


#endif