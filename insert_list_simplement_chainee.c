#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
    int val;
    struct liste *suiv;
}*Liste;

void creer_liste(Liste *l){
    int el,n,i;
    Liste p;
    printf("\t Entrer le nombre d'element de la liste : ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("\t Entrer l'element %d : ",i+1);
        scanf("%d",&el);

        if((*l) == NULL){
            (*l) = (Liste)malloc(sizeof(struct liste));
            (*l)->val = el;
            (*l)->suiv = NULL;
            p = *l;
        }else{ 
        p->suiv = (Liste)malloc(sizeof(struct liste));
        p = p->suiv;
        p->val = el;
        p->suiv = NULL;

        }

    }
        
}

void afficher_liste(Liste l){

    Liste p ;
    p=l;
    printf("\n\t |");
    while (p != NULL) 
    {
       printf("%d|->|",p->val);
       p =p->suiv; 
    }
    printf("o\n");
    

}

void destruction_de_liste(Liste l){
    Liste p = l;
    while (p != NULL)
    {
        l = l->suiv;
        free(p);
        p = l;
    }
    
}

void insertion(Liste *l,int el){

    Liste t,p = *l;
    t = (Liste)malloc(sizeof(struct liste));
    t->val = el;
    if ((*l) == NULL || el < (*l)->val)
    {
        t->suiv = *l;
        *l = t;
    }else{ 
    
        while (p->suiv != NULL)
        {
            
            if (p->suiv->val > el)
            {
                t->suiv = p->suiv;
                p->suiv = t;
                return;

            }

            p = p->suiv;
            
            
        }
        p->suiv = t;
        t->suiv = NULL;
    }
}

int main(){

    Liste p,t, l=NULL;
    int el;

    creer_liste(&l);
    afficher_liste(l);

    p = l;
    printf("\n\t Entrer l'element a inserer : ");
    scanf("%d",&el);
    
   insertion(&l,el);
    


    afficher_liste(l);
    destruction_de_liste(l);
    return 0;
}
