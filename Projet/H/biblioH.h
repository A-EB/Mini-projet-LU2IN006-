#ifndef BIBLIOH_H
#define BIBLIOH_H

//Exercice 2 : Gestion d'une bibliothèque avec une table de hachage

//  Q-2.1

typedef struct livreh{
    int clef;
    int num;
    char* titre;
    char* auteur;
    struct livreh *suivant;
}LivreH;

typedef struct table {
    int nE;
    int m;
    LivreH** T;
}BiblioH;


int fonctionClef(char* auteur);

LivreH* creer_livreH(int num,char* titre,char* auteur);

void liberer_livreH(LivreH* l);

BiblioH* creer_biblioH(int m);

void liberer_biblioH(BiblioH* b);

int fonctionHachage(int cle, int m);

void inserer(BiblioH* b,int num,char* titre,char* auteur);

void affiche_livreH(LivreH *l);

void affiche_biblioH(BiblioH *b);

LivreH *recherche_numH(BiblioH *b,int num);

LivreH *recherche_titreH(BiblioH *b,char* titre);

BiblioH *recherche_auteurH(BiblioH *b , char* auteur);

void supprimerLivreH(BiblioH *b , int num , char* titre , char* auteur);

BiblioH* fusion_biblioH(BiblioH* b1 , BiblioH* b2);

LivreH* recherche_ouvrageH(BiblioH* b);

#endif