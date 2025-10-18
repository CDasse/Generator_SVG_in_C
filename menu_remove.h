#ifndef DEF_MENU_REMOVE
#define DEF_MENU_REMOVE

#include "shapes.h"


void choice_shape_for_remove(array_t *array, viewbox_t *viewbox);


void remove_shape(array_t *array, viewbox_t *viewbox, int choice_user_remove);


int ask_for_confirmation();


#endif