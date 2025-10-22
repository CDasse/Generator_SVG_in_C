#ifndef DEF_EDITION_LINE
#define DEF_EDITION_LINE

#include "shapes.h"


/**
 * @brief Demande a l'utilisateur ce qu'il souhaite modifier de sa ligne
 *  (coordonnees, couleur, deplacement en x et y ou rotation), modifie la forme
 *  et affiche ses nouvelles donnees.
 * 
 * @param shape Structure de la forme.
 */
void edition_line_in_table(shape_struct_t *shape);


/**
 * @brief Redirige vers la bonne fonction de modification en fonction du choix de l'utilisateur.
 * 
 * @param shape Structure de la forme.
 * @param choice_edition_user Choix de modification de l'utilisateur.
 */
void choice_edition_line(shape_struct_t *shape, int choice_edition_user);


/**
 * @brief Demande a l'utilisateur les nouvelles coordonnees de la ligne.
 * 
 * @param shape Structure de la forme.
 */
void edition_coordo_line(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur la nouvelle couleur de trait de la ligne.
 * 
 * @param shape Structure de la forme.
 */
void edition_color_line(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le deplacement en x et y de la ligne.
 * 
 * @param shape Structure de la forme.
 */
void edition_position_line(shape_struct_t *shape);


/**
 * @brief Demande a l'utilisateur le nouvelle angle de la ligne.
 * 
 * @param shape Structure de la forme.
 */
void edition_angle_line(shape_struct_t *shape);


#endif