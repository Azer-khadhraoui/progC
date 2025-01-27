#include <stdio.h>
#include <stdlib.h>
#include "declaration.h"


int main()
{
    adherent ad;
    adherent a[20];
    constat con;
    constat c[3][5];
    int choix, nb=0,r;
    int nbm1=0,nbm2=0,nbm3=0;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- ajouter 1 ad ************************\n");
            printf("*************** 2- ajouter au tableau******************\n");
            printf("*************** 3- afficher le tableau**************************\n");
            printf("*************** 4- saisir constant *************************\n");
            printf("*************** 5- initialiser******************\n");
            printf("*************** 6-  ajouter constat**********************************\n");
            printf("*************** 7-  afficher constat*****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

         if (choix==1){
            ad=saisirad();
         }
         if (choix==2){
            nb=ajouterad(a,ad,nb);
         }
         if(choix==3){
            afficherad(a,nb);
         }
         if(choix==4){
            con=saisirc();

         }
         if(choix==5){
            initialiser(c);
         }
         if(choix==6){
            r=ajouterc(c,con,nbm1,nbm2,nbm3);
            printf("%d",r);
         }
         if(choix==7){
            afficherc(c);
         }


    }
    while(choix!=0);
    return 0;
}
