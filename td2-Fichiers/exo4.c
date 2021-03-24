#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

  char chemin[] = "lazare";
  char nomFichier[] = "lazare.txt";

  printf("Création d'un dossier\n" );
  sleep(1);
  if (mkdir(chemin, S_IRWXU) < 0) {
    printf("Mauvais nom pour le dossier ou alors le dossier existe déjà \n");
    return EXIT_FAILURE;
  }
  printf("Dossier crée avec succès\n" );
  sleep(1);
  printf("Création du lien\n");
  sleep(1);
  if (link("test1.txt", "t_link") != 0) {

    printf("Erreur lors de la création du lien\n");
    return EXIT_FAILURE;
  }
  printf("Lien crée avec succès\n");

  printf("Suppression du lien\n");
  sleep(1);
  if (unlink("t_link") < 0) {

    printf("Erreur lors de la supprésion du lien\n");
    return EXIT_FAILURE;
  }
  sleep(1);

  printf("Changement de répertoire :\n" );

  if (chdir(chemin) < 0) {

    printf("Erreur lors du changement de répertoire\n");
    return EXIT_FAILURE;
  }
  printf("Nous avons changé de répertoire\n" );
  sleep(1);

  printf("Création d'un dossier\n" );
  sleep(1);
  if (mkdir("invite", S_IRWXU) < 0) {
    printf("Mauvais nom pour le dossier ou alors le dossier existe déjà \n");
    return EXIT_FAILURE;
  }
  printf("Dossier crée avec succès\n" );

  printf("Suppression du dossier\n");

  if (rmdir("invite") < 0) {

    printf("Erreur lors de la supprétion du dossier\n");
    return EXIT_FAILURE;
  }
  printf("Dossier supprimé avec succès\n");
  // system("rm -r ../lazare");


  return EXIT_SUCCESS;

}
