#include "graphe_liste.h"

// Crée un nouveau nœud
AdjNode* create_node(int v) {
    AdjNode* newNode = malloc(sizeof(AdjNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour un nœud.\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Crée un graphe vide
Graph* create_graph(int V) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour le graphe.\n");
        exit(EXIT_FAILURE);
    }

    graph->V = V;
    graph->adjLists = malloc(V * sizeof(AdjNode*));
    if (graph->adjLists == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour les listes.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Ajoute une arête entre src et dest (non orienté)
void add_edge(Graph* graph, int src, int dest) {
    // Ajouter dest à la liste de src
    AdjNode* newNode = create_node(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Ajouter src à la liste de dest (car non orienté)
    newNode = create_node(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Affiche les listes d’adjacence
void display_graph(const Graph* graph) {
    printf("\nReprésentation du graphe (listes d’adjacence) :\n");
    for (int i = 0; i < graph->V; i++) {
        AdjNode* temp = graph->adjLists[i];
        printf("Sommet %d :", i + 1);
        while (temp) {
            printf(" -> %d", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Libère toute la mémoire du graphe
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        AdjNode* temp = graph->adjLists[i];
        while (temp) {
            AdjNode* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);
}
