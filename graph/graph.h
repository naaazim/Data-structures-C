#ifndef GRAPH_HEADER
#define GRAPH_HEADER

    /*
        STRUCTURE D'UN GRAPHE NON ORIENTÉ (LISTE D'ADJACENCE)
            Un graphe est composé :
                - d'un nombre de sommets (num_vertices)
                - d'un tableau de listes chaînées, où chaque liste représente les sommets adjacents à un sommet donné
            Chaque noeud d'une liste d'adjacence contient :
                - un entier (vertex) représentant le sommet voisin
                - un pointeur vers le noeud suivant
    */

    // Structure d'un noeud dans la liste d'adjacence
    typedef struct AdjNode {
        int vertex;
        struct AdjNode *next;
    } AdjNode;

    // Structure principale du graphe
    typedef struct Graph {
        int num_vertices;        // nombre total de sommets
        AdjNode **adj_lists;     // tableau de pointeurs vers les listes d'adjacence
    } Graph;

    /*
        FONCTIONS UTILES :
        (1) Créer un graphe vide avec un nombre de sommets donné
        (2) Ajouter une arête entre deux sommets
        (3) Afficher le graphe
        (4) Libérer la mémoire du graphe
    */

    // Créer un graphe vide
    Graph create_graph(int num_vertices);

    // Ajouter une arête entre deux sommets (src et dest)
    void add_edge(Graph *graph, int src, int dest);

    // Afficher les listes d'adjacence du graphe
    void display_graph(const Graph *graph);

    // Libérer toute la mémoire du graphe
    void free_graph(Graph *graph);

#endif
