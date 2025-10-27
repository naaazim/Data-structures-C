#include "graphe.h"

// Créer un graphe vide
Graph create_graph(int oriented) {
    Graph g;
    g.order = 0;
    g.vertices = NULL;
    g.oriented = oriented;
    return g;
}

// Ajouter un sommet
void add_vertex(Graph *graph, int value) {
    graph->order++;
    graph->vertices = realloc(graph->vertices, graph->order * sizeof(Vertex *));
    if (graph->vertices == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour les sommets\n");
        exit(EXIT_FAILURE);
    }

    Vertex *new_vertex = malloc(sizeof(Vertex));
    if (new_vertex == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour un sommet\n");
        exit(EXIT_FAILURE);
    }

    new_vertex->data = value;
    new_vertex->adj = NULL;
    new_vertex->degree = 0;

    graph->vertices[graph->order - 1] = new_vertex;
}

// Ajouter une arête (connexion entre deux sommets)
void add_edge(Graph *graph, int from, int to) {
    if (from >= graph->order || to >= graph->order) {
        fprintf(stderr, "Indice de sommet invalide\n");
        return;
    }

    Vertex *u = graph->vertices[from];
    Vertex *v = graph->vertices[to];

    // Ajouter v à la liste d’adjacence de u
    u->degree++;
    u->adj = realloc(u->adj, u->degree * sizeof(Vertex *));
    u->adj[u->degree - 1] = v;

    // Si graphe non orienté, ajouter aussi u à la liste de v
    if (!graph->oriented) {
        v->degree++;
        v->adj = realloc(v->adj, v->degree * sizeof(Vertex *));
        v->adj[v->degree - 1] = u;
    }
}

// Afficher le graphe (liste d’adjacence)
void display_graph(const Graph *graph) {
    printf("Graphe %s\n", graph->oriented ? "orienté" : "non orienté");
    printf("Ordre : %d sommets\n\n", graph->order);

    for (int i = 0; i < graph->order; i++) {
        Vertex *v = graph->vertices[i];
        printf("%d -> ", v->data);
        for (int j = 0; j < v->degree; j++) {
            printf("%d ", v->adj[j]->data);
        }
        printf("\n");
    }
}
