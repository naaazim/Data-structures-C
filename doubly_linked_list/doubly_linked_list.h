#ifndef DOUBLY_LINKED_LIST_HEADER
#define DOUBLY_LINKED_LIST_HEADER

    /*
        STRUCTURE D'UN NOEUD
            Noeud : contient une valeur (data), un pointeur vers le noeud suivant et un pointeur vers le noeud précèdent
        STRUCTURE D'UNE LISTE DOUBLEMENT CHAINÉE
            Liste : contient une variable size qui stocke sa taille un pointeur vers le premier noeud (tête) et un pointeur vers le dernier élèment (queue), (ce pointeur sert à faire de l'insertion en O(1))
    */
   //Structure d'un noeud
   typedef struct Node{
       int data;
       struct Node *previous;
       struct Node *next;
    }Node;
    
    //Structure d'une liste doublement chaînée
    typedef struct Doubly_linked_list{
        int size; 
        Node *head;
        Node *tail;
   }Doubly_linked_list;
    /*
        fonctions utiles:
        (1). Initialiser une liste doublement chaînée
        (2). Vérifier si une liste est vide
        (3). Insérer un noeud
        (4). Insérer un élèment à une position donnée
        (5). Supprimer un élèment à un position donnée 
        (6). Affichage
    */

    //Prototypage
    
    //Initialiser une liste doublement chaînée
    Doubly_linked_list create_doubly_linked_list(void);

    //Vérifier si une liste est vide
    int is_empty(const Doubly_linked_list *list);

    //Insérer un noeud
    void add(Doubly_linked_list *list, int value);

    //Insérer un noeud de valeur (value) à une position (index) passée en @param
    void insert_at_index(Doubly_linked_list *list, int value, int index);

    //Supprimer un élèment à une position(index) passée en @param
    void delete_at_index(Doubly_linked_list *list, int index);

    //Afficher une liste
    void display(const Doubly_linked_list *list);
#endif