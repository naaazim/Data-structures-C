#include <stdio.h>
#include <stdlib.h>
#include "arbre_binaire.h"

// Création d’un nouveau nœud
Node* create_node(char value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Erreur d’allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Recherche d’un nœud par sa valeur (parcours préfixe)
Node* search_node(Node *root, char value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;

    Node *found = search_node(root->left, value);
    if (found != NULL) return found;

    return search_node(root->right, value);
}

// Insertion en fils gauche
void insert_left(Node *parent, char value) {
    if (parent == NULL) return;
    Node *new_node = create_node(value);
    if (parent->left == NULL) {
        parent->left = new_node;
    } else {
        // Si un fils gauche existe déjà, il devient le fils gauche du nouveau nœud
        new_node->left = parent->left;
        parent->left = new_node;
    }
}

// Insertion en fils droit
void insert_right(Node *parent, char value) {
    if (parent == NULL) return;
    Node *new_node = create_node(value);
    if (parent->right == NULL) {
        parent->right = new_node;
    } else {
        // Si un fils droit existe déjà, il devient le fils droit du nouveau nœud
        new_node->right = parent->right;
        parent->right = new_node;
    }
}

// Parcours préfixe
void preorder(const Node *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Parcours infixe
void inorder(const Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

// Parcours postfixe
void postorder(const Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

// Libération mémoire
void free_tree(Node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
