#ifndef DEF_MENU_EDITION
#define DEF_MENU_EDITION

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur de choisir la forme qu'il souhaite modifier avec confirmation.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 */
void choice_shape_for_edition(array_t *array, viewbox_t *viewbox);


/**
 * @brief Change la forme choisie par l'utilisateur, apres confirmation, avec ses modifications.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 * @param choice_user_edition Index du tableau choisi par l'utilisateur.
 */
void edition_shape_in_table(array_t *array, viewbox_t *viewbox, int choice_user_edition);


/**
 * @brief Demande la confirmation de l'utilisateur pour modifier une forme.
 * 
 * @return Reponse oui ou non de l'utilisateur.
 */
int ask_for_confirmation_edition();


#endif