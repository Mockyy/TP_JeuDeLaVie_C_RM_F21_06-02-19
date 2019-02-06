#include "defineform.h"
#include <stdio.h>
#include <time.h>

///Choix de la forme
/************************
Principe : choisir la forme de base du tableau (pour ne pas commencer avec un tableau vide)

Entrée : un entier

Sortie : le tableau renseigné

Note :
***********************/
void choixForme(Cellule tTab[][TAILLE]){

    int nChoix = 0;

    if(recensement(tTab)>0){
        printf("Voulez-vous reinitialiser le tableau ?\n1: Oui\n2: Non\n");
        scanf("%d",&nChoix);
        if(nChoix==1){
            initTab(tTab);
        }
    }
    printf("Quelle forme voulez-vous ?\n1: Random\n2: Clignotant\n3: Crapaud\n4: Planeur\n5: Galaxie de Kok\n6: Octogone (sans regles)\n7: Annuler\n");
    scanf("%d",&nChoix);

    switch(nChoix){
        case 1: formeRandom(tTab);break;
        case 2: clignotant(tTab);break;
        case 3: crapaud(tTab);break;
        case 4: planeur(tTab);break;
        case 5: galaxieDeKok(tTab);break;
        case 6: octogone(tTab);break;
        default : printf("Annule\n");
    }
    system("cls");

}

///Random
/************************
Principe : remplir aléatoirement le tableau de cellules vivantes

Entrée : le tableau

Sortie : le tableau rempli aléatoirement

Note :
***********************/
void formeRandom(Cellule tTab[][TAILLE]){

    int nRandom = 0;
    int i = 0, j = 0;

    srand(time(NULL));

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            nRandom = rand()%100+1;     //Génération d'un nombre aléatoire entre 1 et 100
            if(nRandom<=50){            //S'il est inférieur à 50, la cellule devient vivante
                tTab[i][j]=vivante;
            }
            else{
                tTab[i][j]=morte;
            }
        }
    }
}

///Clignotant
/************************
Principe : crée un oscillateur "clignotant" dans le tableau

Entrée : le tableau

Sortie : le tableau rempli

Note :
***********************/
void clignotant(Cellule tTab[][TAILLE]){
    tTab[5][3]=vivante;
    tTab[5][4]=vivante;
    tTab[5][5]=vivante;
}

///Crapaud
/************************
Principe : crée un oscillateur "crapaud" dans le tableau

Entrée : le tableau

Sortie : le tableau rempli

Note :
***********************/
void crapaud(Cellule tTab[][TAILLE]){
    tTab[5][3]=vivante;
    tTab[5][4]=vivante;
    tTab[5][5]=vivante;
    tTab[6][4]=vivante;
    tTab[6][5]=vivante;
    tTab[6][6]=vivante;
}

///Planeur
/************************
Principe : crée un planeur de base dans le tableau

Entrée : le tableau

Sortie : le tablau rempli

Note : warp de la gauche du tableau vers la droite : c'est pas un bug, c'est une feature
***********************/
void planeur(Cellule tTab[][TAILLE]){
    tTab[1][15]=vivante;
    tTab[2][14]=vivante;
    tTab[3][14]=vivante;
    tTab[3][15]=vivante;
    tTab[3][16]=vivante;
}

///Galaxie de Kok
/************************
Principe : crée un oscillateur "galaxie de kok" dans le tableau

Entrée : le tableau

Sortie : le tableau rempli

Note :
***********************/
void galaxieDeKok(Cellule tTab[][TAILLE]){
    tTab[3][3]=vivante;
    tTab[3][4]=vivante;
    tTab[3][6]=vivante;
    tTab[3][7]=vivante;
    tTab[3][8]=vivante;
    tTab[3][9]=vivante;
    tTab[3][10]=vivante;
    tTab[3][11]=vivante;
    tTab[4][3]=vivante;
    tTab[4][4]=vivante;
    tTab[4][6]=vivante;
    tTab[4][7]=vivante;
    tTab[4][8]=vivante;
    tTab[4][9]=vivante;
    tTab[4][10]=vivante;
    tTab[4][11]=vivante;
    tTab[5][3]=vivante;
    tTab[5][4]=vivante;
    tTab[6][3]=vivante;
    tTab[6][4]=vivante;
    tTab[6][10]=vivante;
    tTab[6][11]=vivante;
    tTab[7][3]=vivante;
    tTab[7][4]=vivante;
    tTab[7][10]=vivante;
    tTab[7][11]=vivante;
    tTab[8][3]=vivante;
    tTab[8][4]=vivante;
    tTab[8][10]=vivante;
    tTab[8][11]=vivante;
    tTab[9][10]=vivante;
    tTab[9][11]=vivante;
    tTab[10][3]=vivante;
    tTab[10][4]=vivante;
    tTab[10][5]=vivante;
    tTab[10][6]=vivante;
    tTab[10][7]=vivante;
    tTab[10][8]=vivante;
    tTab[10][10]=vivante;
    tTab[10][11]=vivante;
    tTab[11][3]=vivante;
    tTab[11][4]=vivante;
    tTab[11][5]=vivante;
    tTab[11][6]=vivante;
    tTab[11][7]=vivante;
    tTab[11][8]=vivante;
    tTab[11][10]=vivante;
    tTab[11][11]=vivante;
}

///Octogone
/************************
Principe : crée un oscillateur "octogone" dans le tableau

Entrée : le tableau

Sortie : le tableau rempli

Note :
***********************/
void octogone(Cellule tTab[][TAILLE]){
    tTab[2][10]=vivante;
    tTab[2][11]=vivante;
    tTab[3][9]=vivante;
    tTab[3][12]=vivante;
    tTab[4][8]=vivante;
    tTab[4][13]=vivante;
    tTab[5][7]=vivante;
    tTab[6][7]=vivante;
    tTab[5][14]=vivante;
    tTab[6][14]=vivante;
    tTab[7][8]=vivante;
    tTab[7][13]=vivante;
    tTab[8][9]=vivante;
    tTab[8][12]=vivante;
    tTab[9][10]=vivante;
    tTab[9][11]=vivante;
}
