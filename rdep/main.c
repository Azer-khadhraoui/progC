#include <stdio.h>
#include <stdlib.h>
#include<string.h>




typedef struct{
    int id;
    char ville[20];
    char type[20];
    int nbr;
    int nbprod[20];
    char nom[20];
}depot;

void saisir(depot *d);
void ajouter(depot td[],int *n,depot d);
void afficher(depot td[],int n);
void ajouterprod(depot td[],int n,int id,int nbaj);
void listeprd(depot td[],int n,char type[]);
void maxprod(depot td[],int n,int ts[]);
void modres(depot td[],int n,char nom[],int id);
void nbdep(depot td[],int n,char ville[]);
void maxseuil(depot td[],int n,int seuil);
void supp(depot td[],int *n);



int main()
{
    depot d;

    char type[20],nom[20],v[12];
    depot td[20];
    int choix,n=0,nbaj,id,ts[20],id2,seuil;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter depot ************************\n");
            printf("*************** 2- affichage ******************\n");
            printf("*************** 3- ajout du nbre produit **************************\n");
            printf("*************** 4- liste produit*************************\n");
            printf("*************** 5- max produit******************\n");
            printf("*************** 6-  modifier nom **********************************\n");
            printf("*************** 7-  depot par ville*****************************\n");
            printf("*************** 8- seuil  **********************************\n");
            printf("*************** 9- supp*****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if (choix==1){
            saisir(&d);
            ajouter(td,&n,d);
        }
        if (choix==2){
            afficher(td,n);
        }
        if(choix==3){
    printf("id = ");
    scanf("%d",&id);
     printf("nb de produit ajoute = ");
    scanf("%d",&nbaj);
        ajouterprod(td,n,id,nbaj);
        }
        if(choix==4){
            printf("dooner le type cherche \n");
            fflush(stdin);
            gets(type);
            listeprd(td,n,type);
        }
        if (choix==5){
            maxprod(td,n,ts);
        }
        if (choix==6){
              printf("id = ");
                scanf("%d",&id2);

              printf("donner le nom nouveau \n");
            fflush(stdin);
            gets(nom);
            modres(td,n,nom,id2);
        }
        if(choix==7){
            printf("donner la ville\n");
            fflush(stdin);
            gets(v);
            nbdep(td,n,v);
        }
        if(choix==8){
             printf("seuil = ");
                scanf("%d",&seuil);
            maxseuil(td,n,seuil);
        }
        if(choix==9){
            supp(td,&n);
        }


    }
    while(choix!=0);
    return 0;
}
void saisir(depot *d){
    int i;

    printf("id = ");
    scanf("%d",&d->id);
    printf("ville  = ");
    fflush(stdin);
    gets(d->ville);
    printf("type  = ");
    fflush(stdin);
    gets(d->type);
    printf("nom  = ");
    fflush(stdin);
    gets(d->nom);
    printf("nb rayon = ");
    scanf("%d",&d->nbr);
    for (i=0;i<d->nbr;i++){
        d->nbprod[i]=0;
    }
}
void ajouter(depot td[],int *n,depot d){
    td[(*n)]=d;
    (*n)++;

}
void afficher(depot td[],int n){
    int i,j;
    for (i=0;i<n;i++){
        printf("id= %d  ville = %s  type = %s  nom = %s ",td[i].id,td[i].ville,td[i].type,td[i].nom);
        for (j=0;j<td[i].nbr;j++){
            printf("%d|",td[i].nbprod[j]);
        }printf("\n");
    }
}
void ajouterprod(depot td[],int n,int id,int nbaj){
    int i,b=-1,ind,t=-1,ind2;

    for (i=0;i<n && b==-1;i++){
        if(id==td[i].id){
            b=1;
            ind=i;
        }
    }
    for (i=0;i<td[ind].nbr && t==-1;i++){
        if(td[ind].nbprod[i]==0){
            t=1;
            ind2=i;



        }
    }
    td[ind].nbprod[ind2]=nbaj;
}
void listeprd(depot td[],int n,char type[]){
    int i ;
    printf(" les depot de type %s sont :  \n",type);
    for (i=0;i<n;i++){
        if(strcmp(type,td[i].type)==0){
            printf("id: %d ville : %s type : %s ",td[i].id,td[i].ville,td[i].type);
        }printf("\n");
    }
}
void maxprod(depot td[],int n,int ts[]){
    int i,j,m=0,indm=0,s=0;
    for(i=0;i<n;i++){
        for(j=0;j<td[i].nbr;j++){
                 s=s+td[i].nbprod[j];

        }
        ts[i]=s;
        s=0;



    }


    for (i=0;i<n;i++){
            if(ts[i]>m){
                m=ts[i];
                indm=i;
            }

    }

    printf(" le depot qui a  le plus nombre de produit est : \n");
    printf("responsable : %s ville : %s  avec %d produits ",td[indm].nom,td[indm].ville,m);
}
void modres(depot td[],int n,char nom[],int id){
      int i,ind,b=-1;
      for (i=0;i<n && b==-1;i++){
        if(id==td[i].id){
            b=1;
            ind=i;
        }
    }
    strcpy(td[ind].nom,nom);

}
void nbdep(depot td[],int n,char ville[]){
      int i,ind,s=0;
      for (i=0;i<n;i++){
        if(strcmp(td[i].ville,ville)==0){
           s++;
        }
    }
    printf("nombre de depot de %s est %d \n",ville,s);

}
void maxseuil(depot td[],int n,int seuil){
    int i,j,b=0;
    for (i=0;i<n;i++){
        for(j=0;j<td[i].nbr;j++){
            if (td[i].nbprod[j]<seuil){
                b++;
            }
        }
        if (b==td[i].nbr){
            printf("%s -",td[i].nom);
        }b=0;
    }
}
void supp(depot td[],int *n){
    int i,j,b=-1;
    for (i=0;i<(*n) && b==-1;i++){
        if(td[i].nbprod[0]==0){
            b=i;
        }
    }

     if(b!=-1){


     for (i=b;i<(*n);i++){
                td[i]=td[i+1];
            }
            (*n)--;
    }
}
