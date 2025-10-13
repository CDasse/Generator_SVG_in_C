#ifndef DEF_CLI
#define DEF_CLI


void clear_buffer();

int ask_for_int(char *message, char *error_message);

unsigned int ask_for_unsigned_int(char *message, char *error_message);

int ask_for_int_in_range_1_to_3(char *message, char *error_message);

int ask_for_int_in_range_1_to_5(char *message, char *error_message);

int ask_for_int_in_table(char *message, char *error_message, array_t array[]);

#endif