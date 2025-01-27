#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

typedef struct{
    int id;
    char nom[20];
    char pre[20];
    float remb;
}adherent;

typedef struct{
    int type;
    int id2;
    int refe;
    float prix;

}constat;

adherent saisirad();
int ajouterad(adherent a[], adherent ad,int nb);
void afficherad(adherent a[],int nb);
constat saisirc();
void initialiser(constat c[][5]);
int ajouterc(constat c[][5],constat con,int nbm1,int nbm2,int nbm3);
void afficherc(constat c[3][5]);



#endif // DECLARATION_H_INCLUDED
