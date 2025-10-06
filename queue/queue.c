#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue create_new_queue(void){
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    return queue;
}
int is_empty(const Queue *queue){
    return queue->front == NULL;
}
void enqueue(Queue *queue, int value) {
    Cell *new_cell = (Cell *)malloc(sizeof(Cell));
    if (!new_cell) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_cell->data = value;
    new_cell->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_cell;
    } else {
        queue->rear->next = new_cell;
        queue->rear = new_cell;
    }
}

int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "La file est vide, impossible de défiler.\n");
        return -1;
    }
    Cell *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return value;
}

void display(const Queue *queue) {
    const Cell *current = queue->front;
    printf("File: ");
    while (current != NULL) {
        if(current->next == NULL){
            printf("[%d]", current->data);
        }else{
            printf("[%d]<-", current->data);
        }
        current = current->next;
    }
    printf("\n");
}