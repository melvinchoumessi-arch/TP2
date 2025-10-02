#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int valeur;
    struct cellule* suiv;
} cellule;

cellule* creationCellule(int val) {
    cellule* nouveau = (cellule*)malloc(sizeof(cellule));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    nouveau->valeur = val;
    nouveau->suiv = NULL;
    return nouveau;
}

void insererTete(cellule** tete, int valeur) {
    cellule* nouveau = creationCellule(valeur);
    if (*tete == NULL) {
        *tete = nouveau;
        nouveau->suiv = nouveau;
    } else {
        cellule* p = *tete;
        while (p->suiv != *tete) {
            p = p->suiv;
        }
        nouveau->suiv = *tete;
        p->suiv = nouveau;
        *tete = nouveau;
    }
}

void insererQueue(cellule** tete, int valeur) {
    cellule* nouveau = creationCellule(valeur);
    if (*tete == NULL) {
        *tete = nouveau;
        nouveau->suiv = nouveau;
    } else {
        cellule* p = *tete;
        while (p->suiv != *tete) {
            p = p->suiv;
        }
        p->suiv = nouveau;
        nouveau->suiv = *tete;
    }
   }
   
void afficherListe(cellule* tete) {
    if (tete == NULL) {
        printf("Liste vide.\n");
        return;
    }

    cellule* p = tete;
    printf("Liste actuelle :\n");
    do {
        printf("%d -> ", p->valeur);
        p = p->suiv;
    } while (p != tete);
    printf("(retour à la tête)\n");
}

int main() {
    cellule* maListe = NULL;
    int choix, valeur, n, i;

    printf(" Gestion d'une liste simplement chaînée circulaire \n");

    do {
        printf("\nQue voulez-vous faire ?\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Combien de valeurs voulez-vous insérer en tête ? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Entrez la valeur %d : ", i + 1);
                    scanf("%d", &valeur);
                    insererTete(&maListe, valeur);
                }
                break;

            case 2:
                printf("Combien de valeurs voulez-vous insérer en queue ? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Entrez la valeur %d : ", i + 1);
                    scanf("%d", &valeur);
                    insererQueue(&maListe, valeur);
                }
                break;

            case 3:
                afficherListe(maListe);
                break;

            case 0:
                printf("Fermeture du programme.\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 0);

    return 0;
}