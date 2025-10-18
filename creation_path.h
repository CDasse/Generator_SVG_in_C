#ifndef DEF_CREATION_PATH
#define DEF_CREATION_PATH

#include "shapes.h"


void path_for_creation(array_t *array);


path_t *create_path();


void initialization_points_path (path_element_t *element);


void push_in_path(path_t *path, path_element_t *element);


#endif