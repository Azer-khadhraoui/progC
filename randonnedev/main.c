#include <stdio.h>
#include <stdlib.h>
#include<string.h>





typedef struct{
    int j;
    int m;


}date;

typedef struct{
    int cin;
    char nom[20];
    char sexe;

}participant;


typedef struct{
    char dest[20];
    int nbp;
    participant tp[20];
    date d;
}randonne;


void saisirrandonne(randonne *pr);
int chercherrandonne(randonne t[],int n,date d);
void ajouterrandonne(randonne t[],int *pn,randonne r);
void ajouterparticipant(randonne t[],int n,date d);
void afficher(randonne t[],int n);
void taux(randonne t[],int n,float *pf,float *ph);
void tritab(randonne t[],int n);
void participation(randonne t[],int n,int tmois[]);
void haute(randonne t[],int n);


int main()
{
    int choix,n=0,cher,tmois[13],i;
    randonne r;
    randonne tr[20];
    date d1,dch;
    float pf,ph;

    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter randonne ************************\n");
            printf("*************** 2- chercher randonne ******************\n");
            printf("*************** 3- ajouter participant**************************\n");
            printf("*************** 4- afficher*************************\n");
            printf("*************** 5-taux******************\n");
            printf("*************** 6-  tri tab**********************************\n");
            printf("*************** 7-  somme mois*****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
        if(choix==1){
            saisirrandonne(&r);
            ajouterrandonne(tr,&n,r);
        }
        if (choix==2){
            printf("j=");
            scanf("%d",&dch.j);
            printf("m=");
            scanf("%d",&dch.m);
            cher=chercherrandonne(tr,n,dch);
            if(cher==-1){
                printf("introuvable");

            }
            else{
                printf("se trouve dans %d \n",cher);
            }
        }
        if(choix==3){
                   printf("donner la date\n 1-jour=");
                    scanf("%d",&d1.j);
                    do{
                        printf("2-mois=\n");
                        scanf("%d",&d1.m);
                    }while((d1.m<1) || (d1.m>12) );

                ajouterparticipant(tr,n,d1);

        }
        if(choix==4){
            afficher(tr,n);
        }
        if(choix==5){
            taux(tr,n,&pf,&ph);
            printf("pourecentage homme = %.2f \n pourecentage femme = %.2f ",ph,pf);
        }
        if(choix==6){
            tritab(tr,n);
        }
        if (choix==7){
            participation(tr,n,tmois);
        }

    }
    while(choix!=0);
    return 0;
}

void saisirrandonne(randonne *pr){
    int i;

    printf("destination = ");
    fflush(stdin);
    gets(pr->dest);
    pr->nbp=0;
    printf("jour=");
    scanf("%d",&pr->d.j);
    do{
    printf("mois=");
    scanf("%d",&pr->d.m);
    }while((pr->d.m<1) || (pr->d.m>12) );

}
int chercherrandonne(randonne t[],int n,date d){
    int i,ind=-1;
    for (i=0;i<n && ind==-1;i++){
        if((t[i].d.j==d.j)&&(t[i].d.m==d.m)){
            ind=i;
        }
    }
    return ind;

}
void ajouterrandonne(randonne t[],int *pn,randonne r){
    int pos;
    pos=chercherrandonne(t,(*pn),r.d);
    if(pos!=-1){
            printf("erreur ! deja existe dans %d\n",pos);

    }
    else{
        t[(*pn)]=r;
        (*pn)++;
    }

}
void ajouterparticipant(randonne t[],int n,date d){
        int pos1,nbparticipant;
        date d2;
        participant p;

        pos1=chercherrandonne(t,n,d);
        if (pos1==-1){
            printf("erreur ! date introuvable !! \n");
        }
        else{
        printf("cin = ");
        scanf("%d",&p.cin);
        printf("nom = ");
        fflush(stdin);
        gets(p.nom);
        do{
        printf("sexe = ");
        fflush(stdin);
        scanf("%c",&p.sexe);
        }while((p.sexe!='h') && (p.sexe!='f') );
        nbparticipant=t[pos1].nbp;
        t[pos1].tp[nbparticipant]=p;
        t[pos1].nbp++;
        }





}
void afficher(randonne t[],int n){
    int i,j;
    for(i=0;i<n;i++){
        printf("destination= %s nb participant=%d date:%d/%d \n",t[i].dest,t[i].nbp,t[i].d.j,t[i].d.m );
        for(j=0;j<t[i].nbp;j++){
            printf("cin = %d nom = %s sexe=%c || ",t[i].tp[j].cin,t[i].tp[j].nom,t[i].tp[j].sexe);
        }printf("\n\n");
    }
}
void taux(randonne t[],int n,float *pf,float *ph){
    int i,j;
    float cmpth=0,cmptf=0,sommetot;
    for (i=0;i<n;i++){
            for (j=0;j<t[i].nbp;j++){
                if(t[i].tp[j].sexe=='h'){
                    cmpth++;
                }
                else{
                    cmptf++;
                }
            }

    }
    sommetot=cmpth+cmptf;
    (*ph)=(cmpth/sommetot)*100;
    (*pf)=(cmptf/sommetot)*100;

}
void tritab(randonne t[],int n){
    int i,j,ind;
    randonne aux;
    for (i=0;i<n-1;i++){
        ind=i;
        for (j=i+1;j<n;j++){
            if(strcmp(t[j].dest,t[ind].dest)<0){
                ind=j;
            }

        }
        aux=t[i];
    t[i]=t[ind];
    t[ind]=aux;
    }


}
void participation(randonne t[],int n,int tmois[]){
    int i,x;
     for (i=0;i<13;i++){
        tmois[i]=0;
    }

    for(i=0;i<n;i++){
        x=t[i].d.m;
        tmois[x]++;

    }
     for(i=1;i<13;i++){
        printf("%d|",tmois[i]);
    }

}
void haute(randonne t[],int n){
    int s1,s2,s3,s4;
    int somme[4];
    for
}
