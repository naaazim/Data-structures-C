#include <stdio.h>
#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void welshPowell(struct Graph* graph) {
    int degree[MAX_VERTICES] = {0};
    int i, j;

    // Calcul du degré de chaque sommet
    for (i = 0; i < graph->vertices; i++)
        for (j = 0; j < graph->vertices; j++)
            if (graph->adjMatrix[i][j] == 1)
                degree[i]++;

    // Tri des sommets par degré décroissant
    int sorted_vertices[MAX_VERTICES];
    for (i = 0; i < graph->vertices; i++)
        sorted_vertices[i] = i;

    for (i = 0; i < graph->vertices - 1; i++)
        for (j = i + 1; j < graph->vertices; j++)
            if (degree[sorted_vertices[i]] < degree[sorted_vertices[j]]) {
                int tmp = sorted_vertices[i];
                sorted_vertices[i] = sorted_vertices[j];
                sorted_vertices[j] = tmp;
            }

    // Initialisation des couleurs
    int color[MAX_VERTICES];
    for (i = 0; i < graph->vertices; i++)
        color[i] = -1;

    int current_color = 1;

    // Coloration gloutonne
    for (i = 0; i < graph->vertices; i++) {
        int v = sorted_vertices[i];
        if (color[v] == -1) {
            color[v] = current_color;
            // Colorier les autres sommets non adjacents
            for (j = 0; j < graph->vertices; j++) {
                int u = sorted_vertices[j];
                if (color[u] == -1 && graph->adjMatrix[v][u] == 0) {
                    int adjacent = 0;
                    for (int k = 0; k < graph->vertices; k++) {
                        if (graph->adjMatrix[u][k] == 1 && color[k] == current_color) {
                            adjacent = 1;
                            break;
                        }
                    }
                    if (!adjacent)
                        color[u] = current_color;
                }
            }
            current_color++;
        }
    }

    // Affichage du résultat
    printf("\n=== Coloration Welsh–Powell ===\n");
    for (i = 0; i < graph->vertices; i++)
        printf("Sommet %d → Couleur %d (degré %d)\n", i + 1, color[i], degree[i]);
    printf("Nombre total de couleurs utilisées : %d\n", current_color - 1);
}

int main() {
    struct Graph graph = {5, {0}};
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    welshPowell(&graph);
    return 0;
}
