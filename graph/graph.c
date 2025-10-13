#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Créer un nouveau noeud d'adjacence
static AdjNode* create_adj_node(int vertex) {
    AdjNode *new_node = malloc(sizeof(AdjNode));
    if (new_node == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le noeud d'adjacence\n");
        exit(EXIT_FAILURE);
    }
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Créer un graphe vide avec un nombre de sommets donné
Graph create_graph(int num_vertices) {
    Graph graph;
    graph.num_vertices = num_vertices;
    graph.adj_lists = malloc(num_vertices * sizeof(AdjNode*));
    if (graph.adj_lists == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour les listes d'adjacence\n");
        exit(EXIT_FAILURE);
    }

    // Initialiser toutes les listes à NULL
    for (int i = 0; i < num_vertices; i++) {
        graph.adj_lists[i] = NULL;
    }

    return graph;
}

// Ajouter une arête entre deux sommets
void add_edge(Graph *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->num_vertices || dest >= graph->num_vertices) {
        fprintf(stderr, "Erreur : sommet invalide (%d ou %d)\n", src, dest);
        return;
    }

    // Ajouter dest à la liste d'adjacence de src
    AdjNode *new_node = create_adj_node(dest);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    // Comme le graphe est non orienté, ajouter src à la liste de dest
    new_node = create_adj_node(src);
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
}

// Afficher le graphe
void display_graph(const Graph *graph) {
    printf("Représentation du graphe (liste d'adjacence) :\n");
    for (int v = 0; v < graph->num_vertices; v++) {
        printf("Sommet %d : ", v);
        AdjNode *temp = graph->adj_lists[v];
        while (temp) {
            printf("%d", temp->vertex);
            if (temp->next != NULL) {
                printf(" -> ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

// Libérer toute la mémoire
void free_graph(Graph *graph) {
    for (int v = 0; v < graph->num_vertices; v++) {
        AdjNode *temp = graph->adj_lists[v];
        while (temp) {
            AdjNode *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph->adj_lists);
}
