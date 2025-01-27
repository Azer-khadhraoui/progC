#include <stdio.h>
#include <stdlib.h>
#include"declaration.h"


int main()
{
    int choix,i;
    char nomFichier[] = "voyageurs.bin";
    int  nbVoyageursPresent;
    voyageur *listeVoyageurs = NULL;
    listeVoyageurs = charger_donnees(nomFichier, &nbVoyageursPresent);
    do
    {
        do
        {
            printf("***************Menu Principal ******************************\n");
            printf("*************** 0-Quitter **********************************\n");
            printf("*************** 1-  ajouter************************\n");
            printf("*************** 2- afficher*****************\n");
            printf("*************** 3- supprimer**************************\n");
            printf("*************** 4-  sauvegarder_donnees*************************\n");
            printf("*************** 5- quitter******************\n");
            printf("*************** 6-  **********************************\n");
            printf("*************** 7-  *****************************\n");
            printf("*************** 8- **********************************\n");
            printf("*************** 9- *****************************\n");

            printf("donner votre choix\n");
            scanf("%d",&choix);


        }
        while(choix<0||choix>5);
         switch (choix) {
            case 1:
                {
                    voyageur v;
                    saisirVoyageur(&v);
                    listeVoyageurs = ajouter(v, listeVoyageurs, &nbVoyageursPresent);
                    break;
                }
            case 2:

                printf("Liste des voyageurs :\n");
                for (i = 0; i < nbVoyageursPresent; i++) {
                    printf("Voyageur %d :\n", i+1);
                    printf("Identifiant: %s\n", listeVoyageurs[i].id);
                    printf("Nom: %s\n", listeVoyageurs[i].nom);
                    printf("Adresse: %s\n", listeVoyageurs[i].ad);
                    printf("Nombre de voyages: %d\n\n", listeVoyageurs[i].nbv);
                }
                break;
            case 3:
                {
                    char id[20];
                    printf("Identifiant du voyageur à supprimer: ");
                    scanf("%s", id);
                    supprimer(listeVoyageurs, id, &nbVoyageursPresent);
                    break;
                }
            case 4:
                sauvegarder_donnees(nomFichier, listeVoyageurs, nbVoyageursPresent);
                printf("Données sauvegardées avec succès.\n");
                break;
            case 5:
                printf("Quitter l'application...\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
        }


    }
    while(choix!=0);
    liberer(listeVoyageurs);
    return 0;
}

