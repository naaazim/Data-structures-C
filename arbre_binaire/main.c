#include <stdio.h>
#include "arbre_binaire.h"

int main() {
    printf("=== TEST D’UN ARBRE BINAIRE SIMPLE ===\n\n");

    // Création manuelle de l’arbre
    Node *root = create_node('B'); // racine

    insert_left(root, 'A');        // A en fils gauche de B
    insert_right(root, 'O');       // O en fils droit de B

    Node *nA = search_node(root, 'A');
    insert_left(nA, 'R');          // R en fils gauche de A
    insert_right(nA, 'V');         // V en fils droit de A

    // Affichages des parcours
    printf("Parcours préfixe   : ");
    preorder(root);
    printf("\n");

    printf("Parcours infixe    : ");
    inorder(root);
    printf("\n");

    printf("Parcours postfixe  : ");
    postorder(root);
    printf("\n");

    // Libération mémoire
    free_tree(root);

    return 0;
}
