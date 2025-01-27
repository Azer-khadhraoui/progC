#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int code;
    int nbexemp;
}Livre;
typedef struct{
    int num;
    int codelivre;
    char id[20];
    int etat;
}Emprunt;
void saisir_livre(Livre* p_livre);
void chercher_livre(Livre t_livres[], int nl, int code_l, int* pos);
void ajouter_livre(Livre t_livres[], int* nl) ;
void afficher_livres(Livre t_livres[], int nl) ;
void saisir_emprunt(Emprunt* p_emprunt) ;
void chercher_emprunt(int num, Emprunt t_emprunts[], int ne, int* pos);
void ajouter_emprunt(Emprunt t_emprunts[], int* ne, Livre t_livres[], int nl) ;
void affemp(Emprunt t_emprunts[], int ne);
void retourner_emprunt(int num, Emprunt t_emprunts[], int ne, Livre t_livres[],int nl);


int main()
{
    int choix,nl=0,pos,c1,ne=0,numc,poso,num7;
    Livre tl[20];
    Emprunt te[20];

    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1- Ajouter un livre ************************\n");
            printf("*************** 2- recherche ******************\n");
            printf("*************** 3- Afficher tous les livres**************************\n");
            printf("*************** 4- ajouter empruntes*************************\n");
            printf("*************** 5-chercher emprunte******************\n");
            printf("*************** 6-  affiche emprunte**********************************\n");
            printf("*************** 7-  retourner emprunt *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>9);

        if(choix==1){
            ajouter_livre(tl,&nl);
        }
        if(choix==2){
                printf("code");
                scanf("%d",&c1);

                chercher_livre(tl,nl,c1,&pos);
                if(pos==-1){
                    printf("introuvable !");
                }
                else{
                    printf("se trouve dans %d\n",pos);
                }

        }
        if(choix==3){
            afficher_livres(tl,nl);
        }
        if(choix==4){
            ajouter_emprunt(te,&ne,tl,nl);
        }
        if(choix==5){
                printf("donner numero \n");
            scanf("%d",&numc);


            chercher_emprunt(numc,te,ne,&poso);
                if(poso==-1){
                    printf("introuvable !");
                }
                else{
                    printf("se trouve dans %d\n",poso);
                }
        }
        if(choix==6){
            affemp(te,ne);
        }
        if(choix==7){
            printf("donner numero \n");
            scanf("%d",&num7);

            retourner_emprunt(num7,te,ne,tl,nl);
        }


    }
    while(choix!=0);
    return 0;
}
void saisir_livre(Livre* p_livre){
    printf("code = ");
    scanf("%d",&p_livre->code);
    printf("nombre exemplaire = ");
    scanf("%d",&p_livre->nbexemp);

}
void chercher_livre(Livre t_livres[], int nl, int code_l, int* pos){
    int i;
    (*pos)=-1;
    for(i=0;i<nl && (*pos)==-1 ;i++){
            if (t_livres[i].code==code_l){
               (*pos)=i;
            }

    }
}
void ajouter_livre(Livre t_livres[], int* nl) {
    int posi,c1;
    Livre liv;
    saisir_livre(&liv);

    chercher_livre(t_livres,(*nl),liv.code,&posi);
    if (posi==-1){

        t_livres[(*nl)]=liv;
        (*nl)++;
    }
    else{
       t_livres[posi].nbexemp+= liv.nbexemp;
    }

}
void afficher_livres(Livre t_livres[], int nl) {
    int i;
    for (i=0;i<nl;i++){
        printf("livre %d : code = %d  exemplaire = %d |\n",i,t_livres[i].code,t_livres[i].nbexemp);
    }
}
void saisir_emprunt(Emprunt* p_emprunt) {
                printf("numero = ");
                scanf("%d",&p_emprunt->num);
                printf("code livre = ");
                scanf("%d",&p_emprunt->codelivre);
                printf("id=");
                fflush(stdin);
                gets(p_emprunt->id);
                p_emprunt->etat=0;

}
void chercher_emprunt(int num, Emprunt t_emprunts[], int ne, int* pos){
     int i;
    (*pos)=-1;
    for(i=0;i<ne && (*pos)==-1 ;i++){
            if (t_emprunts[i].num==num){
               (*pos)=i;
            }

    }


}
void ajouter_emprunt(Emprunt t_emprunts[], int* ne, Livre t_livres[], int nl) {
    int i,pos1,pos2;
    Emprunt emp;
    saisir_emprunt(&emp);
    chercher_emprunt(emp.num,t_emprunts,(*ne),&pos1);
    if (pos1!=-1){
        printf("erreur , existe !\n");
    }
    else{
        chercher_livre(t_livres,nl,emp.codelivre,&pos2);
        if(pos2==-1){
            printf("erreur livre n'existe pas ! \n");
        }
        else{
            if(t_livres[pos2].nbexemp>=1){
                t_livres[pos2].nbexemp=t_livres[pos2].nbexemp-1;
                t_emprunts[(*ne)]=emp;
                (*ne)++;
            }
            else{
                printf("erreur , nombre d'exemplaire = 0 \n");
            }
        }
    }
}
void affemp(Emprunt t_emprunts[], int ne){
    int i;
    for(i=0;i<ne;i++){
        printf("num = %d code livre = %d  etat = %d  id %s |\n",t_emprunts[i].num,t_emprunts[i].codelivre,t_emprunts[i].etat,t_emprunts[i].id);
    }
}
void retourner_emprunt(int num, Emprunt t_emprunts[], int ne, Livre t_livres[],int nl){
    int p,p1;
    chercher_emprunt(num,t_emprunts,ne,&p);
    if (p==-1){
        printf("erreur ! emprunte introuvable \n");
    }
    else {
        if (t_emprunts[p].etat==1){
                printf("emprunt deja retourne ! \n");

        }
        else{
            chercher_livre(t_livres,nl,t_emprunts[p].codelivre,&p1);
             if (p1==-1){
                printf("erreur ! livre introuvable \n");
                }
                else{
                    t_livres[p1].nbexemp++;
                    t_emprunts[p].etat=1;

                }

        }
    }
}
