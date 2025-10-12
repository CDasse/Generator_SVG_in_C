#ifndef DEF_MODELS
#define DEF_MODELS

typedef struct node_stack_s node_stack_t;


typedef struct viewbox_s {
    int coordo_min_x;
    int coordo_min_y;
    unsigned int width;
    unsigned int height;
} viewbox_t;


typedef struct ellipse_s {
    int coordo_center_x;
    int coordo_center_y;
    int rayon_x;
    int rayon_y;
    // style_t *style;
} ellipse_t;


typedef struct rect_s {
    int coordo_start_x;
    int coordo_start_y;
    int width;
    int height;
    // style_t *style;
} rect_t;


typedef struct line_s {
    int coordo_start_x;
    int coordo_start_y;
    int coordo_end_x;
    int coordo_end_y;
} line_t;


typedef enum user_menu_choice_e {
    CHOICE_CREATION = 1,
    CHOICE_EDITION = 2,
    CHOICE_VISUALISATION = 3
} user_menu_choice_t;


typedef enum user_shape_choice_e {
    CHOICE_ELLIPSE = 1,
    CHOICE_RECTANGLE = 2,
    CHOICE_LINE = 3
} user_shape_choice_t;


typedef union shape_type_u {
    ellipse_t *ellipse;
    rect_t *rectangle;
    line_t *line;
} shape_type_t;


typedef enum shape_type_enum_e {
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE
} shape_type_enum_t;


typedef struct shape_struct_s {
    shape_type_t union_shape;
    shape_type_enum_t enum_shape;
} shape_struct_t;


typedef struct array_s {
    shape_struct_t* table[25];
    int index;
} array_t;


viewbox_t *create_viewbox();

void free_viewbox(viewbox_t *viewbox);


ellipse_t *create_ellipse();

void free_ellipse(ellipse_t *ellipse);


rect_t *create_rect();

void free_rect(rect_t *rect);


line_t *create_line();

void free_line(line_t *line);

void free_shape_in_table(shape_struct_t *shape);

array_t *create_array();

void free_array(array_t *array);

#endif