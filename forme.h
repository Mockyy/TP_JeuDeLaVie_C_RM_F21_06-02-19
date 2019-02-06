#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED
#include "defineform.h"

///Choix forme
extern void choixForme(Cellule tTab[][TAILLE]);

///Forme random
extern void formeRandom(Cellule tTab[][TAILLE]);

///Clignotant
extern void clignotant(Cellule tTab[][TAILLE]);

///Crapaud
extern void crapaud(Cellule tTab[][TAILLE]);

///Planeur
extern void planeur(Cellule tTab[][TAILLE]);

///Galaxie de Kok
extern void galaxieDeKok(Cellule tTab[][TAILLE]);

///Octogone
extern void octogone(Cellule tTab[][TAILLE]);

#endif // FORME_H_INCLUDED
