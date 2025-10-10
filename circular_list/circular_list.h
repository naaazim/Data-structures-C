#ifndef __CIRCULAR_LIST_HEADER__
#define __CIRCULAR_LIST_HEADER__

    /*
        UNE LISTE CHAÎNÉE CIRCULAIRE EST DÉFINIE PAR :
            - Un pointeur vers le premier élément (head)
            - Le dernier élément pointe vers le premier (boucle fermée)

        UNE CELLULE EST DÉFINIE PAR :
            - Une donnée (data)
            - Un pointeur vers le noeud suivant
    */

    typedef struct Cell {
        int data;
        struct Cell *next;
    } Cell;

    typedef struct CircularList {
        Cell *head;
    } CircularList;

    /*
        MÉTHODES UTILITAIRES
            (1). Initialiser une liste circulaire
            (2). Vérifier si une liste est vide
            (3). Insérer un élément en fin de liste
            (4). Supprimer un élément
            (5). Afficher la liste
    */

    // Prototypage des fonctions

    // Créer une nouvelle liste
    CircularList create_new_list(void);

    // Vérifier si la liste est vide
    int is_empty(const CircularList *list);

    // Insérer un élément en fin de liste
    void insert_end(CircularList *list, int value);

    // Supprimer un élément par valeur
    void delete_value(CircularList *list, int value);

    // Afficher la liste
    void display(const CircularList *list);

#endif
