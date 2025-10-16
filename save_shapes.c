#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "shapes.h"
#include "save_shapes.h"
#include "cli.h"


void save_projet(array_t *array, viewbox_t *viewbox) {
    printf("\n");
    char end_viewbox[] = "\n</svg>";

    FILE *saved_file = fopen("projet.svg", "w");

    fprintf(saved_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        viewbox->width, viewbox->height);
    
    for (int i = 0; i < array->index; i++) {

        if (array->table[i] == NULL) {
            continue;
        }

        switch (array->table[i]->enum_shape) {
            case SHAPE_ELLIPSE:
                save_ellipse(array->table[i], saved_file);
            break;
            case SHAPE_RECTANGLE:
                save_rectangle(array->table[i], saved_file);
            break;
            case SHAPE_LINE:
                save_line(array->table[i], saved_file);
            break;
            case SHAPE_POLYLINE:
                save_polyline(array->table[i], saved_file);
            break;
            case SHAPE_POLYGONE:
                save_polygone(array->table[i], saved_file);
            break;
            default:
                printf("Une erreur est survenue.\n");
            break;
        }
    }
    
    fprintf(saved_file, "%s", end_viewbox);
    fclose(saved_file);

    printf("Vous pouvez maintenant ouvrir votre sauvegarde \033[35mprojet.svg\033[0m dans vos fichiers.\n\n");

    ask_for_1("Tapez '1' pour continuer ...",
        "\033[31mMerci d'entrer 1 pour continuer\033[0m");

    menu_for_user(array, viewbox);
}


void save_ellipse(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<ellipse cx='%d' cy='%d' rx='%d' ry='%d' stroke='rgba(%d,%d,%d,0.%d)' "
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
    fprintf(file,"<rect x='%d' y='%d' width='%d' height='%d' stroke='rgba(%d,%d,%d,0.%d)'"
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
    fprintf(file,"<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='rgba(%d,%d,%d,0.%d)'"
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
    liste_t *polyline = shape->union_shape.polyline;
    list_element_t *element = polyline->start;

    fprintf(file,"<polyline fill='none' stroke='rgba(%d,%d,%d,0.%d)' points='",
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
    liste_t *polygone = shape->union_shape.polygone;
    list_element_t *element = polygone->start;

    fprintf(file,"<polygon fill='rgba(%d,%d,%d,0.%d)' stroke='rgba(%d,%d,%d,0.%d)' points='",
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