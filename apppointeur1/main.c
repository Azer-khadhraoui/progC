#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include"declaration.h"


int main()
{
    machine m;
    machine Tm[20];
       int choix, n = 0, ref, n_rep, n_nrep;
       panne p;


    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ************************\n");
            printf("*************** 2-  ajouter machine******************\n");
            printf("*************** 3- chercher machine **************************\n");
            printf("*************** 4-  *************************\n");
            printf("*************** 5- ajouter panne ******************\n");
            printf("*************** 6-  nb total panne **********************************\n");
            printf("*************** 7-  modifier *****************************\n");
            printf("*************** 8-  afficher **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
         switch(choix)
        {
        case 0:
            printf("\n Au revoir:D");
            return -1;
        case 1:
            saisir(&m);
            break;
        case 2:
            saisir(&m);
            ajouter(Tm, m, &n);
            break;
        case 3:
            printf("Donner la reference a cherche");
            scanf("%d",&ref);
            if(rechercherMach(Tm, n, ref) == NON_TROUVE){
                printf("\nLa machine est introuvable");
            }else{
                printf("\nLa machine est trouve a l'indice %d",rechercherMach(Tm, n, ref));
            }
            break;
        case 4:
            saisirPanne(&p);
            break;
        case 5:
            printf("\nDonner la reference de la machine: ");
            scanf("%d",&ref);
            ajouterPanne(ref, Tm, n);
            break;
        case 6:
            printf("\nDonner la reference de la machine: ");
            scanf("%d",&ref);
            if(totalPanne(ref,Tm,n)==NON_TROUVE){
                printf("non trouve");
            }
            else{
                printf("le nombre de panne = %d \n",totalPanne(ref, Tm, n));
            }


            break;


        }

    }

    while(choix!=0);
    return 0;
}



