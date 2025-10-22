#ifndef DEF_MENU_REMOVE
#define DEF_MENU_REMOVE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur de choisir la forme qu'il souhaite supprimer avec confirmation.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 */
void choice_shape_for_remove(array_t *array, viewbox_t *viewbox);


/**
 * @brief Supprime du tableau la forme choisie par l'utilisateur apres confirmation et initialize
 *  l'index a NULL.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 * @param choice_user_remove Index du tableau choisi par l'utilisateur.
 */
void remove_shape(array_t *array, viewbox_t *viewbox, int choice_user_remove);


/**
 * @brief Demande la confirmation de l'utilisateur pour supprimer une forme.
 * 
 * @return Reponse oui ou non de l'utilisateur.
 */
int ask_for_confirmation_remove();


#endif