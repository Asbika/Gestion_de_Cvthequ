#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct formation{

    int   IdF;
    char  TypeF[30];
    char  Specialite[30];
    char  Etablissment[30];
    char  Date_D_F[30];
    char  Date_F_F[15];

};struct formation TF;

/*------------FONCTION RECHERCHER------------*/
int reche(int Numrech){
    FILE *F;
    F=fopen("formation.txt","r");
    do
    {
         fscanf(F,"%d :%s :%s :%s :%s :%s \n",&TF.IdF,&TF.TypeF,&TF.Specialite,&TF.Etablissment,&TF.Date_D_F,&TF.Date_F_F ); //Pour remplire la structeure
         fflush(stdin);//Pour libirer la memoire.
         if(TF.IdF==Numrech)
            {
                fclose(F);
                return 1;
            }
    }while(!feof(F));
    fclose(F);
    return -1;
    }

/*------------ AJOUTER -----------*/
void AjouterFormation(){

    FILE *F;
    int num;
    F=fopen("formation.txt","a");//Lecteur & Ecriteur
    printf("\n\tEntre le numero de nouvelle formation:");
    scanf("%d",&num);
    fflush(stdin);
    while(reche(num)==1)
{
    printf("\n\tCe Numero Existe deja :");
    printf("\n\tEntrer Le Numero de de nouvelle formation :");
    scanf("%d",&num);
}
    TF.IdF=num;

    printf("\n\tEntrez type du formation:");
    gets(TF.TypeF);
    fflush(stdin);

    printf("\n\tEntrez specialite du formation :");
    gets(TF.Specialite);
    fflush(stdin);

    printf("\n\tEntrez etablissement du formation  : ");
    gets(TF.Etablissment);
    fflush(stdin);

    printf("\n\t Entrez dete bebut du formation :");
    gets(TF.Date_D_F);
    fflush(stdin);

    printf("\n\tEntrez dete fin du formation :");
    gets(TF.Date_F_F);
    fflush(stdin);

    fprintf(F,"%d :%s :%s :%s :%s :%s \n",TF.IdF,TF.TypeF,TF.Specialite,TF.Etablissment,TF.Date_D_F,TF.Date_F_F );
    fclose(F);
}

/*-------------RECHERCHE ET AFFICHAGE--------------*/
void RechercherFormation(){
int NumR;

printf("\n\tEntrez Le Numero de formation a Rechercher :");
scanf("%d",&NumR);

FILE *F;
F=fopen("formation.txt","r");

do{

    fscanf(F,"%d :%s :%s :%s :%s :%s \n",&TF.IdF,&TF.TypeF,&TF.Specialite,&TF.Etablissment,&TF.Date_D_F,&TF.Date_F_F );
    if(TF.IdF==NumR){
        printf("\n\t===============INFORMATION SUR LA FORMATION  %d  ================\n\t ",TF.IdF);
        printf("\n\tTYPE DU FORMATION \t\t\t:%s",TF.TypeF);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tSPECIALITE DU FORMATION \t\t\t:%s",TF.Specialite);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tETABLISSEMENT DU FORMATION \t\t\t:%s",TF.Etablissment);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tDEBUT DATE DU FORMATION \t\t\t:%s",TF.Date_D_F);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tFIN DATE DU FORMATION \t\t\t:%s",TF.Date_D_F);
        printf("\n\t-----------------------------------------------------------------");
    }
    }while(!feof(F));
    fclose(F);
}

/*---------------- PROCEDURE DE SUPPRESSION -----------------*/
void SupprimerFormation(){
char rep;
int NumRech;

printf("\n\tEntrez Le numero de formation a Supprimer :");
scanf("%d",&NumRech);
fflush(stdin);

if(reche(NumRech)==1){
    printf("\n\tVoulez Vous Vraiment Supprimer cette formation O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o'||rep=='O'){
        FILE *Fich,*F;
        F=fopen("formation.txt","r");
        Fich=fopen("Tempformation.txt","a");
        do
        {
          fscanf(F,"%d :%s :%s :%s :%s :%s \n",&TF.IdF,&TF.TypeF,&TF.Specialite,&TF.Etablissment,&TF.Date_D_F,&TF.Date_F_F );
          if(NumRech!=TF.IdF){
           fprintf(Fich,"%d :%s :%s :%s :%s :%s \n",TF.IdF,TF.TypeF,TF.Specialite,TF.Etablissment,TF.Date_D_F,TF.Date_F_F );
          }
        }while(!feof(F));
        fclose(Fich);
        fclose(F);
        remove("formation.txt");
        rename("Tempformation.txt","formation.txt");
        printf("\n\tLa Suppression effectuer avec succees\n");
    }
}
else
{
    printf("\n\tCe Numero de formation n'existe pas ! \n");
}
}

