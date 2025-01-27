#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[20];
    int age;
    float tai;
    float poi;




}etud;





int main()
{
    int i,n,nb;
    float maxt;
    etud e[20];
    printf("n=");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("donner le nom");
        fflush(stdin);
        gets(e[i].nom);
        printf("donner age  ");
        scanf("%d",&e[i].age);
        printf("donner la taille ");
        scanf("%f",&e[i].tai);
        printf("donner le poids ");
        scanf("%f",&e[i].poi);
    }

      for (i=0;i<n;i++){
        printf("nom : %s \t age: %d \t taille : %f  poids : %f \n",e[i].nom,e[i].age,e[i].tai,e[i].poi);

    }
         maxt=e[0].tai;
         for (i=0;i<n;i++){
            if (e[i].tai>maxt){
                maxt=e[i].tai;

            }

    }

    printf("la personne qui a la plus grande taille est  : %s",e[i].nom);







    return 0;
}
