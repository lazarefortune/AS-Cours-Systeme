#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

   int main(int argc, char *argv[]) {

      struct dirent *dir;
      // opendir() renvoie un pointeur de type DIR.
      DIR *d = opendir(".");
      if (d)
      {
          while ((dir = readdir(d)) != NULL)
          {
              printf("%s : ", dir->d_name);
              // printf ("\033[34;01m %s \033[00m ", dir->d_name);
              // printf("%d\n", dir->d_type);


          }
          closedir(d);
      }


     return EXIT_SUCCESS;

   }
