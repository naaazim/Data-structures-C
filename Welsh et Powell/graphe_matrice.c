#include "graphe_matrice.h"

// Créer un graphe vide (matrice n×n remplie de 0)
GraphMatrix create_graph_matrix(int n) {
    GraphMatrix g;
    g.n = n;

    g.adj = malloc(n * sizeof(int *));
    if (g.adj == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire pour la matrice.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        g.adj[i] = calloc(n, sizeof(int));
        if (g.adj[i] == NULL) {
            fprintf(stderr, "Erreur d’allocation mémoire ligne %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    return g;
}

// Connecter deux sommets
void add_edge(GraphMatrix *g, int i, int j) {
    if (i < 0 || i >= g->n || j < 0 || j >= g->n) {
        fprintf(stderr, "Indice de sommet invalide (%d, %d)\n", i, j);
        return;
    }
    g->adj[i][j] = 1;
    g->adj[j][i] = 1;
}

// Charger un graphe depuis un fichier ou stdin
GraphMatrix chargeGraphe(const char *filename) {
    FILE *f = NULL;

    if (filename != NULL) {
        f = fopen(filename, "r");
        if (f == NULL) {
            fprintf(stderr, "Impossible d’ouvrir le fichier %s\n", filename);
            exit(EXIT_FAILURE);
        }
        printf("Chargement du graphe depuis le fichier : %s\n", filename);
    } else {
        f = stdin;
        printf("Entrez le nombre de sommets : ");
    }

    int n;
    fscanf(f, "%d", &n);
    printf("Nombre de sommets détecté : %d\n", n);

    GraphMatrix g = create_graph_matrix(n);

    printf("\nEntrez la matrice d’adjacence (%d × %d) :\n", n, n);
    printf("(Chaque ligne doit contenir %d entiers 0 ou 1 séparés par des espaces)\n", n);

    for (int i = 0; i < n; i++) {
        printf("Ligne %d : ", i + 1);
        for (int j = 0; j < n; j++) {
            int val;
            fscanf(f, "%d", &val);
            g.adj[i][j] = val;
        }
    }

    if (filename != NULL) fclose(f);

    printf("\nGraphe chargé avec succès !\n");
    return g;
}


// Afficher la matrice
void display_matrix(const GraphMatrix *g) {
    printf("\nMatrice d’adjacence (%d sommets) :\n", g->n);
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Welsh–Powell : coloration
void welsh_powell(const GraphMatrix *g) {
    int n = g->n;
    int color[n];
    int degree[n];
    int vertices[n];

    // Calcul des degrés
    for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < n; j++) if (g->adj[i][j] == 1) d++;
        degree[i] = d;
        color[i] = 0;
        vertices[i] = i;
    }

    // Tri décroissant des sommets selon leur degré
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (degree[vertices[j]] > degree[vertices[i]]) {
                int tmp = vertices[i];
                vertices[i] = vertices[j];
                vertices[j] = tmp;
            }
        }
    }

    // Affichage de l’ordre de marquage
    printf("\nOrdre de marquage (degré décroissant) :\n");
    for (int i = 0; i < n; i++) {
        printf("Sommet %d (degré %d)\n", vertices[i] + 1, degree[vertices[i]]);
    }

    // Coloration Welsh–Powell
    int current_color = 1;
    for (int i = 0; i < n; i++) {
        int v = vertices[i];
        if (color[v] == 0) {
            color[v] = current_color;
            for (int j = i + 1; j < n; j++) {
                int u = vertices[j];
                if (color[u] == 0) {
                    int adjacent = 0;
                    for (int k = 0; k < n; k++) {
                        if (g->adj[u][k] && color[k] == current_color) {
                            adjacent = 1;
                            break;
                        }
                    }
                    if (!adjacent) color[u] = current_color;
                }
            }
            current_color++;
        }
    }

    // Résultat final
    printf("\n=== Coloration Welsh–Powell ===\n");
    for (int i = 0; i < n; i++) {
        printf("Sommet %d → Couleur %d (degré %d)\n",
               i + 1, color[i], degree[i]);
    }
    printf("Nombre total de couleurs utilisées : %d\n", current_color - 1);
}

// Libérer la mémoire
void free_graph(GraphMatrix *g) {
    for (int i = 0; i < g->n; i++) free(g->adj[i]);
    free(g->adj);
}

