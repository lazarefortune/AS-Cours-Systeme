#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define TAILLE 10

int main(int argc, char *argv[]) {

  int fichier1,fichier2;
  char buffer[TAILLE];

  if ((fichier1 = open("test1.txt",O_RDONLY)) < 0 ) {
    printf("Erreur d'ouverture du fichier 1\n");

    close(fichier1);
    close(fichier2);
    return EXIT_FAILURE;
  }
  if ((fichier2 = open("test2.txt",O_CREAT | O_TRUNC | O_WRONLY)) < 0 ) {
    printf("Erreur d'ouverture du fichier 2 \n");

    close(fichier1);
    close(fichier2);
    return EXIT_FAILURE;
  }

  if(read(fichier1, buffer, TAILLE) != TAILLE){
    printf("Erreur de lecture du fichier 1 \n");
    close(fichier1);
  }

  close(fichier1);
  close(fichier2);

  rename("test2.txt", "test3.txt");

  if (unlink("test1.txt") != 0) {
      printf("Erreur suppression fichier");
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;

}
