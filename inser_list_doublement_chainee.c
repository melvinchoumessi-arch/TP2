#include<stdio.h>
#include<stdlib.h>

typedef struct liste{
    int val;
    struct liste *suiv;
    struct liste *pre;
    
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
        
        if ((*l) == NULL)
        {
            p = (Liste)malloc(sizeof(struct liste));
            p->val = el;
            (*l) = p;
            (*l)->suiv = NULL;
            (*l)->pre = NULL;
        }else{
            p->suiv = (Liste)malloc(sizeof(struct liste));
            p->suiv->pre = p->suiv;
            p = p->suiv;
            p->val = el;
        }     


    }

    p->suiv = NULL;
}


void afficher_liste(Liste l){

    Liste p ;
    p=l;
    printf("\n\t o|<->|");
    while (p != NULL) 
    {
       printf(" %d |<->|",p->val);
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


/*void destruction_de_liste(Liste l){

    if (l != NULL){   
    
    while (l->suiv != NULL)
    {
        l = l->suiv;
        free(l->pre);
    }
    free(l);
    
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
