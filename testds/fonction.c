#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"

void saisircommande(commande *c){

    do{
        printf("numero =");
    scanf("%d",&c->num);
    }while(c->num<=0);

     printf("nom=");
    fflush(stdin);
    gets(c->nom);
   printf("montant=");
    scanf("%f",&c->montant);

}
liste ajoutcommande(liste l,commande com){
    liste parc=l;
    int b=-1;
    liste pred=NULL;
    liste nouv=NULL;

    nouv=malloc(sizeof(struct cellule));

    nouv->c=com;
    nouv->suivant=NULL;
    while ((parc!=NULL)&& (b==-1)){
        if(nouv->c.montant<parc->c.montant){
            if(parc==l){
                nouv->suivant=NULL;
                l=nouv;
                b=1;

            }
            else{
                nouv->suivant=parc;
                pred->suivant=nouv;

            }

        }
        pred=parc;
        parc=parc->suivant;
        if(parc==NULL){
            pred->suivant=nouv;
        }
    }
    return l;

}

void afficher_listecommande(liste l){
      liste parc=l;
    while (parc!=NULL){
        printf("num : %d nom : %s montant : %f \n",parc->c.num,parc->c.nom,parc->c.montant);
        parc=parc->suivant;
    }printf("\n");

}
void sauvegardercommandes(liste l,char nomfiche[]){
       commande c;
    liste parc=l;
    FILE *f=fopen(nomfiche,"w");
    if(f==NULL){
        printf("ereuur");
    }
    else{
            while(parc!=NULL){
                fprintf(f,"%d %s %f \n",parc->c.num,parc->c.nom,parc->c.montant);
                parc=parc->suivant;
            }


    }
    fclose(f);
}
