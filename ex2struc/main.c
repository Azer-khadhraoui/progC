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
    char che[20];
    etudiant e[10];
    int n,i;



    printf("donner le nbre des etudiants");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("donner id %d :",i+1);
        scanf("%s",e[i].id);
        printf("donner nom %d : ",i+1);
        scanf("%s",e[i].nom);
        printf("donner prenom %d  :",i+1);
        scanf("%s",e[i].pre);
        fflush(stdin);
        printf("donner moyenne %d : ",i+1);
        scanf("%.2f",&e[i].moy);
    }
     printf("id cherche");
     gets(che);
     for (i=0;i<n;i++){
        if (che==e[i].id){
            printf ("yyyyyyy");
        }
     }








    return 0;
}
