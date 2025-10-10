#include <stdio.h>
#include <stdlib.h>
#include "sorted_linked_list.h"

int main() {
    SortedList list = create_new_list();

    printf("=== Test de la liste chaînée triée ===\n");
    display(&list);

    printf("\nInsertion de valeurs : 30, 10, 20, 40\n");
    insert_sorted(&list, 30);
    insert_sorted(&list, 10);
    insert_sorted(&list, 20);
    insert_sorted(&list, 40);
    display(&list);

    printf("\nSuppression de 20...\n");
    delete_value(&list, 20);
    display(&list);

    printf("\nSuppression de 10...\n");
    delete_value(&list, 10);
    display(&list);

    printf("\nSuppression d'une valeur inexistante (50)...\n");
    delete_value(&list, 50);
    display(&list);

    printf("\nSuppression des éléments restants...\n");
    delete_value(&list, 30);
    delete_value(&list, 40);
    display(&list);

    return 0;
}
