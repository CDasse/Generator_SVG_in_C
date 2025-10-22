#ifndef DEF_CREATION_PATH
#define DEF_CREATION_PATH

#include "shapes.h"


/**
 * @brief Creation d'un nouveau chemin et affectation dans le tableau de formes.
 * 
 * @param array Tableau de formes.
 */
void path_for_creation(array_t *array);


/**
 * @brief Creation et initialisation du chemin avec les donnees de l'utilisateur
 *  puis affichage dans le terminal.
 * 
 * @return Chemin creee.
 */
path_t *create_path();


/**
 * @brief Affichage des donnees du chemin dans le terminal.
 * 
 * @param path Chemin.
 */
void show_created_path(path_t *path);


/**
 * @brief Initialisation des commandes du chemin.
 * 
 * @param element Position de la commande dans le chemin.
 */
void initialization_points_path (path_element_t *element);


/**
 * @brief Affectation de la nouvelle commande dans le chemin.
 * 
 * @param path Chemin.
 * @param element Poiteur vers la commande.
 */
void push_in_path(path_t *path, path_element_t *element);


#endif