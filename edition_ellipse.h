#ifndef DEF_EDITION_ELLIPSE
#define DEF_EDITION_ELLIPSE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de son ellipse
 *  (coordonnees, couleurs, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_ellipse_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_ellipse(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur les nouvelles coordonnees de l'ellipse.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_ellipse(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur les nouvelles couleurs (de trait et de fond) de l'ellipse.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_ellipse(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y de l'ellipse.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_ellipse(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle de l'ellipse.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_ellipse(shape_struct_t *shape);


#endif