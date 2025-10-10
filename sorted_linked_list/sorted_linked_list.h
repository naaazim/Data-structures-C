#ifndef __SORTED_LINKED_LIST_HEADER__
#define __SORTED_LINKED_LIST_HEADER__
    /*
        UNE LISTE CHAÎNÉE TRIÉE EST DÉFINIE PAR :
            - Un pointeur vers le premier élément (head)
            - Chaque insertion conserve l'ordre croissant des valeurs

        UNE CELLULE EST DÉFINIE PAR :
            - Une donnée (data)
            - Un pointeur vers le noeud suivant
    */

    typedef struct Cell {
        int data;
        struct Cell *next;
    } Cell;

    typedef struct SortedList {
        Cell *head;
    } SortedList;

    /*
        MÉTHODES UTILITAIRES
            (1). Initialiser une liste triée
            (2). Vérifier si la liste est vide
            (3). Insérer un élément en maintenant l'ordre
            (4). Supprimer un élément
            (5). Afficher la liste
    */

    // Créer une nouvelle liste vide
    SortedList create_new_list(void);

    // Vérifier si la liste est vide
    int is_empty(const SortedList *list);

    // Insérer un élément en respectant l'ordre
    void insert_sorted(SortedList *list, int value);

    // Supprimer un élément par sa valeur
    void delete_value(SortedList *list, int value);

    // Afficher la liste
    void display(const SortedList *list);

#endif
