#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct{
    char nom[20];
    char pre[20];
    int nbre;
}employe;

void enregistreremploye(char *f);
void chercher(char nomfichier[] , char pre[]);
void affiche(char nomfichier[],int n);
void supp(char nf1[],char nf2[]);

#endif // DECLARATION_H_INCLUDED
