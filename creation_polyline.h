#ifndef DEF_CREATION_POLYLINE
#define DEF_CREATION_POLYLINE

#include "shapes.h"


/**
 * @brief Creation d'une nouvelle polyline et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void polyline_for_creation(array_t *array);


/**
 * @brief Creation et initialisation de la polyline avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Polyline creee.
 */
liste_t *create_polyline();


/**
 * @brief Ajout d'un nouveau point dans une polyline ou un polygone.
 * 
 * @param list Polyline ou polygone.
 * @param element Pointeur vers le debut de la polyline ou du polygone.
 * @param x Coordonnee x du nouveau point.
 * @param y Coordonnee y du nouveau point.
 */
void push_in_list(liste_t *list, list_element_t *element, int x, int y);


#endif