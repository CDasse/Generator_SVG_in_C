#ifndef DEF_CREATION_POLYGONE
#define DEF_CREATION_POLYGONE

#include "shapes.h"


/**
 * @brief Creation d'un nouveau polygone et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void polygone_for_creation(array_t *array);


/**
 * @brief Creation et initialisation du polygone avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Polygone creee.
 */
liste_t *create_polygone();


#endif