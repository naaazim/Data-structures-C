#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

// Initialisation d'un arbre
Tree create_tree(){
    Tree tree;
    tree.root = NULL;
    return tree;
}

// Inserer un nœud
void insert_node(Tree *tree, int value, Node *father){
    // cas d'un arbre vide -> ajouter à la racine
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->first_child = NULL;
    node->next_sibling = NULL;
    if(tree->root == NULL){
        tree->root = node;
    }
    //cas d'un arbre non vide
    // on vérifie que father existe bien
    else if(father != NULL){
        if(father->first_child == NULL){
            father->first_child = node;
        }else{
            Node *current_node = father->first_child;
            while(current_node->next_sibling != NULL){
                current_node = current_node->next_sibling;
            }
            current_node->next_sibling = node;
        }
    }else{
        fprintf(stderr, "Le noeud à l'adresse %p n'existe pas\n", father);
        exit(EXIT_FAILURE);
    }
}

// Recherche d'un élèment
Node *search_node(Node *node, int value){
    if(node == NULL){
        return NULL;
    }
    if(node->data == value){
        return node;
    }
    Node *result = search_node(node->first_child, value);
    if(result == NULL){
        result = search_node(node->next_sibling, value);
    }
    return result;
}
// Fonction récursive d’affichage avec structure en arbre
void display_node(const Node *node, int depth) {
    if (node == NULL) return;

    // Affichage du frère suivant à droite (pour que l’arbre "penche" à gauche)
    display_node(node->next_sibling, depth);

    // Indentation en fonction de la profondeur
    for (int i = 0; i < depth; i++) {
        printf("     "); // 5 espaces par niveau
    }

    // Affiche la valeur du nœud
    printf("%d\n", node->data);

    // Affichage du fils (sous le parent)
    display_node(node->first_child, depth + 1);
}

// Fonction principale d’affichage de l’arbre
void display(const Tree *tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("L’arbre est vide.\n");
        return;
    }

    printf("\nAffichage visuel de l’arbre :\n\n");
    display_node(tree->root, 0);
}


