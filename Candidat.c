#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct Candidat{

    int   NumCandidat;
    char  NomCandidat[30];
    char  PrenomCandidat[30];
    char  Pays[30];
    char  villeCandidat[30];
    char  Genre[15];
    char  EmailCandidat[50];
    char  Adresse[50];
    char  Telephone[30];
    char  Cin[15];
    char  DateNaissance[50];
};struct Candidat Cnd;

/*------------FONCTION RECHERCHER------------*/
int rech(int Numrech)
{
    FILE *F;
    F=fopen("Candidats.txt","r");
    do
    {
         fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",&Cnd.NumCandidat,&Cnd.NomCandidat,&Cnd.PrenomCandidat,&Cnd.Pays,&Cnd.villeCandidat,&Cnd.Genre,&Cnd.EmailCandidat,&Cnd.Adresse,&Cnd.Telephone,&Cnd.Cin,&Cnd.DateNaissance); //Pour remplire la structeure
         fflush(stdin);//Pour libirer la memoire.
         if(Cnd.NumCandidat==Numrech)
            {
                fclose(F);
                return 1;
            }
    }while(!feof(F));
    fclose(F);
    return -1;
    }

/*------------ AJOUTER -----------*/
void AjouterCandidat(){

    FILE *F;
    int num;
    F=fopen("Candidats.txt","a");//Lecteur & Ecriteur
    printf("\n\tEntre le numero de nouveau Candidat:");
    scanf("%d",&num);
    fflush(stdin);
    while(rech(num)==1)
{
    printf("\n\tCe Numero Existe deja :");
    printf("\n\tEntrer Le Numero de de nouveau Candidat :");
    scanf("%d",&num);
}
    Cnd.NumCandidat=num;

    printf("\n\tEntrez Le Nom :");
    gets(Cnd.NomCandidat);
    fflush(stdin);

    printf("\n\tEntrez Le Prenom :");
    gets(Cnd.PrenomCandidat);
    fflush(stdin);

    printf("\n\tEntrez La Pays : ");
    gets(Cnd.Pays);
    fflush(stdin);

    printf("\n\t Entrez La Ville :");
    gets(Cnd.villeCandidat);
    fflush(stdin);

    printf("\n\tEntrez Le Genre :");
    gets(Cnd.Genre);
    fflush(stdin);

    printf("\n\tEntrez L'email :");
    gets(Cnd.EmailCandidat);
    fflush(stdin);

    printf("\n\tEntrez L'adresse :");
    gets(Cnd.Adresse);
    fflush(stdin);

    printf("\n\tEntrez Le Telephone :");
    gets(Cnd.Telephone);
    fflush(stdin);

    printf("\n\tEntrez La CIN :");
    gets(Cnd.Cin);
    fflush(stdin);

    printf("\n\tEntrez La Date de Naissance :");
    gets(Cnd.DateNaissance);
    fflush(stdin);


    fprintf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",Cnd.NumCandidat,Cnd.NomCandidat,Cnd.PrenomCandidat,Cnd.Pays,Cnd.villeCandidat,Cnd.Genre,Cnd.EmailCandidat,Cnd.Adresse,Cnd.Telephone,Cnd.Cin,Cnd.DateNaissance);
    fclose(F);


}

