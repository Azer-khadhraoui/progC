#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id;
    int prix;
    int lou;
}voiture;

void saisir(voiture v[],int nbv);
void affi(voiture v[],int nbv);
void affunveh(voiture v[],int nbv);
int cher(voiture v[],int nbv);
int nblou(voiture v[],int nbv);
int cherid(voiture v[],int nbv);
int main()
{
    voiture v[20];

    int nbv,choix,moi,pm,k;
    float moy;

    printf("nombre de voiture : \n");
    scanf("%d",&nbv);
     do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  saisir ************************\n");
            printf("*************** 2- affiche ******************\n");
            printf("*************** 3- affiche 1 **************************\n");
            printf("*************** 4- moins cher *************************\n");
            printf("*************** 5-******************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
        if (choix==1){

            saisir(v,nbv);
        }
        if(choix==2){
            affi(v,nbv);
        }
        if (choix==3){
            affunveh(v,nbv);
        }
        if(choix==4){
                moi=cher(v,nbv);
                printf("la voiture moins cher : \n");
                printf("id =%d \t prix=%d \t loue:%d \n ",v[moi].id,v[moi].prix,v[moi].lou);

        }
        if(choix==5){
                pm=nblou(v,nbv);
                printf("le nbre des voiture louee est %d",pm);

        }
        if(choix==6){
            moy=((float)nblou(v,nbv)/nbv);
            printf("%f",moy);
        }
        if(choix==7){
            k=cherid(v,nbv);
            if (k==1){
                printf("se trouve \n");
            }
            else{
                printf("introuvable !! ");
            }
        }

    }
    while(choix!=0);
    return 0;
}
void saisir(voiture v[],int nbv)
{
    int i;
    for(i=0;i<nbv;i++){
        printf("id = ");
        scanf("%d",&v[i].id);
        printf("prix = ");
        scanf("%d",&v[i].prix);
        printf("loue ou non = ");
        scanf("%d",&v[i].lou);
    }
}
void affi(voiture v[],int nbv){
    int i;
        for(i=0;i<nbv;i++){
        printf("id =%d \t prix=%d \t loue:%d \n ",v[i].id,v[i].prix,v[i].lou);

    }printf("\n");


}
void affunveh(voiture v[],int nbv){
    int i,n;
    printf("donner l indice ");
    scanf("%d",&n);
        for(i=0;i<nbv;i++){
        if(n==i){
            printf("id =%d \t prix=%d \t loue:%d \n ",v[i].id,v[i].prix,v[i].lou);
        }

    }printf("\n");

}
int cher(voiture v[],int nbv){
    int min,i,ind;
    min=v[0].prix;
    ind=0;
    for(i=0;i<nbv;i++){
            if(min>v[i].prix){
                min=v[i].prix;
                ind=i;
            }

    }
    return ind;
}
int nblou(voiture v[],int nbv){
    int i,h;
    h=0;
    for(i=0;i<nbv;i++){
        if (v[i].lou==1){
            h++;
        }
    }
    return h;
}
int cherid(voiture v[],int nbv){
    int pop,i;
    printf("donner id");
    scanf("%d",&pop);
    for (i=0;i<nbv;i++){
        if (v[i].id==pop){
            return 1;
        }
    }
    return 2;
}
