#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"
int nbVoyageurs(char nomFich[]){
    voyageur v;
    int nb=0;
    FILE *f=fopen(nomFich,"rb");
    if (f==NULL){
        printf("erreur");
    }
    else{
        while(fread(&v,sizeof(voyageur),1,f)){
            nb++;
        }
    }
    return nb;
    fclose(f);
}
void saisirVoyageur (voyageur * ptv){
    printf("id=");
    fflush(stdin);
    gets(ptv->id);
     printf("nom=");
    fflush(stdin);
    gets(ptv->nom);
     printf("adresse=");
    fflush(stdin);
    gets(ptv->ad);
    printf("nb voyage=");
    scanf("%d",&ptv->nbv);
}
voyageur *charger_donnees(char nomFich[], int *n) {
    FILE *fichier = fopen(nomFich, "rb");
    if (fichier == NULL) {
        printf("Erreur ");

    }

    (*n) = nbVoyageurs(nomFich);
    voyageur *tab = (voyageur *)malloc((*n) * sizeof(voyageur));


    fread(tab, sizeof(voyageur), (*n), fichier);

    fclose(fichier);
    return tab;
}
void sauvegarder_donnees(char nomFich[], voyageur *tab, int n) {
    FILE *fichier = fopen(nomFich, "wb");
    if (fichier == NULL) {
        printf("Erreur ");

    }

    fwrite(tab, sizeof(voyageur), n, fichier);

    fclose(fichier);
}
int trouver(voyageur *tab, char id[], int n) {
    int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(tab[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
     }

voyageur *ajouter(voyageur v, voyageur *tab, int *n) {
    int existant = trouver(tab, v.id, *n);
    if (existant != -1) {
        tab[existant].nbv += v.nbv;
        return tab;
    } else {
        tab=realloc(tab,(*n + 1)  * sizeof(voyageur));
        tab[*n]=v;
        (*n)++;


        return tab;
    }
}
void supprimer(voyageur *tab, char id[], int *n) {
    int i;
    int indice = trouver(tab, id, *n);
    if (indice != -1) {
        for ( i = indice; i < *n - 1; i++) {
            tab[i] = tab[i + 1];
        }
        *n -= 1;
        tab = realloc(tab, (*n) * sizeof(voyageur));
        if (tab == NULL && *n > 0) {
            printf("Erreur ");

        }
    } else {
        printf("Le voyageur avec l'identifiant %s n'existe pas.\n", id);
    }
}


void liberer(voyageur *tab) {
    free(tab);
}
