#ifndef DEF_EDITION_PATH
#define DEF_EDITION_PATH

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de son chemin
 *  (coordonnees, couleurs, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_path_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_path(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur quelle commande il souhaite modifier de son chemin
 *  et les nouvelles coordonnes.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_path(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur les nouvelles couleurs (de trait et de fond) du chemin.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_path(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y du chemin.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_path(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle du chemin.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_path(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur quel commande du chemin il souhaite modifier.
 * 
 * @param liste Le chemin.
 * @return Point designe par l'utilisateur.
 */
path_element_t *get_position_in_path(path_t *liste);


#endif