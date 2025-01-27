#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int an;
    int mois;
    int j;


}date;


typedef struct{
    char titre[20];
    date d;
    int nbau;
    char auteur[20][20];


}livre;






int main()
{
    livre t[20];
    int n,choix,i,b,j,ind,a;
    char aut[20];
    printf("donner le nombre de livre = \n");
    scanf("%d",&n);
        do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- Remplir un tableau . ************************\n");
            printf("*************** 2-  Afficher le tableau des clients.******************\n");
            printf("*************** 3-  Trier les voyages des clients selon l’ordre décroissant de la date **************************\n");
            printf("*************** 4-  Afficher le voyageur le plus fidele*************************\n");
            printf("*************** 5- Afficher la destination la plus demandée pour un voyageur sachant son identifiant******************\n");
            printf("*************** 6-   Afficher le mois de l’année avec le plus grand nombre de réservations*******************************\n");


            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>6);



    if (choix==1){
        for(i=0;i<n;i++){
            printf("donner le titre %d",i);
            fflush(stdin);
            gets(t[i].titre);
             printf("donner l annee ");
            scanf("%d",&t[i].d.an);
             printf("donner le mois");
            scanf("%d",&t[i].d.mois);
             printf("donner le jour");
            scanf("%d",&t[i].d.j);
            printf("donner le nombre d auteur");
            scanf("%d",&t[i].nbau);
            for(j=0;j<t[i].nbau;j++){
                printf("auteur %d = \n",j);
                fflush(stdin);
                scanf("%s",t[i].auteur[j]);
        }
    }


    }
    if(choix==2){
        for (i=0;i<n;i++){
            printf("titre : %s     date :%d/%d/%d    nombre d auteur : %d  ",t[i].titre,t[i].d.an,t[i].d.mois,t[i].d.j,t[i].nbau);
            for(j=0;j<t[i].nbau;j++){
                printf("%s|",t[i].auteur[j]);
            }printf("\n");
        }
    }

    if(choix==3){
        printf("donner le nom d'auteur");
        fflush(stdin);
        gets(aut);
        printf("les livres de %s est : \n",aut);
          for (i=0;i<n;i++){


            for(j=0;j<t[i].nbau ;j++){
                if(strcmp(t[i].auteur[j],aut)==0){
                    printf("%s - ",t[i].titre);
                }
            }
        }

    }

    if(choix==4){
        printf("donner l annee");
        scanf("%d",&a);
        printf("les livres apres %d sont",a);
        for(i=0;i<n;i++){
            if(t[i].d.an>a){
                printf("%s - ",t[i].titre);
            }
        }
    }








    }
    while(choix!=0);
    return 0;
}
