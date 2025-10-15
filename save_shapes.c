#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "shapes.h"
#include "save_shapes.h"


void save_projet(array_t *array, viewbox_t *viewbox) {
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
            
            default:
                printf("Une erreur est survenue.\n");
            break;
        }
    }
    
    fprintf(saved_file, "%s", end_viewbox);
    fclose(saved_file);

    printf("Vous pouvez maintenant ouvrir votre sauvegarde projet.svg dans vos fichiers.\n");

    menu_for_user(array, viewbox);
}


void save_ellipse(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<ellipse cx='%d' cy='%d' rx='%d' ry='%d' fill='#ff000080' />",
        shape->union_shape.ellipse->coordo_center_x,
        shape->union_shape.ellipse->coordo_center_y,
        shape->union_shape.ellipse->rayon_x,
        shape->union_shape.ellipse->rayon_y
    );
}


void save_rectangle(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<rect x='%d' y='%d' width='%d' height='%d' fill='#00ff0080' />",
        shape->union_shape.rectangle->coordo_start_x,
        shape->union_shape.rectangle->coordo_start_y,
        shape->union_shape.rectangle->width,
        shape->union_shape.rectangle->height
    );
}


void save_line(shape_struct_t *shape, FILE *file) {
    fprintf(file,"<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='#0000ff80' />",
        shape->union_shape.line->coordo_start_x,
        shape->union_shape.line->coordo_start_y,
        shape->union_shape.line->coordo_end_x,
        shape->union_shape.line->coordo_end_y
    );
}


void save_polyline(shape_struct_t *shape, FILE *file){
    liste_t *polyline = shape->union_shape.polyline;
    list_element_t *element = polyline->start;

    fprintf(file,"<polyline fill='none' stroke='black' points='");

    while (element != NULL) {
        fprintf(file,"%d,%d ", element->value1, element->value2);
        element = element->next;
    }

    fprintf(file,"'/>");
}