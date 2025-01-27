#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int j;
    int m;
    int a;
}date;
typedef struct{
    char ref[20];
    char nom[20];
    int exmp;
    date d;
}livre;

void saisirlivre(livre *l);
void remplit(livre tl[],livre l,int *n);
void afficher(livre tl[],int n);
int chercher(livre tl[],int n,char nom[]);
void afflivre(livre tl[],int n,char nom[]);
void calculdeff(date dajout,date dcourant,int *jour);
void miseajour(livre tl[],int *n);
void initial(int vente[][3]);
void aff(int vente[][3]);
void vendre(livre tl[],int vente [][3],int *n,char ref[],int jour,int semaine);
void affstat(int vente[][3],int se);

int main()
{
    int choix,n=0,ch,jour,semaine,jj,vente[4][3],seuil;
    livre l;
    livre tl[20];
    char nom[20],ref[20],rf[20];
    date dajout,dcourant;
    initial(vente);
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter un livre************************\n");
            printf("*************** 2- afficher *****************\n");
            printf("*************** 3- chercher livre**************************\n");
            printf("*************** 4- afficher par nom *************************\n");
            printf("*************** 5-difference jour ******************\n");
            printf("*************** 6- mise a jour **********************************\n");
            printf("*************** 7-  affiche matrice*****************************\n");
            printf("*************** 8- vendre**********************************\n");
            printf("*************** 9- stat*****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);


        if(choix==1){
            saisirlivre(&l);
            remplit(tl,l,&n);
        }
        if(choix==2){
            afficher(tl,n);
        }
        if(choix==3){
            printf("reference = ");
            fflush(stdin);
            gets(ref);
            ch=chercher(tl,n,ref);
            if(ch==-1){
                printf("introuvable !\n");
            }
            else{
                printf("se trouve dans %d\n",ch);
            }
        }
        if(choix==4){
            printf("nom = ");
            fflush(stdin);
            gets(nom);
            afflivre(tl,n,nom);
        }
        if (choix==5){
    printf("la date d'ajout: jour = ");
    scanf("%d",&dajout.j);
    printf("la date :mois = ");
    scanf("%d",&dajout.m);
    printf("la date : annee = ");
    scanf("%d",&dajout.a);
    printf("la date courante: jour = ");
    scanf("%d",&dcourant.j);
    printf("la date :mois = ");
    scanf("%d",&dcourant.m);
    printf("la date : annee = ");
    scanf("%d",&dcourant.a);

    calculdeff(dajout,dcourant,&jour);
    if(jour==-1){
        printf("impossible !");
    }
    else{
        printf("difference = %d jours ",jour);
    }
        }

        if(choix==6){
            miseajour(tl,&n);
        }
        if(choix==7){

            aff(vente);
        }
        if(choix==8){
             printf("reference = ");
            fflush(stdin);
            gets(rf);
            printf("jour");
            scanf("%d",&jj);
            printf("semaine");
            scanf("%d",&semaine);
            vendre(tl,vente,&n,rf,jj,semaine);
        }
        if(choix==9){
            printf("seuil");
            scanf("%d",&seuil);
            affstat(vente,seuil);
        }


    }
    while(choix!=0);
    return 0;
}


void saisirlivre(livre *l){
    printf("reference = ");
    fflush(stdin);
    gets(l->ref);
    printf("nom = ");
    fflush(stdin);
    gets(l->nom);
    printf("exemplaire = ");
    scanf("%d",&l->exmp);
    printf("la date : jour = ");
    scanf("%d",&l->d.j);
    printf("la date :mois = ");
    scanf("%d",&l->d.m);
    printf("la date : annee = ");
    scanf("%d",&l->d.a);

}
void remplit(livre tl[],livre l,int *n){
    tl[(*n)]=l;
    (*n)++;
}
void afficher(livre tl[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("reference = %s nom = %s exemplaire = %d date : %d/%d/%d \n",tl[i].ref,tl[i].nom,tl[i].exmp,tl[i].d.j,tl[i].d.m,tl[i].d.a);
    }printf("\n");
}
int chercher(livre tl[],int n,char ref[]){
    int i,b=-1,ind;
    for (i=0;i<n && b==-1;i++){
        if (strcmp(ref,tl[i].ref)==0){
            b=i;
        }
    }
    return b;

}
void afflivre(livre tl[],int n,char nom[]){
    int i;
    for(i=0;i<n;i++){
          if (strcmp(nom,tl[i].nom)==0){
                printf("reference = %s \t",tl[i].ref);
        }printf("\n");
    }
}
void calculdeff(date dajout,date dcourant,int *jour){
    int sommecourant,sommeajout;

    sommecourant=dcourant.a*365+dcourant.m*30+dcourant.j;
    sommeajout=dajout.a*365+dajout.m*30+dajout.j;
    if (sommecourant>sommeajout){
        (*jour)=sommecourant-sommeajout;

    }
    else{
        (*jour)=-1;
    }

}

void miseajour(livre tl[],int *n){
    int i,j,jo;
    date dc;
    printf("la date courante: jour = ");
    scanf("%d",&dc.j);
    printf("la date :mois = ");
    scanf("%d",&dc.m);
    printf("la date : annee = ");
    scanf("%d",&dc.a);
    for (i=0;i<(*n);i++){
        jo=0;
        calculdeff(tl[i].d,dc,&jo);
        if(jo>=365){
            for(j=i;j<(*n);j++){
                tl[j]=tl[j+1];
            }
            i--;
            (*n)--;

        }
    }


}
void initial(int vente[][3]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            vente[i][j]=0;
        }
    }
}
void vendre(livre tl[],int vente [][3],int *n,char ref[],int jour,int semaine){
    int i,pos;
    pos=chercher(tl,(*n),ref);
    if (pos==-1){
        printf("element introuvable \n");
    }
    else{
        tl[pos].exmp=tl[pos].exmp-1;
        vente[semaine][jour]++;
        if(tl[pos].exmp==0){
            for (i=pos;i<(*n);i++){
                    tl[i]=tl[i+1];

            }
            (*n)--;
        }
    }


}
void aff(int vente[][3]){
      int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%d|",vente[i][j]);
        }printf("\n");
    }printf("\n");
}
void affstat(int vente[][3],int se){
    int i,s,j;
    for (i=0;i<3;i++){
            s=0;
        for(j=0;j<4;j++){
            s=s+vente[j][i];

        }
        if(s>se){
            printf("jour %d depasse %d avec total de vente = %d ",i,se,s);
        }
    }
}
