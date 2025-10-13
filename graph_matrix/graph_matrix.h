#ifndef GRAPH_MATRIX_HEADER
#define GRAPH_MATRIX_HEADER

    /*
        STRUCTURE D’UN GRAPHE NON ORIENTÉ (MATRICE D’ADJACENCE)
            - Le graphe est représenté par une matrice carrée de taille (n x n)
            - Chaque case matrix[i][j] vaut :
                1 si une arête relie le sommet i au sommet j
                0 sinon
            - Comme le graphe est non orienté, la matrice est symétrique :
                matrix[i][j] == matrix[j][i]
    */

    // Structure d’un graphe avec matrice d’adjacence
    typedef struct {
        int num_vertices;   // Nombre total de sommets
        int **matrix;       // Pointeur vers la matrice d’adjacence
    } GraphMatrix;

    /*
        FONCTIONS UTILES :
            (1). Créer un graphe vide avec un nombre de sommets donné
            (2). Ajouter une arête entre deux sommets
            (3). Afficher la matrice d’adjacence
            (4). Libérer la mémoire allouée
    */

    // Créer un graphe vide avec un nombre de sommets donné
    GraphMatrix create_graph_matrix(int num_vertices);

    // Ajouter une arête entre deux sommets
    void add_edge_matrix(GraphMatrix *graph, int src, int dest);

    // Afficher la matrice d’adjacence
    void display_graph_matrix(const GraphMatrix *graph);

    // Libérer la mémoire allouée
    void free_graph_matrix(GraphMatrix *graph);

#endif
