#ifndef DEF_CLI
#define DEF_CLI

#include "shapes.h"


void clear_buffer();


int ask_for_int(char *message, char *error_message);


unsigned int ask_for_unsigned_int(char *message, char *error_message);


int ask_for_int_in_range(char *message, char *error_message, int min, int max);


int ask_for_int_in_table(char *message, char *error_message, array_t *array);


int ask_for_int_in_liste(char *message, char *error_message, liste_t *liste);


int ask_color (char *message, char *error_message);


int ask_opacity_color (char *message, char *error_message);


#endif