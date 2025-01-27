#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char id[20];
    char nom[20];
    char pre[20];
    float moy;

}etudiant;






int main()
{

    etudiant t[100];
    char idch[20];
    int i, n,choix,trv ;
    printf("n=\n");
    scanf("%d",&n);
    do {
    do{
    printf("1- Remplir un tableau d’étudiants.\n");
    printf("2- Afficher la liste des étudiants de la classe.\n");
    printf("3- Rechercher un étudiant identifié par un identifiant\n");
    printf("4- Supprimer un étudiant identifié par un identifiant saisi au clavier.\n");
    printf("5- Afficher la moyenne de la classe.\n");



    printf("choix=\n");
    scanf("%d",&choix);
    }while ((choix<0)||(choix>5));


          if (choix==1){
        for (i=0;i<n;i++){
            printf("donner l id %d :",i+1);
            scanf("%s",t[i].id);
            printf("donner l nom %d :",i+1);
            scanf("%s",t[i].nom);
            printf("donner l prenom %d :",i+1);
            scanf("%s",t[i].pre);
            printf("donner l moyenne %d :",i+1);
            scanf("%f",&t[i].moy);
        }
      }
      if (choix==2){
        for (i=0;i<n;i++){
            printf(" id :%s \t nom:%s \t prenom: %s \t  moyenne : %f \n",t[i].id,t[i].nom,t[i].pre,t[i].moy);
        }
      }


      if (choix==3){
        printf("donnerid cherche :");
        scanf("%s",idch);
        trv=1;
        for (i=0;(i<n )&& (trv==1);i++){



        if (strcmp(t[i].id,idch)==0){
                trv=0;

        }


      }
      if (trv==0){
        printf("se trouve");
      }
      else{
        printf("nn");
      }


}









}while (choix!=0);
    return 0;
}
