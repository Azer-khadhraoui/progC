#include <stdio.h>
#include <string.h>

// Déclaration des structures
struct Personnel {
    char login[20];
    char password[20];
    char role[20];
};

// Déclaration des tableaux globaux
struct Personnel personnel[10];
int nombrePersonnel = 0;

// Fonction pour remplir le tableau de personnel
void remplirTableauPersonnel() {
    // Ajoutez ici des entrées pour le personnel selon les besoins
    strcpy(personnel[0].login, "admin");
    strcpy(personnel[0].password, "admin123");
    strcpy(personnel[0].role, "administrateur");
    nombrePersonnel++;

    strcpy(personnel[1].login, "agent1");
    strcpy(personnel[1].password, "agent123");
    strcpy(personnel[1].role, "agent");
    nombrePersonnel++;
}

// Fonction pour identifier le personnel
int identifierPersonnel(char login[], char password[]) {
    int i;
    for ( i = 0; i < nombrePersonnel; i++) {
        if (strcmp(personnel[i].login, login) == 0 && strcmp(personnel[i].password, password) == 0) {
            if (strcmp(personnel[i].role, "administrateur") == 0) {
                return 1;  // Administrateur
            } else if (strcmp(personnel[i].role, "agent") == 0) {
                return 2;  // Agent
            }
        }
    }
    return -1;  // Personnel n'existe pas
}

// Fonction pour le menu des administrateurs
void menuAdministrateur() {
    // Ajoutez ici le code pour les fonctionnalités de l'administrateur
    printf("Menu administrateur\n");
}

// Fonction pour le menu des agents
void menuAgent() {
    // Ajoutez ici le code pour les fonctionnalités de l'agent
    printf("Menu agent\n");
}

int main() {
    remplirTableauPersonnel();

    // Programme principal
    char login[20];
    char password[20];

    while (1) {
        printf("Login : ");
        scanf("%s", login);
        printf("Mot de passe : ");
        scanf("%s", password);

        int role = identifierPersonnel(login, password);

        if (role == 1) {  // Administrateur
            printf("Connecté en tant qu'administrateur.\n");
            menuAdministrateur();
        } else if (role == 2) {  // Agent
            printf("Connecté en tant qu'agent.\n");
            menuAgent();
        } else {
            printf("Personnel non trouvé. Veuillez réessayer.\n");
        }
    }

    return 0;
}
