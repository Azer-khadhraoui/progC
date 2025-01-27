#include <stdio.h>
#include <stdlib.h>

void remplirtab(int tab[],int n);
void affichetab(int tab[],int n);
float moyenne(int tab[],int n);
float ppourcent(int tab[],int n);
int changer(int tab[],int n);
int ajout(int tab[],int n);
void tri (int tab[],int n);
int cher(int tab[],int n);








int main()
{
    int choix,n,t[20],i;
    float moy,p;
    printf("n=");
    scanf("%d",&n);

    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- remplir ************************\n");
            printf("*************** 2- affiche ******************\n");
            printf("*************** 3- moyenne**************************\n");
            printf("*************** 4-pourcent ************************\n");
            printf("*************** 5- ******************\n");
            printf("*************** 6- ajout **********************************\n");
            printf("*************** 7- changer *****************************\n");
            printf("*************** 8- tri **********************************\n");
            printf("*************** 9- cherche*****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);


        if(choix==1){

                remplirtab(t,n);




        }
        if (choix==2){
            affichetab(t,n);
            printf("\n");
        }
        if (choix==3){
            moy=moyenne(t,n);
            printf("la moyenne est %.2f",moy);
        }
        if(choix==4){
            p=ppourcent(t,n);
            printf("le pourcentage est %.2f %",p);
        }
        if (choix==6){
                n=ajout(t,n);

        }
        if(choix==7){
            n=changer(t,n);
        }
        if(choix==8){
            tri(t,n);
        }
        if(choix==9){
            int b;
            b=cher(t,n);
            if (b==-1){
                printf("pas de nombre superieur a valeur donne");
            }
            else{
                printf("la position est %d",b);
            }
        }

    }
    while(choix!=0);
    return 0;
}

void remplirtab(int tab[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("t[%d]=",i);
        scanf("%d",&tab[i]);
    }
}

void affichetab(int tab[],int n){
    int i;
    for(i=0;i<n;i++){
            printf("%d|",tab[i]);

    }

}
float moyenne(int tab[],int n){
    int i;
    float s;
    for(i=0;i<n;i++){
        s+=tab[i];
    }
    return (s/n);
}
float ppourcent(int tab[],int n){
    int i;
    float s;
    for(i=0;i<n;i++){
        if(tab[i]>5){
            s++;
        }
    }
    return (s*100/n);
}
int changer(int tab[],int n){
    int i,x,pos;
    printf("donner la position");
    scanf("%d",&pos);
    printf("donner x = ");
    scanf("%d",&x);
    for(i=n;i>pos;i--){
        tab[i]=tab[i-1];
    }n++;
    tab[pos]=x;
    return n;

}
int ajout(int tab[],int n){
    int i,z;
    printf("donner le nombre ");
    scanf("%d",&z);
    n++;
    tab[n-1]=z;
    return n;
}
void tri (int tab[],int n){
    int i,j,aux,mi;
    for (i=0;i<n;i++){
        mi=i;
        for(j=i;j<n;j++){
            if(tab[j]<tab[mi]){
                mi=j;
            }
        }
        aux=tab[i];
        tab[i]=tab[mi];
        tab[mi]=aux;
    }
}
int cher(int tab[],int n){
    int i,va,b;
    tri(tab,n);
    b=-1;
    printf("valeur = ");
    scanf("%d",&va);
    for(i=0;i<n && b==-1;i++){
            if (tab[i]>va){
                b=i;

            }


    }
    return b;


}

