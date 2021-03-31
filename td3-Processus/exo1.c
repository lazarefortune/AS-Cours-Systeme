#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void erreur(const char *message){
  printf("%s\n", );
}

int main(int argc, char *argv[]) {

  int pid = fork();

  waitpid(pid, NULL, 0);
  if(pid == 0){
    printf("Je suis le fils\n");
    return 0;
    // traitementPourLeFils();
  }else if(pid > 0){
    printf("Je suis le père\n");
    // traitementPourLePere();
    return 0;
  }

  printf ("L'identifiant du processus est %d\n", (int) getpid ());
  printf ("L'identifiant du processus parent est %d\n", (int) getppid ());

  return 0;
}
