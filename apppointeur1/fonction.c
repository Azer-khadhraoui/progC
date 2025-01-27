#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaration.h"

void saisir(machine *m)
{
    int i;
    printf("Donner la reference de la machine: ");
    scanf("%d", &(*m).refer);

    for ( i = 0; i < 10; i++)
    {

        strcpy((*m).liste[i].refer, "");
        (*m).liste[i].etat = 0;
    }
}

void ajouter(machine Tm[], machine m, int *n)
{
    if(*n <100)
    {
        Tm[*n] = m;
        (*n)++;
        printf("Machine ajoutee avec succes.\n");
    }
    else
    {
        printf("Le tableau de machines est plein !\n");
    }
}

int rechercherMach(machine Tm[], int n, int ref)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(Tm[i].refer == ref)
        {
            return i;
        }
    }

    return -1;
}
void saisirPanne(panne *p)
{
    printf("\nEntrez la reference de la panne: ");
    scanf("%s", &(*p).refer);

    printf("\nEntrez l'etat de la panne (1 reparee || 0 non): ");
    scanf("%d", &(*p).etat);
}

void ajouterPanne(int ref, machine Tm[], int n)
{
    int index = rechercherMach(Tm, n, ref);
    int i;

    if(index != -1)
    {
        panne nouvellePanne;
        printf("Ajout d'une panne à la machine %d :\n", ref);
        printf("----------------------------\n");
        printf("Informations de la panne :\n");
        saisirPanne(&nouvellePanne);

        for(i = 0; i < 10; i++)
        {
            if(Tm[index].liste[i].etat == 0)
            {
                Tm[index].liste[i] = nouvellePanne;
                printf("Panne ajoutee avec succes à la machine %d.\n", ref);
                return;
            }
        }

        printf("La liste des pannes de la machine %d est pleine, impossible d'ajouter une nouvelle panne.\n", ref);
    }
    else
    {
        printf("Machine avec la reference %d non trouvee, impossible d'ajouter une panne.\n", ref);
    }
}
int totalPanne(int ref, machine Tm[], int n) {
    int index = rechercherMach(Tm, n, ref);
    int i;

    if (index != -1) {
        int total = 0;

        for (i = 0; i < 10; i++) {
            if (strcmp(Tm[index].liste[i].refer, "") != 0) {
                total++;
            }
        }

        return total;
    } else {
        return -1;
    }
}

