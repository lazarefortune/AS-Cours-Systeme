#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void erreur(const char *message) {
    printf("Erreur durant : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

  int n;
  printf("Saisir le nombre de fils ");
  scanf("%d", &n);
  int pid;


  while (1){
    for (int i = 0; i < n; i++) {
      pid = fork();
      if (pid == 0) {
        printf("Je suis un fils : %d\n", getpid());
        // exit(EXIT_SUCCESS);
      }
      sleep(1);
    }

    kill(getppid(), 9); 

  }

  return 0;
}
