#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char ch[20],listemot[20];
    int i,choix,l,nbmot,nb;

    printf("donner ch \n");
    fflush(stdin);
    gets(ch);
nbmot=0;
l=strlen(ch);

    do {
        printf("1: afficher les mots de la phrase\n");
        printf("2: afficher les voyelles et leur nombre dans un mot\n");
        printf("3: construire  une  phrase\n");
        printf("----------------------------\n");
        printf("saisir votre choix\n");
        scanf("%d",&choix);


    }while ((choix<1)||(choix>3));

    if (choix==1){
            i=0;
            while (i<l){
                if ((ch[i]!='.') && (ch[i]!=' ')){
                    listemot[nb]=ch[i];

                    nb++;




                }
                printf("%s",listemot);
                i++;
                else{
                    i++;
                }
            }

           printf("%d",nb);

    }







    return 0;
}

