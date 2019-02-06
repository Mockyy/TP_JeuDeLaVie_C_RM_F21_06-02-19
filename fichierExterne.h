#ifndef FICHIEREXTERNE_H_INCLUDED
#define FICHIEREXTERNE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


///Ecrire la génération et le nombre de cellules morte et vivantes
extern void ecrireFichier(Cellule tTab[][TAILLE], int nCpt, FILE* fichier);

///Reinitialise les logs
extern void razFichier(FILE* fichier);

///Affiche les logs
extern void lireFichier(FILE* fichier);

///Sauvegarder l'état du tableau
extern void sauvegarde(FILE* fichier, Cellule tTab[][TAILLE]);

///Charger la sauvegarde
extern void charger(FILE* fichier, Cellule tTab[][TAILLE]);

#endif // FICHIEREXTERNE_H_INCLUDED
