#include <stdio.h>
#include <stdlib.h>
#include "circular_list.h"

int main() {
    CircularList list = create_new_list();

    printf("=== Test de la liste chaînée circulaire ===\n");

    display(&list);

    printf("\nInsertion de 10, 20, 30...\n");
    insert_end(&list, 10);
    insert_end(&list, 20);
    insert_end(&list, 30);
    display(&list);

    printf("\nSuppression de 10...\n");
    delete_value(&list, 10);
    display(&list);

    printf("\nSuppression de 20...\n");
    delete_value(&list, 20);
    display(&list);

    printf("\nSuppression de 30...\n");
    delete_value(&list, 30);
    display(&list);

    printf("\nTentative de suppression d'un élément inexistant...\n");
    delete_value(&list, 50);

    return 0;
}
