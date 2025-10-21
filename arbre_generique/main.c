#include <stdio.h>
#include "arbre.h"


int main(){
    Tree tree = create_tree();

    // 2. Insertion de la racine
    insert_node(&tree, 10, NULL);

    // 3. Ajout d’enfants à la racine
    Node *root = tree.root;
    insert_node(&tree, 5, root);
    insert_node(&tree, 7, root);
    insert_node(&tree, 9, root);

    // 4. Ajout d’enfants à un des enfants de la racine
    Node *node5 = search_node(tree.root, 5);
    insert_node(&tree, 2, node5);
    insert_node(&tree, 3, node5);
    insert_node(&tree, 4, node5);

    Node *node7 = search_node(tree.root, 7);
    insert_node(&tree, 8, node7);

    // 5. Affichage de l’arbre
    display(&tree);
}