#ifndef DEF_SHAPES
#define DEF_SHAPES


typedef struct stroke_s stroke_t;

typedef struct fill_s fill_t;

typedef struct color_s color_t;

typedef struct list_element_s list_element_t;

typedef struct liste_s liste_t;

typedef struct path_element_s path_element_t;

typedef struct path_s path_t;


/**
 * @brief Structure de la fenetre de visualisation (viewbox).
 * 
 * @var Coordonnee en x du point initial de la viewbox.
 * @var Coordonnee en y du point initial de la viewbox.
 * @var Largeur de la viewbox (en pixels).
 * @var Hauteur de la viewbox (en pixels).
 */
typedef struct viewbox_s {
    int coordo_min_x;
    int coordo_min_y;
    unsigned int width;
    unsigned int height;
} viewbox_t;


/**
 * @brief Structure de la couleur de trait (stroke) en rgba d'une forme.
 * 
 * @var Composante rouge de la couleur (chiffre entre 0 et 255).
 * @var Composante verte de la couleur (chiffre entre 0 et 255).
 * @var Composante bleue de la couleur (chiffre entre 0 et 255).
 * @var Transparence de la couleur (chiffre entre 0 et 9 -> decimal).
 */
typedef struct stroke_s {
    int r;
    int g;
    int b;
    int a;
} stroke_t;


/**
 * @brief Structure de la couleur de fond (fill) en rgba d'une forme.
 * 
 * @var Composante rouge de la couleur (chiffre entre 0 et 255).
 * @var Composante verte de la couleur (chiffre entre 0 et 255).
 * @var Composante bleue de la couleur (chiffre entre 0 et 255).
 * @var Transparence de la couleur (chiffre entre 0 et 9 -> decimal).
 */
typedef struct fill_s {
    int r;
    int g;
    int b;
    int a;
} fill_t;


/**
 * @brief Structure regroupant la couleur de trait et la couleur de fond d'une forme.
 * 
 * @var Couleur de trait (stroke) en rgba.
 * @var Couleur de fond (fill) en rgba.
 */
typedef struct color_s {
    stroke_t stroke;
    fill_t fill;
} color_t;


/**
 * @brief Structure permettant de definir une ellipse.
 * 
 * @var Coordonnee du centre de l'ellipse en x.
 * @var Coordonnee du centre de l'ellipse en y.
 * @var Rayon honrizontal de l'ellipse (en pixels).
 * @var Rayon vertical de l'ellipse (en pixels).
 * @var Structure couleur (trait + fond) de l'ellipse.
 * @var Angle de rotation de l'ellipse (en degre).
 */
typedef struct ellipse_s {
    int coordo_center_x;
    int coordo_center_y;
    int rayon_x;
    int rayon_y;
    color_t color;
    int angle;
} ellipse_t;


/**
 * @brief Structure permettant de definir un rectangle.
 * 
 * @var Coordonnee en x du point initial du rectangle.
 * @var Coordonnee en y du point initial du rectangle.
 * @var Largeur du rectangle (en pixels).
 * @var Hauteur du rectanlge (en pixels).
 * @var Structure couleur (trait + fond) du rectangle.
 * @var Angle de rotation du rectangle (en degre).
 */
typedef struct rect_s {
    int coordo_start_x;
    int coordo_start_y;
    int width;
    int height;
    color_t color;
    int angle;
} rect_t;


/**
 * @brief Structure permettant de definir une ligne.
 * 
 * @var Coordonnee en x du premier point de la ligne.
 * @var Coordonnee en y du premier point de la ligne.
 * @var Coordonnee en x du deuxieme point de la ligne.
 * @var Coordonnee en y du deuxieme point de la ligne.
 * @var Structure couleur (trait + fond) de la ligne.
 * @var Angle de rotation de la ligne (en degre).
 */
typedef struct line_s {
    int coordo_start_x;
    int coordo_start_y;
    int coordo_end_x;
    int coordo_end_y;
    color_t color;
    int angle;
} line_t;


/**
 * @brief Enumeration des choix possibles dans le menu principal.
 * 
 * Cretation d'une nouvelle forme.
 * Edition d'une forme creee.
 * Suppression d'une forme creee.
 * Sauvegarde des formes creeent sous format .svg.
 * Sortir du programme.
 */
typedef enum user_menu_choice_e {
    CHOICE_CREATION = 1,
    CHOICE_EDITION = 2,
    CHOICE_REMOVE = 3,
    CHOICE_SAVE = 4,
    CHOICE_EXIT = 5
} user_menu_choice_t;


