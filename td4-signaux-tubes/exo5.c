#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>



int main(int argc, char const *argv[]) {

    int fils;
    int tube[2];
    pipe(tube);

    char* texte;
    printf("Saisir un texte \n");
    scanf("%s", texte);
    int pid = fork()
    char* bufLecture;
    char* bufEcriture;

    if (pid == 0) {
      read(tube[0], bufLecture, 100);
      printf("%s\n", bufLecture);
      close(p[0]);
    }else{
      write(tube[1], bufEcriture, 100);
      close(tube[1]);
      wait(NULL);
    }





    return EXIT_SUCCESS;

  return 0;
}
