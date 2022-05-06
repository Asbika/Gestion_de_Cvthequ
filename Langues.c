#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

struct Langues{
    int IdLangue;
    char *NomLangue[100];
    char *Niveau[100];
    int IdCandidats;
};struct Langues Lng;

/*------------FONCTION-RECHERCHER-LA-LANGUE------------*/
int rechLng(int Numrech)
{
    FILE *Flng;
    Flng=fopen("Langue.txt","r");
    do
    {
         fscanf(Flng,"%d :%s :%s :%d \n",&Lng.IdLangue,&Lng.NomLangue,&Lng.Niveau,&Lng.IdCandidats);
         fflush(stdin);
         if(Lng.IdLangue==Numrech)
            {
                fclose(Flng);
                return 1;
            }
    }while(!feof(Flng));
    fclose(Flng);
    return -1;
    }

/*------------AJOUTER----------------------------------*/
void AjouterLng(){
    int num;

    FILE *Flng;

    Flng=fopen("Langue.txt","a");
    printf("\n\tEntrez L'id de nouveau Langue:");
    scanf("%d",&num);
    fflush(stdin);
    while(rechLng(num)==1)
{
    printf("\n\tDesole! Ce Id Existe deja :");
    printf("\n\tEntrerz L'id de de nouveau Langue :");
    scanf("%d",&num);
}

    Lng.IdLangue=num;

    printf("\n\tEntrez La Langue :");
    gets(Lng.NomLangue);
    fflush(stdin);

    printf("\n\tEntrez Le Niveau :");
    gets(Lng.Niveau);
    fflush(stdin);

    printf("\n\tEntrez L'id Candidat : ");
    scanf("%d",&Lng.IdCandidats);
    fflush(stdin);


    fprintf(Flng,"%d :%s :%s :%d \n",Lng.IdLangue,Lng.NomLangue,Lng.Niveau,Lng.IdCandidats);
    fclose(Flng);

}

/*------------RECHERCHE ET AFFICHAGE-------------------*/
void RechercherLng(){
int NumR;

printf("\n\tEntrez L'id de La Langue a Rechercher :");
scanf("%d",&NumR);

FILE *Flng;
Flng=fopen("Langue.txt","r");

do{

    fscanf(Flng,"%d :%s :%s :%d \n",&Lng.IdLangue,&Lng.NomLangue,&Lng.Niveau,&Lng.IdCandidats);
    if(Lng.IdLangue==NumR){
        printf("\n\t-------------------INFORMATION SUR LA LANGUE %d ------------------\n\t ",Lng.IdLangue);
        printf("\n\tLa Langue \t\t\t:%s",Lng.NomLangue);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tLe Niveau \t\t\t:%s",Lng.Niveau);
        printf("\n\t-----------------------------------------------------------------");
        printf("\n\tL'id de Candidat\t\t\t:%s",Lng.IdCandidats);
        printf("\n\t-----------------------------------------------------------------");

    }
    }while(!feof(Flng));
    fclose(Flng);
}
/*------------PROCEDURE DE SUPPRESSION------------------*/
void SupprimerLng(){
char rep;
int NumRech;

printf("\n\tEntrez L'id de la Langue a Supprimer :");
scanf("%d",&NumRech);
fflush(stdin);

    if(rechLng(NumRech)==1){
    printf("\n\tVoulez Vous Vraiment Supprimer O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o'||rep=='O'){
        FILE *TFlng,*Flng;
        Flng=fopen("Langue.txt","r");
        TFlng=fopen("TLangue.txt","a");
        do
        {
          fscanf(Flng,"%d :%s :%s :%d \n",&Lng.IdLangue,&Lng.NomLangue,&Lng.Niveau,&Lng.IdCandidats);
          if(NumRech!=Lng.IdLangue){
            fprintf(TFlng,"%d :%s :%s :%d \n",Lng.IdLangue,Lng.NomLangue,Lng.Niveau,Lng.IdCandidats);
          }
        }while(!feof(Flng));
        fclose(TFlng);
        fclose(Flng);
        remove("Langue.txt");
        rename("TLangue.txt","Langue.txt");
        printf("\n\tLa Suppression effectuer avec succees\n");
    }
}
else
{
    printf("\n\tCe id n'existe pas ! \n");
}
}

