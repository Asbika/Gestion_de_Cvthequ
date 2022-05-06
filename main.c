#include<stdio.h>
#include<stdlib.h>
#include"Candidat.h"
#include"Langues.h"
#include"Cv.h"
#include"Experience.h"
#include"Competence.h"
#include"Formation.h"



void Menu(){

int Choix;char rep;
do
{
    system("cls");
    printf("\n\t              *********************                   ");
    printf("\n\t***************  MENU PRINCIPALE  ***************");
    printf("\n\t*             *********************             *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*   (1)  Menu du Cv                             *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (2)  Menu du Candidats                      *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (3)  Menu du Competence                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (4)  Menu du Experience                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (5)  Menu du Formation                      *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (7)  Menu du Langue                         *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (8)  Quiter                                 *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
     printf("\n\t>>> Etrez votre choix...");
     scanf("%d",&Choix);
    }while(Choix<1||Choix>8);
    switch(Choix){
    case 1:MenuCv();
        break;
    case 2:CndMenu();
        break;
    case 3:MenuCompetence();
        break;
    case 4:Menu_Experience();
        break;
   case 5:MenuFormation();
        break;
    case 6:LngMenu();
        break;
    case 7:return;
    }
    printf("\n\t>>> Voulez-vous revenir au Menu principale O/N?...");
    scanf("%s",&rep);
    fflush(stdin);
}while(rep=='o'||rep=='O');
printf("\n\n\t*********************************************");
printf("\n\t*                                           *");
printf("\n\t* FIN DE PROGRAMME! MERCI POUR VOTRE VISITE *");
printf("\n\t*                                           *");
printf("\n\t*********************************************\n\n\n");
}

void main(){

  Menu();

}
