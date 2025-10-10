#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    Node *root = NULL;

    printf("=== TEST DE L’ARBRE AVL ===\n");

    int values[] = {30, 20, 40, 10, 25, 50, 5};
    int n = sizeof(values) / sizeof(values[0]);

    printf("\nInsertion des valeurs : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n\nAffichage (parcours infixe) :\n");
    inorder(root);
    printf("\n");

    printf("\nAjout de nouvelles valeurs : 35, 45, 60\n");
    root = insert(root, 35);
    root = insert(root, 45);
    root = insert(root, 60);

    printf("\nAffichage après rééquilibrage :\n");
    inorder(root);
    printf("\n");

    return 0;
}
