#ifndef DEF_FREE_MALLOC
#define DEF_FREE_MALLOC

#include "shapes.h"


/**
 * @brief Liberation de l'allocation dynamique de la fenetre de visualisation.
 * 
 * @param viewbox Fenetre de visualisation.
 */
void free_viewbox(viewbox_t *viewbox);


/**
 * @brief Liberation de l'allocation dynamique de l'ellipse.
 * 
 * @param ellipse Ellipse.
 */
void free_ellipse(ellipse_t *ellipse);


/**
 * @brief Liberation de l'allocation dynamique du rectangle.
 * 
 * @param rect Rectangle.
 */
void free_rect(rect_t *rect);


/**
 * @brief Liberation de l'allocation dynamique de la ligne.
 * 
 * @param line Ligne.
 */
void free_line(line_t *line);


/**
 * @brief Liberation de l'allocation dynamique de la liste.
 * 
 * @param liste Liste.
 */
void free_liste(liste_t *liste);


/**
 * @brief Liberation de l'allocation dynamique des elements d'une liste et de la liste.
 * 
 * @param liste Liste.
 */
void free_elements_in_liste(liste_t *liste);


/**
 * @brief Liberation de l'allocation dynamique du chemin.
 * 
 * @param path Chemin.
 */
void free_path(path_t *path);


/**
 * @brief Liberation de l'allocation dynamique des elements d'un chemin et du chemin.
 * 
 * @param path Chemin.
 */
void free_elements_in_path(path_t *path);


/**
 * @brief Liberation de l'allocation dynamique des elements du tableau de forme.
 * 
 * @param shape Structures du tableau.
 */
void free_shape_in_table(shape_struct_t *shape);


/**
 * @brief Liberation de l'allocation dynamique des elements du tableau de forme,
 *  du tableau et de la viewbox.
 * 
 * @param array Tableau de formes.
 * @param viewbox Fenetre de visualisation.
 */
void free_all(array_t *array, viewbox_t *viewbox);


#endif