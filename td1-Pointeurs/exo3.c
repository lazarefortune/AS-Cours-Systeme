#include <stdio.h>

typedef struct{
  int x,y,z;
}coordonnees;

// Initialisation
void initialise(coordonnees* c){
  c->x = 10;
  c->y = 5;
  c->z = 2;
}

// Affichage
void affichage(coordonnees* c){

  printf("les coordonnees sont %d, %d et %d \n",c->x ,c->y , c->z);
}

// Multiplication
void multiplication(coordonnees* c){

  c->z = c->x * c->y;
  affichage(c);
}

// Addition
void addition(coordonnees* c){

  c->z = c->y + c->z;
  affichage(c);
}

int main(int argc, char *argv[]) {

    coordonnees c;
    initialise(&c);
    affichage(&c);
    multiplication(&c);
    addition(&c);
    return 0;
}
