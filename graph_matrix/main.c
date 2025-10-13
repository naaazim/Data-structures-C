#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

int main() {
    // Création d’un graphe avec 5 sommets (0, 1, 2, 3, 4)
    GraphMatrix graph = create_graph_matrix(5);

    // Ajout des arêtes (graphe non orienté)
    add_edge_matrix(&graph, 0, 1);
    add_edge_matrix(&graph, 0, 4);
    add_edge_matrix(&graph, 1, 2);
    add_edge_matrix(&graph, 1, 3);
    add_edge_matrix(&graph, 1, 4);
    add_edge_matrix(&graph, 2, 3);
    add_edge_matrix(&graph, 3, 4);

    // Affichage de la matrice d’adjacence
    display_graph_matrix(&graph);

    // Libération de la mémoire
    free_graph_matrix(&graph);

    return 0;
}
