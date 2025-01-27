#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char des[20];
    int qt;
    float prix;
}ingrediant;




typedef struct{
    int type;
    int nbi;
    ingrediant ing[20];
}gateau;

void saisir (gateau * g) ;
void ajouterGateau ( gateau tabG [], gateau g, int * tg) ;
void afficher(gateau tabG [], int tg);
void trouver(gateau tabG[],int tg, int type, int *pos);
float calculerPrix(gateau g ) ;
void initialiser(int matV [][7], float tabP[]) ;
void vendre(int matV[][7], gateau tabG[], int type, int jour, int *tg, float tabP[]);
 void afficherRecette(int matV[][7], int jour, float tabP[]);

int main()
{

    gateau g;
    gateau tabg[20];
    int choix,tg=0,pos,type,type1,jour,matV[3][7],jour1;
    float pr;
    float tabP[7];
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter un gateau ************************\n");
            printf("*************** 2- afficher tableau  ******************\n");
            printf("*************** 3- recherche **************************\n");
            printf("*************** 4- *************************\n");
            printf("*************** 5-vendre  *****************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if(choix==1){
            saisir (&g);
            ajouterGateau (tabg,g,&tg);
        }
        if (choix==2){
            afficher(tabg,tg);
        }
        if(choix==3){
            printf("donner le type cherche");
            scanf("%d",&type);
            trouver(tabg,tg,type,&pos);
            if(pos==-1){
                printf("element introuvable !\n");
            }
            else{
                printf("se trouve dans %d \n",pos);
            }
        }
        if(choix==4){
           pr=calculerPrix(tabg[0] );
           printf("%f",pr);

        }
        if(choix==5){
            int i,j;
            printf("donner le type vendu");
            scanf("%d",&type1);
             printf("donner le jour ");
            scanf("%d",&jour);
            vendre(matV,tabg,type1,jour,&tg,tabP);

            for (i=0;i<7;i++){
                printf("%.2f|",tabP[i]);
    }printf("\n");
     for (i=0;i<3;i++){
         for (j=0;j<7;j++){
                printf("%d|",matV[i][j]);

    }printf("\n");
    }
        }

        if(choix==6){
             printf("donner le jour ");
            scanf("%d",&jour1);
            afficherRecette(matV,jour1,tabP);
        }


    }
    while(choix!=0);
    return 0;
}
void saisir (gateau * g){
    int i;
    do{
    printf("type = \n");
    scanf("%d",&g->type);
    }while((g->type>3) || (g->type<0));
    printf("nb ingrediant = \n");
    scanf("%d",&g->nbi);
    for (i=0;i<g->nbi;i++){
        printf("designation %d = \n",i);
        fflush(stdin);
        gets(g->ing[i].des);
        printf("quantite %d = \n",i);
        scanf("%d",&g->ing[i].qt);
        printf("prix %d = \n",i);
        scanf("%f",&g->ing[i].prix);

    }

}
 void ajouterGateau ( gateau tabG[], gateau g, int * tg){
     tabG[(*tg)]=g;
     (*tg)++;
 }
 void afficher(gateau tabG [], int tg){
     int i,j;
     for (i=0;i<tg;i++){
        printf("type : %d nbre ingrediants : %d : \n",tabG[i].type,tabG[i].nbi);
        for (j=0;j<tabG[i].nbi;j++){
            printf("designation : %s  quantite: %d  prix: %.2f |",tabG[i].ing[j].des,tabG[i].ing[j].qt,tabG[i].ing[j].prix);
        }printf("\n");
     }
 }
 void trouver(gateau tabG[],int tg, int type, int *pos){
     int i;
     (*pos)=-1;
     for (i=0;i<tg && (*pos)==-1;i++){
           if(type==tabG[i].type){
             (*pos)=i;
           }

     }
 }
float calculerPrix(gateau g ) {
    int i;
    float p=0,cout=0;

    for(i=0;i<g.nbi;i++){
        cout=cout+(g.ing[i].prix * g.ing[i].qt);
    }
    if (g.type==0){
        p= cout + 0.1*cout;
    }
    else if(g.type==1){
        p=cout + 0.15*cout;
    }
    else{
        p=cout+0.2*cout;
    }
    return p ;


}
void initialiser(int matV [][7], float tabP[]) {
    int i,j;
    for (i=0;i<7;i++){
        tabP[i]=0;
    }
     for (i=0;i<3;i++){
         for (j=0;j<7;j++){
                matV [i][j]=0;

    }
    }
}
void vendre(int matV[][7], gateau tabG[], int type, int jour, int *tg, float tabP[]){
    int i,pos;
    float prix=0;
    trouver(tabG,(*tg),type,&pos);
    if (pos==-1){
        printf("introuvable");

    }
    else{
        prix=calculerPrix(tabG[pos]);
        tabP[jour]+=prix;
        matV[type][jour]++;
        for (i=pos;i<(*tg);i++){
            tabG[i]=tabG[i+1];
        }
        (*tg)--;


    }
}
 void afficherRecette(int matV[][7], int jour, float tabP[]){
     int i,j;
     printf("chiffres dans ce jour = %.2f",tabP[jour]);
     printf("nombre de gateau vendu type 0 = %d ",matV[0][jour]);
      printf("nombre de gateau vendu type 1 = %d ",matV[1][jour]);
       printf("nombre de gateau vendu type 2 = %d ",matV[2][jour]);



 }
