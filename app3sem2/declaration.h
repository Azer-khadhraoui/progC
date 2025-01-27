#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct{
    char id[20];
    char nom[20];
    char ad[20];
    int nbv;
}voyageur;
int nbVoyageurs(char nomFich[]);
void saisirVoyageur (voyageur * ptv);
voyageur * charger_donnees (char nomFich[], int * n);
void sauvegarder_donnees(char nomFich[], voyageur *tab, int n);
int trouver(voyageur *tab, char id[], int n);
voyageur *ajouter(voyageur v, voyageur *tab, int *n);
void supprimer(voyageur *tab, char id[], int *n);
void liberer(voyageur *tab);

#endif // DECLARATION_H_INCLUDED
