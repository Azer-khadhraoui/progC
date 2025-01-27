#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"
#include<string.h>


void enregistreremploye(char *f){
    employe e;
    int n,i;
    FILE *fichier=fopen(f,"wb");
    if (fichier==NULL){
        printf("erreur");
    }
    else{
        printf("donner le nombre d'emloye");
        scanf("%d",&n);
        for (i=0;i<n;i++){
        printf("donner le nom\n");
        fflush(stdin);
        gets(e.nom);
        printf("prenom = \n");
        fflush(stdin);
        gets(e.pre);
        printf("donner le nombre d'enfants\n");
        scanf("%d",&e.nbre);


        fwrite(&e,sizeof(employe),1,fichier);
        }

        fclose(fichier);
    }
}
void chercher(char nomfichier[] , char pre[]){
    int i;
    employe e;
    FILE *f=fopen(nomfichier,"rb");
    if(f==NULL){
        printf("erreur");
    }
    else{
           while((strcmp(e.pre,pre)!=0)&& (fread(&e,sizeof(employe),1,f))){


    }
    if (strcmp(e.pre,pre)==0){
        printf("  se trouve\n");
    }
    else{
        printf("ne se trouve pas\n");
    }
    }

    fclose(f);

}
void affiche(char nomfichier[],int n){
        employe e;
    FILE *f=fopen(nomfichier,"rb");
    if(f==NULL){
        printf("erreur");
    }
    else{
           printf("les gens qui ont plus que %d enfants sont : \n",n);
           while(fread(&e,sizeof(employe),1,f)){

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
    FILE *f = fopen(nf1, "rb");
    FILE *f1 = fopen(nf2, "w+b");
    if (f == NULL || f1 == NULL) {
        printf("erreur");

    }

    while (fread(&e,sizeof(employe),1,f)) {
        if (e.nbre != 0) {
            fwrite(&e,sizeof(employe),1,f1);
        }
    }

    fclose(f);
    fclose(f1);

    f1 = fopen(nf2, "rb");
    if (f1 == NULL) {
        printf("erreur");

    }
    printf("les employes qui ont plus que 0 enfants sont : \n");
    while (fread(&e,sizeof(employe),1,f1)) {

        printf("%s %s \n", e.nom, e.pre);
    }

    fclose(f1);
    remove(nf1);
    rename(nf2,"nombre_enfants.bin");
}
