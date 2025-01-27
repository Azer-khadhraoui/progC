#include <stdio.h>

struct Participant {
    char cin[10];
    char nom[50];
    char pre[50];
    int chd;   // Breakfast choice
    int chdi;  // Dinner choice
    int chh;   // Hotel choice
    int hotelChoice; // Store the chosen hotel option
};

int main() {
    struct Participant c[100]; // Assuming you will have up to 100 participants
    int choix = 0;
    int choix2;
    int i = 0;

    while (choix != 0) {
        do {
            printf("*************** Menu Principal ******************************\n");
            printf("*************** 0- Quitter **********************************\n");
            printf("*************** 1- Ajouter un participant *******************\n");
            printf("*************** 2- Calculer le montant de sa facture *********\n");
            printf("*************** 3- Afficher les informations du participant ****\n");
            printf("*************** 4- Supprimer un participant ********************\n");
            printf("********************************************************\n");
            printf("Donnez votre choix: ");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 4);

        if (choix == 1) {
            choix2 = 1;
            while (choix2 == 1 && i < 100) {
                printf("Donnez le numéro CIN: ");
                scanf("%s", c[i].cin);
                printf("Donnez le nom: ");
                scanf("%s", c[i].nom);
                printf("Donnez le prénom: ");
                scanf("%s", c[i].pre);
                printf("Voulez-vous un petit déjeuner (1-oui / 0-non) ? ");
                scanf("%d", &c[i].chd);
                printf("Voulez-vous un dîner (1-oui / 0-non) ? ");
                scanf("%d", &c[i].chdi);
                printf("Voulez-vous un hôtel (1-oui / 0-non) ? ");
                scanf("%d", &c[i].chh);
                if (c[i].chh == 1) {
                    printf("1- 4 étoiles // 2- 5 étoiles: ");
                    scanf("%d", &c[i].hotelChoice);
                }
                i++;

                printf("Voulez-vous ajouter une autre personne ? (1-oui / 2-non): ");
                scanf("%d", &choix2);
            }
        }
    }

    return 0;
}

