#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void afficher(){
  printf("Je suis un signal\n");
}

int main(int argc, char *argv[]) {

  int pid = getpid();
  printf("%d\n", pid);

  for (int i = 1; i < NSIG; i++) {
    if (signal(i, afficher) == SIG_ERR) {
      printf("Erreur pour signal %d\n", i);
    }
  }
  while (1){

  }
  return 0;
}
