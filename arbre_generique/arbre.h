#ifndef __ARBRE_HEADER__
#define __ARBRE_HEADER__
    
    /*
        Nous allons étendre la structure arbre binaire pour passer à une structure plus flexible qui est la structure arbre générique
        Dans un arbre binaire une cellule (Node) contient un pointeur vers le fils gauche, une valeur (data) et enfin un pointeur vers le fils droit.
        Afin de permettre cette extension, nous allons faire une transition fils gauche frere droit:
            - Le pointeur vers le sous arbre gauche devient un pointeur vers le premier fils (first child)
            - Le pointeur vers le sous arbre droit devient un pointeur vers le frère droit.
        
        Un arbre générique est défini par:
            - Une racine (root)
            - chaque nœud contient:
                * Un pointeur vers son premier fils (fils gauche). 
                * Une donnée (data de type int par préference)
                * Un pointeur vers le frère droit
    */

    //Structure d'un nœud
   typedef struct Node
   {
        int data;
        struct Node *first_child;
        struct Node *next_sibling;
   }Node;

   //Structure d'un arbre générique
   typedef struct Tree
   {
        Node *root;
   }Tree;

   /*
        Méthodes utilitaires:
            (1). Initialiser un arbre
            (2). Insérer un élèment
            (3). Rechercher un élément
            (4). Afficher un arbre 
            (5). Liberer l'espace alloué 
   */

   // Créer un nouvel arbre vide
   Tree create_tree(void);

   // Insérer un nœud dans un un arbre 
   void insert_node(Tree *tree, int value, Node *father);

   // Rechercher un élèment dans l'arbre
   Node *search_node(Node *node, int value);

   // Afficher un arbre
   void display(const Tree *tree);

   //liberer l'espace alloué 
   void free_tree(Tree *tree);
    
#endif