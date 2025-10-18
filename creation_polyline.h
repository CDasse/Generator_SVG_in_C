#ifndef DEF_CREATION_POLYLINE
#define DEF_CREATION_POLYLINE

#include "shapes.h"


void polyline_for_creation(array_t *array);


liste_t *create_polyline();


void push_in_list(liste_t *list, list_element_t *element, int x, int y);


#endif