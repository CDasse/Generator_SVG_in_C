// cli : command line interface

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "cli.h"


void clear_buffer() {
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


int ask_for_int(char *message, char *error_message) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        fprintf(stdout, "%s", message);

        if (scanf ("%d", &temp) > 0) {
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }

        clear_buffer();
    }

    return temp;
}


unsigned int ask_for_unsigned_int(char *message, char *error_message) {
    int value = -1;
    while (value < 0) {
        value = ask_for_int(message, error_message);
    }
    return (unsigned int) value;
}


int ask_for_int_in_range_1_to_2(char *message, char *error_message) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp > 0) && (temp < 3)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }

        clear_buffer();
    }
   
    return temp;
}


int ask_for_int_in_range_1_to_3(char *message, char *error_message) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp > 0) && (temp < 4)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }

        clear_buffer();
    }
   
    return temp;
}


int ask_for_int_in_range_1_to_4(char *message, char *error_message) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp > 0) && (temp < 5)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }

        clear_buffer();
    }
   
    return temp;
}


int ask_for_int_in_range_1_to_5(char *message, char *error_message) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) { 
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp > 0) && (temp < 6)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }

        clear_buffer();
    }
   
    return temp;
}


int ask_for_int_in_table(char *message, char *error_message, array_t *array) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp >= 0) && (temp < array->index)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }
        
        clear_buffer();
    }
   
    return temp;
}


int ask_for_int_in_liste(char *message, char *error_message, liste_t *liste) {
    int temp = 0;
    bool is_user_input_valid = false;

    while (! is_user_input_valid) {
        
        fprintf(stdout, "%s", message);

        if ((scanf ("%d", &temp) > 0) && (temp >= 1) && (temp <= liste->lenght)) {
            printf("\n");
            is_user_input_valid = true;
        } else {
            fprintf(stdout, "%s\n", error_message);
        }
        
        clear_buffer();
    }
   
    return temp;
}