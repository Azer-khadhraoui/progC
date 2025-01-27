#include <stdio.h>
#include <stdlib.h>

struct cellule{
    int val;
    struct cellule *suivant;
};
typedef struct cellule *liste;
liste ajouter_debut(liste tete,int valeur);
liste ajouter_fin(liste tete,int valeur);
liste ajouter_milieu(liste tete,int valeur,int critere);
liste supprimer_debut(liste tete);
liste supprimer_fin(liste tete);
liste supprimer_milieu(liste tete,int valeur);
void afficher(liste tete);
int main()
{
    int choix,val,val1,val2,crit,val3;
    liste tete=NULL;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  tete************************\n");
            printf("*************** 2- fin******************\n");
            printf("*************** 3- milieu**************************\n");
            printf("*************** 4- affiche*************************\n");
            printf("*************** 5-s tete*****************\n");
            printf("*************** 6- s fin **********************************\n");
            printf("*************** 7-  s milieu*****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);
        if(choix==1){
            printf("val=");
            scanf("%d",&val);
            tete=ajouter_debut(tete,val);
        }
        if(choix==2){
            printf("val=");
            scanf("%d",&val1);
            tete=ajouter_fin(tete,val1);
        }
        if(choix==3){
                printf("val=");
            scanf("%d",&val1);
        printf("critere=");
            scanf("%d",&crit);
            tete=ajouter_milieu(tete,val1,crit);
        }
        if(choix==4){
            afficher(tete);
        }
         if(choix==5){
            tete= supprimer_debut(tete);
        }
         if(choix==6){
            tete= supprimer_fin(tete);
        }
         if(choix==7){
                printf("val=");
            scanf("%d",&val3);
            tete=supprimer_milieu(tete,val3);
        }


    }
    while(choix!=0);
    return 0;
}
liste ajouter_debut(liste tete,int valeur){
    liste nouv;
    nouv=malloc(sizeof(struct cellule));
    nouv->val=valeur;
    nouv->suivant=tete;
    tete=nouv;
    return tete;

}
liste ajouter_fin(liste tete,int valeur){
    liste nouv;
    liste parc=tete;
    nouv=malloc(sizeof(struct cellule));
    nouv->val=valeur;
    nouv->suivant=NULL;
    if (tete==NULL){
        tete=nouv;
    }
    else{
        while(parc->suivant!=NULL){
            parc=parc->suivant;
        }
        parc->suivant=nouv;
    }
    return tete;
}
liste ajouter_milieu(liste tete,int valeur,int critere){
    liste nouv=NULL;
    liste pred=NULL;
    liste parc=tete;
    while((parc!=NULL) && (parc->val!=critere)){
            pred=parc;
            parc=parc->suivant;

    }
    if(parc==NULL){
        printf("introuvable\n");
    }
    else{
            nouv=malloc(sizeof(struct cellule));
            nouv->val=valeur;
            nouv->suivant=parc;
            if(parc==tete){
                tete=nouv;
            }
            else{
                pred->suivant=nouv;
            }

    }
    return tete;
}
void afficher(liste tete){
    liste parc=tete;
    while (parc!=NULL){
        printf("%d|",parc->val);
        parc=parc->suivant;
    }printf("\n");
}
liste supprimer_debut(liste tete){
    liste tmp=NULL;
    if(tete!=NULL){
            tmp=tete;
            tete=tete->suivant;
            free(tmp);

    }
    return tete;
}
liste supprimer_fin(liste tete){
    liste tmp;
    liste courant;
    if(tete!=NULL){
        if(tete->suivant==NULL){
            free(tete);
            tete=NULL;
        }
        else{
            tmp=tete;
            courant=tete;
            while (tmp->suivant!=NULL){
                courant=tmp;
                tmp=tmp->suivant;
            }
            courant->suivant=NULL;
            free(tmp);
        }
    }
    return tete;

}
liste supprimer_milieu(liste tete,int valeur){
    liste courant=tete;
    liste pred=NULL;
    int trouve=0;
    if(tete!=NULL){
        if(tete->val==valeur){
            tete=supprimer_debut(tete);
        }
        else{
            while((courant!=NULL) && (!trouve)){
                if(courant->val==valeur){
                    trouve=1;
                }
                else{
                    pred=courant;
                    courant=courant->suivant;
                }
            }
            if(trouve){
                pred->suivant=courant->suivant;
                free(courant);
            }
            else{
                printf("introuvable \n");
            }
        }
    }
    return tete;
}
