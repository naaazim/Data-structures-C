#ifndef __GRAPHE_LISTE_HEADER__
#define __GRAPHE_LISTE_HEADER__

#include <stdio.h>
#include <stdlib.h>

/*
    Représentation d’un graphe non orienté à l’aide de listes d’adjacence.

    Chaque sommet possède une liste chaînée de voisins.
    Cette représentation est plus économe en mémoire que la matrice d’adjacence.
*/

// Structure d’un nœud dans la liste d’adjacence
typedef struct AdjNode {
    int vertex;                 // Numéro du sommet voisin
    struct AdjNode *next;       // Pointeur vers le prochain voisin
} AdjNode;

// Structure principale du graphe
typedef struct {
    int V;                      // Nombre total de sommets
    AdjNode **adjLists;         // Tableau de listes d’adjacence (une par sommet)
} Graph;

// Création d’un graphe vide
Graph* create_graph(int V);

// Ajout d’une arête entre deux sommets
void add_edge(Graph* graph, int src, int dest);

// Affichage du graphe (listes d’adjacence)
void display_graph(const Graph* graph);

// Libération de la mémoire
void free_graph(Graph* graph);

#endif
