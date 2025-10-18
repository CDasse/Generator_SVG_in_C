#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "save_shapes.h"
#include "shapes.h"
#include "cli.h"


void save_ellipse(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<ellipse cx='%d' cy='%d' rx='%d' ry='%d' "
        "stroke='rgba(%d,%d,%d,0.%d)' "
        "fill='rgba(%d,%d,%d,0.%d)' transform='rotate(%d)' />",
        shape->union_shape.ellipse->coordo_center_x,
        shape->union_shape.ellipse->coordo_center_y,
        shape->union_shape.ellipse->rayon_x,
        shape->union_shape.ellipse->rayon_y,
        shape->union_shape.ellipse->color.stroke.r,
        shape->union_shape.ellipse->color.stroke.g,
        shape->union_shape.ellipse->color.stroke.b,
        shape->union_shape.ellipse->color.stroke.a,
        shape->union_shape.ellipse->color.fill.r,
        shape->union_shape.ellipse->color.fill.g,
        shape->union_shape.ellipse->color.fill.b,
        shape->union_shape.ellipse->color.fill.a,
        shape->union_shape.ellipse->angle
    );
}


void save_rectangle(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<rect x='%d' y='%d' width='%d' height='%d' "
        "stroke='rgba(%d,%d,%d,0.%d)'"
        " fill='rgba(%d,%d,%d,0.%d)' transform='rotate(%d)' />",
        shape->union_shape.rectangle->coordo_start_x,
        shape->union_shape.rectangle->coordo_start_y,
        shape->union_shape.rectangle->width,
        shape->union_shape.rectangle->height,
        shape->union_shape.rectangle->color.stroke.r,
        shape->union_shape.rectangle->color.stroke.g,
        shape->union_shape.rectangle->color.stroke.b,
        shape->union_shape.rectangle->color.stroke.a,
        shape->union_shape.rectangle->color.fill.r,
        shape->union_shape.rectangle->color.fill.g,
        shape->union_shape.rectangle->color.fill.b,
        shape->union_shape.rectangle->color.fill.a,
        shape->union_shape.rectangle->angle
    );
}


void save_line(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<line x1='%d' y1='%d' x2='%d' y2='%d' "
        "stroke='rgba(%d,%d,%d,0.%d)'"
        " transform='rotate(%d)' />",
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y,
        shape->union_shape.line->color.stroke.r,
        shape->union_shape.line->color.stroke.g,
        shape->union_shape.line->color.stroke.b,
        shape->union_shape.line->color.stroke.a,
        shape->union_shape.line->angle
    );
}


void save_polyline(shape_struct_t *shape, FILE *file) {
    list_element_t *element = shape->union_shape.polyline->start;

    fprintf(file,"<polyline fill='none' stroke='rgba(%d,%d,%d,0.%d)' "
        "points='",
        shape->union_shape.polyline->color.stroke.r,
        shape->union_shape.polyline->color.stroke.g,
        shape->union_shape.polyline->color.stroke.b,
        shape->union_shape.polyline->color.stroke.a
    );

    while (element != NULL) {
        fprintf(file,"%d,%d ", element->value1, element->value2);
        element = element->next;
    }

    fprintf(file,"' transform='rotate(%d)'/>", shape->union_shape.polyline->angle);
}


void save_polygone(shape_struct_t *shape, FILE *file) {
    list_element_t *element = shape->union_shape.polygone->start;

    fprintf(file,"<polygon fill='rgba(%d,%d,%d,0.%d)' "
        "stroke='rgba(%d,%d,%d,0.%d)' points='",
        shape->union_shape.polygone->color.stroke.r,
        shape->union_shape.polygone->color.stroke.g,
        shape->union_shape.polygone->color.stroke.b,
        shape->union_shape.polygone->color.stroke.a,
        shape->union_shape.polygone->color.fill.r,
        shape->union_shape.polygone->color.fill.g,
        shape->union_shape.polygone->color.fill.b,
        shape->union_shape.polygone->color.fill.a
    );

    while (element != NULL) {
        fprintf(file,"%d,%d ", element->value1, element->value2);
        element = element->next;
    }

    fprintf(file,"' transform='rotate(%d)'/>", shape->union_shape.polygone->angle);
}


void save_path(shape_struct_t *shape, FILE *file) {
    path_element_t *element = shape->union_shape.path->start;

    fprintf(file,
        "<path fill='rgba(%d,%d,%d,0.%d)' "
        "stroke='rgba(%d,%d,%d,0.%d)' d='",
        shape->union_shape.path->color.fill.r,
        shape->union_shape.path->color.fill.g,
        shape->union_shape.path->color.fill.b,
        shape->union_shape.path->color.fill.a,
        shape->union_shape.path->color.stroke.r,
        shape->union_shape.path->color.stroke.g,
        shape->union_shape.path->color.stroke.b,
        shape->union_shape.path->color.stroke.a
    );

    while (element != NULL) {
        switch (element->command) {
            case 'M':
            case 'L':
                fprintf(file, "%c %d %d ", element->command, element->x, element->y);
            break;
            case 'H':
                fprintf(file, "%c %d ", element->command, element->x);
            break;
            case 'V':
                fprintf(file, "%c %d ", element->command, element->y);
            break;
            case 'Q':
                fprintf(file, "%c %d %d %d %d ",
                    element->command,
                    element->x, element->y,
                    element->x1, element->y1);
            break;
            case 'C':
                fprintf(file, "%c %d %d %d %d %d %d ",
                    element->command,
                    element->x, element->y,
                    element->x1, element->y1,
                    element->x2, element->y2);
            break;
            case 'Z':
                fprintf(file, "%c ", element->command);
            break;
            default:
            break;
        }

        element = element->next;
    }

    fprintf(file, "' transform='rotate(%d)' />", shape->union_shape.path->angle);
}