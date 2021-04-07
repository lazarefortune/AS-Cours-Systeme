#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

    char *message = malloc(100 * sizeof(char));

    pid_t pidFils;

    int tube[2];
    pipe(tube);

    pidFils = fork();

    if(pidFils == 0)

    {
        close(tube[1]);
        read(tube[0], message, sizeof(message));
        printf("Le fils affiche : %s \n", message);

    }else{

        close(tube[0]);

        printf("Saisir un texte :\n");
        // scanf("%s", message);
        fgets(message, sizeof(message), stdin);
        printf("%s\n", message);

        write(tube[1], message, sizeof(message));

        wait(NULL);
    }

    free(message);
    return EXIT_SUCCESS;

}
