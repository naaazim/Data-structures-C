#include "graphe_liste.h"

int main() {
    printf("=== Représentation d’un graphe par liste d’adjacence ===\n");

    // Exemple : graphe européen simplifié (5 sommets)
    Graph* g = create_graph(5);

    add_edge(g, 0, 1); // 1–2
    add_edge(g, 0, 2); // 1–3
    add_edge(g, 1, 3); // 2–4
    add_edge(g, 2, 3); // 3–4
    add_edge(g, 3, 4); // 4–5

    display_graph(g);

    free_graph(g);

    return 0;
}
