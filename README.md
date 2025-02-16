# 📚 Gestion d'une Bibliothèque - Mini-Projet 2 (LU2IN006)

## 📝 Description
Ce projet consiste à implémenter une gestion de bibliothèque en utilisant deux structures de données : 
1. Une liste simplement chaînée.
2. Une table de hachage.

L'objectif est d'apprendre à manipuler ces structures et à comparer leurs performances.

## 📂 Structure du projet

- `biblioLC.h` : Déclaration des fonctions et structures pour la gestion avec une liste chaînée.
- `biblioLC.c` : Implémentation des fonctions pour la gestion avec une liste chaînée.
- `biblioH.h` : Déclaration des fonctions et structures pour la gestion avec une table de hachage.
- `biblioH.c` : Implémentation des fonctions pour la gestion avec une table de hachage.
- `entreeSortieLC.h` : Déclaration des fonctions de gestion des fichiers.
- `entreeSortieLC.c` : Implémentation des fonctions de gestion des fichiers.
- `main.c` : Programme principal avec une interface en ligne de commande.
- `Makefile` : Automatisation de la compilation.
- `README.md` : Ce fichier.

## ⚙️ Compilation
Pour compiler le projet, utilisez la commande :
```sh
make
```
Cela générera un exécutable `main`.

## 🚀 Exécution
L'exécution du programme se fait avec la commande :
```sh
./main GdeBiblio.txt 100
```
Cela charge les 100 premières entrées du fichier `GdeBiblio.txt`.

## 🔍 Fonctionnalités
Le programme permet :
- D'afficher la bibliothèque.
- D'ajouter un livre.
- De rechercher un livre par numéro, titre ou auteur.
- De supprimer un livre.
- De fusionner deux bibliothèques.
- De détecter les ouvrages avec plusieurs exemplaires.

## 📊 Comparaison des performances
Un troisième fichier compStruct consiste à comparer les performances des structures en mesurant les temps de recherche pour différentes tailles de bibliothèques.


