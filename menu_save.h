#ifndef DEF_MENU_SAVE
#define DEF_MENU_SAVE

#include "shapes.h"

/**
 * @brief Ouverture du fichier externe .svg, redaction des codes HTML 
 * de la viewbox et des formes, fermeture du fichier.
 * 
 * @param array Tableau de stockage des formes.
 * @param viewbox Fenetre de visualisation.
 */
void save_projet(array_t *array, viewbox_t *viewbox);


/**
 * @brief Redaction du code HTML en fonction du type de forme du
 *  tableau.
 * 
 * @param array Tableau de stockage des formes.
 * @param saved_file Nom du fichier destinataire.
 */
void save_shapes_in_projet(array_t *array, FILE *saved_file);


#endif