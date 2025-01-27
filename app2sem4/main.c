#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"declaration.h"


int main()
{
    int choix,x,n,z,y,n2;
    liste tete=NULL;
    wagon wg;
    wagon val;
    wagon ww;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajout tete************************\n");
            printf("*************** 2-  ajout fin******************\n");
            printf("*************** 3- affichage**************************\n");
            printf("*************** 4- rechercher*************************\n");
            printf("*************** 5-supprimer *****************\n");
            printf("*************** 6-   supprimer tous**********************************\n");
            printf("*************** 7-  ajout *****************************\n");
            printf("*************** 8- enregistrer**********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if(choix==1){
            saisirwg(&wg);
            y=recherche(tete,wg.num);
            if(y==1){
                printf("deja insere\n");
            }
             else if(strcmp(wg.type,"wagon")==0){
                    printf("il faut ajouter lokomotive au debut !!!!!! ");

            }
            else{
                tete=ajouttete(tete,wg);
            }

        }
        else if(choix==2){
            saisirwg(&ww);
            z=recherche(tete,ww.num);
            if(z==1){
                printf("deja insere\n");
            }
            else if(strcmp(ww.type,"lokomotive")==0){
                    printf("il faut ajouter un wagon a la fin !!!!!! ");

            }
            else  {
               tete= ajoutfin(tete,ww);
            }
             }


        else if(choix==3){
            afficher(tete);
        }
        else if(choix==4){
            printf("numero =");
            scanf("%d",&n);
            x=recherche(tete,n);
            if(x==1){
                printf("disponible");
            }
            else{
                printf("pas dispoo");
            }
        }
        if(choix==5){
            tete=supprimer(tete);
        }
        if(choix==6){
            tete=supprimertous(tete);
        }
        if(choix==7){
            printf("numero =");
            scanf("%d",&n2);
            saisirwg(&val);
            if(strcmp(val.type,"wagon")==0){
                tete=ajouterwagon(tete,val,n2);
            }
            else {
                printf("il faut ajouter un wagon \n");
            }

        }
        if(choix==8){
            enregistrer(tete,"fichier.txt");
        }
    }
    while(choix!=0);
    liberer(tete);
    return 0;
}

