#ifndef DEF_CLI
#define DEF_CLI

#include "shapes.h"


/**
 * @brief Reinitialisation du buffer.
 */
void clear_buffer();


/**
 * @brief Demande a l'utilisateur d'entrer un nombre entier.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_int(char *message, char *error_message);


/**
 * @brief Demande a l'utilisateur d'entrer un nombre entier positif.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @return Nombre entre par l'utilisateur.
 */
unsigned int ask_for_unsigned_int(char *message, char *error_message);


/**
 * @brief Demande a l'utilisateur d'entrer le nombre 1.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_1(char *message, char *error_message);


/**
 * @brief Demande a l'utilisateur d'entrer un nombre compris dans une fourchette
 *  de nombres.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @param min Nombre minimum possible.
 * @param max Nombre maximum possible.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_int_in_range(char *message, char *error_message, int min, int max);


/**
 * @brief Demande a l'utilisateur d'entrer un index d'un tableau.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @param array Tableau concerne.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_int_in_table(char *message, char *error_message, array_t *array);


/**
 * @brief Demande a l'utilisateur d'entrer un index d'une liste.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @param liste Liste concernee.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_int_in_liste(char *message, char *error_message, liste_t *liste);


/**
 * @brief Demande a l'utilisateur d'entrer un index d'un chemin.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @param path Chemin concerne.
 * @return Nombre entre par l'utilisateur.
 */
int ask_for_int_in_path(char *message, char *error_message, path_t *path);


/**
 * @brief Demande a l'utilisateur d'entrer un nombre pour une couleur en rgba.
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @return Nombre entre par l'utilisateur.
 */
int ask_color (char *message, char *error_message);


/**
 * @brief Demande a l'utilisateur d'entrer un nombre pour une opacite
 *  de couleur (decimal).
 * 
 * @param message Message indiquant ce que l'utilisateur doit entrer.
 * @param error_message Message d'erreur si l'utilisateur a entrer
 *  une commande qui ne correspond pas.
 * @return Nombre entre par l'utilisateur.
 */
int ask_opacity_color (char *message, char *error_message);


#endif