#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch[100], listemot[20];
    int i, choix, l, nbmot;

    printf("donner ch \n");
    fflush(stdin);
    fgets(ch, sizeof(ch), stdin);  // Remplace gets() par fgets()

    l = strlen(ch);

    do {
        printf("1: afficher les mots de la phrase\n");
        printf("2: afficher les voyelles et leur nombre dans un mot\n");
        printf("3: construire une phrase\n");
        printf("----------------------------\n");
        printf("saisir votre choix\n");
        scanf("%d", &choix);
    } while ((choix < 1) || (choix > 3));

    if (choix == 1) {
        i = 0;
        nbmot = 0;
        int mot_len = 0;

        while (i < l) {
            if ((ch[i] != '.') && (ch[i] != ' ') && (ch[i] != '\n')) {
                listemot[mot_len] = ch[i];
                mot_len++;
            } else {
                if (mot_len > 0) {
                    listemot[mot_len] = '\0';  // Fin de la chaîne
                    printf("Mot %d: %s\n", nbmot+1, listemot);
                    nbmot++;
                    mot_len = 0;
                }
            }
            i++;
        }

        if (mot_len > 0) {
            listemot[mot_len] = '\0';  // Si le dernier mot n'est pas suivi d'un espace, d'un point ou d'une nouvelle ligne.
            printf("Mot %d: %s\n", nbmot+1, listemot);
            nbmot++;
        }

        printf("Nombre total de mots: %d\n", nbmot);
    }

    // Notez que je n'ai pas implémenté les choix 2 et 3 car ils n'étaient pas présents dans le code d'origine.
    return 0;
}

