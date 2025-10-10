#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "models.h"
#include "cli.h"

void modifie_viewbox(viewbox_t *viewbox);
void modifie_ellipse(ellipse_t *ellipse);
void modifie_rect(rect_t *rect);
void modifie_line(line_t *line);
void menu_for_user ();
void choice_model_for_edition ();


void modifie_viewbox(viewbox_t *viewbox) {

    printf ("Pour commencer, veuillez préciser la"
        " dimension de votre fenetre de visualisation\n"
        " (la largeur puis la hauteur).\n\n");

    viewbox->width = ask_for_int("largeur: ", "Merci d'entrer un nombre entier.");
    viewbox->height = ask_for_int("hauteur: ", "Merci d'entrer un nombre entier.");

    printf("Votre fenetre de visualisation aura une largeur de"
        " %dpx et une hauteur de %dpx.\n\n", 
        viewbox->width, viewbox->height);
}


void modifie_ellipse(ellipse_t *ellipse) {

    printf ("Veuillez préciser les informations concernant votre ellipse.\n"
        "(coordo x du point central / coordo y du point central / rayon en x / rayon en y).\n\n");

    ellipse->coordo_center_x = ask_for_int("coordo centre x: ", "Merci d'entrer un nombre entier.");
    ellipse->coordo_center_y = ask_for_int("coordo centre y: ", "Merci d'entrer un nombre entier.");
    ellipse->rayon_x = ask_for_int("rayon x: ", "Merci d'entrer un nombre entier.");
    ellipse->rayon_y = ask_for_int("rayon y: ", "Merci d'entrer un nombre entier.");

    printf("Votre ellipse aura un centre de coordonnées : x = %d / y = %d,"
        " un rayon x = %dpx et un rayon y = %dpx.\n\n", 
        ellipse->coordo_center_x, ellipse->coordo_center_y, ellipse->rayon_x, ellipse->rayon_y);
}


void modifie_rect(rect_t *rect) {

    printf ("Veuillez préciser les informations concernant votre rectangle.\n"
        " (coordo x du premier point / coordo y du premier point / largeur / hauteur).\n\n");
    
    rect->coordo_start_x = ask_for_int("coordo x: ", "Merci d'entrer un nombre entier.");
    rect->coordo_start_y = ask_for_int("coordo y: ", "Merci d'entrer un nombre entier.");
    rect->width = ask_for_int("largeur: ", "Merci d'entrer un nombre entier.");
    rect->height = ask_for_int("hauteur: ", "Merci d'entrer un nombre entier.");

    printf("Votre rectangle aura son premier point aux coordonnées : x = %d / y = %d,"
        " une largeur de %dpx et une hauteur de %dpx.\n\n", 
        rect->coordo_start_x, rect->coordo_start_y, rect->width, rect->height);
}


void modifie_line(line_t *line) {

    printf ("Veuillez préciser les informations concernant votre ligne.\n"
        " (x du premier point / y du premier point / x du deuxieme point / y du deuxieme point).\n\n");
    
    line->coordo_start_x = ask_for_int("coordo x: ", "Merci d'entrer un nombre entier.");
    line->coordo_start_y = ask_for_int("coordo y: ", "Merci d'entrer un nombre entier.");
    line->coordo_end_x = ask_for_int("largeur: ", "Merci d'entrer un nombre entier.");
    line->coordo_end_y = ask_for_int("hauteur: ", "Merci d'entrer un nombre entier.");

    printf("Votre ligne aura son premier point aux coordonnées : x = %d / y = %d,"
        " et son deuxieme point aux coordonnées : x = %d / y = %d.\n\n", 
        line->coordo_start_x, line->coordo_start_y, line->coordo_end_x, line->coordo_end_y);
}


void menu_for_user () {

    user_menu_choice_t choice_menu = ask_for_int_in_range_1_to_3("Que voulez-vous faire ?\n"
    "(1:creation / 2:edition / 3:visualisation)\n", "Merci d'entrer un nombre entre 1 et 3.");
    
    switch (choice_menu)
    {
    case CHOICE_CREATION:
        printf("Désolée, cette fonction n'existe pas encore. Wait and see ;)\n\n");
        break;
    case CHOICE_EDITION:
        choice_model_for_edition ();
    break;
    case CHOICE_VISUALISATION:
        printf("Désolée, cette fonction n'existe pas encore. Wait and see ;-)\n\n");
    break;
    default:
        printf("Erreur dans votre choix de menu");
        break;
    }

}


void choice_model_for_edition () {
    int choice_model = ask_for_int_in_range_1_to_3("Quelle forme voulez-vous realiser ?\n"
    "(1:ellipse / 2:rectangle / 3:ligne)\n", "Merci d'entrer un nombre entre 1 et 3.");

    switch (choice_model)
    {
    case 1:
        ellipse_t *ellipse1 = create_ellipse();
        modifie_ellipse(ellipse1);
    break;
    case 2:
        rect_t *rectangle1 = create_rect();
        modifie_rect(rectangle1);
    break;
    case 3:
        line_t *line1 = create_line();
        modifie_line(line1);
    break;
    default:
        break;
    }

    menu_for_user();
}


// typedef struct style_s {
//     // creer la structure pour les couleurs RGBA
// } style_t;

// style_t *create_style(){
//     // initialiser toutes les valeurs de style
// }

// polyline et polygon est une suite de point !!!  --->  liste chainée


int main(void) {

    printf("Bienvenue dans ma super application de création de SVG !!\n\n");

    viewbox_t *vb = create_viewbox();
    modifie_viewbox(vb);

    menu_for_user();



    // ellipse_t *ellipse = create_ellipse();
    // modifie_ellipse(ellipse);
    
    // rect_t *rectangle = create_rect();
    // modifie_rect(rectangle);

    // line_t *line = create_line();
    // modifie_line(line);





    char end_viewbox[] = "\n</svg>";

    FILE *my_file = fopen("test.svg", "w");

    if (fprintf(my_file, "<svg viewBox='0 0 %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        vb->width, vb->height) &&
    fprintf(my_file, "%s", end_viewbox) <0) {
        printf("Something went wrong");
    }
    
    fclose(my_file);
    
    // system("clear");

    return 0;
}

// mettre le code sur plusieurs ligne pour qu'il ne soit pas trop long  (alt-z)


// creer fonction pour tester valeurs entrer par l'utilisateur (uint)
// boucler une structure à fond (avec menu creer (pas possible sinon liste) / modifier / imprimer)
// appeler jerem à l'aide pour les listes
// creer des listes pour juste un type / avoir des id fixes pour les nodes
// ajouter au menu la possibilite de creer et supprimer
// ajouter les autres struct


// la fonction ask_for_int ne bloque pas les nombres negatifs
