#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct Exeperience {

    int   IdExper;
    char  PosteExper[30];
    char  DomaineExper[30];
    char  DureeExper[30];

};struct Exeperience TEX;

/*------------FONCTION RECHERCHER------------*/
int recher(int Numrech)//cette fonction permetra de verifie l'existence de Id avant ajouter ou modefier ;
{
    FILE *F;

    F=fopen("experience.txt","r");
    do
    {
         fscanf(F,"%d :%s :%s :%s \n",&TEX.IdExper,&TEX.PosteExper,&TEX.DomaineExper,&TEX.DureeExper); //Pour remplire la structeure
         fflush(stdin);//Pour libirer la memoire.
         if(TEX.IdExper==Numrech)
            {
                fclose(F);
                return 1;
            }
    }while(!feof(F));
    fclose(F);
    return -1;
    }

/*------------ AJOUTER -----------*/
void Ajouter_experience(){

         FILE *F2;
      F2=fopen("experience.txt","a");
    int num;
  //Lecteur & Ecriteur
    printf("\n\tEntrez le numero d'experience a ajoute :");
    scanf("%d",&num);
    fflush(stdin);
    while(recher(num)==1)
{
    printf("\n\tCe Numero Existe deja :");
    printf("\n\tEntrez Numero d'experience a ajoute :");
    scanf("%d",&num);
}
    TEX.IdExper=num;

    printf("\n\tEntrez Le poste occupe d'experience a ajoute :");
    gets(TEX.PosteExper);
    fflush(stdin);

    printf("\n\tEntrez Le domaine d'experience a ajoute :");
    gets(TEX.DomaineExper);
    fflush(stdin);

    printf("\n\tEntrez La duree d'experience a ajoute: ");
    gets(TEX.DureeExper);
    fflush(stdin);

      fprintf(F2,"%d :%s :%s :%s \n",TEX.IdExper,TEX.PosteExper,TEX.DomaineExper,TEX.DureeExper);
      fclose(F2);


}

/*-------------RECHERCHE ET AFFICHAGE--------------*/
void Rechercher_experience(){
int NumR;

printf("\n\tEntrez Le Numero d'experience a Rechercher :");
scanf("%d",&NumR);

FILE *F;
int i=0;
F=fopen("experience.txt","a");
fclose(F);
F=fopen("experience.txt","r");

do{

    fscanf(F,"%d :%s :%s :%s \n",&TEX.IdExper,&TEX.PosteExper,&TEX.DomaineExper,&TEX.DureeExper);
    if(TEX.IdExper==NumR){
            i=1;
        printf("\n\t========L'INFORMATION SUR L'EXPERIENCE  %d sont:\n\t ",TEX.IdExper);
        printf("\n\tPOSTE OCCUPE \t\t:%s",TEX.PosteExper);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tDOMAINE\t\t\t:%s",TEX.DomaineExper);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tDUREE \t\t\t:%s",TEX.DureeExper);
        printf("\n\t-----------------------------------------------------------------");
    }
    }while(!feof(F));
    fclose(F);
    if(i==0){
        printf("L'experience qui recherche n'existe pas\n");
    }
}

/*---------------- PROCEDURE DE SUPPRESSION -----------------*/
void Supprimer_experience(){
char rep;
int NumRech;

printf("\n\tEntrez Le numero d'experience a Supprimer :");
scanf("%d",&NumRech);
fflush(stdin);

if(recher(NumRech)==1){
    printf("\n\tVoulez Vous Vraiment Supprimer cette experience O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o'||rep=='O'){
        FILE *Fich,*F;
        F=fopen("experience.txt","r");
        Fich=fopen("Tempexperience.txt","a");
        do
        {
           fscanf(F,"%d :%s :%s :%s \n",&TEX.IdExper,&TEX.PosteExper,&TEX.DomaineExper,&TEX.DureeExper);
          if(NumRech!=TEX.IdExper){
            fprintf(Fich,"%d :%s :%s :%s \n",TEX.IdExper,TEX.PosteExper,TEX.DomaineExper,TEX.DureeExper);
          }
        }while(!feof(F));
        fclose(Fich);
        fclose(F);
        remove("experience.txt");
        rename("Tempexperience.txt","experience.txt");
        printf("\n\tLa Suppression effectuer avec succees\n");
    }
}
else
{
    printf("\n\tCette experience n'existe pas ! \n");
}
}