/*-------------RECHERCHE ET AFFICHAGE--------------*/
void Rechercher(){
int NumR;

printf("\n\tEntrez Le Numero de Candidat a Rechercher :");
scanf("%d",&NumR);

FILE *F;
F=fopen("Candidats.txt","r");

do{

    fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",&Cnd.NumCandidat,&Cnd.NomCandidat,&Cnd.PrenomCandidat,&Cnd.Pays,&Cnd.villeCandidat,&Cnd.Genre,&Cnd.EmailCandidat,&Cnd.Adresse,&Cnd.Telephone,&Cnd.Cin,&Cnd.DateNaissance);
    if(Cnd.NumCandidat==NumR){
        printf("\n\t===============INFORMATION SUR LE CANDIDATS  %d  ================\n\t ",Cnd.NumCandidat);
        printf("\n\tNOM \t\t\t:%s",Cnd.NomCandidat);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tPRENOM \t\t\t:%s",Cnd.PrenomCandidat);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tPAYS \t\t\t:%s",Cnd.Pays);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tVILLE \t\t\t:%s",Cnd.villeCandidat);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tGENRE \t\t\t:%s",Cnd.Genre);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tE-MAIL \t\t\t:%s",Cnd.EmailCandidat);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tADRESSE \t\t:%s",Cnd.Adresse);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tTELEPHONE \t\t:%s",Cnd.Telephone);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tCIN \t\t\t:%s",Cnd.Cin);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tDATE_NASSANCE \t\t:%s",Cnd.DateNaissance);
        printf("\n\t-----------------------------------------------------------------");
    }
    }while(!feof(F));
    fclose(F);
}

