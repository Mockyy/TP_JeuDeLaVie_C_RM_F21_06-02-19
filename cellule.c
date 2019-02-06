#include "defineform.h"

/************************
Principe : initialise le tableau avec des cellules mortes

Entrée : le tableau

Sortie : le tableau rempli de cellules mortes

Note :
***********************/
void initTab(Cellule tTab[][TAILLE]){

    int i = 0, j = 0;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            tTab[i][j]=morte;
        }
    }
}

/************************
Principe : renvoie si la cellule est vivante ou morte

Entrée : le tableau et deux indices

Sortie : une cellule

Note :
***********************/
Cellule rechercheVie(Cellule tTab[][TAILLE],const int i,const int j){

    if(tTab[i][j]==vivante){
        return vivante;
    }
    else{
        return morte;
    }
}

/************************
Principe : renvoie le nombre de voisins vivants

Entrée : le tableau et deux indices

Sortie : un entier

Note : essayer de trouver un moyen de réduire la fonction (avec une boucle)
***********************/
int voisinnage(Cellule tTab[][TAILLE], const int i, const int j){

    int nCptVoisin = 0;

    if(tTab[i-1][j-1]==vivante){
        nCptVoisin++;
    }
    if(tTab[i][j-1]==vivante){
        nCptVoisin++;
    }
    if(tTab[i+1][j-1]==vivante){
        nCptVoisin++;
    }
    if(tTab[i-1][j]==vivante){
        nCptVoisin++;
    }
    if(tTab[i+1][j]==vivante){
        nCptVoisin++;
    }
    if(tTab[i-1][j+1]==vivante){
        nCptVoisin++;
    }
    if(tTab[i][j+1]==vivante){
        nCptVoisin++;
    }
    if(tTab[i+1][j+1]==vivante){
        nCptVoisin++;
    }

    return nCptVoisin;
}

/************************
Principe : renvoie l'état d'une cellule vivante à la prochaine génération, selon ses voisins

Entrée : le nombre de voisins vivants

Sortie : la cellule

Note : essayer de fusionner nouvelEtatVivante et nouvelEtatMorte
***********************/
Cellule nouvelEtatVivante(int nCptVoisin){

    if((nCptVoisin==2) || (nCptVoisin==3)){
        return vivante;
    }
    else{
        return morte;
    }
}

/************************
Principe : renvoie l'état d'une cellule morte à la prochaine génération, selon ses voisins

Entrée : le nombre de voisins vivants

Sortie : la cellule

Note : essayer de fusionner nouvelEtatVivante et nouvelEtatMorte
***********************/
Cellule nouvelEtatMorte(int nCptVoisin){

    if(nCptVoisin==3){
        return vivante;
    }
    else{
        return morte;
    }
}

/************************
Principe : calcul la prochaine génération et la copie dans un autre tableau

Entrée : les deux tableaux

Sortie : la copie du tableau avec la prochaine génération

Note :
***********************/
void vie(Cellule tTab[][TAILLE], Cellule tCopieTab[][TAILLE]){

    int i = 0, j = 0;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(rechercheVie(tTab,i,j)){                                     //si la cellule est vivante
                tCopieTab[i][j]=nouvelEtatVivante(voisinnage(tTab,i,j));    //on définit son prochain état grâce à nouvelEtatVivante
            }
            else{                                                           //Si elle est morte
                tCopieTab[i][j]=nouvelEtatMorte(voisinnage(tTab,i,j));      //on se sert de nouvelEtatMorte
            }
        }
    }
}

/************************
Principe : copie la copie du tableau dans le tableau principal

Entrée : les deux tableau

Sortie : le tableau principal à la génération suivante

Note :
***********************/
void copieVie(Cellule tTab[][TAILLE], Cellule tCopieTab[][TAILLE]){

    int x = 0, y = 0;
    for(x=0;x<TAILLE;x++){
        for(y=0;y<TAILLE;y++){
            tTab[x][y]=tCopieTab[x][y];
        }
    }
}

/************************
Principe : compte le nombre de cellules vivantes à chaque génération

Entrée : le tableau

Sortie : un entier

Note : permet de compter les cellules vivantes et mortes pour les reporter dans les logs
***********************/
int recensement(Cellule tTab[][TAILLE]){

    int i = 0, j = 0;
    int nCptVivant = 0;

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(tTab[i][j]==vivante){
                nCptVivant++;
            }
        }
    }

    return nCptVivant;
}

