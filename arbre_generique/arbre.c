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
#include <stdio.h>
#include "arbre.h"

// Fonction récursive d’affichage stylisée
void display_node(const Node *node, const char *prefix, int is_last) {
    if (node == NULL) return;

    // Affiche le préfixe et le symbole (├── ou └──)
    printf("%s", prefix);
    printf("%s%d\n", (is_last ? "└── " : "├── "), node->data);

    // Nouveau préfixe pour les niveaux suivants
    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, (is_last ? "    " : "│   "));

    // Compte le nombre de fils pour savoir quand afficher └──
    Node *child = node->first_child;
    while (child) {
        Node *next = child->next_sibling;
        display_node(child, new_prefix, next == NULL);
        child = next;
    }
}

// Fonction principale d’affichage
void display(const Tree *tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("L’arbre est vide.\n");
        return;
    }

    printf("\nAffichage visuel de l’arbre :\n\n");
    printf("%d\n", tree->root->data); // racine
    Node *child = tree->root->first_child;
    while (child) {
        Node *next = child->next_sibling;
        display_node(child, "", next == NULL);
        child = next;
    }
}

// Fonction récursive pour libérer chaque nœud et ses descendants
void free_node(Node *node) {
    if (node == NULL) return;

    // Libérer d'abord tous les enfants
    free_node(node->first_child);

    // Libérer ensuite tous les frères
    free_node(node->next_sibling);

    // Enfin, libérer le nœud lui-même
    free(node);
}

// Fonction principale pour libérer tout l’arbre
void free_tree(Tree *tree) {
    if (tree == NULL || tree->root == NULL) return;

    free_node(tree->root);
    tree->root = NULL; // Sécurité : éviter un pointeur pendu
}
