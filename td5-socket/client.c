#include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

#define PORT 6000
#define MAX_BUFFER 1000

int main(int argc, char const *argv[]) {
  int fdSocket;
  int ndRecu;
  struct sockaddr_in coordonneesServeur;
  int longueurAdresse;
  char tampon[MAX_BUFFER];

  fdSocket = socket(AF_INET, SOCK_STREAM, 0);

  if (fdSocket < 0) {
    printf("Socket incorrect\n");
    exit(EXIT_FAILURE);
  }

  // On prépare les coordonnees du serveur
  longueurAdresse = sizeof(struct sockaddr_in);
  memset(&coordonneesServeur, 0x00, longueurAdresse);

  coordonneesServeur.sin_family = PF_INET;
  // addresse du Serveur
  inet_aton("127.0.0.1", &coordonneesServeur.sin_addr);

  // Toutes interfaces locales disponibles

  coordonneesServeur.sin_port = htons(PORT);

  if (connect(fdSocket, (struct sockaddr *) &coordonneesServeur, sizeof(coordonneesServeur)) == -1) {
    printf("Connexion impossible\n");
    exit(EXIT_FAILURE);
  }

  printf("Connexion ok\n");

  while (1) {
    /* code */
  }

}
