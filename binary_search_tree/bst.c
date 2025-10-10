#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BST create_new_tree(void) {
    BST tree;
    tree.root = NULL;
    return tree;
}

Node* create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Valeur %d déjà présente dans l’arbre (ignorée).\n", value);

    return root;
}

Node* search(Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

Node* find_min(Node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* delete(Node *root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        // Cas 1 : pas d’enfant
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Cas 2 : un seul enfant
        else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Cas 3 : deux enfants
        Node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(const Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}
