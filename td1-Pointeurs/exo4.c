#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Saisie de la taille du tableau
    char clavier[10];
    printf("Saisir la taille du tableau = \n");
    scanf("%s", clavier);
    int taille = atoi(clavier);

    // Allocation de la mémoire
    char* tableau = malloc(taille * sizeof(char));

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

    // Libération de la mémoire
    free(tableau);

    return 0;
}
