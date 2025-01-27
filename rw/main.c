#include <stdio.h>
#include <stdlib.h>


typedef struct{

    char nom[20];
     char id[20];
    int nb;
    int note[20];
}etudiant;





int main()
{

    etudiant e[20];
    int i,j,n,choix,ind,s,ix,aux,min,k;
    float m,mo,b,max,z;
    char f[20];
    float moy[20];

    printf("n=");
    scanf("%d",&n);


       do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- Remplir un tableau . ************************\n");
            printf("*************** 2-  Afficher le tableau des clients.******************\n");
            printf("*************** 3-  moyenne pour 1 etd **************************\n");
            printf("*************** 4-  moyenne pour tous les etudiants*************************\n");
            printf("*************** 5- Afficher la destination la plus demandée pour un voyageur sachant son identifiant******************\n");
            printf("*************** 6-   Afficher le mois de l’année avec le plus grand nombre de réservations*******************************\n");
            printf("*************** 7- tri   *******************************\n");


            printf("donner votre choix\n");
            scanf("%d",&choix);

        }while(choix<0||choix>7);




    if(choix==1){

    for (i=0;i<n;i++){
    printf("nom =\n");
    fflush(stdin);
    gets(e[i].nom);
     printf("id =\n");
    fflush(stdin);
    gets(e[i].id);
      printf("nombre de note =\n");
    scanf("%d",&e[i].nb);
    for(j=0;j<e[i].nb;j++){
        printf("donner note %d ",j);
        scanf("%d",&e[i].note[j]);
    }





}




}



if (choix==2){
    for(i=0;i<n;i++){
        printf("nom %s \t id: %s \t nb matiere : %d \t",e[i].nom,e[i].id,e[i].nb);
        for(j=0;j<e[i].nb;j++){
            printf("%d|",e[i].note[j]);
        }printf("\n");

    }
}
b=-1;
if(choix==3){
    mo=0;
    s=0;
    printf("donner le nom de l etudiant");
    scanf("%s",&f);
    for (i=0;i<n && b==-1;i++){
        if(strcmp(e[i].nom,f)==0){
            ind=i;
            b=1;
        }
    }
    for (i=0;i<e[ind].nb;i++){
            s=s+e[ind].note[i];

    }
    mo=(float)s/e[ind].nb;
    printf("la moyenne de %s est %f",e[ind].nom,mo);

}


if (choix==4){
        for (i=0;i<n;i++){
            mo=0;
            s=0;
            for(j=0;j<e[i].nb;j++){
                    s=s+e[i].note[j];

            }
            mo=(float)s/e[i].nb;
            moy[i]=mo;
        }


        for (i=0;i<n;i++){
            printf("%f-",moy[i]);
        }

}

if(choix==5){
    max=moy[0];
    for (i=0;i<n;i++){
        if(max<moy[i]){
            max=moy[i];
            ix=i;
        }
    }
    printf("le 1er etudiant est %s avec %f moyenne",e[ix].nom,moy[ix]);
}


if(choix==6){

    for(i=0;i<n;i++){
       z=-1;
        for(j=0;j<e[i].nb && z==-1;j++){
                if(e[i].note[j]<10){
                    z=1;
                    printf("%s a echoue une matiere",e[i].nom);
                }

        }
    }
}
if (choix==7){
    for(i=0;i<n;i++){
        for(j=0;j<e[i].nb;j++){
                min=j;
                for(k=j+1;k<e[i].nb;k++){
                    if(e[i].note[k]<e[i].note[min]){
                        min=k;
                    }
                }
                aux=e[i].note[j];
                e[i].note[j]=e[i].note[min];
                e[i].note[min]=aux;

        }

    }

    for(i=0;i<n;i++){
        for(j=0;j<e[i].nb;j++){
            printf("%d|",e[i].note[j]);
        }printf("\n");
    }

}


  }
    while(choix!=0);

    return 0;
}
