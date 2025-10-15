#ifndef DEF_CLI
#define DEF_CLI

#include "shapes.h"

void clear_buffer();


int ask_for_int(char *message, char *error_message);


unsigned int ask_for_unsigned_int(char *message, char *error_message);


int ask_for_int_in_range_1_to_2(char *message, char *error_message);


int ask_for_int_in_range_1_to_3(char *message, char *error_message);


int ask_for_int_in_range_1_to_4(char *message, char *error_message);


int ask_for_int_in_range_1_to_5(char *message, char *error_message);


int ask_for_int_in_table(char *message, char *error_message, array_t *array);


int ask_for_int_in_liste(char *message, char *error_message, liste_t *liste);


#endif