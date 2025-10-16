#ifndef DEF_SHAPES
#define DEF_SHAPES
#include <stdbool.h>

typedef struct node_stack_s node_stack_t;

typedef struct list_element_s list_element_t;

typedef struct liste_s liste_t;

typedef struct stroke_s stroke_t;

typedef struct fill_s fill_t;

typedef struct color_s color_t;


typedef struct viewbox_s {
    int coordo_min_x;
    int coordo_min_y;
    unsigned int width;
    unsigned int height;
} viewbox_t;


typedef struct stroke_s {
    int r;
    int g;
    int b;
    int a;
} stroke_t;


typedef struct fill_s {
    int r;
    int g;
    int b;
    int a;
} fill_t;


typedef struct color_s {
    stroke_t stroke;
    fill_t fill;
} color_t;


typedef struct ellipse_s {
    int coordo_center_x;
    int coordo_center_y;
    int rayon_x;
    int rayon_y;
    color_t color;
    int angle;
} ellipse_t;


typedef struct rect_s {
    int coordo_start_x;
    int coordo_start_y;
    int width;
    int height;
    color_t color;
    int angle;
} rect_t;


typedef struct line_s {
    int coordo_start_x;
    int coordo_start_y;
    int coordo_end_x;
    int coordo_end_y;
    color_t color;
    int angle;
} line_t;


typedef enum user_menu_choice_e {
    CHOICE_CREATION = 1,
    CHOICE_EDITION = 2,
    CHOICE_REMOVE = 3,
    CHOICE_SAVE = 4,
    CHOICE_EXIT = 5
} user_menu_choice_t;


typedef enum user_shape_choice_e {
    CHOICE_ELLIPSE = 1,
    CHOICE_RECTANGLE = 2,
    CHOICE_LINE = 3,
    CHOICE_POLYLINE = 4,
    CHOICE_POLYGONE = 5
} user_shape_choice_t;


typedef union shape_type_u {
    ellipse_t *ellipse;
    rect_t *rectangle;
    line_t *line;
    liste_t *polyline;
    liste_t *polygone;
} shape_type_t;


typedef enum shape_type_enum_e {
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE,
    SHAPE_POLYLINE,
    SHAPE_POLYGONE
} shape_type_enum_t;


typedef struct shape_struct_s {
    shape_type_t union_shape;
    shape_type_enum_t enum_shape;
} shape_struct_t;


typedef struct array_s {
    shape_struct_t* table[40];
    int index;
} array_t;


typedef struct list_element_s {
   int value1;
   int value2;
   list_element_t *next;
} list_element_t;


typedef struct liste_s {
    int length;
    color_t color;
    int angle;
    list_element_t *start;
} liste_t;


viewbox_t *create_viewbox();

void free_viewbox(viewbox_t *viewbox);


array_t *create_array();

void initialize_array(array_t *array);

void free_shape_in_table(shape_struct_t *shape);

int ask_for_confirmation();


ellipse_t *create_ellipse();

void free_ellipse(ellipse_t *ellipse);


rect_t *create_rect();

void free_rect(rect_t *rect);


line_t *create_line();

void free_line(line_t *line);


void free_all(array_t *array, viewbox_t *viewbox);


liste_t *create_polyline();

liste_t *create_polygone();

void push_in_list(liste_t *list, list_element_t *liste_element, int x, int y);

void free_liste(liste_t *liste);

void free_element(list_element_t *element);

void free_elements_in_liste(liste_t *liste);


#endif