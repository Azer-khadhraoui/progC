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
            printf("*************** 4- supp*************************\n");
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
         enregistreremploye("nombre_enfants.txt");
    }
    if(choix==2){

     printf("donner le prenom cherche = \n");
        fflush(stdin);
        gets(pre);
        chercher( "nombre_enfants.txt",pre);
    }
    if(choix==3){
        printf("n=");
        scanf("%d",&n);

        affiche("nombre_enfants.txt",n);

    }
    if (choix==4){
        supp("nombre_enfants.txt","nombre_enfants2.txt");
    }
    }
    while(choix!=0);
    return 0;
}
