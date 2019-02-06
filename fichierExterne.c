#include <stdio.h>
#include <stdlib.h>
#include "defineform.h"
#define TAILLE_CHAINE 1000

/************************
Principe : reporte le nombre de cellules vivantes et mortes à chaque génération dans les logs

Entrée : le tableau, le numero de la génération et le fichier des logs

Sortie : le fichier des logs rempli

Note :
***********************/
void ecrireFichier(Cellule tTab[][TAILLE], int nCpt, FILE* fichier){

    int nCptVivant = 0;
    int nCptMort = 0;

    nCptVivant = recensement(tTab);         //On compte les cellules vivantes
    nCptMort = TAILLE*TAILLE - nCptVivant;  //on calcule les cellules morte à partir des cellules vivantes

    fichier = fopen("generations.txt", "a");
    if (fichier==NULL) perror ("Erreur lors de l'ouverture du fichier");
    //On écrit dans le fichier le numero de la génération ainsi que le nombre de cellules vivantes et mortes
    fprintf(fichier, "Generation %d :\n\n  Cellules vivantes : %d\n  Cellules mortes : %d\n\n",nCpt, nCptVivant, nCptMort);
    fclose(fichier);
}

/************************
Principe : lis les logs et les affiche

Entrée : le fichier des logs

Sortie : l'affichage des logs

Note : TODO : ajouter la possibilité de chercher une génération précise à afficher
***********************/
void lireFichier(FILE* fichier){

    char cChaine[TAILLE_CHAINE];

    system("cls");
    fichier = fopen("generations.txt", "r");
    if (fichier==NULL) perror ("Erreur lors de l'ouverture du fichier");
    while(fgets(cChaine, TAILLE_CHAINE, fichier)!=NULL){    //on fait une boucle pour lire ligne par ligne
        printf("%s",cChaine);
    }

    fclose(fichier);
}

/************************
Principe : réinitialise les logs

Entrée : le fichier des logs

Sortie : le fichier des logs réinitialisé

Note :
***********************/
void razFichier(FILE* fichier){

    fichier = fopen("generations.txt", "w");    //On ouvre le fichier en réécriture pour écraser le contenu existant
    if (fichier==NULL) perror ("Erreur lors de l'ouverture du fichier");
    fprintf(fichier, "---POPULATION---\n\n");   //On donne une en-tête au fichier (et on écrase le contenu existant)
    fclose(fichier);
    printf("Logs reinitialises\n\n");           //On indique à l'utilisateur que les logs on été remis à zéro
}

/************************
Principe : enregistrer l'état de chaque cellule d'une génération dans un fichier texte

Entrée : le tableau, le fichier

Sortie : le fichier

Note :
***********************/
void sauvegarde(FILE* fichier, Cellule tTab[][TAILLE]){

    int i = 0, j = 0;

    fichier = fopen("sauvegarde.txt", "w");
    if (fichier==NULL) perror ("Erreur lors de l'ouverture du fichier");

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            fprintf(fichier, "%d", tTab[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}

/************************
Principe : récupérer l'état de chaque cellule depuis le fichier

Entrée : le tableau et le fichier

Sortie : le tableau

Note : ça marche pô
***********************/
void charger(FILE* fichier, Cellule tTab[][TAILLE]){

    int i = 0, j = 0;
    char c = 0;

    fichier = fopen("sauvegarde.txt", "r");
    if (fichier==NULL) perror ("Erreur lors de l'ouverture du fichier");

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            c = fgetc(fichier);
            printf("%c",c);
            if(c=='1'){
                tTab[i][j]=vivante;
            }
            else{
                tTab[i][j]=morte;
            }
        }
    }
    fclose(fichier);
}









