#ifndef DEF_EDITION_POLYGONE
#define DEF_EDITION_POLYGONE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de son polygone
 *  (coordonnees, couleurs, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_polygone_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_polygone(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur s'il souhaite editer ou supprimer un point du polygone
 *  et le redirige vers la bonne fonction.
 * 
 * @param shape Structure de la forme.
 */
void edition_or_remove_coordo_polygone(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel point il souhaite modifier et ses nouvelles coordonnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_polygone(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel point il souhaite supprimer et le retire du polygone.
 * 
 * @param shape Structure de la forme.
 */
void remove_coordo_polygone(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur les nouvelles couleurs (de trait et de fond) du polygone.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_polygone(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y du polygone.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_polygone(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle du polygone.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_polygone(shape_struct_t *shape);


#endif