/**
 * @brief Enumeration des formes disponibles à la creation.
 * 
 * Ellipse.
 * Rectangle.
 * Ligne.
 * Polyline.
 * Polygone.
 * Chemin.
 */
typedef enum user_shape_choice_e {
    CHOICE_ELLIPSE = 1,
    CHOICE_RECTANGLE = 2,
    CHOICE_LINE = 3,
    CHOICE_POLYLINE = 4,
    CHOICE_POLYGONE = 5,
    CHOICE_PATH = 6
} user_shape_choice_t;


/**
 * @brief Union regroupant les formes possibles du programme.
 * 
 * Ellipse.
 * Rectangle.
 * Ligne.
 * Polyline.
 * Polygone.
 * Chemin.
 */
typedef union shape_type_u {
    ellipse_t *ellipse;
    rect_t *rectangle;
    line_t *line;
    liste_t *polyline;
    liste_t *polygone;
    path_t *path;
} shape_type_t;


/**
 * @brief Enumeration des formes possibles du programme.
 * 
 * Ellipse.
 * Rectangle.
 * Ligne.
 * Polyline.
 * Polygone.
 * Chemin.
 */
typedef enum shape_type_enum_e {
    SHAPE_ELLIPSE,
    SHAPE_RECTANGLE,
    SHAPE_LINE,
    SHAPE_POLYLINE,
    SHAPE_POLYGONE,
    SHAPE_PATH
} shape_type_enum_t;


/**
 * @brief Union regroupant les formes possibles du programme.
 * 
 * Ellipse.
 * REctangle.
 * Ligne.
 * Polyline.
 * Polygone.
 * Chemin.
 */
typedef struct shape_struct_s {
    shape_type_t union_shape;
    shape_type_enum_t enum_shape;
} shape_struct_t;


/**
 * @brief Structure du tableau de formes.
 * 
 * @var Tableau pouvant contenir jusqu'à 40 formes.
 * @var Longueur actuelle du tableau.
 */
typedef struct array_s {
    shape_struct_t *table[40];
    int index;
} array_t;


/**
 * @brief Structure des elements d'une liste (polyline ou polygone).
 * 
 * @var Coordonnee en x du point.
 * @var Coordonnee en y du point.
 * @var Pointeur vers le prochain element de la liste.
 */
typedef struct list_element_s {
   int value1;
   int value2;
   list_element_t *next;
} list_element_t;


/**
 * @brief Structure de liste (polyline ou polygone).
 * 
 * @var Longueur actuelle de la liste.
 * @var Couleur des elements de la liste.
 * @var Angle de rotation de la liste.
 * @var Pointeur vers le premier element de la liste.
 */
typedef struct liste_s {
    int length;
    color_t color;
    int angle;
    list_element_t *start;
} liste_t;


/**
 * @brief Structure des elements du chemin.
 * 
 * @var Commande de l'element (M, L, H, V, C, Q ou Z).
 * @var Coordonnee en x du point de destination.
 * @var Coordonnee en y du point de destination.
 * @var Coordonnee en x du premier point de controle (pour C et Q).
 * @var Coordonnee en y du premier point de controle (pour C et Q).
 * @var Coordonnee en x du deuxieme point de controle (pour C).
 * @var Coordonnee en y du deuxieme point de controle (pour C).
 */
typedef struct path_element_s {
    char command;
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;
    struct path_element_s *next;
} path_element_t;


/**
 * @brief Structure de chemin.
 * 
 * @var Longueur actuelle du chemin.
 * @var Couleur des elements du chemin.
 * @var Angle de rotation du chemin.
 * @var Pointeur vers le premier element du chemin.
 */
typedef struct path_s {
    int length;
    color_t color;
    int angle;
    path_element_t *start;
} path_t;


/**
 * @brief Creation et initialisation par l'utilisateur de la fenetre de
 *  visualisation (viewbox).
 * 
 * @return Pointeur vers la viewbox.
 */
viewbox_t *create_viewbox();


/**
 * @brief Creation et initialisation du tableau qui acceuillera les formes.
 * 
 * @return Pointeur vers le tableau cree.
 */
array_t *create_array();


/**
 * @brief Initialisation de tous les index du tableau à NULL.
 * 
 * @param array Pointeur vers le tableau à initialiser.
 */
void initialize_array(array_t *array);


#endif