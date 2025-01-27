#include <stdio.h>
#include <stdlib.h>

typedef struct

{

int type;

int nbr_ing;

float prix;

} gateau;

void saisir_gateau (gateau *g);
void ajouter_gateau_ft (gateau g, char nom_fich[]);
int nbre_gateaux_ft (char nom_fich[]);
void afficher_gateau (char nom_fich[], int num);
void calculer_afficher_moyenne_salaires(char nom_fich[]);
void supprimer_gateau(char nom_fich[], int num);


int main()
{
    int choix,n,x,num;
    gateau g;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajout ************************\n");
            printf("*************** 2- nb g******************\n");
            printf("*************** 3- cherche**************************\n");
            printf("*************** 4- affiche moy*************************\n");
            printf("*************** 5- supp******************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
        if (choix==1){
            saisir_gateau (&g);
            ajouter_gateau_ft (g,"gateau.txt");
        }
        if(choix==2){
            x=nbre_gateaux_ft ("gateau.txt");
            printf("nombre de gateau = %d",x);
        }
        if(choix==3){

             printf("n g=");
            scanf("%d",&n);
            afficher_gateau ("gateau.txt",n);
        }
        if(choix==4){
            calculer_afficher_moyenne_salaires("gateau.txt");
        }
        if(choix==5){
                 printf("num=");
            scanf("%d",&num);
            supprimer_gateau("gateau.txt",num);
        }


    }
    while(choix!=0);
    return 0;
}
void saisir_gateau (gateau *g){
     printf("type=");
    scanf("%d",&g->type);
    printf("nb ingrediants=");
    scanf("%d",&g->nbr_ing);
    printf("prix=");
    scanf("%f",&g->prix);
}
void ajouter_gateau_ft (gateau g, char nom_fich[]){
    FILE *f=fopen(nom_fich,"a");
    if (f==NULL){
        printf("erreur");

    }
    else{
        fprintf(f,"%d %d %.2f\n",g.type,g.nbr_ing,g.prix);
    }
    fclose(f);

}
int nbre_gateaux_ft (char nom_fich[]){
       int nb=0;
       gateau g;
       FILE *f=fopen(nom_fich,"r");
    if (f==NULL){
        printf("erreur");

    }
    else{

        while (fscanf(f,"%d %d %f",&g.type,&g.nbr_ing,&g.prix)!=EOF){
            nb++;


        }

    }
    return nb;
    fclose(f);

}
void afficher_gateau (char nom_fich[], int num){
       gateau g;
       int nb=0;
       FILE *f=fopen(nom_fich,"r");
    if (f==NULL){
        printf("erreur");

    }
    else{

        while (fscanf(f,"%d %d %f",&g.type,&g.nbr_ing,&g.prix)!=EOF){

            nb++;
            if (nb==num){
                printf("t:%d nbi:%d prix: %f",g.type,g.nbr_ing,g.prix);
            }
        }

    }

    fclose(f);
}
void calculer_afficher_moyenne_salaires(char nom_fich[]){
        gateau g;
        int nbg;
       float nb=0,moy=0;
       FILE *f=fopen(nom_fich,"r");
    if (f==NULL){
        printf("erreur");

    }
    else{

        while (fscanf(f,"%d %d %f",&g.type,&g.nbr_ing,&g.prix)!=EOF){

            nb+=g.prix;

        }
        nbg=nbre_gateaux_ft (nom_fich);
        moy=nb/nbg;
        printf("moyenne = %.2f",moy);

    }

    fclose(f);
}
void supprimer_gateau(char nom_fich[], int num){
            gateau g;
        int nbg;
       float nb=0,moy=0;
       FILE *f=fopen(nom_fich,"r");
       FILE *f2=fopen("gt2.txt","w");
    if (f==NULL){
        printf("erreur");

    }
    else{

        while (fscanf(f,"%d %d %f",&g.type,&g.nbr_ing,&g.prix)!=EOF){

            nb++;
            if(nb!=num){
                    fprintf(f2,"%d %d %f",g.type,g.nbr_ing,g.prix);

            }

        }


           fclose(f);
    fclose(f2);

          FILE *f2=fopen("gt2.txt","r");
          while (fscanf(f2,"%d %d %f",&g.type,&g.nbr_ing,&g.prix)!=EOF){
                printf("t:%d nbi: %d p :%f",g.type,g.nbr_ing,g.prix);

        }



    }

    fclose(f);
    fclose(f2);

}
