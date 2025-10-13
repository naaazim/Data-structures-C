#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    // Création d’un graphe avec 5 sommets (0, 1, 2, 3, 4)
    Graph graph = create_graph(5);

    // Ajout des arêtes
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 4);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);

    // Affichage du graphe
    display_graph(&graph);

    // Libération de la mémoire
    free_graph(&graph);

    return 0;
}
