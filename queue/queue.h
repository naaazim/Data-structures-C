#ifndef __FILE_HEADER__
#define __FILE_HEADER__
    /*
        UNE FILE EST DÉFINIE PAR:
            Une tête de file
            Le dernier élèment d'une file
        UNE CELLULE EST DÉFINIE PAR:
            Une donnée (data)
            Un pointeur vers le noeud suivant  
    */

    typedef struct Cell{
        int data;
        struct Cell *next; 
    }Cell; 

    typedef struct Queue{
        Cell *front;
        Cell *rear;
    }Queue;

    /*
        MÉTHODES UTILITAIRES
            (1). Initialisation d'une file
            (2). Vérifier si une file est vide
            (3). Enfiler un élèment
            (4). Défiler la file
            (5). Affichage
    */

    //Prototypage


    //Créer une file
    Queue create_new_queue(void);

    //Vérifier si une file est vide
    int is_empty(const Queue *queue);

    //Enfiler un élèment à une file
    void enqueue(Queue *queue, int value);

    //Défiler une file
    int dequeue(Queue *queue);

    //Afficher une file
    void display(const Queue *queue);
#endif