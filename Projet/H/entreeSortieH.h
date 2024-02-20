#ifndef ENTREESORTIEH_H
#define ENTREESORTIEH_H
#include "biblioH.h"

//Exercice 2 : Gestion d'une bibliothèque avec une table de hachage

//  Q-2.6

BiblioH* charger_n_entreesH(char* nomfic, int n, int dim);

void enregistrer_biblioH(BiblioH *b, char* nomfic);

#endif