#ifndef DEF_MENU_CREATION
#define DEF_MENU_CREATION

#include "shapes.h"


/**
 * @brief Creation de la forme voulue par l'utilisateur et insertion dans le tableau de forme.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 * @throws Action impossible si le tableau contient deja 40 formes (y compris les formes suprimees).
 */
void choice_shape_for_creation(array_t *array, viewbox_t *viewbox);


#endif