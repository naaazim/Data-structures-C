#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

// Créer un graphe vide avec un nombre de sommets donné
GraphMatrix create_graph_matrix(int num_vertices) {
    GraphMatrix graph;
    graph.num_vertices = num_vertices;

    // Allocation de la matrice
    graph.matrix = malloc(num_vertices * sizeof(int*));
    if (graph.matrix == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour la matrice d’adjacence\n");
        exit(EXIT_FAILURE);
    }

    // Allocation de chaque ligne et initialisation à 0
    for (int i = 0; i < num_vertices; i++) {
        graph.matrix[i] = calloc(num_vertices, sizeof(int));
        if (graph.matrix[i] == NULL) {
            fprintf(stderr, "Erreur d’allocation mémoire pour la ligne %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    return graph;
}

// Ajouter une arête entre deux sommets
void add_edge_matrix(GraphMatrix *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->num_vertices || dest >= graph->num_vertices) {
        fprintf(stderr, "Erreur : sommet invalide (%d ou %d)\n", src, dest);
        return;
    }

    // Ajouter l’arête dans les deux sens (non orienté)
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

// Afficher la matrice d’adjacence
void display_graph_matrix(const GraphMatrix *graph) {
    printf("Matrice d’adjacence du graphe :\n");

    // En-têtes de colonnes
    printf("    ");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Ligne de séparation
    printf("   ");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("--");
    }
    printf("\n");

    // Affichage du contenu de la matrice
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d | ", i);
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Libérer la mémoire allouée
void free_graph_matrix(GraphMatrix *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
}
