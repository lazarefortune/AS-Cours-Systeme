#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {

  int pid;
  printf("Saisir le pid ");
  scanf("%d", &pid);
  for (int i = 10; i < NSIG; i++) {
    kill(pid, i);
    sleep(1);
  }

  return 0;
}
