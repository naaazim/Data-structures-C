#ifndef __GRAPHE_MATRICE_HEADER__
#define __GRAPHE_MATRICE_HEADER__

#include <stdio.h>
#include <stdlib.h>

/*
    Représentation d’un graphe non orienté à l’aide d’une matrice d’adjacence.
    Chargement possible depuis un fichier ou stdin.
*/

typedef struct {
    int **adj;   // Matrice d’adjacence
    int n;       // Nombre de sommets
} GraphMatrix;

// Création d’un graphe vide
GraphMatrix create_graph_matrix(int n);

// Ajouter une arête entre deux sommets
void add_edge(GraphMatrix *g, int i, int j);

// Charger un graphe depuis un fichier texte ou stdin
GraphMatrix chargeGraphe(const char *filename);

// Afficher la matrice d’adjacence
void display_matrix(const GraphMatrix *g);

// Welsh–Powell (coloration)
void welsh_powell(const GraphMatrix *g);

// Libérer la mémoire de la matrice
void free_graph(GraphMatrix *g);

#endif
