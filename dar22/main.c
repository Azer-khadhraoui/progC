#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char nom[20];
    char pre[20];
    int nbe;
}employe;
void enregistreinfo(char nomfichier[]);
void chercher(char nomfichier[],char pre[]);
void nbennnn(char nomfichier[],int nb);
void mettreAJourNombreEnfants(char nomFichier[], char prenom[], int nouveauNbEnfants);
void moyenne(char nomfichier[],float *m);
void plusgrand(char nomfichier[], char *nom);



int main()
{
    int choix,nb,nbn;
    char p[20],pr[20],nn[20];
    float m;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  saisir************************\n");
            printf("*************** 2- cherche******************\n");
            printf("*************** 3- seuill**************************\n");
            printf("*************** 4- *************************\n");
            printf("*************** 5-******************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if(choix==1){
            enregistreinfo("nbenfant.txt");

        }
        if(choix==2){
            printf("prenom=");
        fflush(stdin);
        gets(p);
            chercher("nbenfant.txt",p);
        }
        if(choix==3){
            printf("nb=");
            scanf("%d",&nb);
            nbennnn("nbenfant.txt",nb);
        }
        if(choix==4){
            printf("nb enfant nouveau =");
            scanf("%d",&nbn);
            printf("prenom=");
        fflush(stdin);
        gets(pr);
            mettreAJourNombreEnfants("nbenfant.txt",pr,nbn);
        }
        if(choix==5){
            moyenne("nbenfant.txt",&m);
            printf("moyenne = %.2f\n",m);
        }
        if(choix==6){
            plusgrand("nbenfant.txt",nn);
            printf("le nom d employe qui le plus grand nombre est %s\n\n",nn);
        }


    }
    while(choix!=0);
    return 0;
}

void enregistreinfo(char nomfichier[]){
    FILE *f=fopen(nomfichier,"a");
    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
        printf("nom=");
        fflush(stdin);
        gets(e.nom);
        printf("prenom=");
        fflush(stdin);
        gets(e.pre);
        printf("nb enfants =");
        scanf("%d",&e.nbe);
        fprintf(f,"%s %s %d\n",e.nom,e.pre,e.nbe);
    }
    fclose(f);
}
void chercher(char nomfichier[],char pre[]){
    FILE *f=fopen(nomfichier,"r");
    int b;
    b=-1;
    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
            while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbe)!=EOF) && (b==-1)){
                    if(strcmp(e.pre,pre)==0){
                        printf("se trouve");
                        b=1;
                    }

            }

    }
    fclose(f);
}
void nbennnn(char nomfichier[],int nb){
    FILE *f=fopen(nomfichier,"r");

    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
            while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbe)!=EOF) ){
                    if(e.nbe>=nb){
                        printf("nom=%s prenom=%s nb enfants=%d",e.nom,e.pre,e.nbe);

                    }

            }

    }
    fclose(f);

}
void mettreAJourNombreEnfants(char nomFichier[], char prenom[], int nouveauNbEnfants){
        FILE *f=fopen(nomFichier,"r+");

    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
            while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbe)!=EOF) ){
                    if(strcmp(e.pre,prenom)==0){
                        e.nbe=nouveauNbEnfants;

                    }

            }

    }
    fclose(f);

}
void moyenne(char nomfichier[],float *m){
    float s=0;
    int c=0;
    FILE *f=fopen(nomfichier,"r+");

    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
            while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbe)!=EOF) ){
                 c++;
                 s+=e.nbe;

            }
            (*m)=s/c;

    }
    fclose(f);
}
void plusgrand(char nomfichier[], char *nom){
      int max=0;
      FILE *f=fopen(nomfichier,"r");

    employe e;
    if(f==NULL){
        printf("erreur");
    }
    else{
            while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbe)!=EOF) ){
                 if (max<e.nbe){
                    strcpy((nom),e.nom);
                    max=e.nbe;
                 }

            }


    }
    fclose(f);
}
