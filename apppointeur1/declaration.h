#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED
#define NON_TROUVE -1

typedef struct{
    char refer[20];
    int etat;

}panne;
typedef struct{
    int refer;
    panne liste[10];

}machine;






void saisir (machine *m);
void ajouter (machine Tm [], machine m,int *n) ;
int rechercherMach(machine Tm[], int n, int ref);
void saisirPanne(panne *p);

void ajouterPanne(int ref, machine Tm[], int n);
int totalPanne(int ref, machine Tm[], int n);



#endif // DECLARATION_H_INCLUDED
