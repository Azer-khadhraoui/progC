#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"declaration.h"

void saisirwg(wagon *wg){
    printf("num = ");
    scanf("%d",&wg->num);
    do{
    printf(" type = ");
    fflush(stdin);
    gets(wg->type);
    }while((strcmp(wg->type,"lokomotive")!=0) && (strcmp(wg->type,"wagon")!=0));
    do{
    printf("etat = ");
    scanf("%d",&wg->etat);
    }while ((wg->etat!=0) && (wg->etat!=1));
}
liste ajouttete(liste tete,wagon wg){

    liste nouv;


        nouv=malloc(sizeof(struct cellule));
        nouv->w=wg;
        nouv->suivant=tete;
        tete=nouv;


    return tete;

}
liste ajoutfin(liste tete,wagon wg){
    liste parc;
    liste nouv;
    nouv=malloc(sizeof(struct cellule));
    nouv->w=wg;
    nouv->suivant=NULL;
    if(tete==NULL){
        tete=nouv;
    }
    else{
        parc=tete;
        while(parc->suivant!=NULL){
            parc=parc->suivant;
        }
        parc->suivant=nouv;

    }
    return tete;
}
void afficher(liste tete){
    liste parc=tete;
    while(parc!=NULL){
        printf("num = %d \n type = %s \n etat=%d \n\n ",parc->w.num,parc->w.type,parc->w.etat);
        parc=parc->suivant;
    }
}
int recherche(liste tete,int n){
        liste parc=tete;

    while((parc!=NULL)){
        if(n==parc->w.num){
            return 1;
        }
        parc=parc->suivant;
    }
    return 0;
}
liste supprimer(liste tete){
    liste parc=tete;
    liste pred=NULL;
    while((parc!=NULL) && (parc->w.etat!=0)){
        pred=parc;
        parc=parc->suivant;
    }
    if(parc==NULL){
        printf("tous les wagons sont en bonne etat maintenant !! \n");
    }
    else{
        pred->suivant=parc->suivant;
        free(parc);
    }
    return tete;
}
liste supprimertous(liste tete){
    liste parc=tete;
    while(parc!=NULL){
        tete=supprimer(tete);
        parc=parc->suivant;
    }
    return tete;
}
liste ajouterwagon(liste tete,wagon val,int num){
    liste parc=tete;
    liste pred=NULL;
    liste nouv=NULL;



        while((parc!=NULL) && (parc->w.num!=num)){
            pred=parc;
            parc=parc->suivant;
        }
        if(parc==NULL){
            printf("numero invalide \n");
        }
        else{
           nouv=malloc(sizeof(struct cellule));
           nouv->w=val;
           nouv->suivant=parc->suivant;


            parc->suivant=nouv;

        }
        return tete;

}
void liberer(liste tete){
    free(tete);
}
void enregistrer(liste tete,char nomfich[]){
    wagon w;
    liste parc=tete;
    FILE *f=fopen(nomfich,"w");
    if(f==NULL){
        printf("erreuuuuuuuuur");
    }
    else{
            while(parc!=NULL){
                fprintf(f,"%d %s %d \n",parc->w.num,parc->w.type,parc->w.etat);
                parc=parc->suivant;
            }


    }
    fclose(f);
}
