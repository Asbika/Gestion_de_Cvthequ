#include<stdio.h>
#include<stdlib.h>

struct Competence
{
    int Id;
    char NCompetence[40];
    char Secteur[50];
};struct Competence Cmpt;

/*--------FONCTION DE RECHERCHE-----------*/
int rechC(int Numrech)
{
FILE *Fc;
Fc=fopen("Competences.txt","r");
do
{
fscanf(Fc,"%d :%s :%s \n",&Cmpt.Id,&Cmpt.NCompetence,&Cmpt.Secteur);
fflush(stdin);
if(Cmpt.Id==Numrech)
{
fclose(Fc);
return 1;
}
}while(!feof(Fc));
fclose(Fc);
return -1;
}

/*--------AJOUTER--------------------------*/
void AjouterCmp(){

FILE *Fc;
int num;
Fc=fopen("Competences.txt","a");
printf("\n\tEntrez le Numero de nouveau Competence :");
scanf("%d",&num);
fflush(stdin);
while(rechC(num)==1)
{
 printf("\n\tCe Numero existe deja !:");
 printf("\n\tEntrez le numero de Competence:");
 scanf("%d",&num);
}
Cmpt.Id=num;

printf("\n\tEntrez La Competence :");
gets(Cmpt.NCompetence);
fflush(stdin);

printf("\n\tEntrez Le Secteur :");
gets(Cmpt.Secteur);
fflush(stdin);

fprintf(Fc,"%d :%s :%s \n",Cmpt.Id,Cmpt.NCompetence,Cmpt.Secteur);
fclose(Fc);
}

/*-----------RECHERCHE ET AFFICHER-------------*/
void RechercheCmp(){
int NumR,j=0;
printf("\n\tEntrez le numero de Competece a rechercher :");
scanf("%d",&NumR);
FILE *Fc;
Fc=fopen("Competences.txt","r");
do
{
fscanf(Fc,"%d :%s :%s \n",&Cmpt.Id,&Cmpt.NCompetence,&Cmpt.Secteur);
if(NumR==Cmpt.Id)
{
        printf("\n\t===============INFORMATION SUR LA COMPETENCE  %d  ================\n\t ",Cmpt.Id);
        printf("\n\tLa Competence \t\t\t:%s",Cmpt.NCompetence);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tLe Secteur \t\t\t:%s",Cmpt.Secteur);
        printf("\n\t-----------------------------------------------------------------");
        j++;
}

}while(!feof(Fc));
fclose(Fc);
if(j==0){
    printf("\n\tDesole! Cet Competence n'existe pas\n");
}
}

/*----------------SUPPRIMER-COMPETENCE-------------------*/
void SupprimerCmp(){
char rep;
int NumRech;
printf("\n\tEntrez Le numero de Competence a supprimer :");
scanf("%d",&NumRech);
fflush(stdin);

if(rechC(NumRech)==1)
{
    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o'||rep=='O')
    {
        FILE *Fct,*Fc;
        Fc=fopen("Competences.txt","r");
        Fct=fopen("TCompetences.txt","a");
        do
        {
         fscanf(Fc,"%d :%s :%s \n",&Cmpt.Id,&Cmpt.NCompetence,&Cmpt.Secteur);
         if(NumRech!=Cmpt.Id)
         {
         fprintf(Fct,"%d :%s :%s \n",Cmpt.Id,Cmpt.NCompetence,Cmpt.Secteur);
         }
        }while(!feof(Fc));
        fclose(Fct);
        fclose(Fc);
        remove("Competences.txt");
        rename("TCompetences.txt","Competences.txt");
        printf("\n\tLa suppression Effectuee avec succees");

    }
}
else
{
    printf("\n\tCe numero de Competence n'existe pas");
}
}

/*---------------MODIFIER-----------------*/
void ModifierCmp(){

FILE *Fc,*Fct;
int num,i;
char rep='n';
printf("\n\tEntrez Le numero de Competence a Modifier: ");
scanf("%d",&num);
fflush(stdin);

if(rechC(num)==1)
{
printf("\n\tVoulez vous vraiment Modifier o/n?");
scanf("%c",&rep);
fflush(stdin);
printf("%c",rep);
if(rep=='o'||rep=='O')
{
 Fc=fopen("Competences.txt","r");
 Fct=fopen("TCompetences.txt","a");

 do
 {
fscanf(Fc,"%d :%s :%s \n",&Cmpt.Id,&Cmpt.NCompetence,&Cmpt.Secteur);
if(num==Cmpt.Id)
{
Cmpt.Id=num;

printf("\n\tEntrez Le Nouveau Competence :");
gets(Cmpt.NCompetence);

printf("\n\tEntrez Le Secteur de Cet Cometence :");
gets(Cmpt.Secteur);
}
fprintf(Fct,"%d :%s :%s \n",Cmpt.Id,Cmpt.NCompetence,Cmpt.Secteur);
}while(!feof(Fc));
fclose(Fc);
fclose(Fct);
remove("Competences.txt");
rename("TCompetences.txt","Competences.txt");
printf("\n\tLa Modification a Reussi");
}
else
{
printf("\n\tLa Modification a ete annule\n");
}
}
else
{
printf("\n\tCe Numero de Competence N'existe pas\n");
}
}

/*--------------AFFICHER---------------------*/
void AfficherCmp(){
FILE *Fc;
Fc=fopen("Competences.txt","r");
printf("\n\tLa liste des Competences est :\n");
printf("\n\tNumero\tLa Competence\tLe Secteur\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fc,"%d :%s :%s \n",&Cmpt.Id,&Cmpt.NCompetence,&Cmpt.Secteur);
fflush(stdin);
printf("\n\t%d :%s :%s \n",Cmpt.Id,Cmpt.NCompetence,Cmpt.Secteur);
}while(!feof(Fc));
fclose(Fc);
}

/*---------Le Menu-DE-COMPETENCE--------------*/
void MenuCompetence(){
int Choix;char rep;
do
{
    system("cls");
    printf("\n\t              **********************                  ");
    printf("\n\t*************** MENU DE COMPETENCE **************");
    printf("\n\t*             **********************            *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*  (1) Ajouter un Competence                    *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (2) Rechercher Une Competence                *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (3) Supprimer Une Competence                 *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (4) Modifier Une Competence                  *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (5) Afficher tous Les Competences            *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (6) Quiter                                   *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
     printf("\n\t>>> Etrez votre choix...");
     scanf("%d",&Choix);
    }while(Choix<1||Choix>6);
    switch(Choix){
    case 1:AjouterCmp();
        break;
    case 2:RechercheCmp();
        break;
    case 3:SupprimerCmp();
        break;
    case 4:ModifierCmp();
        break;
    case 5:AfficherCmp();
        break;
    case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N?...");
    scanf("%s",&rep);
    fflush(stdin);
}while(rep=='o'||rep=='O');
}



























































