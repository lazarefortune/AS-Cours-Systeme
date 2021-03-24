#include <stdio.h>

void plus(int* a, int* b, int* resultat){

  *resultat = *a + *b;
}

void moins(int* a, int* b, int* resultat){
  *resultat = *a - *b;
}
void fois(int* a, int* b, int* resultat){
  *resultat = *a * *b;
}

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


    // int x = 10, y = 5 ,z = 2;
    // plus(&x, &y, &z);
    // printf("la somme %d + %d = %d \n",x,y, z);
    //
    // moins(&x, &y, &z);
    // printf("la différence %d - %d = %d \n",x,y, z);
    //
    // fois(&x, &y, &z);
    // printf("le produit %d * %d = %d \n",x,y, z);

    coordonnees c;
    initialise(&c);
    affichage(&c);
    multiplication(&c);
    addition(&c);
    return 0;
}



















// printf("Hello, les amis! \n");
//
// int a = 12;
// printf("la valeur de a = %d \n", a );
//
// int age;
// char clavier[100];
// printf("Saisissez du text  = \n");
// scanf("%s", clavier);
// printf("%s\n", clavier);
//
// printf("\nMainenant, on va lister tous les arguments (argv)\n");
// int i;
// for (i = 0; i < argc; i++) {
  //     printf("%s \n", argv[i]);
  // }
