#include <stdio.h>
#include <stdlib.h>
#include "models.h"
#include "cli.h"


viewbox_t *create_viewbox() {
    viewbox_t *viewbox = malloc(sizeof(viewbox_t));
    viewbox->coordo_min_x = 0;
    viewbox->coordo_min_y = 0;
    viewbox->width = 0;
    viewbox->height = 0;
    return viewbox;
}


void free_viewbox(viewbox_t *viewbox) {
    free(viewbox);
}


ellipse_t *create_ellipse() {
    ellipse_t *ellipse = malloc(sizeof(ellipse_t));
    ellipse->coordo_center_x = 0;
    ellipse->coordo_center_y = 0;
    ellipse->rayon_x = 0;
    ellipse->rayon_y = 0;
    // ellipse->style = create_style();
    return ellipse;
}

void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


rect_t *create_rect() {
    rect_t *rect = malloc(sizeof(rect_t));
    rect->coordo_start_x = 0;
    rect->coordo_start_y = 0;
    rect->width = 0;
    rect->height = 0;
    return rect;
}


void free_rect(rect_t *rect) {
    free(rect);
}


line_t *create_line() {
    line_t *line = malloc(sizeof(line_t));
    line->coordo_start_x = 0;
    line->coordo_start_y = 0;
    line->coordo_end_x = 0;
    line->coordo_end_y = 0;
    return line;
}


void free_line(line_t *line) {
    free(line);
}