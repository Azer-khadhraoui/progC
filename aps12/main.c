#include <stdio.h>
#include <stdlib.h>


void remplir(int t[],int *x);
void affiche(int t[],int x);
void somme(int t[],int x,int *s);
void maxim(int t[],int x,int *max);
void tri(int t[],int x);
void ajout(int t[],int *x,int ajo,int pos);
void moyenne(int t[],int x,float *m);




int main()
{
    int choix,n,nouv,max,y,s,pos,ajo;
    float m;
    int t[20];
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- remplir ************************\n");
            printf("*************** 2- affiche******************\n");
            printf("*************** 3- somme **************************\n");
            printf("*************** 4- max *************************\n");
            printf("*************** 5-tri  ******************\n");
            printf("*************** 6-  ajout**********************************\n");
            printf("*************** 7-  moyenne **************************\n");
            printf("*************** 8-  **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);


        if (choix==1){
            remplir(t,&n);
        }
        if (choix==2){
            affiche(t,n);
        }
        if (choix==3){
           s=0;
           somme(t,n,&s);
           printf("somme %d \n",s);
        }
        if(choix==4){
            maxim(t,n,&max);
            printf("max = %d \n",max);
        }
          if(choix==5){
            tri(t,n);
        }
        if(choix==6){
            printf("donner l entier");
            scanf("%d",&ajo);
            printf("donner la position");
            scanf("%d",&pos);
            ajout(t,&n,ajo,pos);
        }
           if(choix==7){
            m=0;
            moyenne(t,n,&m);
            printf("moyenne %.2f\n",m);
        }


    }
    while(choix!=0);
    return 0;
}

void remplir(int t[],int *x){
    int i;
    printf("donner nombre d elements");
    scanf("%d",x);
    for (i=0;i<*x;i++){
        printf("donner t[%d]",i);
        scanf("%d",&t[i]);
    }


}
void affiche(int t[],int x){
    int i;
    for (i=0;i<x;i++){
        printf("%d|",t[i]);
    }printf("\n");

}
void somme(int t[],int x,int *s){
    int i;
    for(i=0;i<x;i++){
        (*s)=(*s)+t[i];
    }

}
void maxim(int t[],int x,int *max){
    int i;
    (*max)=t[0];
    for(i=0;i<x;i++){
        if((*max)<t[i]){
            (*max)=t[i];
        }
    }
}
void tri(int t[],int x){
    int i,j,min,aux;
    for(i=0;i<x;i++){
        min=i;
        for (j=i;j<x;j++){
            if(t[min]>t[j]){
                min=j;
            }
        }
        aux=t[i];
        t[i]=t[min];
        t[min]=aux;
    }

}
void ajout(int t[],int *x,int ajo,int pos){
    int i;

            for (i=(*x);i>=pos;i--){
                t[i]=t[i-1];
            }
            t[pos]=ajo;
            (*x)++;



}
void moyenne(int t[],int x,float *m){
    int so;
    so=0;
    somme(t,x,&so);
    (*m)=(float)so/x;

}
