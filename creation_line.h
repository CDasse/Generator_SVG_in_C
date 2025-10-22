#ifndef DEF_CREATION_LINE
#define DEF_CREATION_LINE

#include "shapes.h"


/**
 * @brief Creation d'une nouvelle ligne et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void line_for_creation(array_t *array);


/**
 * @brief Creation et initialisation de la ligne avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Ligne creee.
 */
line_t *create_line();


#endif