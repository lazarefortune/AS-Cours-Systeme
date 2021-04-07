#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{

  /* Creation du tube */
    if (mkfifo("fichier.txt", 0644) != 0) {
      perror("mkfifo";
      // exit(1);
      exit(EXIT_FAILURE);
    }

    // open(”fichier.txt", O_WRONLY);

    return EXIT_SUCCESS;

}
