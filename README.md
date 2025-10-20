# Générateur d’Images Vectorielles SVG en C

## Description

Ce projet fournit une suite de modules en **C** destinés à la **création**, **l’édition**, **la suppression** et **la sauvegarde** de formes géométriques (rectangles, lignes, ellipses, polygones, polylignes, chemins) au **format SVG**.

Il s’adresse à toute personne souhaitant générer ou manipuler des fichiers SVG de manière programmatique via une **interface en ligne de commande**.

Le projet est entièrement écrit en C et utilise un Makefile pour la compilation.

## Prérequis

* Un compilateur C (ex. : gcc)
* Les outils GNU standards (make, etc.)
* Un système d’exploitation capable d’exécuter des programmes C
(Linux, macOS, ou Windows avec un environnement adapté)

## Installation

```
git clone https://github.com/CDasse/Generator_SVG_in_C.git
cd Generator_SVG_in_C
make
```
Cela compilera le projet et générera l’exécutable dans le répertoire bin.

## Guide d'utilisation

Le programme commencera toujours par vous demander de configurer votre **viewbox** (fenêtre de visualisation).

Vous avez ensuite accés au **menu principal** du programme qui propose les options suivantes :

* **Créer une nouvelle forme** : sélectionner parmi les formes disponibles (rectangle, ellipse, ligne, polygone, polyline, chemin).

* **Éditer une forme existante** : modifier les attributs (position, dimensions, couleur, traçage).

* **Supprimer une forme** : retirer une forme déjà créée.

* **Sauvegarder dans un fichier SVG** : enregistrer le contenu au format SVG dans un fichier nommé projet.svg (accessible depuis l'explorateur de fichier).

* **Fermer le programme**


### 1. Configuration de la ViewBox

Au démarrage, le programme vous demande de configurer votre **viewBox** (fenêtre de visualisation).
Indiquez simplement la **largeur** et la **hauteur** souhaitées (en pixels).
Le point initial de la viewBox est toujours **x = 0** et **y = 0**.

### 2. Création d’une forme

⚠️ **Vous pouvez créer jusqu’à 40 formes maximum.**

Vous avez le choix entre les formes suivantes : Ellipse / Rectangle / Ligne / Polyline / Poligone / Chemin

**Ellipse**
* Coordonnées du centre (x, y) ;
* Rayons en x et y (en pixels) ;
* Couleur de contour (en rgba) ;
* Couleur de fond (en rgba) ;
* Angle de rotation (en degrés).

**Rectangle**
* Coordonnées du point initial (x, y) ;
* Largeur et hauteur (en pixels) ;
* Couleur de contour (en rgba) ;
* Couleur de fond (en rgba) ;
* Angle de rotation (en degrés).

**Ligne**
* Coordonnées du premier point (x₁, y₁) ;
* Coordonnées du deuxième point (x₂, y₂) ;
* Couleur du trait (en rgba) ;
* Angle de rotation (en degrés).

**Polyline**
* Liste des points (x, y) ;
* Couleur du trait (en rgba) ;
* Angle de rotation (en degrés).

**Polygone**
* Liste des points (x, y) ;
* Couleur du trait (en rgba) ;
* Couleur de fond (en rgba) ;
* Angle de rotation (en degrés).

**Chemin (Path)**
* Commandes SVG et coordonnées associées ;
    * M -> Déplacement
    * L -> Ligne
    * H -> Ligne horizontale
    * V -> Ligne verticale
    * C -> Courbe avec deux points de contrôle
    * Q -> Courbe avec un point de contrôle
    * Z -> Fermeture du chemin
* Couleur du trait (en rgba) ;
* Couleur de fond (en rgba) ;
* Angle de rotation (en degrés).

### 3. Édition d’une forme

Le programme affiche la liste des formes créées et vous invite à choisir celle que vous souhaitez modifier.

Vous pouvez :
* Modifier les coordonnées, couleurs et rotation ;
* Déplacer la forme sur les axes x et y ;
* Pour les **polylignes** et **polygones**, supprimer un point spécifique.

🧭 Une sécurité vous permet d’annuler une édition en cours.

### 4. Suppression d’une forme

Le programme affiche les formes créées et vous demande laquelle supprimer.

⚠️ **Cette action supprime définitivement la forme choisie.**

🧭 Une sécurité vous permet cependant d’annuler une suppression en cours.

### 5. Sauvegarde en fichier SVG

La sauvegarde crée un fichier nommé `projet.svg` contenant toutes vos formes.
Ouvrez ce fichier dans un navigateur pour visualiser le rendu.

⚠️ **Si vous relancez le programme et sauvegardez de nouveau,
le fichier `projet.svg` sera écrasé.
Pensez à le renommer ou à créer une sauvegarde.**

## Structure du projet

```
├── Generator_SVG_in_C/
│   ├── main.c                # Point d’entrée du programme
│   ├── menu_*.c / .h         # Gestion des différents menus
│   ├── creation_*.c / .h     # Création des formes
│   ├── edition_*.c / .h      # Édition des formes
│   ├── save_shapes.c / .h    # Sauvegarde au format SVG
│   ├── cli.c / .h            # Interface en ligne de commande
│   ├── shapes.c / .h         # Définitions des types de formes
│   ├── show_shapes.c / .h    # Affichage des formes sous forme de liste
│   ├── free_malloc.c / .h    # Libération de la mémoire allouée
├── Makefile                  # Compilation avec 'make'
└── bin/                      # Exécutable généré
```

## Exemple rapide

```
./bin/main
```
1. Créez une **viewBox** (ex. : largeur = 100, hauteur = 150)

2. Choisissez **« Créer une forme »** → Rectangle

3. Entrer les paramètres (par exemple : coordo_start_x=10, coordo_start_y=20, largeur=100, hauteur=50, couleur de trait=(250, 0, 0, 0.8), couleur de fond=(0, 250, 0, 0.8), angle=45) .

4. Choisissez **« Créer une forme »** → Ellipse

5. Entrer les paramètres (par exemple : coordo_center_x=50, coordo_center_y=75, rayon_x=25, rayon_y=75, couleur de trait=(75, 75, 0, 0.7), couleur de fond=(0, 75, 75, 0.7), angle=15).

6. Choisissez **« Sauvegarder »**

7. Ouvrez **projet.svg** dans votre navigateur

8. Sélectionnez **« Quitter »**

![Visualisation de l'exemple.](exemple_svg.png "Visualisation de l'exemple.")


## Astuces & remarques

* Supprimer l’exécutable généré :
```
make clean
```

* Les fichiers objets sont supprimer lors du lancement de la commande : ```make build```

* Des erreurs de **buffer** peuvent apparaître pendant l’exécution.


## Contributor

Auteur : @CDasse