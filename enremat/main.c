#include <stdio.h>
#include <stdlib.h>
#include<string.h>



typedef struct{
    char nom[20];
    float no1;
    float no2;
}eleve;



int saisir();
void remplir(eleve t[],int n);
void afficher(eleve t[],int n);
void moyenne(eleve t[],int n);

int ajout(eleve t[],int n);
int ch(eleve t[],int n,char noo[]);
int eff(eleve t[],int n);

int main()
{
    eleve e[20],el;
    int n,choix,y,b;
    char noo[22];

   do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- saisir ************************\n");
            printf("*************** 2- remplir******************\n");
            printf("*************** 3- afficher**************************\n");
            printf("*************** 4- moyenne*************************\n");
            printf("*************** 5- ajout******************\n");
            printf("*************** 6-  recherche **********************************\n");
            printf("*************** 7-  effacer *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if (choix==1){
            n=saisir();

            }
            if(choix==2){
    remplir(e,n);
    }
    if(choix==3){
    afficher(e,n);
    }
    if(choix==4){
    moyenne(e,n);
    }
    if (choix==5){
        n=ajout(e,n);
    }
     if (choix==6){

    printf("donner le nom");
    fflush(stdin);
    gets(noo);
        y=ch(e,n,noo);
        if (y==-1){
            printf("introuvable\n");
        }
        else{
            printf("se trouve\n");
        }
    }
   if (choix==7){

     n=eff(e,n);
    }

    } while(choix!=0);
    return 0;
}



int saisir(){
    int x;
    printf("donner le nombre d'eleve \n");
    scanf("%d",&x);
    return x;
}
void remplir(eleve t[],int n){
    int i;
    for (i=0;i<n;i++){
        printf("nom = ");
        fflush(stdin);
        gets(t[i].nom);
        printf("note 1 = ");
        scanf("%f",&t[i].no1);
        printf("note 2 = ");
        scanf("%f",&t[i].no2);
    }
}
void afficher(eleve t[],int n){
        int i;
    for (i=0;i<n;i++){
        printf("nom =  %s  note1= %.2f note2= %.3f  \n ",t[i].nom,t[i].no1,t[i].no2);

    }
}
void moyenne(eleve t[],int n){
    float m;
    int i;
    for (i=0;i<n;i++){
        m=(t[i].no1+t[i].no2)/2;
        printf("moyenne %s est : %.2f \n",t[i].nom,m);
    }

}





int ajout(eleve t[],int n){
    int po,i,j;
    printf("donner la position");
    scanf("%d",&po);
    for (i=0;i<n;i++){
        if (po==i){
            for(j=n;j>po;j--){
                t[j]=t[j-1];
            }
        printf("nom = ");
        fflush(stdin);
        gets(t[po].nom);
        printf("note 1 = ");
        scanf("%f",&t[po].no1);
        printf("note 2 = ");
        scanf("%f",&t[po].no2);
        n++;

        }

    }
    return n;


}
int ch(eleve t[],int n,char noo[]){
    int i,cp;

    cp=-1;
    for(i=0;i<n && cp==-1;i++){
        if(strcmp(t[i].nom,noo)==0){
                cp=i;

        }
    }
    return cp;
}
int eff(eleve t[],int n){
    int i,o,j;
    char z[22];
    printf("donner le nom");
    fflush(stdin);
    gets(z);
    o=ch(t,n,z);
    if (o==-1){
        return n;

    }
    else{

            for (j=o;j<n;j++){
                t[j]=t[j+1];
            }

        n--;
        return n;
    }
}
