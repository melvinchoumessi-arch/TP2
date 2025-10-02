#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
    int val;
    struct liste* prec;
    struct liste* suiv;
} liste;

void insererQueue(liste** l, int val) {
    liste* p = (liste*)malloc(sizeof(liste));
    p->val = val;
    if (*l == NULL) {
        p->suiv = p;
        p->prec = p;
        *l = p;
    } else {
        liste* q = *l;
        p->suiv = q;
        p->prec = q->prec;
        q->prec->suiv = p;
        q->prec = p;
    }
}

void afficher(liste* l) {
    if (l == NULL) return;
    liste* p = l;
    do {
        printf("%d ", p->val);
        p = p->suiv;
    } while (p != l);
    printf("\n");
}

int main() {
    liste* l = NULL;
    int n, val;

    printf("entrer les valeurs initiales ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &val);
        insererQueue(&l, val);
    }

    printf("Liste avant insertion en queue : ");
    afficher(l);

    printf("Valeur à insérer en queue : ");
    scanf("%d", &val);
    insererQueue(&l, val);

    printf("Liste après insertion en tête : ");
    afficher(l);

    return 0;
}
