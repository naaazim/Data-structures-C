#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Node* create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1; // Un nouveau nœud a une hauteur de 1
    return node;
}

int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int get_balance(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rotate_right(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Mise à jour des hauteurs
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));

    return x; // Nouvelle racine
}

Node* rotate_left(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Mise à jour des hauteurs
    x->height = 1 + ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right));
    y->height = 1 + ((height(y->left) > height(y->right)) ? height(y->left) : height(y->right));

    return y; // Nouvelle racine
}

Node* insert(Node *node, int value) {
    // Étape 1 : insertion normale BST
    if (node == NULL)
        return create_node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node; // pas de doublons

    // Étape 2 : mise à jour de la hauteur
    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    // Étape 3 : calcul du facteur d’équilibre
    int balance = get_balance(node);

    // Étape 4 : cas de déséquilibre

    // Cas gauche-gauche
    if (balance > 1 && value < node->left->data)
        return rotate_right(node);

    // Cas droite-droite
    if (balance < -1 && value > node->right->data)
        return rotate_left(node);

    // Cas gauche-droite
    if (balance > 1 && value > node->left->data) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Cas droite-gauche
    if (balance < -1 && value < node->right->data) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    // Si l’arbre est équilibré
    return node;
}

void inorder(const Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}
