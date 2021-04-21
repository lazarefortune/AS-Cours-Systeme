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

    socklen_t tailleCoord = sizeof(coordonneesAppelant);

    if ((fdSocketCommunication = accept(fdSocketAttente, (struct sockaddr *) &coordonneesAppelant, &tailleCoord)) == -1) {
      printf("Erreur de accept\n");
      exit(EXIT_FAILURE);
    }

    printf("Client connecté\n");

    nbRecu = recv(fdSocketCommunication, tampon , MAX_BUFFER, 0);

    if (nbRecu > 0) {
      tampon[nbRecu] = 0;
      printf("Recu %s\n", tampon);
    }

    printf("Envoi du message au client\n");
    strcpy(tampon, "Message renvoye par le serveur");
    
}
