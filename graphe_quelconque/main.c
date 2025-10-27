#include "graphe.h"

int main() {
    // Création d’un graphe non orienté
    Graph g = create_graph(0);

    // Ajout de sommets
    add_vertex(&g, 1);
    add_vertex(&g, 2);
    add_vertex(&g, 3);
    add_vertex(&g, 4);

    // Ajout d’arêtes
    add_edge(&g, 0, 1); // 1 ↔ 2
    add_edge(&g, 0, 2); // 1 ↔ 3
    add_edge(&g, 1, 3); // 2 ↔ 4

    // Affichage
    printf("\nAffichage du graphe sous forme de liste d’adjacence :\n");
    display_graph(&g);

    return 0;
}
