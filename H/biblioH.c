# include <stdio.h>
# include <stdlib.h>
# include "biblioH.h"
# include <math.h>
# include <string.h>

//Exercice 2 : Gestion d'une bibliothèque avec une table de hachage

//  Q-2.2

int fonctionClef(char* auteur){
    int res = 0;
    for(int i = 0 ; auteur[i] != '\0' ; i++){
        res += (int)auteur[i];
    }
    return res;
}

//  Q-2.3

LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH* l = malloc(sizeof(LivreH));
    if(!l){
        printf("Erreur d'allocation d'un Livre\n");
        exit(1);
    }
    l->clef = fonctionClef(auteur);
    l->num = num;
    l->titre = strdup(titre);
    l->auteur = strdup(auteur);
    l->suivant=NULL;
    return l;
}

void liberer_livreH(LivreH* l){
    while(l){
        LivreH* tmp = l;
        l = l->suivant;
        free(tmp->auteur);
        free(tmp->titre);
        free(tmp);
    }
    free(l);
}

BiblioH* creer_biblioH(int m){
    BiblioH* res = malloc(sizeof(BiblioH));
    res->nE = 0;
    res->m = m;
    res->T = malloc(m*sizeof(LivreH*));
    for (int i = 0; i < m; i++) {
        res->T[i] = NULL;
    }
    return res;
}

void liberer_biblioH(BiblioH* b){
    for(int i=0;i<b->m;i++){
        liberer_livreH(b->T[i]);
    }
    free(b->T);
    free(b);
}

//  Q-2.4

int fonctionHachage(int cle, int m){
    double a = (sqrt(5)-1)/2;
    return (int)(m*(cle*a-(int)(cle*a)));
}

//  Q-2.5

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    LivreH *l = creer_livreH(num, titre, auteur);
    int i = fonctionHachage(l->clef, b->m);
    l->suivant = b->T[i];
    b->T[i] = l;
    b->nE++;
}

//-------------------------------------------------------//

//  Q-2.6

void affiche_livreH(LivreH* livre) {
    while(livre){
        printf("Num : %d | Titre : %s | Auteur : %s \n",livre->num,livre->titre,livre->auteur);
        livre=livre->suivant;
        printf("\n");
    }
}

void affiche_biblioH(BiblioH* biblio) {
    for (int i = 0; i < biblio->m; i++) {
        if(biblio->T[i]){
            LivreH* courant = biblio->T[i];
            printf("Indice %d:\n", i);
            affiche_livreH(courant);
            printf("\n");
        }
    }
}

LivreH *recherche_numH(BiblioH *b,int num){
    for(int i = 0 ; i < b->m ; i++){
        LivreH* l = b->T[i];
        while(l){
            if(l->num == num){
                return l;
            }
            l = l->suivant;
        }
    }
    printf("Aucune oeuvre ne porte ce numero\n");
    return NULL;
}

LivreH *recherche_titreH(BiblioH *b,char* titre){
    for(int i = 0 ; i < b->m ; i++){
        LivreH* l = b->T[i];
        while(l){
            if(strcmp(l->titre,titre) == 0){
                return l;
            }
            l = l->suivant;
        }
    }
    printf("Aucune oeuvre ne porte ce titre\n");
    return NULL;
}

BiblioH *recherche_auteurH(BiblioH *b , char* auteur){
    BiblioH* res = creer_biblioH(b->m);
    int cleH = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH* l = b->T[cleH];
    while(l){
        if(strcmp(l->auteur,auteur)==0){
            inserer(res,l->num,l->titre,l->auteur);
        }
        l = l ->suivant;
    }
    return res;
}

void supprimerLivreH(BiblioH *b , int num , char* titre , char* auteur){
    int cleH = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH* l = b->T[cleH];
    
    if(strcmp(b->T[cleH]->titre , titre ) == 0 && (b->T[cleH]->num == num)){
        LivreH* tmp = b->T[cleH];
        b->T[cleH] = b->T[cleH]->suivant;
        free(tmp);
    }

    else{
        while(l->suivant){
            if(strcmp(l->suivant->titre,titre) == 0 && l->suivant->num==num){
                LivreH* tmp = l->suivant;
                l->suivant = l->suivant->suivant;
                free(tmp);
                break;
            }
            l = l->suivant;
        }
    }
}

BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2) {
    for (int i=0; i<b2->m; i++){
        LivreH *livre = b2->T[i];
        while (livre){
            if (!recherche_numH(b1, livre->num))
                inserer(b1, livre->num, livre->titre, livre->auteur);
            livre = livre->suivant;
        }
    } liberer_biblioH(b2);
    return b1;
}

LivreH* recherche_ouvrageH(BiblioH* b) {

    int *tab = malloc(sizeof(int)*(b->nE));
    for(int i = 0 ; i < b->nE ; i++){
        tab[i] = 0;
    }

    LivreH* res=NULL, *l1=NULL, *l2=NULL;
        for(int i=0;i<b->m;i++){
            l1 = b->T[i];
            int cpt=0; // compteur pour le premier livre qu'on trouve 
            while(l1){
                l2 = l1->suivant;
                while(l2){
                    if((strcmp(l2->auteur,l1->auteur) == 0) && (strcmp(l2->titre,l1->titre) == 0)){
                        if(tab[l2->num] == 0){
                            if(cpt==0){
                                LivreH *tmp = creer_livreH(l1->num,l1->titre,l1->auteur);
                                tmp->suivant = res;
                                res = tmp;
                                tab[l1->num] = 1;
                                cpt++;
                            }
                            LivreH *tmp = creer_livreH(l2->num,l2->titre,l2->auteur);
                            tmp->suivant = res;
                            res = tmp;
                            tab[l2->num] = 1;
                        }
                    }
                    l2 = l2->suivant;
                }
                l1 = l1->suivant;
            }
        }
        free(tab);
    return res;
}