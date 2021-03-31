#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int pid = fork();
  if(pid == 0){
    traitementPourLeFils();
  }else if(pid > 0){
    traitementPourLePere();
  }
  return 0;
}
