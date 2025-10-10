#ifndef __BST_HEADER__
#define __BST_HEADER__

    /*
        UN ARBRE BINAIRE DE RECHERCHE (BST) EST DÉFINI PAR :
            - Un nœud racine (root)
            - Chaque nœud contient :
                * une valeur (data)
                * un pointeur vers le sous-arbre gauche
                * un pointeur vers le sous-arbre droit

        PROPRIÉTÉ DU BST :
            Pour chaque nœud :
                * Les valeurs du sous-arbre gauche < valeur du nœud
                * Les valeurs du sous-arbre droit > valeur du nœud
    */

    typedef struct Node {
        int data;
        struct Node *left;
        struct Node *right;
    } Node;

    typedef struct BST {
        Node *root;
    } BST;

    /*
        MÉTHODES UTILITAIRES :
            (1). Initialiser un arbre
            (2). Insérer un élément
            (3). Rechercher un élément
            (4). Supprimer un élément
            (5). Afficher l’arbre (parcours infixe)
            (6). Trouver le minimum et le maximum
    */

    // Créer un nouvel arbre vide
    BST create_new_tree(void);

    // Créer un nouveau nœud
    Node* create_node(int value);

    // Insérer un élément dans le BST
    Node* insert(Node *root, int value);

    // Rechercher un élément
    Node* search(Node *root, int value);

    // Supprimer un élément
    Node* delete(Node *root, int value);

    // Trouver le nœud minimum (gauche le plus profond)
    Node* find_min(Node *root);

    // Afficher les valeurs de l’arbre (parcours infixe)
    void inorder(const Node *root);

#endif
