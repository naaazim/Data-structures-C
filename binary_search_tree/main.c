#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    BST tree = create_new_tree();

    printf("=== TEST D'UN ARBRE BINAIRE DE RECHERCHE ===\n");

    // Insertion
    printf("\nInsertion des éléments : 50, 30, 70, 20, 40, 60, 80\n");
    tree.root = insert(tree.root, 50);
    tree.root = insert(tree.root, 30);
    tree.root = insert(tree.root, 70);
    tree.root = insert(tree.root, 20);
    tree.root = insert(tree.root, 40);
    tree.root = insert(tree.root, 60);
    tree.root = insert(tree.root, 80);

    printf("\nAffichage (infixe) :\n");
    inorder(tree.root);
    printf("\n");

    // Recherche
    int val = 40;
    printf("\nRecherche de %d...\n", val);
    Node *found = search(tree.root, val);
    if (found)
        printf("Valeur %d trouvée dans l’arbre.\n", val);
    else
        printf("Valeur %d non trouvée.\n", val);

    // Suppression
    printf("\nSuppression de 20, 30 et 50...\n");
    tree.root = delete(tree.root, 20);
    tree.root = delete(tree.root, 30);
    tree.root = delete(tree.root, 50);

    printf("\nAffichage après suppression :\n");
    inorder(tree.root);
    printf("\n");

    return 0;
}
