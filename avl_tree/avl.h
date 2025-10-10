#ifndef __AVL_HEADER__
#define __AVL_HEADER__

    /*
        UN ARBRE AVL EST UN ARBRE BINAIRE DE RECHERCHE ÉQUILIBRÉ.
        
        CHAQUE NŒUD CONTIENT :
            - Une valeur (data)
            - Un pointeur vers le sous-arbre gauche
            - Un pointeur vers le sous-arbre droit
            - Un entier représentant la hauteur du nœud

        PROPRIÉTÉ D'ÉQUILIBRE :
            Pour chaque nœud, la différence de hauteur (balance factor)
            entre les sous-arbres gauche et droit ∈ {-1, 0, +1}
    */

    typedef struct Node {
        int data;
        struct Node *left;
        struct Node *right;
        int height;
    } Node;

    /*
        MÉTHODES UTILITAIRES :
            (1). Créer un nouveau nœud
            (2). Obtenir la hauteur d’un nœud
            (3). Calculer le facteur d’équilibre
            (4). Effectuer des rotations :
                - rotation droite
                - rotation gauche
            (5). Insérer un nœud avec rééquilibrage
            (6). Afficher l’arbre (parcours infixe)
    */

    // Créer un nœud
    Node* create_node(int value);

    // Obtenir la hauteur
    int height(Node *node);

    // Calculer le facteur d’équilibre
    int get_balance(Node *node);

    // Rotation droite
    Node* rotate_right(Node *y);

    // Rotation gauche
    Node* rotate_left(Node *x);

    // Insertion avec équilibrage
    Node* insert(Node *node, int value);

    // Parcours infixe
    void inorder(const Node *root);

#endif
