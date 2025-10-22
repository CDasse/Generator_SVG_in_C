#ifndef DEF_EDITION_POLYLINE
#define DEF_EDITION_POLYLINE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de sa polyline
 *  (coordonnees, couleur, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_polyline_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_polyline(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur s'il souhaite editer ou supprimer un point de la polyline
 *  et le redirige vers la bonne fonction.
 * 
 * @param shape Structure de la forme.
 */
void edition_or_remove_coordo_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel point il souhaite modifier et ses nouvelles coordonnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel point il souhaite supprimer et le retire de la polyline.
 * 
 * @param shape Structure de la forme.
 */
void remove_coordo_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur la nouvelle couleur de trait de la polyline.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y de la polyline.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle de la polyline.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_polyline(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel point de la polyline ou du polygone il souhaite modifier.
 * 
 * @param liste La polyline ou le polygone concerne.
 * @return Point designe par l'utilisateur.
 */
list_element_t *get_position_in_liste(liste_t *liste);


#endif