#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char message[100];

    pid_t pidFils;

    int tube1[2], tube2[2];
    pipe(tube1);
    pipe(tube2);

    pidFils = fork();

    if(pidFils == 0)

    {
        close(tube1[1]);
        read(tube1[0], message, 100);
        printf("Message reçu \n");

        close(tube2[0]);
        write(tube2[1], message, strlen(message));

    }else{

        close(tube1[0]);

        printf("Saisir un texte :\n");

        fgets(message, 100, stdin);

        write(tube1[1], message, strlen(message));

        close(tube2[1]);
        read(tube2[0], message, 100);
        printf("j'ai reçu : %s\n", message);
        wait(NULL);
    }

    return EXIT_SUCCESS;

}
