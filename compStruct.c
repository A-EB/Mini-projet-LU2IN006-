# include <stdio.h>
# include <stdlib.h>
# include "H/biblioH.h"
# include "H/entreeSortieH.h"
# include "LC/biblioLC.h"
# include "LC/entreeSortieLC.h"
# include <time.h>
 
// Fonctions utilitaires pour la mesure du temps
double temps_execution(clock_t debut, clock_t fin){
    return ((double)(fin - debut))*1000 / CLOCKS_PER_SEC;
} 

void clear_screen() {
    printf("\033[H\033[2J");
    fflush(stdout);
}

void menu(){
    printf("\n~~~~~~~~~~~~~~~~Veuillez choisir une des options proposées~~~~~~~~~~~~~~~~\n");
    printf("\n0 : Quitter le programme\n");
    printf("\n1 : Comparaison des fonctions LC et H\n");
    printf("\n2 : Comparaison des fonctions de recherche d'ouvrages\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// Fonction principale
int main(int argc , char** argv){
    int rep;
    do {
    menu();
    scanf (  "%d" ,&rep);
    switch (rep) {
        case 1:
            Biblio *bLC;
            // Ajoutez ici vos livres à la bibliothèque
            clock_t debut_charge_LC = clock();
            bLC = charger_n_entrees(argv[1] , atoi(argv[2]));
            clock_t fin_charge_LC = clock();
            double temps_charges_n_entreesLC = temps_execution(debut_charge_LC,fin_charge_LC);

            // Mesure du temps de recherche par numéro dans la structure de LC
            clock_t debut_liste_chaine_num = clock();
            Livre* l1 = recherche_num(bLC,2799);// la recherche par numéro dans la structure de LC
            clock_t fin_liste_chaine_num = clock();
            double temps_liste_chaine_num = temps_execution(debut_liste_chaine_num, fin_liste_chaine_num);

            clock_t debut_liste_chaine_num_NE = clock();
            recherche_num(bLC,3001); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_liste_chaine_num_NE = clock();
            double temps_liste_chaine_num_NE = temps_execution(debut_liste_chaine_num_NE,fin_liste_chaine_num_NE);

            // Mesure du temps de recherche par titre dans la structure de LC
            clock_t debut_liste_chaine_titre = clock();
            Livre* l2 = recherche_titre(bLC,"AVNMKEFZEEIJ");// la recherche par titre dans la structure de LC
            clock_t fin_liste_chaine_titre = clock();
            double temps_liste_chaine_titre = temps_execution(debut_liste_chaine_titre, fin_liste_chaine_titre);

            clock_t debut_liste_chaine_titre_NE = clock();
            recherche_titre(bLC,"SXONRMQNEMCO"); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_liste_chaine_titre_NE = clock();
            double temps_liste_chaine_titre_NE = temps_execution(debut_liste_chaine_titre_NE,fin_liste_chaine_titre_NE);

            // Mesure du temps de recherche par auteur dans la structure de LC
            clock_t debut_liste_chaine_auteur = clock();
            Biblio* b1 = recherche_auteur(bLC,"zgpikjpppmg");// la recherche par auteur dans la structure de LC
            clock_t fin_liste_chaine_auteur = clock();
            double temps_liste_chaine_auteur = temps_execution(debut_liste_chaine_auteur, fin_liste_chaine_auteur);

            clock_t debut_liste_chaine_auteur_NE = clock();
            Biblio* b2 = recherche_auteur(bLC,"fbxobpdt"); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_liste_chaine_auteur_NE = clock();
            double temps_liste_chaine_auteur_NE = temps_execution(debut_liste_chaine_auteur_NE, fin_liste_chaine_auteur_NE);


            // Création d'une bibliothèque avec une H


            BiblioH *bH;
            // Remplissage de la H avec les mêmes livres que ceux ajoutés à la bibliothèque
            clock_t debut_charge_H = clock();
            bH = charger_n_entreesH(argv[1] , atoi(argv[2]) , 100);
            clock_t fin_charge_H = clock();
            double temps_charges_n_entreesH = temps_execution(debut_charge_H,fin_charge_H);

            // Mesure du temps de recherche par numéro dans la structure de H
            clock_t debut_table_hachage_num = clock();
            LivreH* l3 = recherche_numH(bH,2799); // la recherche par numéro dans la structure de H
            clock_t fin_table_hachage_num = clock();
            double temps_table_hachage_num = temps_execution(debut_table_hachage_num, fin_table_hachage_num);

            clock_t debut_table_hachage_num_NE = clock();
            recherche_numH(bH,3001); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_table_hachage_num_NE = clock();
            double temps_table_hachage_num_NE = temps_execution(debut_table_hachage_num_NE,fin_table_hachage_num_NE);

            // Mesure du temps de recherche par titre dans la structure de H
            clock_t debut_table_hachage_titre = clock();
            LivreH* l4 = recherche_titreH(bH,"AVNMKEFZEEIJ");// la recherche par titre dans la structure de H
            clock_t fin_table_hachage_titre = clock();
            double temps_table_hachage_titre = temps_execution(debut_table_hachage_titre, fin_table_hachage_titre);

            clock_t debut_table_hachage_titre_NE = clock();
            recherche_titreH(bH,"SXONRMQNEMCO"); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_table_hachage_titre_NE = clock();
            double temps_table_hachage_titre_NE = temps_execution(debut_table_hachage_titre_NE,fin_table_hachage_titre_NE);

            // Mesure du temps de recherche par ouvrage dans la structure de H
            clock_t debut_table_hachage_auteur = clock();
            BiblioH* b3 = recherche_auteurH(bH,"zgpikjpppmg");// la recherche par auteur dans la structure de H
            clock_t fin_table_hachage_auteur = clock();
            double temps_table_hachage_auteur = temps_execution(debut_table_hachage_auteur, fin_table_hachage_auteur);

            clock_t debut_table_hachage_auteur_NE = clock();
            BiblioH* b4 = recherche_auteurH(bH,"fbxobpdt"); // ici nous avons fixé le nombre de ligne à 3000 donc 3001 n'existe pas
            clock_t fin_table_hachage_auteur_NE = clock();
            double temps_table_hachage_auteur_NE = temps_execution(debut_table_hachage_auteur_NE, fin_table_hachage_auteur_NE);


            // Affichage des résultats
            printf("\n---------------------------------\n");
            printf("Temps de chargement de fichier (LC) : %f ms\n", temps_charges_n_entreesLC);
            printf("Temps de chargement de fichier (H)  : %f ms\n", temps_charges_n_entreesH);
            printf("\n---------------------------------\n");
            printf("Temps de recherche par numéro (LC) : %f ms\n", temps_liste_chaine_num);
            printf("Temps de recherche par numéro(NE) (LC) : %f ms\n", temps_liste_chaine_num_NE);
            printf("Temps de recherche par numéro (H) : %f ms\n", temps_table_hachage_num);
            printf("Temps de recherche par numéro(NE) (H) : %f ms\n", temps_table_hachage_num_NE);
            printf("\n---------------------------------\n");
            printf("Temps de recherche par titre (LC) : %f ms\n", temps_liste_chaine_titre);
            printf("Temps de recherche par titre (NE) (LC) : %f ms\n", temps_liste_chaine_titre_NE);
            printf("Temps de recherche par titre (H) : %f ms\n", temps_table_hachage_titre);
            printf("Temps de recherche par titre (NE) (H) : %f ms\n", temps_table_hachage_titre_NE);
            printf("\n---------------------------------\n");
            printf("Temps de recherche par auteur (LC) : %f ms\n", temps_liste_chaine_auteur);
            printf("Temps de recherche par auteur (NE) (LC) : %f ms\n", temps_liste_chaine_auteur_NE);
            printf("Temps de recherche par auteur (H) : %f ms\n", temps_table_hachage_auteur);
            printf("Temps de recherche par auteur (NE) (H) : %f ms\n", temps_table_hachage_auteur_NE);
            printf("\n---------------------------------\n");
        // Création d'une bibliothèque avec un ensemble de livres

        liberer_livre(l1);
        liberer_livre(l2);
        liberer_livreH(l3);
        liberer_livreH(l4);
        liberer_biblio(b1);
        liberer_biblio(b2);
        liberer_biblioH(b3);
        liberer_biblioH(b4);
        liberer_biblio(bLC);
        liberer_biblioH(bH);

        break;
    case 2:
        FILE* fichier = fopen("resultats.txt", "w");
        if (fichier == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
        }

        for(int i=1000;i<=64000;i*=2){
            BiblioH *bHo;
            bHo=charger_n_entreesH(argv[1],i,50);
            Biblio *bLCo;
            bLCo=charger_n_entrees(argv[1] ,i);

            clock_t debut_table_hachage_ouvrage = clock();
            LivreH* loH=recherche_ouvrageH(bHo);
            clock_t fin_table_hachage_ouvrage = clock();
            double temps_table_hachage_ouvrage = temps_execution(debut_table_hachage_ouvrage, fin_table_hachage_ouvrage);

            clock_t debut_table_LC_ouvrage = clock();
            Livre* loLC=recherche_ouvrage(bLCo);
            clock_t fin_table_LC_ouvrage = clock();
            double temps_table_LC_ouvrage = temps_execution(debut_table_LC_ouvrage, fin_table_LC_ouvrage);

            printf("\n---------------------------------\n");
            printf("Temps de recherche ouvrage (LC) : %f ms\n", temps_table_LC_ouvrage);
            printf("Temps de recherche ouvrage (H) : %f ms\n", temps_table_hachage_ouvrage);
            printf("\n---------------------------------\n");

            fprintf(fichier,"%d %f %f\n",i,temps_table_LC_ouvrage,temps_table_hachage_ouvrage);

            liberer_livre(loLC);
            liberer_livreH(loH);
            liberer_biblio(bLCo);
            liberer_biblioH(bHo);
        }
        fclose(fichier);
        break;
    }
    } while (rep != 0);
    clear_screen();
    printf("Merci, et au revoir.\n");
    return 0;
}