/*------------MODIFICATION------------------------------*/
void ModifierLng(){

FILE *Flng,*TFlng;
int num,i;
char rep='n';

printf("\n\tEntrez l'id de La Langue a Modifier :");
scanf("%d",&num);
fflush(stdin);

if(rechLng(num)==1){
    printf("\n\tVoulez Vous Vraiment Modifier O/N ?");
    scanf("%c",&rep);
    fflush(stdin);
    printf("%c",rep);
    if(rep=='o'||rep=='O')
    {
        Flng=fopen("Langue.txt","r");
        TFlng=fopen("TLangue.txt","a");
        do{
        fscanf(Flng,"%d :%s :%s :%d \n",&Lng.IdLangue,&Lng.NomLangue,&Lng.Niveau,&Lng.IdCandidats);
        if(num==Lng.IdLangue){
            Lng.IdLangue==num;

        printf("\n\tEntrez La nouvelle Langue :");
        gets(Lng.NomLangue);
        fflush(stdin);

        printf("\n\tEntrez Le Niveau de la Langue :");
        gets(Lng.Niveau);
        fflush(stdin);

        printf("\n\tEntrez La nouvelle id de Candidat : ");
        scanf("%d",&Lng.IdCandidats);
        fflush(stdin);

        }
        fprintf(TFlng,"%d :%s :%s :%d \n",Lng.IdLangue,Lng.NomLangue,Lng.Niveau,Lng.IdCandidats);

        }while(!feof(Flng));
        fclose(TFlng);
        fclose(Flng);
        remove("Langue.txt");
        rename("TLangue.txt","Langue.txt");
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
void Affichertoutlng(){
FILE *Flng;
Flng=fopen("Langue.txt","r");
printf("\n\tLa liste des Langues est :\n");
printf("\n\tIdLangue\tLangue\tNiveau\tIdCandidat\n");
printf("\n\t---------------------------------------\n");
do{

    fscanf(Flng,"\t%d :%s :%s :%d \n",&Lng.IdLangue,&Lng.NomLangue,&Lng.Niveau,&Lng.IdCandidats);
    fflush(stdin);
    printf("\n\t%d  %s  %s  %d \n",Lng.IdLangue,Lng.NomLangue,Lng.Niveau,Lng.IdCandidats);
}while(!feof(Flng));
 fclose(Flng);
}

/*-------------------MENU-DE-LANGUE-----------*/
void LngMenu(){
    int Choix;
    char rep;
    do
    {

        system("cls");
    printf("\n\t              *********************                   ");
    printf("\n\t*************** MENU  DE  LANGUES ***************");
    printf("\n\t*             *********************             *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*  (1)  Ajouter Une Langue                      *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (2)  Rechercher sur une Langue               *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (3)  Supprimer Une Langue                    *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (4)  Modifier Une Langue                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (5)  Afficher Tous les Langues               *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*  (6)  Quiter                                  *\n");
    printf("\t*-----------------------------------------------*\n");
    do
    {
        printf("\n\t>>> Entrez Votre Choix...");
        scanf("%d",&Choix);
    }while(Choix<1||Choix>6);

     switch(Choix){
     case 1:AjouterLng();
        break;
     case 2:RechercherLng();
        break;
     case 3:SupprimerLng();
        break;
     case 4:ModifierLng();
        break;
     case 5:Affichertoutlng();
        break;
     case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N ?...");
    scanf("%s",&rep);
    fflush(stdin);
    }while(rep=='o'||rep=='O');
}
