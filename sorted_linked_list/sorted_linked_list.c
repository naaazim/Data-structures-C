#include <stdio.h>
#include <stdlib.h>
#include "sorted_linked_list.h"

SortedList create_new_list(void) {
    SortedList list;
    list.head = NULL;
    return list;
}

int is_empty(const SortedList *list) {
    return list->head == NULL;
}

void insert_sorted(SortedList *list, int value) {
    Cell *new_cell = (Cell *)malloc(sizeof(Cell));
    if (!new_cell) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    new_cell->data = value;
    new_cell->next = NULL;

    // Cas 1 : liste vide ou insertion en tête
    if (is_empty(list) || value < list->head->data) {
        new_cell->next = list->head;
        list->head = new_cell;
        return;
    }

    // Cas 2 : insertion au milieu ou à la fin
    Cell *current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_cell->next = current->next;
    current->next = new_cell;
}

void delete_value(SortedList *list, int value) {
    if (is_empty(list)) {
        printf("La liste est vide.\n");
        return;
    }

    Cell *current = list->head;
    Cell *prev = NULL;

    // Cas spécial : suppression en tête
    if (current->data == value) {
        list->head = current->next;
        free(current);
        return;
    }

    // Recherche de la valeur à supprimer
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Valeur %d non trouvée dans la liste.\n", value);
        return;
    }

    prev->next = current->next;
    free(current);
}

void display(const SortedList *list) {
    if (is_empty(list)) {
        printf("Liste vide.\n");
        return;
    }

    const Cell *current = list->head;
    printf("Liste triée : ");
    while (current != NULL) {
        if (current->next == NULL) {
            printf("[%d]", current->data);
        } else {
            printf("[%d] -> ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}
