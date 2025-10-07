#include <stdio.h>
#include <stdlib.h>

typedef struct viewbox_s {
    int min_x;
    int min_y;
    int width;
    int height;
} viewbox_t;


viewbox_t *create_viewbox() {
    viewbox_t *viewbox = malloc(sizeof(viewbox_t));
    viewbox->min_x = 0;
    viewbox->min_y = 0;
    viewbox->width = 0;
    viewbox->height = 0;
    return viewbox;
}


void free_viewbox(viewbox_t *viewbox) {
    free(viewbox);
}


void modifie_viewbox(viewbox_t *viewbox) {

    printf ("Bonjour, pour commencer, veuillez préciser la"
        " dimension de votre fenetre de visualisation\n"
        " (2 nombres, pour la largeur puis la hauteur).\n");
    
    do {
        scanf("%d", &viewbox->width);
        scanf("%d", &viewbox->height);
    } while ((viewbox->width < 0) || (viewbox->height < 0));

    printf("Votre fenetre de visualisation aura une largeur de"
        " %dpx et une hauteur de %dpx.\n", 
        viewbox->width, viewbox->height);
}


typedef struct ellipse_s {
    int cx;
    int cy;
    int rx;
    int ry;
    // style_t *style;
} ellipse_t;


ellipse_t *create_ellipse() {
    ellipse_t *ellipse = malloc(sizeof(ellipse_t));
    ellipse->cx = 0;
    ellipse->cy = 0;
    ellipse->rx = 0;
    ellipse->ry = 0;
    // ellipse->style = create_style();
    return ellipse;
}


void free_ellipse(ellipse_t *ellipse) {
    free(ellipse);
}


void modifie_ellipse(ellipse_t *ellipse, viewbox_t *viewbox) {

    printf ("Veuillez préciser les informations concernant votre ellipse.\n"
        " (x du point central / y du point central / rayon en x / rayon en y).\n");
    
    do {
        scanf("%d", &ellipse->cx);
        scanf("%d", &ellipse->cy);
        scanf("%d", &ellipse->rx);
        scanf("%d", &ellipse->ry);
    } while ((!((ellipse->cx > 0) & (ellipse->cx < viewbox->width)))
            & (!((ellipse->cy > 0) & (ellipse->cx < viewbox->height))));

    printf("Votre ellipse aura un centre de coordonnées : x = %d / y = %d,"
        " un rayon x = %d et un rayon y = %d.\n", 
        ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry);
}


typedef struct rect_s {
    int x;
    int y;
    int width;
    int height;
    // style_t *style;
} rect_t;


rect_t *create_rect() {
    rect_t *rect = malloc(sizeof(rect_t));
    rect->x = 0;
    rect->y = 0;
    rect->width = 0;
    rect->height = 0;
    return rect;
}


void free_rect(rect_t *rect) {
    free(rect);
}


void modifie_rect(rect_t *rect, viewbox_t *viewbox) {

    printf ("Veuillez préciser les informations concernant votre rectangle.\n"
        " (x du premier point / y du premier point / largeur / hauteur).\n");
    
    do {
        scanf("%d", &rect->x);
        scanf("%d", &rect->y);
        scanf("%d", &rect->width);
        scanf("%d", &rect->height);
    } while ((!((rect->x > 0) & (rect->x < viewbox->width)))
            & (!((rect->y > 0) & (rect->y < viewbox->height))));

    printf("Votre rectangle aura son premier point aux coordonnées : x = %d / y = %d,"
        " une largeur de %dpx et une hauteur de %dpx.\n", 
        rect->x, rect->y, rect->width, rect->height);
}


typedef struct line_s {
    int x1;
    int y1;
    int x2;
    int y2;
} line_t;


line_t *create_line() {
    line_t *line = malloc(sizeof(line_t));
    line->x1 = 0;
    line->y1 = 0;
    line->x2 = 0;
    line->y2 = 0;
    return line;
}


void free_line(line_t *line){
    free(line);
}

void modifie_line(line_t *line, viewbox_t *viewbox) {

    printf ("Veuillez préciser les informations concernant votre ligne.\n"
        " (x du premier point / y du premier point / x du deuxieme point / y du deuxieme point).\n");
    
    do {
        scanf("%d", &line->x1);
        scanf("%d", &line->y1);
        scanf("%d", &line->x2);
        scanf("%d", &line->y2);
    } while ((!((line->x1 > 0) & (line->x1 < viewbox->width)))
            & (!((line->x2 > 0) & (line->x2 < viewbox->width)))
            & (!((line->y1 > 0) & (line->y1 < viewbox->height)))
            & (!((line->y2 > 0) & (line->y2 < viewbox->height))));

    printf("Votre ligne aura son premier point aux coordonnées : x = %d / y = %d,"
        " et son deuxieme point aux coordonnées : x = %d / y = %d.\n", 
        line->x1, line->y1, line->x2, line->y2);
}


// typedef struct style_s {
//     // creer la structure pour les couleurs RGBA
// } style_t;

// style_t *create_style(){
//     // initialiser toutes les valeurs de style
// }

// polyline et polygon est une suite de point !!!  --->  liste chainée


int main(void) {

    viewbox_t *vb = create_viewbox();
    modifie_viewbox(vb);

    ellipse_t *ellipse = create_ellipse();
    modifie_ellipse(ellipse, vb);
    
    rect_t *rectangle = create_rect();
    modifie_rect(rectangle, vb);

    line_t *line = create_line();
    modifie_line(line, vb);





    char end_viewbox[] = "\n</svg>";

    FILE *write_file = fopen("test.svg", "w");

    if (fprintf(write_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n", vb->width, vb->height) &&
    fprintf(write_file, "%s", end_viewbox) <0) {
        printf("Something went wrong");
    }
    
    fclose(write_file);
    
    // system("clear");

    return 0;
}

// ATTENTION ERREUR AVEC MAKE CLEAN DU MAKEFILE
// mettre le code sur plusieurs ligne pour qu'il ne soit pas trop long  (alt-z)
// ERREUR avec les bornes d'erreur des coordonnees de mon rectangle