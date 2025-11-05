#ifndef __ARBRE_BINAIRE_HEADER__
#define __ARBRE_BINAIRE_HEADER__

/*
    Un arbre binaire est une structure composée :
        - d’un nœud racine
        - chaque nœud contient :
            * une valeur (caractère ou entier)
            * un pointeur vers un fils gauche
            * un pointeur vers un fils droit
*/

typedef struct Node {
    char data;              // valeur du nœud (caractère)
    struct Node *left;      // pointeur vers le fils gauche
    struct Node *right;     // pointeur vers le fils droit
} Node;

/*
    Fonctions principales :
    (1) Créer un nouveau nœud
    (2) Insérer un nœud en fils gauche ou droit
    (3) Rechercher un nœud par sa valeur
    (4) Parcourir l’arbre (préfixe, infixe, postfixe)
    (5) Libérer la mémoire
*/

// Créer un nouveau nœud
Node* create_node(char value);

// Rechercher un nœud contenant une valeur donnée
Node* search_node(Node *root, char value);

// Insérer un nœud en fils gauche d’un parent
void insert_left(Node *parent, char value);

// Insérer un nœud en fils droit d’un parent
void insert_right(Node *parent, char value);

// Parcours préfixe
void preorder(const Node *root);

// Parcours infixe
void inorder(const Node *root);

// Parcours postfixe
void postorder(const Node *root);

// Libération mémoire
void free_tree(Node *root);

#endif
