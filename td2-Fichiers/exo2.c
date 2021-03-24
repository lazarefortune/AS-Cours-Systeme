#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define TAILLE 10

int main(int argc, char *argv[]) {

    int fichier1, fichier2;
    char buffer[BUFSIZ];

    if (argc != 3) {
      printf("Nombre d'arguments insuffisants\n");
      return EXIT_FAILURE;
    }

    // char fileName1[] = argv[0];
    // char fileName2[] = argv[1];

    printf("file 1 : %s\n", argv[1]);
    printf("file 1 : %s\n", argv[2]);

    if ((fichier1 = open(argv[1],O_RDONLY)) < 0 ) {
      printf("Erreur d'OUVERTURE du fichier 1\n");

      close(fichier1);
      close(fichier2);
      return EXIT_FAILURE;
    }

    if ((fichier2 = open(argv[2],O_CREAT | O_TRUNC | O_WRONLY)) < 0 ) {
      printf("Erreur d'OUVERTURE du fichier 2 \n");

      close(fichier1);
      close(fichier2);
      return EXIT_FAILURE;
    }

    if(read(fichier1, buffer, BUFSIZ) != BUFSIZ){
      printf("Erreur de LECTURE du fichier 1 \n");
      close(fichier1);
    }

  return EXIT_SUCCESS;

}
