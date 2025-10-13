#ifndef DEF_FUNCTIONS
#define DEF_FUNCTIONS

#include "shapes.h"

void menu_for_user (array_t array[], viewbox_t *viewbox);

void choice_shape_for_creation (array_t array[], viewbox_t *viewbox);

void ellipse_for_creation(array_t array[]);

void rect_for_creation(array_t array[]);

void line_for_creation(array_t array[]);

char *get_shape_type(shape_type_enum_t type);

void show_shapes_in_table(array_t array[]);

void choice_shape_for_edition(array_t array[], viewbox_t *viewbox);

void choice_shape_for_remove(array_t array[], viewbox_t *viewbox);

void save_projet (array_t array[], viewbox_t *viewbox);


#endif