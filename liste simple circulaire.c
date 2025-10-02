#include <stdio.h>
#include <stdlib.h>

// Définition d'une cellule (nœud) de la liste
typedef struct cellule {
    int val;
    struct cellule *suiv;
} cellule;

// Fonction d'insertion en tête
void insererTete(cellule **head, int valeur) {
    cellule *nouveau = (cellule*)malloc(sizeof(cellule));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveau->val = valeur;

    if (*head == NULL) {  // liste vide
        nouveau->suiv = nouveau;
        *head = nouveau;
    } else {
        cellule *temp = *head;
        // chercher le dernier élément
        while (temp->suiv != *head) {
            temp = temp->suiv;
        }
        nouveau->suiv = *head;
        temp->suiv = nouveau;
        *head = nouveau;  // mise à jour de la tête
    }
}

// Fonction d'insertion en queue
void insererQueue(cellule **head, int valeur) {
    cellule *nouveau = (cellule*)malloc(sizeof(cellule));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return;
    }
    nouveau->val = valeur;

    if (*head == NULL) { // liste vide
        nouveau->suiv = nouveau;
        *head = nouveau;
    } else {
        cellule *temp = *head;
        while (temp->suiv != *head) {
            temp = temp->suiv;
        }
        temp->suiv = nouveau;
        nouveau->suiv = *head;
    }
}

// Fonction d'affichage
void afficher(cellule *head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    cellule *temp = head;
    printf("Valeurs de la liste : ");
    do {
        printf("%d ", temp->val);
        temp = temp->suiv;
    } while (temp != head);
    printf("\n");
}

// Création initiale de la liste (l'utilisateur entre N valeurs)
void creerListe(cellule **head) {
    int n, val;
    printf("Combien de valeurs voulez-vous entrer dans la liste ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &val);
        insererQueue(head, val); // on construit la liste en ajoutant en queue
    }
    afficher(*head);
}

// Programme principal
int main() {
    cellule *liste = NULL;  // liste initialement vide
    int choix, valeur;

    printf("=== LISTE CHAINÉE CIRCULAIRE ===\n");

    // Création initiale de la liste
    creerListe(&liste);

    // Menu interactif
    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher les valeurs de la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur a inserer en tete : ");
                scanf("%d", &valeur);
                insererTete(&liste, valeur);
                afficher(liste);
                break;

            case 2:
                printf("Entrez la valeur a inserer en queue : ");
                scanf("%d", &valeur);
                insererQueue(&liste, valeur);
                afficher(liste);
                break;

            case 3:
                afficher(liste);
                break;

            case 0:
                printf("Programme termine.\n");
                break;

            default:
                printf("Choix invalide, reessayez.\n");
        }
    } while (choix != 0);

    return 0;
}