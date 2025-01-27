#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nom[20];
    char pre[20];
    int rdv;
}Patient;
typedef struct cellule{
    Patient pat;
    struct cellule *suivant;
}cellule;
typedef cellule *liste;
void saisirPatient(Patient *p);
void afficherPatient(Patient p);
void afficherPatient2(liste tete);
liste AjoutPatient(liste tete,Patient P);
void RendezVous ( liste tete, int *rdv, int *sansRdv );
void rechercherPatientParNom(liste tete, char *nom);
void modifierRendezVous(liste tete, char *nom, int nouveauStatut);
void afficherPatientsAvecRdv(liste tete);
liste SupprimePatient ( liste tete );
void sauvegarderPatients(liste tete,char *chemin);
liste recupererListePatients(liste tete,char *chemin);

int main()
{
    int choix,r=0,sr=0,nouveauStatut;
    char nom[20];
    char nom2[20];
    Patient p;
    liste tete=NULL;
    tete=recupererListePatients(tete,"fichier_patient.txt");
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajout ************************\n");
            printf("*************** 2- affichage *****************\n");
            printf("*************** 3- rdv **************************\n");
            printf("*************** 4- recherche*************************\n");
            printf("*************** 5-nouveauStatut ******************\n");
            printf("*************** 6-  rdv ou nn**********************************\n");
            printf("*************** 7-  supprimer*****************************\n");
            printf("*************** 8- sauvegarderPatients**********************************\n");
            printf("*************** 9- *****************************\n");
            printf("*************** 10- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);

        }
        while(choix<0||choix>10);
        if(choix==1){
            saisirPatient(&p);
            tete=AjoutPatient(tete,p);
        }
        if (choix==2){
            afficherPatient2(tete);
        }
        if (choix==3){
            RendezVous (tete,&r,&sr);
            printf("avec rdv : %d \n sans rdv : %d \n",r,sr);
        }
        if(choix==4){
            printf("nom = ");
            fflush(stdin);
            gets(nom);
            rechercherPatientParNom(tete,nom);
        }
        if(choix==5){
             printf("nom = ");
            fflush(stdin);
            gets(nom2);
             printf("nouveauStatut = ");
             scanf("%d",&nouveauStatut);
            modifierRendezVous(tete,nom2,nouveauStatut);
        }
        if(choix==6){
            afficherPatientsAvecRdv(tete);
        }
        if(choix==7){
            tete=SupprimePatient (tete);
        }
        if(choix==8){
            sauvegarderPatients(tete,"fichier_patient.txt");
        }



    }
    while(choix!=0);
    return 0;
}
void saisirPatient(Patient *p){
    printf("nom =");
    fflush(stdin);
    gets(p->nom);
    printf("prenom =");
    fflush(stdin);
    gets(p->pre);
    printf("rdv =");
    scanf("%d",&p->rdv);
}
void afficherPatient(Patient p){
    printf("nom = %s  \nprenom = %s \nrdv = %d \n",p.nom,p.pre,p.rdv);
}
liste AjoutPatient(liste tete,Patient P){
    cellule *nouv;
     cellule *parc;
    nouv=(cellule*)malloc(sizeof(cellule));
    nouv->pat=P;
    nouv->suivant=NULL;
    if(tete==NULL){
        tete=nouv;
    }
    else{
        parc=tete;
        while (parc->suivant!=NULL){
            parc=parc->suivant;

        }
        parc->suivant=nouv;
    }
    return tete;
}
void RendezVous ( liste tete, int *rdv, int *sansRdv ){
    cellule *parc=tete;
    *rdv=0;
    *sansRdv=0;
    while (parc!=NULL){
        if(parc->pat.rdv==1){
            (*rdv)++;
        }
        else{
            (*sansRdv)++;
        }
        parc=parc->suivant;
    }
}
void afficherPatient2(liste tete){
    cellule *parc=tete;
    while (parc!=NULL){
        afficherPatient(parc->pat);
        printf("\n");
        parc=parc->suivant;
    }
}
void rechercherPatientParNom(liste tete, char *nom){
    liste parc;
    parc=tete;
    while((parc!=NULL)&&(strcmp(parc->pat.nom,nom)!=0)){
        parc=parc->suivant;
    }
    if(parc==NULL){
        printf("introuvable !");

    }
    else{
        printf("se trouve \n");
    }
}
void modifierRendezVous(liste tete, char *nom, int nouveauStatut){
    liste parc;
    parc=tete;
    while((parc!=NULL)&&(strcmp(parc->pat.nom,nom)!=0)){
        parc=parc->suivant;
    }
    if(parc==NULL){
        printf("introuvable !");

    }
    else{
        parc->pat.rdv=nouveauStatut;
    }
}
void afficherPatientsAvecRdv(liste tete){
    liste parc=tete;
    while(parc!=NULL){
        if(parc->pat.rdv!=0){
            afficherPatient(parc->pat);
            printf("\n");

        }
        parc=parc->suivant;
    }
}
liste SupprimePatient ( liste tete ){
    liste parc=tete;
    liste pred=NULL;
    liste temp=tete;
    while ((parc!=NULL) && (parc->pat.rdv!=1)){
            pred=parc;
            parc=parc->suivant;

    }
    if (parc==NULL){

        tete=tete->suivant;
        free(temp);

    }
    else{
            if(pred!=NULL){
                pred->suivant=parc->suivant;
            }
            else{
                tete=tete->suivant;
            }

            free(parc);

    }
    return tete;
}
void sauvegarderPatients(liste tete,char *chemin){
    FILE *f=fopen(chemin,"w");
    liste parc=tete;
    if(f==NULL){
        printf("vide");
    }
    else{
       while (parc!=NULL){
        fprintf(f, " %s %s %d\n",parc->pat.nom,parc->pat.pre,parc->pat.rdv);
        parc=parc->suivant;
       }
    }
    fclose(f);
}
liste recupererListePatients(liste tete,char *chemin){
     FILE *f=fopen(chemin,"r");
     Patient pat;
    liste parc=tete;
    if(f==NULL){
        printf("vide");
    }
    else{
       while (fscanf(f, " %s %s %d\n",pat.nom,pat.pre,&pat.rdv)!=EOF){

        tete=AjoutPatient(tete,pat);

       }
    }
    fclose(f);
    return tete;
}
