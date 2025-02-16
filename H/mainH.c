# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "biblioH.h"
# include "entreeSortieH.h"

void menu(){
    printf("\n~~~~~~~~~~~~~~~~Veuillez choisir une des options proposées~~~~~~~~~~~~~~~~\n");

    printf("\n0 : Quitter le programme\n");
    printf("1 : Affichage de la Bibliothèque\n");
    printf("2 : Inserer un ouvrage dans la Bibliothèque\n");
    printf("3 : Recherche des exemplaires d'un ouvrage\n");
    printf("4 : Suppression d'un examplaire\n");
    printf("5 : Fusion de deux Bibliothèques\n");
    printf("6 : Recherche par num\n");
    printf("7 : Recherche par titre\n");
    printf("8 : Recherche par auteur\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void clear_screen() {
    printf("\033[H\033[2J");
    fflush(stdout);
}

    //  Q-1.4
int main(int argc , char** argv){
    BiblioH* b1 = charger_n_entreesH(argv[1] , atoi(argv[2]), 50);
    BiblioH* b2 = charger_n_entreesH(argv[3] , atoi(argv[4]), 50);
int rep;
do {
    menu();
    scanf (  "%d" ,&rep);
    switch (rep) {
        case 1:
            clear_screen();

            printf("Affichage :\n");
            affiche_biblioH(b1);

            break;
        case 2:
            int num;
            char titre[256];
            char auteur[256];
            clear_screen();

            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage.\n");
            if (scanf("%d %s %s", &num, titre, auteur) == 3) {
                clear_screen();
                inserer(b1, num, titre, auteur);
                printf("Ajout fait.\n");
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 3:
            affiche_livreH(recherche_ouvrageH(b1));
            break;
        case 4:
            int nu;
            char ti[256];
            char au[256];
            clear_screen();

            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage.\n");
            if (scanf("%d %s %s", &nu, ti, au) == 3) {
                supprimerLivreH(b1,nu,ti,au);
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 5:
            clear_screen();

            printf("Fusion des deux Bibliothèques\n");
            affiche_biblioH(fusion_biblioH(b1,b2));

            break;
        case 6:
            int nume;
            clear_screen();

            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            if (scanf("%d", &nume) == 1) {
                LivreH* l = recherche_numH(b1,nume);
                printf("Num : %d | Titre : %s | Auteur : %s \n",l->num,l->titre,l->auteur);

            } else {
                printf("Erreur de format\n");
            }
            break;
        case 7:
            char titr[256];
            clear_screen();

            printf("Veuillez écrire le titre de l'ouvrage.\n");
            if (scanf("%s",titr) == 1) {
                LivreH* l = recherche_titreH(b1,titr);
                printf("Num : %d | Titre : %s | Auteur : %s \n",l->num,l->titre,l->auteur);

            } else {
                printf("Erreur de format\n");
            }
            break;
        case 8:
            char aut[256];
            clear_screen();

            printf("Veuillez écrire l'auteur de l'ouvrage.\n");
            if (scanf("%s",aut) == 1) {
                affiche_biblioH(recherche_auteurH(b1,aut));

            } else {
                printf("Erreur de format\n");
            }
            break;
    }
} while (rep != 0);
clear_screen();
printf("Merci, et au revoir.\n");
return 0;
}