/*---------------- PROCEDURE DE SUPPRESSION -----------------*/
void SupprimerC(){
char rep;
int NumRech;

printf("\n\tEntrez Le numero de Candidat a Supprimer :");
scanf("%d",&NumRech);
fflush(stdin);

if(rech(NumRech)==1){
    printf("\n\tVoulez Vous Vraiment Supprimer O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o'||rep=='O'){
        FILE *Fich,*F;
        F=fopen("Candidats.txt","r");
        Fich=fopen("TempCandidat.txt","a");
        do
        {
          fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",&Cnd.NumCandidat,&Cnd.NomCandidat,&Cnd.PrenomCandidat,&Cnd.Pays,&Cnd.villeCandidat,&Cnd.Genre,&Cnd.EmailCandidat,&Cnd.Adresse,&Cnd.Telephone,&Cnd.Cin,&Cnd.DateNaissance);
          if(NumRech!=Cnd.NumCandidat){
            fprintf(Fich,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",Cnd.NumCandidat,Cnd.NomCandidat,Cnd.PrenomCandidat,Cnd.Pays,Cnd.villeCandidat,Cnd.Genre,Cnd.EmailCandidat,Cnd.Adresse,Cnd.Telephone,Cnd.Cin,Cnd.DateNaissance);
          }
        }while(!feof(F));
        fclose(Fich);
        fclose(F);
        remove("Candidats.txt");
        rename("TempCandidat.txt","Candidats.txt");
        printf("\n\tLa Suppression effectuer avec succees\n");
    }
}
else
{
    printf("\n\tCe Numero de Candidat n'existe pas ! \n");
}
}

/*---------------MODIFICATION-----------------*/
void ModifierCnd(){

FILE *F,*Fich;
int num,i;
char rep='n';

printf("\n\tEntrez le numero de Candidat a Modifier :");
scanf("%d",&num);
fflush(stdin);

if(rech(num)==1){
    printf("\n\tVoulez Vous Vraiment Modifier O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    printf("%c",rep);
    if(rep=='o'||rep=='O')
    {
        F=fopen("Candidats.txt","r");
        Fich=fopen("TempCandidat.txt","a");
        do{
        fscanf(F,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",&Cnd.NumCandidat,&Cnd.NomCandidat,&Cnd.PrenomCandidat,&Cnd.Pays,&Cnd.villeCandidat,&Cnd.Genre,&Cnd.EmailCandidat,&Cnd.Adresse,&Cnd.Telephone,&Cnd.Cin,&Cnd.DateNaissance);
        if(num==Cnd.NumCandidat){
            Cnd.NumCandidat==num;

        printf("\n\tEntrez Le nouveau Nom :");
        gets(Cnd.NomCandidat);
        fflush(stdin);

        printf("\n\tEntrez Le nouveau Prenom :");
        gets(Cnd.PrenomCandidat);
        fflush(stdin);

        printf("\n\tEntrez La nouvelle Pays : ");
        gets(Cnd.Pays);
        fflush(stdin);

        printf("\n\t Entrez La nouvelle Ville :");
        gets(Cnd.villeCandidat);
        fflush(stdin);

        printf("\n\tEntrez Le nouveau Genre :");
        gets(Cnd.Genre);
        fflush(stdin);

        printf("\n\tEntrez la nouvelle adresse e-mail :");
        gets(Cnd.EmailCandidat);
        fflush(stdin);

        printf("\n\tEntrez Le nouveau adresse :");
        gets(Cnd.EmailCandidat);
        fflush(stdin);

        printf("\n\tEntrez Le nouveau numéro de teléphone :");
        gets(Cnd.Telephone);
        fflush(stdin);

        printf("\n\tEntrez La  nouvelle CIN :");
        gets(Cnd.Cin);
        fflush(stdin);

        printf("\n\tEntrez La nouvelle Date de Naissance :");
        gets(Cnd.DateNaissance);
        fflush(stdin);


        }
        fprintf(Fich,"%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",Cnd.NumCandidat,Cnd.NomCandidat,Cnd.PrenomCandidat,Cnd.Pays,Cnd.villeCandidat,Cnd.Genre,Cnd.EmailCandidat,Cnd.Adresse,Cnd.Telephone,Cnd.Cin,Cnd.DateNaissance);

        }while(!feof(F));
        fclose(Fich);
        fclose(F);
        remove("Candidats.txt");
        rename("TempCandidat.txt","Candidats.txt");
        printf("\n\tLa Modification effectuer avec succees\n");
    }
    else{
        printf("\n\t La Modification a ete annule! \n");
    }
}
else{
    printf("\n\tCe Numero de Candidat n'existe pas !\n");
}
}

/*------------------AFFICHER TOUT------------------*/
void AffichertoutCnd(){
FILE *F;
F=fopen("Candidats.txt","r");
printf("\n\tLa liste des Candidats est :\n");
printf("\n\tNumero\tNom\tPrenom\tPays\tVille\tGenre\tE-mail\tAdresse\tTelephone\tDate-Naissance\n");
printf("\n\t-------------------------------------------------------------------------------------------------------------------\n");
do{

    fscanf(F,"\t%d :%s :%s :%s :%s :%s :%s :%s :%s :%s :%s \n",&Cnd.NumCandidat,&Cnd.NomCandidat,&Cnd.PrenomCandidat,&Cnd.Pays,&Cnd.villeCandidat,&Cnd.Genre,&Cnd.EmailCandidat,&Cnd.Adresse,&Cnd.Telephone,&Cnd.Cin,&Cnd.DateNaissance);
    fflush(stdin);
    printf("\n\t%d  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s \n",Cnd.NumCandidat,Cnd.NomCandidat,Cnd.PrenomCandidat,Cnd.Pays,Cnd.villeCandidat,Cnd.Genre,Cnd.EmailCandidat,Cnd.Adresse,Cnd.Telephone,Cnd.Cin,Cnd.DateNaissance);
}while(!feof(F));
 fclose(F);
}

/*-------------------MENU-DE-CANDIDATS-----------*/
void CndMenu(){
    int Choix;
    char rep;
    do
    {

    system("cls");
    printf("\n\t              *********************                   ");
    printf("\n\t*************** MENU DE CANDIDATS ***************");
    printf("\n\t*             *********************             *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*  (1)  Ajouter Un Candidat                      *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (2)  Rechercher Un Candidat                   *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (3)  Supprimer Un Candidat                    *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (4)  Modifier Un Candidat                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (5)  Afficher Tous les Candidats              *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (6)  Quiter                                   *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
        printf("\n\t>>> Entrez Votre Choix...");
        scanf("%d",&Choix);
    }while(Choix<1||Choix>6);

     switch(Choix){
     case 1:AjouterCandidat();
        break;
     case 2:Rechercher();
        break;
     case 3:SupprimerC();
        break;
     case 4:ModifierCnd();
        break;
     case 5:AffichertoutCnd();
        break;
     case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N ?...");
    scanf("%s",&rep);
    fflush(stdin);
    }while(rep=='o'||rep=='O');
}
