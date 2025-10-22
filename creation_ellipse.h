#ifndef DEF_CREATION_ELLIPSE
#define DEF_CREATION_ELLIPSE

#include "shapes.h"


/**
 * @brief Creation d'une nouvelle ellipse et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void ellipse_for_creation(array_t *array);


/**
 * @brief Creation et initialisation de l'ellipse avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Ellipse creee.
 */
ellipse_t *create_ellipse();


#endif