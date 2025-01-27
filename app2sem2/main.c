#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"
#include<string.h>



int main()
{
    int choix,n;
     char pre[20];
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  saisir************************\n");
            printf("*************** 2- chercher******************\n");
            printf("*************** 3- nb enfants**************************\n");
            printf("*************** 4- supprimer *************************\n");
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
         enregistreremploye("nombre_enfants.bin");
    }
    if(choix==2){

     printf("donner le prenom cherche = \n");
        fflush(stdin);
        gets(pre);
        chercher( "nombre_enfants.bin",pre);
    }
    if(choix==3){
        printf("n=");
        scanf("%d",&n);

        affiche("nombre_enfants.bin",n);

    }
    if (choix==4){
        supp("nombre_enfants.bin","nombre_enfants2.bin");
    }
    }
    while(choix!=0);
    return 0;
}
