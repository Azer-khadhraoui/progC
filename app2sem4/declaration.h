#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct{
    int num;
    char type[20];
    int etat;
}wagon;
struct cellule{
    wagon w;
    struct cellule *suivant;
};
typedef struct cellule *liste;
void saisirwg(wagon *wg);
liste ajouttete(liste tete,wagon wg);
liste ajoutfin(liste tete,wagon wg);
void afficher(liste tete);
int recherche(liste tete,int n);
liste supprimer(liste tete);
liste supprimertous(liste tete);
liste ajouterwagon(liste tete,wagon val,int num);
void liberer(liste tete);
void enregistrer(liste tete,char nomfich[]);


#endif // DECLARATION_H_INCLUDED
