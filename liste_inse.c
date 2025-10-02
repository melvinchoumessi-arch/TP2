#include<stdio.h>
#include<stdlib.h>

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
        p = (Liste)malloc(sizeof(struct liste));
        printf("\t Entrer l'element %d : ",i+1);
        scanf("%d",&el);
        p->val = el;
        p->suiv = *l;
        *l = p;
    }
    
}

void afficher_liste(Liste l){

    Liste p ;
    p=l;
    printf("\n\t|");
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

/*void insertion(Liste *l,int el){

    Liste t,p = *l;
    t = (Liste)malloc(sizeof(struct liste));
    t->val = el;
    if ((*l) = NULL || el > (*l)->val)
    {
        t->suiv = *l;
        *l = t;
    }else{ 
    
        while (p->suiv != NULL)
        {
            
            if (p->suiv->val < el)
            {
                t->suiv = p->suiv;
                p->suiv = t;
                return;

            }

            p = p->suiv;
            
        }
    }

    


}*/


int main(){

    Liste p,t, l=NULL;
    int el;

    creer_liste(&l);
    afficher_liste(l);
    p = l;
    printf("\n\t Entrer l'element a suprimer : ");
    scanf("%d",&el);
    
    while (p->suiv != NULL)
    {
       if (l->val == el)
       {
            l = l->suiv;
            free(p);
            p = l;

       }
       if (p->suiv->val == el){
            t = p->suiv;
            p->suiv = p->suiv->suiv;
            free(t);
       }else{
            p = p->suiv;
       }
         
    } 
    


    afficher_liste(l);
    destruction_de_liste(l);
    return 0;
}
