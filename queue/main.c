#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    Queue queue = create_new_queue();
    display(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);

    printf("Défilé: %d\n", dequeue(&queue));
    display(&queue);

    printf("Défilé: %d\n", dequeue(&queue));
    display(&queue);

    printf("Défilé: %d\n", dequeue(&queue));
    display(&queue);

    printf("Défilé: %d\n", dequeue(&queue)); // Tentative de défiler une file vide

    return 0;
}