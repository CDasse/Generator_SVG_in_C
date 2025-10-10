#ifndef DEF_MODELS
#define DEF_MODELS


typedef struct viewbox_s {
    int coordo_min_x;
    int coordo_min_y;
    int width;
    int height;
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


viewbox_t *create_viewbox();
void free_viewbox(viewbox_t *viewbox);

ellipse_t *create_ellipse();
void free_ellipse(ellipse_t *ellipse);

rect_t *create_rect();
void free_rect(rect_t *rect);

line_t *create_line();
void free_line(line_t *line);


#endif