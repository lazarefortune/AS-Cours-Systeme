#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2

void erreur(const char *message) {
    printf("Erreur durant : %s\n", message);
    exit(EXIT_FAILURE);
}

int main(const int argc, char const *argv[]) {
    int i;

    int f1 = fork();
    if (f1 == 0) {
      /* code */
      printf("Je suis un fils : %d\n", getpid());
      return 0;
    }
    int f2 = fork();
    if (f2 == 0) {
      /* code */
      printf("Je suis un fils : %d\n", getpid());
      return 0;
    }
    printf("Je suis votre pere : %d\n", getppid());


    return EXIT_SUCCESS;
}