/*---------------MODIFICATION-----------------*/
void Modifier_experience(){


int num,i;
char rep='n';

printf("\n\tEntrez le numero d'experience a Modifier :");
scanf("%d",&num);
fflush(stdin);

if(recher(num)==1){
    printf("\n\tVoulez Vous Vraiment Modifier cette experience O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    printf("%c",rep);
    if(rep=='o'||rep=='O')
    {   FILE *F,*Fich;
        F=fopen("experience.txt","r");
        Fich=fopen("Tempexperience.txt","a");
        do{
        fscanf(F,"%d :%s :%s :%s \n",&TEX.IdExper,&TEX.PosteExper,&TEX.DomaineExper,&TEX.DureeExper);
        if(num==TEX.IdExper){
            TEX.IdExper==num;

        printf("\n\tEntrez Le poste d'experience :");
        gets(TEX.PosteExper);
        fflush(stdin);

        printf("\n\tEntrez Le domaine d'experience :");
        gets(TEX.DomaineExper);
        fflush(stdin);

        printf("\n\tEntrez La durée d'experience : ");
        gets(TEX.DureeExper);
        fflush(stdin);

        }
         fprintf(Fich,"%d :%s :%s :%s \n",TEX.IdExper,TEX.PosteExper,TEX.DomaineExper,TEX.DureeExper);

        }while(!feof(F));

         fclose(F);
         fclose(Fich);
        remove("experience.txt");
        rename("Tempexperience.txt","experience.txt");
        printf("\n\tLa Modification effectuer avec succees\n");
    }
    else{
        printf("\n\t La Modification a ete annule! \n");
    }
}
else{
    printf("\n\tCette experience n'existe pas !\n");
}
}

/*---------------AFFICHER TOUT------------------*/
void Afficher_toute_experience(){
FILE *F3,*F6;
F6=fopen("experience.txt","a");
fclose(F6);
F3=fopen("experience.txt","r");
printf("\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
printf("\n\t\t*Voici La liste des experiences * ");
printf("\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
printf("\n\t\tNumero\t****\tPOST OCCUPE\t****\tDOMAINE\t****\tDUREE\n");
printf("\n\t\t-----------------------------------------------------------------------\n");
do{

     fscanf(F3,"\t%d :%s :%s :%s \n",&TEX.IdExper,&TEX.PosteExper,&TEX.DomaineExper,&TEX.DureeExper);
    fflush(stdin);
    printf("\n\t\t%d\t****\t %s\t****\t %s \t****\t%s \n",TEX.IdExper,TEX.PosteExper,TEX.DomaineExper,TEX.DureeExper);
    printf("\n\t\t-----------------------------------------------------------------------\n");
}while(!feof(F3));

 fclose(F3);
}
/*-------------------MENU-DE-CANDIDATS-----------*/
void Menu_Experience(){
    int Choix;
    char rep;
    do
    {

    system("cls");
    printf("\n\t              **********************                  ");
    printf("\n\t*************** MENU D'EXPERIENCES ***************");
    printf("\n\t*             **********************            *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*  (1) Ajouter une experience                   *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (2) Rechercher une experience                *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (3) Supprimer une experience                 *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (4) Modifier une experience                  *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (5) Afficher Toutes les  experiences         *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (6) Quiter                                   *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
        printf("\n\t>>> Entrez Votre Choix...");
        scanf("%d",&Choix);
    }while(Choix<1||Choix>6);

     switch(Choix){
     case 1:Ajouter_experience();
        break;
     case 2:Rechercher_experience();
        break;
     case 3:Supprimer_experience();
        break;
     case 4:Modifier_experience();
        break;
     case 5:Afficher_toute_experience();
        break;
     case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N ?...");
    scanf("%s",&rep);
    fflush(stdin);
    }while(rep=='o'||rep=='O');
}
