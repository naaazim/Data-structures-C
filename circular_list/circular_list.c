#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

CircularList create_new_list(void) {
    CircularList list;
    list.head = NULL;
    return list;
}

int is_empty(const CircularList *list) {
    return list->head == NULL;
}

void insert_end(CircularList *list, int value) {
    Cell *new_cell = (Cell *)malloc(sizeof(Cell));
    if (!new_cell) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_cell->data = value;

    if (is_empty(list)) {
        new_cell->next = new_cell;  // Se pointe lui-même
        list->head = new_cell;
    } else {
        Cell *temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = new_cell;
        new_cell->next = list->head;
    }
}

void delete_value(CircularList *list, int value) {
    if (is_empty(list)) {
        printf("La liste est vide.\n");
        return;
    }

    Cell *current = list->head;
    Cell *prev = NULL;

    // Cas spécial : suppression de la tête
    if (current->data == value) {
        if (current->next == list->head) {
            // Un seul élément
            free(current);
            list->head = NULL;
        } else {
            // Plusieurs éléments
            Cell *last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            list->head = current->next;
            last->next = list->head;
            free(current);
        }
        return;
    }

    // Recherche de l'élément à supprimer
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            return;
        }
    } while (current != list->head);

    printf("Élément %d non trouvé dans la liste.\n", value);
}

void display(const CircularList *list) {
    if (is_empty(list)) {
        printf("Liste vide.\n");
        return;
    }

    Cell *current = list->head;
    printf("Liste circulaire : ");
    do {
        if (current->next == list->head) {
            printf("[%d]", current->data);
        } else {
            printf("[%d] -> ", current->data);
        }
        current = current->next;
    } while (current != list->head);
    printf(" -> (retour à la tête)\n");
}
