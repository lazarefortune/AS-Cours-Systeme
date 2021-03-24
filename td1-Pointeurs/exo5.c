#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Saisie de la taille du tableau
    char clavier[10];
    printf("Saisir la taille du tableau = \n");
    scanf("%s", clavier);
    int taille = atoi(clavier);

    // Allocation de la mémoire
    int* tableau = malloc(taille * sizeof(int));

    // Remplissage du tableau
    for (int i = 0; i < taille; i++) {
      tableau[i] = rand() % 100;
    }

    // Affichage du tableau
    printf("affichage du tableau\n");
    printf("la taille du tableau est  = %d \n", taille);
    for (int i = 0; i < taille; i++) {
      printf("%d ", tableau[i] );
      // printf("tab[%d] = %d\n", i, tableau[i] );
    }
    printf("\n");

    // -------- MODIFICATION DE LA TAILLE DU TABLEAU ------------------
    printf("---------------------------------------\n\n");
    // Saisie de la taille du tableau
    printf("Saisir la nouvelle taille du tableau = \n");
    scanf("%s", clavier);
    int newTaille = atoi(clavier);

    // Allocation de la mémoire
    tableau = realloc(tableau, newTaille * sizeof(int));

    // Remplissage du tableau
    for (int i = taille; i < newTaille; i++) {
      tableau[i] = rand() % 100;
    }

    // Affichage du tableau
    printf("affichage du nouveau tableau\n");
    printf("la taille du nouveau tableau est  = %d \n", newTaille);
    for (int i = 0; i < newTaille; i++) {
      printf("%d ", tableau[i] );
      // printf("tab[%d] = %d\n", i, tableau[i] );
    }
    printf("\n");

    // Libération de la
    free(tableau);

    return 0;
}
