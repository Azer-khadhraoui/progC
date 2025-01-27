#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"
#include<string.h>


void enregistreremploye(char *f){
    employe e;
    FILE *fichier=fopen(f,"a");
    if (fichier==NULL){
        printf("erreur");
    }
    else{
        printf("donner le nom\n");
        fflush(stdin);
        gets(e.nom);
        printf("prenom = \n");
        fflush(stdin);
        gets(e.pre);
        printf("donner le nombre d'enfants\n");
        scanf("%d",&e.nbre);


        fprintf(fichier,"%s %s %d\n",e.nom,e.pre,e.nbre);
        fclose(fichier);
    }
}
void chercher(char nomfichier[] , char pre[]){
    int i;
    employe e;
    FILE *f=fopen(nomfichier,"r");
    if(f==NULL){
        printf("erreur");
    }
    else{
           while((strcmp(e.pre,pre)!=0)&& (fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbre)!=EOF)){   //while (!feof(nomf) && test ==-1) retour fscanf(....)


    }
    if (strcmp(e.pre,pre)==0){
        printf("se trouve");
    }
    else{
        printf("ne se trouve pas");
    }
    }

    fclose(f);

}
void affiche(char nomfichier[],int n){
        employe e;
    FILE *f=fopen(nomfichier,"r");
    if(f==NULL){
        printf("erreur");
    }
    else{
           printf("les gens qui ont plus que %d enfants sont : \n",n);
           while((fscanf(f,"%s %s %d",e.nom,e.pre,&e.nbre)!=EOF)){

            if(e.nbre>n){
                printf("%s|",e.nom);
            }

    }

    }
    printf("\n");

    fclose(f);

}
void supp(char nf1[], char nf2[]) {
    employe e;
    FILE *f = fopen(nf1, "r");
    FILE *f1 = fopen(nf2, "w+");
    if (f == NULL || f1 == NULL) {
        printf("erreur");
        return;
    }

    while (fscanf(f, "%s %s %d", e.nom, e.pre, &e.nbre) != EOF) {
        if (e.nbre != 0) {
            fprintf(f1, "%s %s %d\n", e.nom, e.pre, e.nbre);
        }
    }

    fclose(f);
    fclose(f1);

    f1 = fopen(nf2, "r");
    if (f1 == NULL) {
        printf("erreur");
        return;
    }

    while (fscanf(f1, "%s %s %d", e.nom, e.pre, &e.nbre) != EOF) {
        printf("%s %s %d\n", e.nom, e.pre, e.nbre);
    }

    fclose(f1);
}
