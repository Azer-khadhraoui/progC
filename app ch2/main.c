#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char ch[20],listemot[20];
    int i,choix,l,nbmot,nb,nbvoy,b,y,n,j ,x, ordre[7],o[7];
     char ex[6][8]={"sixieme","notre","pour","c'est","annee","prosit"};
    o[0]=2;
    o[1]=1;
    o[2]=4;
    o[3]=0;
    o[4]=5;
    o[5]=3;






    printf("donner ch \n");
    fflush(stdin);
    gets(ch);
nbmot=0;
l=strlen(ch);

    do{
    do {
        printf("1: afficher les mots de la phrase\n");
        printf("2: afficher les voyelles et leur nombre dans un mot\n");
        printf("3: construire  une  phrase\n");
        printf("----------------------------\n");
        printf("saisir votre choix\n");
        scanf("%d",&choix);





    if (choix==1){

            i=0;
            nb=0;
                while (i<l){
                if ((ch[i]!='.') && (ch[i]!=' ')){
                    listemot[nb]=ch[i];

                    nb++;




                }



                else{
                    listemot[nb]='\0';
                    printf("%s\n",listemot);
                    nb=0;
                    nbmot++;

                }

                i++;

            }


           printf("%d",nbmot);

    }

    if (choix==2){
    nbvoy=0;
        for (i=0;i<l;i++){
            if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' ||
            ch[i] == 'y' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' ||
            ch[i] == 'U' || ch[i] == 'Y'){
                nbvoy++;
                printf("%c,",ch[i]);
        }

    }

printf("\n%d",nbvoy);

}


if (choix==3){

        for (i=0;i<6;i++){
            printf("donner l ordre de mot %s ",ex[i]);
            scanf("%d",&ordre[i]);

        }
  y=0;
  b=1;
  x=0;
  while ((y<6)&&(b==1)){

            if (ordre[x]==o[y]){
                y++;
                x++;
            }
            else {
                    b=0;

            }



  }

if (b==0){
    printf("votre ordre est faux");
}
else{
    printf("bravo ! c est vrai");
}




}





    }while ((choix<0)||(choix>3)&&(n==1));

    }while (choix!=0);







    return 0;
}
