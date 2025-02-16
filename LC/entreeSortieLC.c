#include <stdlib.h>
#include <stdio.h>
#include "entreeSortieLC.h"
#include "biblioLC.h"

//  Q-1.3

// Fonction pour charger les n premières entrées d'un fichier texte dans une bibliothèque
Biblio* charger_n_entrees(char* nomfic, int n){
    FILE *fichier = fopen(nomfic,"r");  // Ouvrir le fichier en mode lecture
    if (fichier==NULL){
        printf("Erreur a l'ouverture du fichier txt\n");
        exit(1);
    }
    Biblio *b = creer_biblio(); // Créer une nouvelle bibliothèque vide
    int num;
    char titre[100], auteur[100];

    // Lire les n premières entrées du fichier et les ajouter à la bibliothèque
    for (int i = 0; i < n; ++i) {
        fscanf(fichier, "%d %s %s", &num, titre, auteur);
        inserer_en_tete(b, num, titre, auteur);
    }
    fclose(fichier);    // Fermer le fichier après lecture
    return b;
}

// Fonction pour enregistrer une bibliothèque dans un fichier texte
void enregistrer_biblio(Biblio *b, char* nomfic) {
    FILE *fichier = fopen(nomfic, "w"); // Ouvrir le fichier en mode écriture
        if (fichier == NULL) {
            printf("Erreur a l'ouverture du fichier txt");
            exit(1);
        }

        Livre *l = b->L;
        // Parcourir la bibliothèque et écrire les détails de chaque livre dans le fichier
        while (l != NULL) {
            fprintf(fichier, "%d %s %s\n", l->num, l->titre, l->auteur);
            l = l->suiv;
        }

        fclose(fichier);    // Fermer le fichier après écriture
}