/*---------------MODIFICATION-----------------*/
void ModifierFormation(){

FILE *F,*Fich;
int num,i;
char rep='n';

printf("\n\tEntrez le numero de formation a Modifier :");
scanf("%d",&num);
fflush(stdin);

if(reche(num)==1){
    printf("\n\tVoulez Vous Vraiment Modifier cette formation O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    printf("%c",rep);
    if(rep=='o'||rep=='O')
    {
        F=fopen("formation.txt","r");
        Fich=fopen("Tempformation.txt","a");
        do{
        fscanf(F,"%d :%s :%s :%s :%s :%s \n",&TF.IdF,&TF.TypeF,&TF.Specialite,&TF.Etablissment,&TF.Date_D_F,&TF.Date_F_F );
        if(num==TF.IdF){
            TF.IdF==num;

        printf("\n\tEntrez Le nouveau type du formation  :");
        gets(TF.TypeF);
        fflush(stdin);

        printf("\n\tEntrez Le nouvelle specialite du formation :");
        gets(TF.Specialite);
        fflush(stdin);

        printf("\n\tEntrez La nouvelle etablissement du formation  : ");
        gets(TF.Etablissment);
        fflush(stdin);

        printf("\n\tEntrez La nouvelle debut date du  formation  :");
        gets(TF.Date_D_F);
        fflush(stdin);

        printf("\n\tEntrez la nouvelle fin date du formation :");
        gets(TF.Date_F_F);
        fflush(stdin);

        }
        fprintf(Fich,"%d :%s :%s :%s :%s :%s \n",TF.IdF,TF.TypeF,TF.Specialite,TF.Etablissment,TF.Date_D_F,TF.Date_F_F );

        }while(!feof(F));
        fclose(Fich);
        fclose(F);
        remove("formation.txt");
        rename("Tempformation.txt","formation.txt");
        printf("\n\tLa Modification effectuer avec succees\n");
    }
    else{
        printf("\n\t La Modification a ete annule! \n");
    }
}
else{
    printf("\n\tCe Numero de formation  n'existe pas !\n");
}
}

/*------------------AFFICHER TOUT------------------*/
void AffichertoutFormation(){
FILE *F;
int i=0;

F=fopen("formation.txt","r");

printf("\n\tNumero\tTYPE\tSPECIALITE\tETABLISSEMENT\tDATE DU DEBUT\tDATE DU FIN\n");
printf("\n\t--------------------------------------------------------------------\n");
do{

     fscanf(F,"%d :%s :%s :%s :%s :%s \n",&TF.IdF,&TF.TypeF,&TF.Specialite,&TF.Etablissment,&TF.Date_D_F,&TF.Date_F_F );
    fflush(stdin);
    printf("\n\t%d  %s  %s  %s  %s  %s \n",TF.IdF,TF.TypeF,TF.Specialite,TF.Etablissment,TF.Date_D_F,TF.Date_F_F );
     i++;
}while(!feof(F));
 fclose(F);
if(i==0)
{
    printf("la liste est vide ;\n");
    return ;

}

}

/*-------------------MENU-DE-FORMATION-----------*/
void MenuFormation(){
    int Choix;
    char rep;
    do
    {
    system("cls");
    printf("\n\t              *********************                   ");
    printf("\n\t*************** MENU DE FORMATION ***************");
    printf("\n\t*             *********************             *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*  (1) Ajouter Une formation                    *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (2) Rechercher une formation                 *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (3) Supprimer une formation                  *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (4) Modifier une formation                   *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (5) fficher Toutes les formation             *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (6) Quiter                                   *\n");
    printf("\t*-----------------------------------------------*\n");
    do
    {
        printf("\n\t>>> Entrez Votre Choix...");
        scanf("%d",&Choix);
    }while(Choix<1||Choix>6);

     switch(Choix){
     case 1:AjouterFormation();
        break;
     case 2:RechercherFormation();
        break;
     case 3:SupprimerFormation();
        break;
     case 4:ModifierFormation();
        break;
     case 5:AffichertoutFormation();
        break;
     case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N ?...");
    scanf("%s",&rep);
    fflush(stdin);
    }while(rep=='o'||rep=='O');
}
