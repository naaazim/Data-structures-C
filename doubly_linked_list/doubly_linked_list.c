#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

//Initialisation
Doubly_linked_list create_doubly_linked_list(void){
    Doubly_linked_list list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

//Vérifie si la liste est vide
int is_empty(const Doubly_linked_list *list){
    return list->size == 0;
}
//Insérer un élèment
void add(Doubly_linked_list *list, int value){
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation problem\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    if(is_empty(list)){
        node->next = NULL;
        node->previous = NULL;
        list->head=node;
        list->tail=node;
    }else{
        node->previous = list->tail;
        list->tail->next = node;
        list->tail = node;
        node->next = NULL;
    }
    list->size++;
}


//Insérer à un indice donné
void insert_at_index(Doubly_linked_list *list, int value, int index){
    if(index < 0 || index > list->size){
        printf("Indice non cohérent");
        exit(EXIT_FAILURE);
    }
    //cas ou la liste est vide
    if(is_empty(list) || index == list->size){
        //appel la fonction précédente
        add(list, value);
    }else{
        Node *currentNode = list->head;
        for(int i = 0; i < index; i++){
            currentNode = currentNode->next;
        }
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Memory allocation problem\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = value;
        newNode->next = currentNode;
        newNode->previous = currentNode->previous;
        currentNode->previous = newNode;
        if(newNode->previous != NULL){
            newNode->previous->next = newNode;
        }else{
            list->head = newNode;
        }
        list->size++;
    }
}
// Supprimer à un indice donné
void delete_at_index(Doubly_linked_list *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Indice non cohérent\n");
        exit(EXIT_FAILURE);
    }
    if (is_empty(list)) {
        printf("La liste est vide\n");
        exit(EXIT_FAILURE);
    }
    Node *currentNode = list->head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    // Cas 1 : suppression du head
    if (currentNode == list->head) {
        list->head = currentNode->next;
        if (list->head != NULL) {
            list->head->previous = NULL;
        } else {
            // la liste devient vide
            list->tail = NULL;
        }
    }
    // Cas 2 : suppression du tail
    else if (currentNode == list->tail) {
        list->tail = currentNode->previous;
        list->tail->next = NULL;
    }
    // Cas 3 : suppression au milieu
    else {
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
    }
    free(currentNode);
    list->size--;
}


//Affichage
void display(const Doubly_linked_list *list) {
    if (is_empty(list)) {
        printf("La liste est vide\n");
    } else {
        Node *node = list->head;
        while (node != NULL) {
            // afficher previous
            if (node->previous == NULL) {
                printf("(NULL, ");
            } else {
                printf("(%p, ", node->previous);
            }

            // afficher data
            printf("%d, ", node->data);

            // afficher next
            if (node->next == NULL) {
                printf("NULL)");
            } else {
                printf("%p)", node->next);
            }

            // séparateur si pas le dernier
            if (node->next != NULL) {
                printf(" <-> ");
            }

            node = node->next;
        }
        printf("\n");
    }
}

