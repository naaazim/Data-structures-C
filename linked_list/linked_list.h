#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER


    /*
        STRUCTURE D'UN NOEUD
            Noeud : contient une valeur + un pointeur vers le nœud suivant.

        STRUCTURE D'UNE LISTE CHAINÉE:
            Liste : un pointeur vers le premier nœud (tête) et un pointeur vers le dernier noeud (ce pointeur sert à faire de l'insertion en O(1))
    */

    //Noeud
    typedef struct Node{
        int data;
        struct Node *next;
    }Node;

    //Liste chaînée
    typedef struct Linked_list{
        Node *head;
        Node *tail;
    }Linked_list;

    /*
        Méthode utiles:
        (1). Initialiser une liste chaînée
        (2). Vérifier si une liste est vide
        (3). Ajouter un élèment
        (4). Suppression du dernier élèment
        (5). Affichage
    */

    //Prototypage

    //initialisation d'une liste chaînée
    Linked_list create_linked_list(void);

    //Vérifier si la liste est vide
    int is_empty(const Linked_list *list);

    //Ajout d'un élèment
    void add(Linked_list *list, int value);

    //Suppression du dernier élèment
    void pop(Linked_list *list);

    //Affichage
    void display(const Linked_list *list);

#endif