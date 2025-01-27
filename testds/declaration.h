#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct{
    int num;
    char nom[20];
    float montant;
}commande;


struct cellule{
    commande c;
    struct cellule *suivant;
};
typedef struct cellule *liste;

void saisircommande(commande *Commande);
liste ajoutcommande(liste l,commande com);
void afficher_listecommande(liste l);
void sauvegardercommandes(liste l,char nomfiche[]);

#endif // DECLARATION_H_INCLUDED
