# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

#define PORT 6000
#define MAX_BUFFER 1000

const char *EXIT = "exit";

void lireMessage(char tampon[]){
    printf("Saisir un message à envoyer:\n");
    fgets(tampon ,MAX_BUFFER, stdin);
}

int main(int argc, char const *argv[]){
    int fdSocketAttente;
    int fdSocketCommunication;
    struct sockaddr_in coordonneesServeur;
    struct sockaddr_in coordonneesAppelant;
    char tampon[MAX_BUFFER];
    int nbRecu;
    int longueurAdresse;

    fdSocketAttente = socket(PF_INET, SOCK_STREAM, 0);

    if(fdSocketAttente <0){
        printf("socket incorrecte\n");
        exit(EXIT_FAILURE);
    }

    //on prépare l'adresse d'attachement locale
    longueurAdresse = sizeof(struct sockaddr_in);
    memset(&coordonneesServeur, 0x00, longueurAdresse);

    coordonneesServeur.sin_family=PF_INET;
    coordonneesServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    coordonneesServeur.sin_port = htons(PORT);

    if(bind(fdSocketAttente, (struct sockaddr *) &coordonneesServeur, sizeof(coordonneesServeur)) ==-1) {
        printf("erreur de bind \n");
        exit(EXIT_FAILURE);
    }

    if(listen(fdSocketAttente, 5) == -1){
        printf("erreur de listen \n");
        exit(EXIT_FAILURE);
    }

    while (1){

    }
}
