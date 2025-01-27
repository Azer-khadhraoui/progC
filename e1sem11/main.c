#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int sear(char ch[]);
void searall(char ch[]);
void del(char ch[]);
int nbocc(char ch[]);





int main()
{
    char ch[20];
    int choix,z,t;
    printf("ch=\n");
    fflush(stdin);
    gets(ch);
     do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- search ************************\n");
            printf("*************** 2- ******************\n");
            printf("*************** 3- **************************\n");
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
    if (choix==1){
            z=sear(ch);
            if (z==-1){
                printf("ne se trouve pas");
            }
            else {
                printf("l indice est %d \n",z);
            }

    }
    if (choix==2){
            searall(ch);

    }
    if(choix==3){
            del(ch);

    }
    if (choix==4){
        t=nbocc(ch);
        printf("nombre d occ est %d",t);
    }

    }
    while(choix!=0);

    return 0;
}

int sear(char ch[]){
    int i,in,l;
    char ca;
    l=strlen(ch);
    printf("caractere=\n");
    fflush(stdin);
    scanf("%c",&ca);
    in=-1;
    for (i=0;i<l;i++){
            if (ch[i]==ca){
                in=i;
            }

    }
    return in;
}
void searall(char ch[]){
        int i,in,l;
    char ca;
    l=strlen(ch);
    printf("caractere=\n");
    fflush(stdin);
    scanf("%c",&ca);
    in=-1;
    printf("les positions sont : ");
    for (i=0;i<l;i++){
            if (ch[i]==ca){
                printf("%d-",i);
            }

    }

}
void del(char ch[]){
         int i,in,l,j;
    char ca;
    l=strlen(ch);
    printf("caractere=\n");
    fflush(stdin);
    scanf("%c",&ca);
    in=-1;

    for (i=0;i<l;i++){
            if (ch[i]==ca){
                for (j=i;j<l;j++){
                    ch[j]=ch[j+1];
                }
                l--;
                i--;
            }

    }
    ch[l]='\0';
    printf("%s",ch);

}
int nbocc(char ch[]){
      int i,in,l;
    char ca;
    l=strlen(ch);
    printf("caractere=\n");
    fflush(stdin);
    scanf("%c",&ca);
    in=0;
    for (i=0;i<l;i++){
            if (ch[i]==ca){
                in++;
            }

    }
    return in;

}
