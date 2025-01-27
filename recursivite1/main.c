#include <stdio.h>
#include <stdlib.h>

void inverserRec(int tableau[], int debut, int fin);



int main() {
    int tableau[] = {1, 2, 3, 99, 5};
    int taille = 5;
    int i;

    printf("Tableau original : ");
    for ( i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }

    inverserRec(tableau, 0, taille - 1);

    printf("\nTableau inversé : ");
    for ( i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }

    return 0;
}
void inverserRec(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int temp = tableau[debut];
        tableau[debut] = tableau[fin];
        tableau[fin] = temp;


        inverserRec(tableau, debut + 1, fin - 1);
    }
}
