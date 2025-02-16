#ifndef BIBLIOLC_H
#define BIBLIOLC_H

//  Exercice 1 : Gestion d'une bibliothèque avec une liste chaînée de struct    //
//  Q-1.1
typedef struct livre {
    int num ;
    char * titre ;
    char * auteur ;
    struct livre * suiv ;
}Livre ;

typedef struct { /* Tete fictive */
    Livre * L ; /* Premier element */
}Biblio ;

Livre* creer_livre(int num,char* titre,char* auteur);

void liberer_livre(Livre* l);

Biblio* creer_biblio();

void liberer_biblio(Biblio* b);

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);

void affiche_livre(Livre *l);

void affiche_biblio(Biblio *b);

Livre* recherche_num(Biblio *b,int num);

Livre* recherche_titre(Biblio *b,char* titre);

Biblio* recherche_auteur(Biblio *b , char* auteur);

void supprimerLivre(Biblio *b , int num , char* titre , char* auteur);

Biblio* fusion_biblio(Biblio* b1 , Biblio* b2);

Livre *recherche_ouvrage(Biblio *b);

#endif