#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char refpanne[20];
    int etat;
}panne;
typedef struct{
    int refmachine;
    panne p[10];
}machine;

void saisir(machine *m);
void ajouter (machine tm [], machine m, int * n);
int rechercherMach (machine Tm [],int n, int refm) ;
void saisirPanne(panne * pa);
void ajouterPanne(int refmachine, machine tm[], int n, panne pa) ;
int totalPanne(int refmachine, machine tm[], int n) ;
 void modifier_etat_panne (int refmachine, machine tm[], int n) ;
  void afficher (int n, machine tm[],int refmachine) ;
  void trouver (machine tm[], int n, int *n_rep, int *n_nrep, int refmachine) ;
   void supprimer (machine tm[], int *n) ;
   void supprimer2(machine tm[], int *n);


int main()
{
    int n=0;
    int npanne=0;
    panne pa;
    machine m;
    machine tm[20];
    int choix,refch,val,refch2,refch3,refch4,refch5,refch6,n_nrep=0,n_rep=0;
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  saisir************************\n");
            printf("*************** 2- ajouter machine ******************\n");
            printf("*************** 3- chercher une machine**************************\n");
            printf("*************** 4- saisirPanne*************************\n");
            printf("*************** 5-ajouterPanne******************\n");
            printf("*************** 6-  nombre de panne **********************************\n");
            printf("*************** 7-  modifier_etat_panne*****************************\n");
            printf("*************** 8- affichage**********************************\n");
            printf("*************** 9- nombre des pannes rep et non rep*****************************\n");
            printf("*************** 10- supprimer   *****************************\n");
             printf("*************** 11- supprimer 2  *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>11);
        if (choix==1){
                saisir(&m);

        }
          if (choix==2){
                int i;
                ajouter (tm,m,&n);
                for(i=0;i<n;i++){
                    printf("ref machine : %d  refpanne : %s \n",tm[i].refmachine,tm[i].p[i].refpanne);
                }

        }
        if (choix==3){
            printf("donner la reference de la machine cherche \n");
            scanf("%d",&refch);
            val=rechercherMach (tm,n,refch);
            if(val==-1){
                printf("introuvable ! \n");
            }
            else{
                printf("se trouve dans l'indice %d \n",val);
            }
        }
        if(choix==4){
            saisirPanne(&pa);
        }
        if(choix==5){
            int i,j;
            printf("donner la reference de la machine cherche \n");
            scanf("%d",&refch2);
            ajouterPanne(refch2,tm,n,pa);
        for(i=0;i<n;i++){
                    printf("ref machine : %d  :\n",tm[i].refmachine);
                  for (j = 0; j < 10; j++) {
            if (strcmp(tm[i].p[j].refpanne, "") != 0) {
                printf("refpanne : %s    etat:%d | ", tm[i].p[j].refpanne, tm[i].p[j].etat);
            }
        }
        printf("\n");
    }


    }
    if(choix==6){
        int z;
        printf("donner la reference de la machine cherche \n");
        scanf("%d",&refch3);
        z=totalPanne(refch3,tm,n);
        if (z==-1){
            printf("machine introuvable ! \n");
        }
        else{
            printf("le nombre de la machine %d panne est %d \n ",refch3,z);
        }

    }
    if(choix==7){
        printf("donner la reference de la machine cherche \n");
        scanf("%d",&refch4);
        modifier_etat_panne (refch4,tm,n);
    }
    if(choix==8){
         printf("donner la reference de la machine cherche \n");
        scanf("%d",&refch5);
        afficher (n,tm,refch5);
    }
    if(choix==9){
           printf("donner la reference de la machine cherche \n");
        scanf("%d",&refch6);
        trouver (tm,n,&n_rep,&n_nrep,refch6);
        printf("le nombre des panne repares de la machine %d est : %d \n\n",refch6,n_rep);
        printf("le nombre des panne non repares de la machine %d est : %d \n\n",refch6,n_nrep);
    }
    if(choix==10){
        supprimer (tm,&n);
    }
    if(choix==11){
         supprimer2(tm,&n);
    }


    }
    while(choix!=0);
    return 0;
}
void saisir(machine *m){
    int i;
    printf("donner la reference de la machine \n");
    scanf("%d",&(*m).refmachine);
    for (i=0;i<10;i++){
        strcpy((*m).p[i].refpanne,"");

    }
}
void ajouter (machine tm [], machine m, int * n){
    tm[*n]=m;
    (*n)=(*n)+1;
}
 int rechercherMach (machine tm [],int n, int refm) {
     int i,b;
     b=-1;
     for(i=0;i<n && b==-1;i++){
        if (refm==tm[i].refmachine){
            return i;
        }
     }
     return b;


 }
 void saisirPanne(panne * pa){
     printf("donner la reference de la panne \n ");
     fflush(stdin);
     gets((*pa).refpanne);
      printf("donner l'etat de la panne  \n");
            scanf("%d",&(*pa).etat);

 }
 void ajouterPanne(int refmachine, machine tm[], int n, panne pa){
     int i,v,e=-1;
     v=rechercherMach(tm,n,refmachine);
     if(v==-1){
        printf("introuvable ! reessayer \n");
     }
     else{
        for (i=0;i<10 && e==-1;i++){
            if (strcmp(tm[v].p[i].refpanne,"")==0){
                tm[v].p[i]=pa;
                printf("Panne ajoutee avec succes à la machine %d\n",refmachine);
                e=1;
            }
        }
     }
 }
 int totalPanne(int refmachine, machine tm[], int n) {
     int i,s=0,v;
     v=rechercherMach(tm,n,refmachine);
   if(v==-1){
    return -1;
   }
   else{
    for (i=0;i<10;i++){
        if(strcmp(tm[v].p[i].refpanne,"")!=0){
            s++;
        }
    }
   }
   return s;
 }
  void modifier_etat_panne (int refmachine, machine tm[], int n) {
      int i,v;
      v=rechercherMach(tm,n,refmachine);
      if(v==-1){
        printf("introuvavle");
      }
      else{
        for (i=0;i<10;i++){
            if(tm[v].p[i].etat==0){
                tm[v].p[i].etat=1;
            }
        }
      }


  }
 void afficher (int n, machine tm[],int refmachine) {
     int i,v;
     v=rechercherMach(tm,n,refmachine);
     if(v==-1){
        printf("introuvavle");
      }
      else{
       printf("les pannes de la machine de reference %d est : \n",refmachine);
       for (i=0;i<10;i++){
        if (strcmp(tm[v].p[i].refpanne,"")!=0){
             printf("refpanne : %s    etat :%d |",tm[v].p[i].refpanne,tm[v].p[i].etat);
       }printf("\n");
      }
        }

 }

  void trouver (machine tm[], int n, int *n_rep, int *n_nrep, int refmachine) {
       int i,v;
     v=rechercherMach(tm,n,refmachine);
     if(v==-1){
        printf("introuvavle");
      }
  else
    {
        i=0;

        while(i<10 &&strcmp(tm[v].p[i].refpanne,"")!=0)
        {
            if(tm[v].p[i].etat==0)
            {
                (*n_rep)++;
            }
            if(tm[v].p[i].etat==1)
            {
                (*n_nrep)++;
            }
            i++;
        }
    }

}
void supprimer(machine tm[], int *n) {
    int i, v, z, nbnonrep = 0, nbrep = 0, refmm;
    printf("donner la reference de la machine \n");
    scanf("%d", &refmm);
    z = totalPanne(refmm, tm, *n);
    v = rechercherMach(tm, *n, refmm);
    trouver(tm, *n, &nbrep, &nbnonrep, refmm);

    printf("nbrep: %d,nbnonrep: %d, z: %d\n", nbrep,nbnonrep, z);

    if (nbnonrep == z) {
        for (i = v; i < (*n - 1); i++) {
            tm[i] = tm[i + 1];
        }
        (*n)--;
        printf("Machine supprimee avec succes.\n");
    } else {
        printf("Impossible de supprimer la machine car certaines pannes ne sont pas reparees.\n");
    }
}
void supprimer2(machine tm[], int *n) {
    int i, j, z, nbrep = 0, nbnonrep = 0;

    for (i = 0; i < (*n); i++) {
        trouver(tm, *n, &nbrep, &nbnonrep, tm[i].refmachine);
        z = totalPanne(tm[i].refmachine, tm, *n);

        if (nbnonrep == z) {
            for (j = i; j < (*n - 1); j++) {
                tm[j] = tm[j + 1];
            }
            (*n)--;
            i--;  // Pour s'assurer que l'élément suivant est également vérifié
            printf("Suppression avec succès de la machine %d\n", tm[i].refmachine);
        }
    }
}

