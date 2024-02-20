#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieH.h"
#include "biblioH.h"

//Exercice 2 : Gestion d'une bibliothèque avec une table de hachage

//  Q-2.6

BiblioH* charger_n_entreesH(char* nomfic, int n, int dim){
    FILE *fichier = fopen(nomfic,"r");
    if (fichier==NULL){
        printf("Erreur a l'ouverture du fichier txt\n");
        exit(1);
    }
    BiblioH *b = creer_biblioH(dim);
    int num;
    char titre[100], auteur[100];

    for (int i = 0; i < n; i++) {
        fscanf(fichier, "%d %s %s", &num, titre, auteur);
        inserer(b, num, titre, auteur);
    }
    fclose(fichier);
    return b;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic) {
    FILE *fichier = fopen(nomfic, "w");
        if (fichier == NULL) {
            printf("Erreur a l'ouverture du fichier txt");
            exit(1);
        }

        for(int i = 0 ; i < b->m ; i++){
            LivreH* l = b->T[i];
            while (l != NULL) {
            fprintf(fichier, "%d %s %s\n", l->num, l->titre, l->auteur);
            l = l->suivant;
            }
        }

        fclose(fichier);
}

