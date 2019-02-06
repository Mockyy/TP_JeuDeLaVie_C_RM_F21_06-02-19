#include <stdio.h>
#include "defineform.h"

/************************
Principe : afficher le tableau

Entrée : le tableau

Sortie : l'affichage du tablau

Note : retirer les tests et ne garder que l'affichage
***********************/
void afficheTab(Cellule tTab[][TAILLE]){

    int i = 0, j = 0;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(tTab[i][j]==vivante){
                printf("O ");           //Si la cellule est vivante on écrit 'O'
            }
            else{
                printf("  ");           //Sinon on laisse un espace vide ' '
            }
        }
        printf("\n");
    }
}
