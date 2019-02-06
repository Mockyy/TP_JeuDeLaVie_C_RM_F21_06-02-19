#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

#define TAILLE 20
///STRUCT
typedef enum cellule{morte, vivante} Cellule;

///PROTO

///Initalisation du tableau
extern void initTab(Cellule tTab[][TAILLE]);

///Recherche si la cellule est vivante ou morte -> renvoie une cellule
extern Cellule rechercheVie(Cellule tTab[][TAILLE],const int i,const int j);

///Compte les voisins vivants -> renvoie un entier
extern int voisinnage(Cellule tTab[][TAILLE], const int i, const int j);

///Renvoie le prochain etat d'une cellule vivante
extern Cellule nouvelEtatVivante(int nCptVoisin);

///Renvoie le prochain etat d'unce cellule morte
extern Cellule nouvelEtatMorte(int nCptVoisin);

///Passe à la génération suivante -> renvoie une copie du tableau à génération+1
extern void vie(Cellule tTab[][TAILLE], Cellule tCopieTab[][TAILLE]);

///Copie la copie du tableau dans le tableau principal
extern void copieVie(Cellule tTab[][TAILLE], Cellule tCopieTab[][TAILLE]);

///Compte le nombre de cellules vivantes
int recensement(Cellule tTab[][TAILLE]);

#endif // CELLULE_H_INCLUDED
