#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"



int main()
{
    int choix;
    liste l=NULL;
    commande com;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajout ************************\n");
            printf("*************** 2- affiche*****************\n");
            printf("*************** 3- sauvegarde**************************\n");
            printf("*************** 4- *************************\n");
            printf("*************** 5-******************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
    if(choix==1){
        saisircommande(&com);
        l=ajoutcommande(l,com);
    }
      if(choix==2){
afficher_listecommande(l);
    }
      if(choix==3){
    sauvegardercommandes(l,"commande.txt");
    }


    }
    while(choix!=0);
    return 0;
}

