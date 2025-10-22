#ifndef DEF_EDITION_RECTANGLE
#define DEF_EDITION_RECTANGLE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de son rectangle
 *  (coordonnees, couleurs, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_rectangle_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_rectangle(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur les nouvelles coordonnees du rectangle.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_rectangle(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur les nouvelles couleurs (de trait et de fond) du rectangle.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_rectangle(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y du rectangle.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_rectangle(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle du rectangle.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_rectangle(shape_struct_t *shape);


#endif