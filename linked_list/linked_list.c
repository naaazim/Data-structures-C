#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//Créer une liste chaînée
Linked_list create_linked_list(void){
    Linked_list list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

//Vérifier si la liste est vide
int is_empty(const Linked_list *list){
    return list->head == NULL;
}

//Ajout d'un élèment
void add(Linked_list *list, int value){
    Node *node = malloc(sizeof(Node));
    if(node == NULL){
        fprintf(stderr,"Memory allocation problem\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    //Cas où la liste est vide
    if(is_empty(list)){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
}

//Suppression du dernier élèment
void pop(Linked_list *list){
    if(is_empty(list)){
        fprintf(stderr, "List already empty\n");
    }else{
        if(list->head == list->tail){
            free(list->tail);
            list->head = NULL;
            list->tail = NULL;
        }else{
            Node *node = list->head;
            while(node->next != list->tail){
                node = node->next;
            }
            free(list->tail);
            list->tail = node;
            node->next = NULL;
        }
    }
}

//Affichage
void display(const Linked_list *list){
    if(is_empty(list)){
        printf("List is empty\n");
    }else{
        Node *node = list->head;
        while(node != NULL){
            if(node->next == NULL){
                printf("[%d, %p]", node->data, node->next);
            }else{
                printf("[%d, %p]->", node->data, node->next);
            }
            node = node->next;
        }
        printf("\n");
    }
}
