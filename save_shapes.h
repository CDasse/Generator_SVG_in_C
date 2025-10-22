#ifndef DEF_SAVE_SHAPES
#define DEF_SAVE_SHAPES

#include "shapes.h"


/**
 * @brief Redaction d'un format svg contenant les informations de l'ellipse dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_ellipse(shape_struct_t *shape, FILE *file);


/**
 * @brief Redaction d'un format svg contenant les informations du rectangle dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_rectangle(shape_struct_t *shape, FILE *file);


/**
 * @brief Redaction d'un format svg contenant les informations de la ligne dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_line(shape_struct_t *shape, FILE *file);


/**
 * @brief Redaction d'un format svg contenant les informations de la polyline dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_polyline(shape_struct_t *shape, FILE *file);


/**
 * @brief Redaction d'un format svg contenant les informations du polygone dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_polygone(shape_struct_t *shape, FILE *file);


/**
 * @brief Redaction d'un format svg contenant les informations du chemin dans un fichier.
 * 
 * @param shape Structure de la forme.
 * @param file Nom du fichier destinataire.
 */
void save_path(shape_struct_t *shape, FILE *file);


#endif