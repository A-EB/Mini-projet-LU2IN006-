# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "biblioLC.h"
# include "entreeSortieLC.h"

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

int main(int argc , char** argv){
    //  Q-1.4
    Biblio* b1 = charger_n_entrees(argv[1] , atoi(argv[2]));
    Biblio* b2 = charger_n_entrees(argv[3] , atoi(argv[4]));

int rep;
do {
    menu();
    scanf (  "%d" ,&rep);
    switch (rep) {
        case 1:
            clear_screen();

            printf("Affichage :\n");
            affiche_biblio(b1);

            sleep(5);
            break;
        case 2:
            int num;
            char titre[256];
            char auteur[256];
            clear_screen();

            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage.\n");
            /* On suppose que le titre et l’auteur ne contiennent pas d’espace */
            if (scanf("%d %s %s", &num, titre, auteur) == 3) {
                clear_screen();
                inserer_en_tete(b1, num, titre, auteur);
                printf("Ajout fait.\n");
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 3:
            affiche_livre(recherche_ouvrage(b1));
            break;
        case 4:
            int nu;
            char ti[256];
            char au[256];
            clear_screen();

            printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage.\n");
            if (scanf("%d %s %s", &nu, ti, au) == 3) {
                supprimerLivre(b1,nu,ti,au);
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 5:
            clear_screen();

            printf("Fusion des deux Bibliothèques\n");
            affiche_biblio(fusion_biblio(b1,b2));

            sleep(5);
            break;
        case 6:
            int nume;
            clear_screen();

            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            if (scanf("%d", &nume) == 1) {
                Livre* l = recherche_num(b1,nume);
                printf("Num : %d | Titre : %s | Auteur : %s \n",l->num,l->titre,l->auteur);
                sleep(5);
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 7:
            char titr[256];
            clear_screen();

            printf("Veuillez écrire le titre de l'ouvrage.\n");
            if (scanf("%s",titr) == 1) {
                Livre* l = recherche_titre(b1,titr);
                printf("Num : %d | Titre : %s | Auteur : %s \n",l->num,l->titre,l->auteur);
                sleep(5);
            } else {
                printf("Erreur de format\n");
            }
            break;
        case 8:
            char aut[256];
            clear_screen();

            printf("Veuillez écrire l'auteur de l'ouvrage.\n");
            if (scanf("%s",aut) == 1) {
                affiche_biblio(recherche_auteur(b1,aut));
                sleep(5);
            } else {
                printf("Erreur de format\n");
            }
            break;
    }
} while (rep != 0);
liberer_biblio(b1);
liberer_biblio(b2);
clear_screen();
printf("Merci, et au revoir.\n");
return 0;

}