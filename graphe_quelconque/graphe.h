#ifndef __GRAPHE_HEADER__
#define __GRAPHE_HEADER__

/*
    Nous allons étendre la structure d’un arbre générique pour obtenir
    une structure encore plus flexible : le graphe quelconque.

    Dans un arbre générique, chaque nœud possède :
        - un pointeur vers son premier fils,
        - un pointeur vers son frère suivant,
        - et une hiérarchie (racine → fils).

    Cependant, cette organisation impose une structure hiérarchique :
    chaque nœud n’a qu’un seul père et les cycles sont interdits.

    Pour représenter un graphe quelconque, on doit supprimer cette
    contrainte hiérarchique et permettre à chaque nœud d’être relié
    à plusieurs autres, sans restriction d’ordre ou de direction.

    Ainsi, un graphe est défini par :
        - Un ensemble de sommets (vertices)
        - Un ensemble d’arêtes (edges) reliant ces sommets

    Dans notre implémentation :
        - Chaque sommet (Vertex) contient une donnée (data)
          et une liste de ses voisins (adjacents)
        - Le graphe contient un tableau de sommets
          et une information sur son ordre (nombre de sommets)
*/

#include <stdio.h>
#include <stdlib.h>

// Structure d’un sommet (vertex)
typedef struct Vertex {
    int data;                 // Identifiant ou valeur du sommet
    struct Vertex **adj;      // Tableau dynamique de pointeurs vers les sommets adjacents
    int degree;               // Nombre de voisins (degré)
} Vertex;

// Structure d'un graphe
typedef struct Graph {
    int order;                // Nombre de sommets
    Vertex **vertices;        // Tableau dynamique de sommets
    int oriented;             // 0 : non orienté, 1 : orienté
} Graph;

/*
    Méthodes utilitaires :
        (1) Créer un graphe
        (2) Ajouter un sommet
        (3) Ajouter une arête entre deux sommets
        (4) Afficher le graphe
*/

// Créer un graphe vide
Graph create_graph(int oriented);

// Ajouter un sommet au graphe
void add_vertex(Graph *graph, int value);

// Ajouter une arête entre deux sommets (u, v)
void add_edge(Graph *graph, int from, int to);

// Afficher le graphe sous forme de listes d’adjacence
void display_graph(const Graph *graph);

#endif
