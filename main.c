#include <stdio.h>
#include <stdlib.h>
#include "defineform.h"
///TODO
//sauvegarder
//placer les formes a une position aléatoire aléatoire
//renvoyer une erreur si on veut mettre une forme trop grande (selon la constante TAILLE)

int main()
{
    FILE* fichier = NULL;

    Cellule tTab[TAILLE][TAILLE];
    Cellule tCopieTab[TAILLE][TAILLE];
    int nCpt = 0;
    int nChoix = 0;
    char cPause = 'a';

    initTab(tTab);

    printf("-------JEU DE LA VIE-------\n\n");
    ///Boucle principale
    do{
        ///Boucle de menu
        do{
            printf("Que voulez-vous faire ?\n1: Jouer\n2: Reinitialiser le tableau\n3: Choisir une forme\n4: Lire les logs\n");
            printf("5: Reinitialiser les logs\n6: Sauvegarder\n7: Charger (coming soon)\n8: Quitter\n");
            scanf("%d",&nChoix);
            system("cls");
            switch(nChoix){
                case 1: if(recensement(tTab)==0){
                            printf("Le tableau est vide :(\n\n");
                            choixForme(tTab);
                        }break;
                case 2: initTab(tTab);break;
                case 3: choixForme(tTab);break;
                case 4: lireFichier(fichier);break;
                case 5: razFichier(fichier);break;
                case 6: sauvegarde(fichier, tTab);break;
                case 7: charger(fichier, tTab);break;
                default: return 0;break;
            }

        }while(nChoix != 1);

        ///Boucle de jeu
        do{
            printf("Appuyez sur une touche pour avancer, 0 pour retourner au menu.\n\nGeneration : %d\n\n",nCpt);

            afficheTab(tTab);

            ecrireFichier(tTab, nCpt, fichier);

            scanf("%c",&cPause);
            system("cls");

            vie(tTab, tCopieTab);

            copieVie(tTab, tCopieTab);

            nCpt++;

        }while(cPause != '0');
    }while(nChoix != 0);

    return 0;
}
