#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char des[20];
    char type[20];
    int qt;

}aide;
typedef struct{
    int cin;
    int nbmembre;
    char deleg[20];

}famille;
int verifier_exit( aide TA[], int nA, char designation[]) ;
void saisir_aide(aide *A) ;
void ajouter_aide(aide TA[], int *nA, aide A);
void afficher_aide(aide TA[], int n);
void remplir_famille(famille TF[], int nF);
void afficher_famille(famille TF[], int nF);
void max_min_aide(aide TA[], int nA, int *min, int *max);
int max_membre(famille TF[], int nF);
void supprimer (famille TF[], int *nF, int pos) ;
void controler_stock( aide TA[], int nA, aide TStock[], int *nS);

int main()
{
    famille tf[20];
    aide a[20],st[20];
    aide ai;
    int choix,n=0,nf,max,min,indm,posi,ns=0;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- ajouter_aide ************************\n");
            printf("*************** 2- afficher_aide ******************\n");
            printf("*************** 3- remplir_famille**************************\n");
            printf("*************** 4- afficher_famille*************************\n");
            printf("*************** 5-max,min : aide******************\n");
            printf("*************** 6-  max nb membre**********************************\n");
            printf("*************** 7-  supprimer famille *****************************\n");
            printf("*************** 8- controle aide**********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if (choix==1){
            saisir_aide(&ai) ;
            ajouter_aide(a,&n,ai);

        }
        if (choix==2){
                afficher_aide(a,n);

        }
          if (choix==3){
               printf("donner le nombres des familles ");
               scanf("%d",&nf);
               remplir_famille(tf,nf);

        }
        if (choix==4){
            afficher_famille(tf,nf);
        }
        if (choix==5){
           max_min_aide(a,n,&min,&max);
           printf("max dans la position = %d \t min dans la position = %d \n",max,min);
        }
        if(choix==6){
            indm=max_membre(tf,nf);
            printf("la famille qui a le plus grand nombre de membre est : %d \n",indm);
        }
        if(choix==7){
                printf("donner la position");
        scanf("%d",&posi);
            supprimer (tf,&nf,posi);
        }
        if(choix==8){
            controler_stock(a,n,st,&ns);
            afficher_aide(st,ns);
        }


    }
    while(choix!=0);
    return 0;
}
int verifier_exit( aide TA[], int nA, char designation[]) {
    int i,pos;
    pos=-1;
    for(i=0;i<nA && pos==-1;i++){
            if (strcmp(TA[i].des,designation)==0){
                return i;
            }

    }
    return -1;
}
void saisir_aide(aide *A) {
    printf("donner la designation\n");
    fflush(stdin);
    gets(A->des);
    printf("donner le type\n");
    fflush(stdin);
    gets(A->type);
    printf("donner la quantite\n");
    scanf("%d",&A->qt);
}
void ajouter_aide(aide TA[], int *nA, aide A) {
    int verif;
    verif=verifier_exit(TA,*nA,A.des);
    if(verif==-1){
        TA[*nA]=A;
        (*nA)++;
    }
    else {
        TA[verif].qt=TA[verif].qt+A.qt;

    }
}
void afficher_aide(aide TA[], int n) {
    int i;
    for(i=0;i<n;i++){
        printf("designation : %s type : %s  quantite :%d |\n",TA[i].des,TA[i].type,TA[i].qt);
    }
}
void remplir_famille(famille TF[], int nF) {
    int i;
    for (i=0;i<nF;i++){
    printf("donner CIN\n");
    scanf("%d",&TF[i].cin);
    printf("donner le nombre des membres : \n");
    scanf("%d",&TF[i].nbmembre);
    printf("donner la delegation \n");
    fflush(stdin);
    gets(TF[i].deleg);

    }
}
void afficher_famille(famille TF[], int nF) {
    int i;
    for(i=0;i<nF;i++){
        printf("cin:%d nb membre=%d  delegation: %s ||",TF[i].cin,TF[i].nbmembre,TF[i].deleg);
    }printf("\n");
}
void max_min_aide(aide TA[], int nA, int *min, int *max){
    int i;
    (*max)=0;
    (*min)=0;
    for (i=0;i<nA;i++){
        if (TA[i].qt>TA[(*max)].qt){
              (*max)=i;

        }

    }
       for (i=0;i<nA;i++){
        if (TA[i].qt<TA[(*min)].qt){
              (*min)=i;

        }

    }
}
int max_membre(famille TF[], int nF){
    int i,indmax=0;
    for(i=0;i<nF;i++){
        if(TF[i].nbmembre>TF[indmax].nbmembre){
            indmax=i;
        }
    }
    return indmax;
}
void supprimer (famille TF[], int *nF, int pos) {
    int i;
    for (i=pos;i<(*nF);i++){
            TF[i]=TF[i+1];

    }(*nF)--;
}
void controler_stock( aide TA[], int nA, aide TStock[], int *nS){
    int i ;
    for(i=0;i<nA;i++){
        if(TA[i].qt <5){
            TStock[(*nS)]=TA[i];
            (*nS)++;
        }
    }
}
