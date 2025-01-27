#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char id[20];
    char nom[20];
    char ad[20];
    int nbv;
}voyageur;

int nbVoyageurs(char nomFich[]);
void saisirVoyageur (voyageur * ptv);
voyageur * charger_donnees (char nomFich[], int * n);
void sauvegarder_donnees (char nomFich[], voyageur * tab, int n);
int trouver(voyageur * tab, char id[], int n);
voyageur * ajouter (voyageur v, voyageur * tab, int * n);
void supprimer (voyageur * tab , char id[], int * n);
 void liberer (voyageur * tab);
 void afficher(voyageur *tab,int n);
 void moyenneVoyages(voyageur *tab, int n);


int main()
{
    int choix;
    int n;
    voyageur v;
    voyageur *tab;
    char id[20];
    tab=charger_donnees ("fichier.bin",&n);
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter************************\n");
            printf("*************** 2- afficher ******************\n");
            printf("*************** 3- sauvegarder*************************\n");
            printf("*************** 4- supprimerr*************************\n");
            printf("*************** 5-moyenne ****************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if(choix==1){
                saisirVoyageur (&v);
                tab=ajouter(v,tab,&n);

        }
        if(choix==2){
            afficher(tab,n);
        }
        if(choix==3){
            sauvegarder_donnees ("fichier.bin",tab,n);
        }
        if(choix==4){
            printf("id= ");
            fflush(stdin);
            gets(id);
            supprimer(tab,id,&n);
        }
        if(choix==5){
            moyenneVoyages(tab,n);
        }


    }
    while(choix!=0);
    liberer(tab);
    return 0;
}

int nbVoyageurs(char nomFich[]){
    voyageur v;
    int nb=0;
    FILE *f=fopen(nomFich,"rb");
    if(f==NULL){
        printf("erreur");
    }
    else{
        while (fread(&v,sizeof(voyageur),1,f)){
                nb++;

        }
    }
    fclose(f);
    return nb;
}
void saisirVoyageur (voyageur * ptv){
    printf("id= ");
    fflush(stdin);
    gets(ptv->id);
    printf("nom= ");
    fflush(stdin);
    gets(ptv->nom);
    printf("adresse= ");
    fflush(stdin);
    gets(ptv->ad);
    printf("nb voyage = ");
    scanf("%d",&ptv->nbv);
}
voyageur * charger_donnees (char nomFich[], int * n){
     voyageur v;

    FILE *f=fopen(nomFich,"rb");
    if(f==NULL){
        printf("erreur");
    }
    else{
    (*n) = nbVoyageurs(nomFich);
    voyageur *tab = (voyageur *)malloc((*n) * sizeof(voyageur));


    fread(tab, sizeof(voyageur), (*n), f);

    fclose(f);
    return tab;
    }
}
void sauvegarder_donnees (char nomFich[], voyageur * tab, int n){
    voyageur v;

    FILE *f=fopen(nomFich,"wb");
    if(f==NULL){
        printf("erreur");
    }
    else{
        fwrite(tab, sizeof(voyageur), n, f);


    fclose(f);

    }
}
int trouver(voyageur * tab, char id[], int n){
    int i,b=-1;
    for(i=0;i<n && b==-1;i++){
            if(strcmp(tab[i].id,id)==0){
                b=i;
            }

    }
    return b;

}
voyageur * ajouter (voyageur v, voyageur * tab, int * n){
    int i,pos;
    pos=trouver(tab,v.id,(*n));
    if(pos!=-1){
        tab[pos].nbv+=v.nbv;
        printf(" %s existe deja",v.nom);
    }
    else{
        tab=realloc(tab,(*n+1)*sizeof(voyageur));
        tab[(*n)]=v;
        (*n)++;
    }
    return tab;
}
void supprimer(voyageur *tab, char id[], int *n) {
    int pos = trouver(tab, id, (*n));
    int i;
    if (pos == -1) {
        printf("%s introuvable\n", id);
    } else {
        for ( i = pos; i < (*n) - 1; i++) {
            tab[i] = tab[i + 1];
        }
        (*n)--;
        tab = realloc(tab, (*n) * sizeof(voyageur));
    }
}
 void liberer (voyageur * tab){
     free(tab);
 }
void afficher(voyageur *tab, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("ID: %s\n", tab[i].id);
        printf("Nom: %s\n", tab[i].nom);
        printf("Adresse: %s\n", tab[i].ad);
        printf("Nombre de voyages: %d\n", tab[i].nbv);
        printf("\n");
    }printf("\n");
}

void moyenneVoyages(voyageur *tab, int n){
    int i;
    float s=0,m=0;
    for (i=0;i<n;i++){
        s+=tab[i].nbv;
    }
    m=s/n;
    printf("moyenne = %.2f",m);
}
