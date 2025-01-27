#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int jour;
    int mois;
    int an;

}date;

typedef struct{
    char dest[20];
    date d;



}voyage;
typedef struct {
    char id[20];
    char nom[20];
    char pre[20];
    int nbvoy;
    voyage voy[20];




}client;









int main()
{
    client cli[20];
    int choix,n,i,j,max,c,nbres,nbremax,x,y;




    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- Remplir un tableau de n clients. ************************\n");
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
                printf("donner le nombre de client");
                scanf("%d",&n);
                for (i=0;i<n;i++){
                    printf("donner l id du client \n");
                    fflush(stdin);
                    gets(cli[i].id);
                    printf("donner le nom du client \n");
                    fflush(stdin);
                    gets(cli[i].nom);
                     printf("donner le prenom du client \n");
                    fflush(stdin);
                    gets(cli[i].pre);
                     printf("donner le nombre de voyage du client  \n");
                    scanf("%d",&cli[i].nbvoy);


                    for(j=0;j<cli[i].nbvoy;j++){
                    printf("donner la destination \n");
                    fflush(stdin);
                    gets(cli[i].voy[j].dest);

                    printf("donner le jour pour le client %d \n",i+1);
                    scanf("%d",&cli[i].voy[j].d.jour);
                    printf("donner le mois pour le client %d \n",i+1);
                    scanf("%d",&cli[i].voy[j].d.mois);
                    printf("donner l'annee pour le client %d \n",i+1);
                    scanf("%d",&cli[i].voy[j].d.an);

                    }








                }

        }

        if (choix==2){
                for(i=0;i<n;i++){
                    printf("id : %s \t nom : %s \t prenom : %s \t nombre de voyage: %d \t ",cli[i].id,cli[i].nom,cli[i].pre,cli[i].nbvoy);
                    for(j=0;j<cli[i].nbvoy;j++){
                        printf("destination: %s \t jour : %d mois :%d annee : %d",cli[i].voy[j].dest,cli[i].voy[j].d.jour,cli[i].voy[j].d.mois,cli[i].voy[j].d.an);
                    }printf("\n");
                }






        }


        if (choix==3){
            for(i=0;i<n;i++){
                maxx=cli[i].voy[j].d.an;
                for(j=i+1;j<n;j++){
                    if(t[j]<t[maxx]){
                        maxx=j;
                    }
                }
                aux=t[i];
                t[i]=t[maxx];
                t[maxx]=aux;
            }





        }

        if (choix==4){
                max=cli[0].nbvoy;
                c=0;
                for(i=0;i<n;i++){
                    if (cli[i].nbvoy>max){
                        max=cli[i].nbvoy;
                        c=i;
                    }


                }
                printf("le client le plus fidele est : %s il a %d voyage",cli[c].nom,max);

        }

        if (choix==6){
            nbres=0;
            nbremax=0;
            for(i=0;i<n;i++){
                    for(j=i+1;j<cli[i].nbvoy;j++){
                        if (cli[i].voy[j].d.an==cli[i].voy[j+1].d.an){
                            nbres++;
                            x=i;
                            y=j;

                        }
                    }
                     if (nbremax<nbres){
                                    nbremax=nbres;


                            }nbres=0;

            }
            printf("l annee qui a plus de resrvation est %s   il ya %d reservation",cli[x].voy[y].d.an,nbremax);
        }



    }
    while(choix!=0);
    return 0;
}
