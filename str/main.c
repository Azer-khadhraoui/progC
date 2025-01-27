#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id[20];
    char vil[20];
    char prod[20];
    int nbray;
    int t[20];
    char respo[20];




}depot;






int main()
{
    depot dep[20],d;
    int choix,i,nbpr,nbdepot=0,j,sommeproduit;
    char iddep[20],type[20],vi[20];
    int trv,trv2,s[20],x,max,so;


    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- Ajouter un nouv depot ************************\n");
            printf("*************** 2- Afficher les depot******************\n");
            printf("*************** 3- ajouter produit dans 1 er rayon vide**************************\n");
            printf("*************** 4- afficher depot d un type saisi*************************\n");
            printf("*************** 5- afficher depot MAx produit******************\n");
            printf("*************** 6-  Modifier responsable**********************************\n");
            printf("*************** 7-  Calculer le nb depot d une ville*****************************\n");
            printf("*************** 8- Afficher depot inf a seuil **********************************\n");
            printf("*************** 9- Supprimer tous les depots vide *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);





        if (choix==1){
            printf("donner l'id \n");
            fflush(stdin);
            gets(d.id);
            printf("donner la ville\n");
            fflush(stdin);
            gets(d.vil);
            printf("donner le produit \n");
            fflush(stdin);
            gets(d.prod);
            printf("donner le nombre de rayon \n");
            scanf("%d",&d.nbray);
            for (i=0;i<d.nbray;i++){
                d.t[i]=0;


            }
            printf("donner le responsable\n");
            fflush(stdin);
            gets(d.respo);
            dep[nbdepot]=d;
            nbdepot++;



        }




        if (choix==2){
            for (i=0;i<nbdepot;i++){
            printf("id : %s \t ville : %s \t produit : %s \t responsable : %s \n",dep[i].id,dep[i].vil,dep[i].prod,dep[i].respo);
            for (j=0;j<dep[i].nbray;j++){
                printf("%d|",dep[i].t[j]);
            }printf("\n");



            }
        }




        if (choix==3){
            trv=-1;
            printf("donner l id de depot ");
            scanf("%s",&iddep);
            for (i=0;i<nbdepot && trv==-1;i++){
                if(strcmp(dep[i].id,iddep)==0){
                    trv=i;
                }

            }
            printf("donner le nombre de produit ");
            scanf("%d",&nbpr);

            trv2=-1;
            for (i=0;i<dep[trv].nbray && trv2==-1;i++){
                if (dep[trv].t[i]==0){
                    trv2=i;
                }
            }
            dep[trv].t[trv2]=nbpr;

        }


        if (choix==4){
            printf("donner le type de depot");
            fflush(stdin);
            gets(type);
            for(i=0;i<nbdepot;i++){
                if (strcmp(type,dep[i].prod)==0){
                    printf("%s \t",dep[i].respo);
                }
            }printf("\n");
        }


        if (choix==5){

            for(i=0;i<nbdepot;i++){
                sommeproduit=0;

                for (j=0;j<dep[i].nbray;j++){
                    sommeproduit+=dep[i].t[j];
                }
                s[i]=sommeproduit;
            }
            max=s[0];
            x=0;
            for (i=0;i<nbdepot;i++){
                if (max<s[i]){
                    max=s[i];
                    x=i;
                }
            }
            printf("le responsable qui a le plus grand nombre de produit est %s : %d",dep[x].respo,s[x]);


        }





        if (choix==7){
                printf("la ville : ");
        fflush(stdin);
        gets(vi);
        so=0;

        for (i=0;i<nbdepot ;i++){
            if (strcmp(dep[i].vil,vi)==0){
                for (j=0;j<dep[i].nbray;j++){
                    so+=dep[i].t[j];
                }


            }
        }
        printf("la ville %s a %d produit",vi,so);

        }
        if (choix==9)
        {

        }


    }
    while(choix!=0);

    return 0;
}
