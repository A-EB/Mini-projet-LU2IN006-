#include "biblioLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//  Exercice 1 : Gestion d'une bibliothèque avec une liste chaînée de struct  //
//  Q-1.2 :

//          Creation d'un livre
Livre* creer_livre(int num,char* titre,char* auteur){
    Livre *l = (Livre *)malloc(sizeof(Livre));      // Allouer de la mémoire pour le livre
    if(!l){
        printf("Erreur d'allocation d'un Livre\n");
        exit(1);    // Quitter le programme si l'allocation échoue
    }
    l->num = num;                   // Définir le numéro du livre 
    l->titre = strdup(titre);       // Copier et définir le titre du livre
    l->auteur = strdup(auteur);     // Copier et définir le nom de l'auteur
    l->suiv=NULL;                   // Définir le suivant comme NULL
    return l;
}

//          Liberation d'un livre
void liberer_livre(Livre* l){
    while(l){               // Parcourir la liste tant que le pointeur n'est pas NULL
        free(l->titre);     // Libérer la mémoire allouée pour le titre et l'auteur du livre
        free(l->auteur);
        Livre * temp = l;   // Stocker le pointeur actuel dans une variable temporaire temp
        l=l->suiv;      
        free(temp);         // Libérer la mémoire allouée pour la variable temporaire 
    }
    free(l);
}

//          Creation d'une bibliothèque
Biblio* creer_biblio(){
    Biblio *b = (Biblio *)malloc(sizeof(Biblio));       // Allouer de la mémoire pour la bibliothèque
    if(!b){
        printf("Erreur d'allocation d'un Biblio\n");
        exit(1);    // Quitter le programme si l'allocation échoue
    }
    b->L=NULL;
    return b;
}

//          Liberation d'une bibliothèque
void liberer_biblio(Biblio* b){
    liberer_livre(b->L); // Liberation de livre avant la liberation de bibliothèque
    free(b);
}

//          Insertion en tete d'un livre dans une bibliothèque
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre *new_l = creer_livre(num,titre,auteur);   // Creation d'un livre
    if(!new_l){
        printf("Erreur d'allocation du nouveau livre\n");
        exit(1);        // Quitter le programme si la creation échoue
    }
    new_l->suiv = b->L; // Le nouveau livre pointe vers l'ancien premier livre de la bibliothèque
    b->L = new_l;       // La tête de la bibliothèque pointe maintenant vers le nouveau livre
}

//  Q-1.6:

//          Affichage d'un livre
void affiche_livre(Livre *l){
    Livre* tmpl = l;
    while(tmpl){
        printf("Num : %d | Titre : %s | Auteur : %s \n",tmpl->num,tmpl->titre,tmpl->auteur);
        tmpl = tmpl->suiv;
    }
}

//          Affichage d'une bibliothèque
void affiche_biblio(Biblio *b){
    Livre* tmp = b->L;
    while(tmp){
        printf("Num : %d | Titre : %s | Auteur : %s \n",tmp->num,tmp->titre,tmp->auteur);
        tmp=tmp->suiv;
    }
}

//          Recherche d'un livre à partir de son numéro
Livre *recherche_num(Biblio *b,int num){
    Livre* res;
    Livre *l = b->L;
    while(l){
        if(l->num == num){
            res = creer_livre(l->num,l->titre,l->auteur);
            return res;
        }
        l=l->suiv;
    }
    printf("Aucun livre avec çe numéro");
    return NULL;
}

//          Recherche d'un livre à partir de son titre
Livre *recherche_titre(Biblio *b,char* titre){
    Livre* res;
    Livre *l = b->L;
    while(l){
        if(strcmp(l->titre,titre) == 0){
            res = creer_livre(l->num,l->titre,l->auteur);
            return res;
        }
        l=l->suiv;
    }
    printf("Aucun livre avec çe titre");
    return NULL;
}

//          Recherche d'un livre à partir de son auteur
Biblio *recherche_auteur(Biblio *b , char* auteur){
    Biblio *res = creer_biblio();
    res->L = NULL;
    Livre *l = b->L;
    while(l){
        if(strcmp(l->auteur,auteur) == 0){
            inserer_en_tete(res,l->num,l->titre,l->auteur);
            return res;
        }
        l = l->suiv;
    }
    liberer_biblio(res);
    printf("Aucun livre avec cet auteur");
    return NULL;
}

//          Supression d'un livre d'une bibliothèque
void supprimerLivre(Biblio *b , int num , char* titre , char* auteur){
    if ((strcmp(b->L->titre, titre) == 0) && (strcmp(b->L->auteur, auteur) == 0) && (b->L->num == num)) { //    Si le livre à supprimer est à la tête de la liste
        Livre* tmp = b->L;
        b->L = b->L->suiv;
        free(tmp); // Libérer la mémoire du livre supprimé
    }else{
        Livre* l1 = b->L;
        while(l1->suiv){ // Parcours de la liste
            if((strcmp(l1->suiv->titre,titre) == 0) && (strcmp(l1->suiv->auteur,auteur)== 0) && l1->suiv->num == num){
                Livre* tmp = l1->suiv;
                l1->suiv = l1->suiv->suiv;
                free(tmp);
            }
            l1 = l1->suiv;
        }
    }
}

//          Fusion de deux Bibliothéques
Biblio* fusion_biblio(Biblio* b1 , Biblio* b2){
    Livre* l = b1->L;
    Livre* debut = b2->L;
    Livre* resL = creer_livre(debut->num,debut->titre,debut->auteur);
    debut = debut->suiv;
    while(debut){
        Livre* tmp = creer_livre(debut->num,debut->titre,debut->auteur);
        tmp->suiv = resL;
        resL = tmp;
        debut = debut->suiv;
    }
    while(l->suiv)
        l = l->suiv;
    l->suiv = resL;
    liberer_biblio(b2);
    return b1;
}

//          Recherche des ouvrages avec plusieurs examplaires
Livre* recherche_ouvrage(Biblio *b) {
    Livre *l1 = b->L;
    int taille = 0;
    while(l1){
        taille++;
        l1 = l1->suiv;
    }

    int *tab = malloc(sizeof(int)*taille);
    for(int i = 0 ; i < taille ; i++){
        tab[i] = 0;
    }

    Livre *l2 = b->L;
    Livre *res = NULL;

    while(l2){
        Livre *l3 = b->L;
        while(l3){
            if(l2->num != l3->num &&strcmp(l2->auteur,l3->auteur) == 0 && strcmp(l2->titre,l3->titre) == 0){
                if(tab[l3->num] == 0){
                    Livre *tmp = creer_livre(l3->num,l3->titre,l3->auteur);
                    tmp->suiv = res;
                    res = tmp;
                    tab[l3->num] = 1; // on le rend egale a 1 pour ne pas doubler son occurence 
                }
            }
            l3 = l3->suiv;
        }
        l2 = l2->suiv;
    }
    free(tab);
    return res;
}