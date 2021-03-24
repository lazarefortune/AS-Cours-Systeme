#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Saisie des dimensions de la matrice
    char clavier[10];
    printf("Saisir le nombre de ligne = \n");
    scanf("%s", clavier);
    int nbLigne = atoi(clavier);

    printf("Saisir le nombre de colonne = \n");
    scanf("%s", clavier);
    int nbColonne = atoi(clavier);

    // Allocation de la mémoire
    int** matrice = malloc(nbLigne * sizeof(int*));

    for (int i = 0; i < nbLigne; i++) {
      matrice[i] = malloc(nbColonne * sizeof(int));
    }

    // Remplissage de la matrice

    for (int i = 0; i < nbLigne; i++) {
      for (int j = 0; j < nbColonne; j++) {
        matrice[i][j] = rand() % 100;
      }
    }

    // Affichage

    printf("affichage de la matrice \n");

    for (int i = 0; i < nbLigne; i++) {
      for (int j = 0; j < nbColonne; j++) {

        printf("%d ", matrice[i][j] );
      }
      printf("\n");
    }
    printf("\n ----------------------------------------\n\n");

    // ------------------ NOUVELLE MATRICE ----------------------

    // Saisie des dimensions de la NOUVELLE matrice

    printf("Saisir un nouveau nombre de ligne = \n");
    scanf("%s", clavier);
    int newNbLigne = atoi(clavier);

    printf("Saisir un nouveau nombre de colonne = \n");
    scanf("%s", clavier);
    int newNbColonne = atoi(clavier);

    // Allocation de la mémoire de la NOUVELLE
    matrice = realloc(matrice, newNbLigne * sizeof(int*));

    for (int i = 0; i < newNbLigne; i++) {
      matrice[i] = realloc(matrice[i], newNbColonne * sizeof(int));
    }

    // Remplissage de la NOUVELLE matrice

    for (int i = 0; i < newNbLigne; i++) {
      for (int j = nbColonne; j < newNbColonne; j++) {
        matrice[i][j] = rand() % 100;
      }
    }

    // Affichage de la NOUVELLE matrice

    printf("affichage de la matrice \n");

    for (int i = 0; i < newNbLigne; i++) {
      for (int j = 0; j < newNbColonne; j++) {

        printf("%d ", matrice[i][j] );
      }
      printf("\n");
    }
    printf("\n");

    free(matrice);

    return 0;
}
