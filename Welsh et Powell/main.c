#include "graphe_matrice.h"

int main() {
    printf("Chargement du graphe...\n");

    // Charger depuis un fichier texte
    // Format du fichier :
    // Ligne 1 : nombre de sommets
    // Puis matrice n×n de 0/1
    GraphMatrix g = chargeGraphe(NULL);

    // Afficher la matrice
    display_matrix(&g);

    // Appliquer Welsh–Powell
    welsh_powell(&g);

    // Libérer la mémoire
    free_graph(&g);

    return 0;
    // Analyse de l'algorithme welsh_powell
    /*
        L’algorithme de Welsh–Powell est une méthode gloutonne de coloration de graphes.
        Il commence par trier les sommets selon leur degré décroissant, puis attribue les couleurs en évitant que deux sommets adjacents partagent la même couleur.
        Sa complexité est O(n²) lorsqu’on utilise une matrice d’adjacence, car il faut parcourir toutes les connexions entre sommets pour calculer les degrés et vérifier les adjacences.
        1. Calcul des degrés: Pour chaque sommet i, on parcourt tous les autres sommets j pour compter les connexions (double boucle sur n × n) -> O(n²)
        2. Tri des sommets: On trie les sommets selon leur degré décroissant avec un tri à bulles (deux boucles imbriquées) -> O(n²)
        3. Coloration: Pour chaque sommet, on vérifie les adjacences avec tous les autres pour éviter les conflits de couleur -> O(n²)
        Total: Somme des étapes dominée par les boucles imbriquées -> O(n²)
    */
}
