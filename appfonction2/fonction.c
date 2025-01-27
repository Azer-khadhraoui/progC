#include <stdio.h>
#include <stdlib.h>
#include "declaration.h"

adherent saisirad(){
    adherent ad;
    printf("id = ");
    scanf("%d",&ad.id);
    printf("nom = ");
    fflush(stdin);
    gets(ad.nom);
    printf("prenom = ");
    fflush(stdin);
    gets(ad.pre);
    printf("rembourssement = ");
    scanf("%f",&ad.remb);
    return ad;


}
int ajouterad(adherent a[], adherent ad,int nb){
    a[nb]=ad;
    nb++;
    return nb;

}
void afficherad(adherent a[],int nb){
    int i;
    for (i=0;i<nb;i++){
        printf("id=%d \t nom=%s \t prenom=%s \t rembourssement=%f \n",a[i].id,a[i].nom,a[i].pre,a[i].remb);
    }
}
constat saisirc(){
    constat con;
    printf("type = ");
    scanf("%d",&con.type);
    printf("id = ");
    scanf("%d",&con.id2);
    printf("reference = ");
    scanf("%d",&con.refe);
    printf("prix = ");
    scanf("%f",&con.prix);

    return con;

}
void initialiser(constat c[][5]){
    int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<5;j++){
            c[i][j].refe=0;
        }
    }

}
int ajouterc(constat c[3][5],constat con,int nbm1,int nbm2,int nbm3){
    if (con.type==0){
        c[0][nbm1]=con;
        nbm1++;
        return nbm1;
    }
      else  if (con.type==1){
        c[1][nbm2]=con;
        nbm2++;
        return nbm2;
    }
        else if (con.type==2){
        c[2][nbm3]=con;
        nbm3++;
        return nbm3;
    }
}
void afficherc(constat c[3][5]){
   int i,j;
    for (i=0;i<3;i++){
            for (j=0;j<5;j++){
              printf("type = %d   id=%d   reference=%d   prix=%f",c[i][j].type,c[i][j].id2,c[i][j].refe,c[i][j].prix);

            }printf("\n");

    }
}
