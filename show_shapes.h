#ifndef DEF_SHOW_SHAPES
#define DEF_SHOW_SHAPES

#include "shapes.h"

/**
 * @brief Recupere le nom de la forme d'une structure de forme.
 * 
 * @param type Enumeration de la structure de forme.
 * @return Le nom de la structure sous forme de chaine de caractere.
 */
char *get_shape_type(shape_type_enum_t type);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  des formes presentes dans le tableau.
 * 
 * @param array Tableau de forme.
 */
void show_shapes_in_table(array_t *array);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'une ellipse dans le tableau.
 * 
 * @param i Index du tableau contenant l'ellipse.
 * @param shape Structure de la forme.
 */
void show_ellipse_in_table(int i, shape_struct_t *shape);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'un rectangle dans le tableau.
 * 
 * @param i Index du tableau contenant le rectangle.
 * @param shape Structure de la forme.
 */
void show_rectangle_in_table(int i, shape_struct_t *shape);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'une ligne dans le tableau.
 * 
 * @param i Index du tableau contenant la ligne.
 * @param shape Structure de la forme.
 */
void show_line_in_table(int i, shape_struct_t *shape);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'une polyline dans le tableau.
 * 
 * @param i Index du tableau contenant la polyline.
 * @param shape Structure de la forme.
 */
void show_polyline_in_table(int i, shape_struct_t *shape);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'un polygone dans le tableau.
 * 
 * @param i Index du tableau contenant le polygone.
 * @param shape Structure de la forme.
 */
void show_polygone_in_table(int i, shape_struct_t *shape);


/**
 * @brief Affichage des informations (coordonnees/couleur/angle)
 *  d'un chemin dans le tableau.
 * 
 * @param i Index du tableau contenant le chemin.
 * @param shape Structure de la forme.
 */
void show_path_in_table(int i, shape_struct_t *shape);


#endif