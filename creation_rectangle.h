#ifndef DEF_CREATION_RECTANGLE
#define DEF_CREATION_RECTANGLE

#include "shapes.h"


/**
 * @brief Creation d'un nouveau rectangle et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void rect_for_creation(array_t *array);


/**
 * @brief Creation et initialisation du rectangle avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Rectangle cree.
 */
rect_t *create_rect();


#endif