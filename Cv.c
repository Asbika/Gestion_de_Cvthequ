#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct Cv{
    int IdCv;
    char TitreCv[100];
    char DateCreation[100];
    char DateModification[100];
    }; struct Cv Cv;

/*----------------FONCTION DE RECHERCHE--------------------*/
    int ChercherCv(int numcher){
    FILE *Fcv;
    Fcv=fopen("Cvs.txt","r");//l'ouverteur un fichier en lecteur.
    do{
    fscanf(Fcv,"%d :%s :%s :%s \n",&Cv.IdCv,&Cv.TitreCv,&Cv.DateCreation,&Cv.DateModification);
    fflush(stdin);

    if(Cv.IdCv==numcher)
    {
    fclose(Fcv);
    return 1;
    }
    }while(!feof(Fcv));
    fclose(Fcv);
    return -1;
}

/*----------------FONCTION D'AJOUTER------------------------*/
    void AjouterCv(){
    int n;
    FILE *Fcs;
    Fcs=fopen("Cvs.txt","a");//l'ouverteur d'un fichier en lecteur ecriteure.
    printf("\n\t Veuillez Entrez  l'd du nouveau Cv :\n ");
    scanf("%d",&n);
    fflush(stdin);

    while(ChercherCv(n)==1){

        printf("\n\tCe Cv Existe deja!\n");
        printf("\n\tVeuillez Entrez  l'id du nouveau Cv :\n ");
        scanf("%d",&n);
    }


    Cv.IdCv=n;

    printf("\n\tVeuillez Entrez  le Titre du nouveau Cv :\n");
    gets(Cv.TitreCv);
    fflush(stdin);

    printf("Veuillez Entrez  la date de Creation du nouveau Cv :\n");
    gets(Cv.DateCreation);
    fflush(stdin);

    strcpy(Cv.DateModification,Cv.DateCreation);

    fprintf(Fcs,"%d :%s :%s :%s \n",Cv.IdCv,Cv.TitreCv,Cv.DateCreation,Cv.DateModification);

    fclose(Fcs);
}

/*----------------FONCTION D'AFFICHAGE----------------------*/
    void fctafficherCv(){
         FILE *Fcv;
         Fcv=fopen("Cvs.txt","r");
         printf("\n\n\tID-CV  \tTITRE-CV   \t \tDATE DE CREATION      \tDATE DE MODIFICATION");
         printf("\n   ===================================================================================");
         do{
         fscanf(Fcv,"%d :%s :%s :%s \n",&Cv.IdCv,&Cv.TitreCv,&Cv.DateCreation,&Cv.DateModification);
         fflush(stdin);
         printf("\n\n\t%d     \t%s\t\t%s\t\t\t\t%s\n",Cv.IdCv,Cv.TitreCv,Cv.DateCreation,Cv.DateModification);
         printf("   ===================================================================================");
         }while(!feof(Fcv));
         fclose(Fcv);
     }

/*----------------FONCTION DE SUPPRESSION------------------*/
    void SupprimerCv(){
         char rep;
         int NumRech;

         printf("\n\tEntrez L'id Cv a supprimer :");
         scanf("%d",&NumRech);
         fflush(stdin);

    if(ChercherCv(NumRech)==1)
 {
        printf("\n\tVoulez Vous Vraiment Supprimer o/n ? ");
        scanf("%c",&rep);
        fflush(stdin);

        if(rep=='o'||rep=='O')
        {
        FILE *Fcv,*TmpFcv;
        Fcv=fopen("Cvs.txt","r");
        TmpFcv=fopen("TmpCvs.txt","a");
        do
{
        fscanf(Fcv,"%d :%s :%s :%s \n",&Cv.IdCv,&Cv.TitreCv,&Cv.DateCreation,&Cv.DateModification);
        if(NumRech!=Cv.IdCv)
{
        fprintf(TmpFcv,"%d :%s :%s :%s \n",Cv.IdCv,Cv.TitreCv,Cv.DateCreation,Cv.DateModification);
}
} while(!feof(Fcv));

        fclose(TmpFcv);
        fclose(Fcv);

         remove("Cvs.txt");
         rename("TmpCvs.txt","Cvs.txt");

        printf("\n\tSuppression Effectuee avec succees");

 }
}
else
{


    printf("\n\tCe Cv n'existe pas !\n");
    }
}

/*----------------FONCTION DE RECHERCHE-&-AFFICHER---------*/
    void RechercheCv(){

        int Num;
        printf("\n\tEntrez l'id du Cv a rechercher :");
        scanf("%d",&Num);
        FILE *Fcv;
        Fcv=fopen("Cvs.txt","r");
        do
        {
         fscanf(Fcv,"%d :%s :%s :%s \n",&Cv.IdCv,&Cv.TitreCv,&Cv.DateCreation,&Cv.DateModification);
         if(Cv.IdCv==Num)
        {
            printf("\n\t==============================\n");
            printf("\n\tInformation sur le Cv   %d    =\n",Num);
            printf("\n                                     =\n");
            printf("\t============================================================\n");
            printf("\n\t\tLe titre                :  %s\n",Cv.TitreCv);
            printf("\t============================================================\n");
            printf("\n\t\tLa date de Creation     :  %s\n",Cv.DateCreation);
            printf("\t=============================================================\n");
            printf("\n\t\tLa date de Modification :  %s\n",Cv.DateModification);
            printf("\t=============================================================\n");
            //printf("\n\n\t%d :%s :%s :%s \n",Cv.IdCv,Cv.TitreCv,Cv.DateCreation,Cv.DateModification);
        }
        }while(!feof(Fcv));
        fclose(Fcv);
        if(Num!=Cv.IdCv){
            printf("\n\tDesole! le Cv (%d) n'existe pas dans la liste des Cv.\n",Num);
        }
}

/*----------------FONCTION DU MODIFICATION-----------------*/
    void fctmodifiationCv(){

     char rep;
     int num;

     printf("\n\tEntrez l'id de Cv a modifier:\n");
     scanf("%d",&num);
     fflush(stdin);

     if(ChercherCv(num)==1)
     {
     printf("\n\tVoulez vous Vraiment Modifier o/n?");
     scanf("%c",&rep);
     fflush(stdin);

     if(rep=='o'||rep=='O')
     {
        FILE *Fcv,*TmpFcv;
        Fcv=fopen("Cvs.txt","r");
        TmpFcv=fopen("TmpCvs.txt","a");

        do
        {

        fscanf(Fcv,"%d :%s :%s :%s \n",&Cv.IdCv,&Cv.TitreCv,&Cv.DateCreation,&Cv.DateModification);
        if(num==Cv.IdCv)

        {
        Cv.IdCv=num;
        printf("\n\tVeuillez Entrez  le Titre du nouveau Cv :\n");
        gets(Cv.TitreCv);
        fflush(stdin);

        printf("\n\tVeuillez Entrez  la date de Modification du Cv :\n");
        gets(Cv.DateModification);
        fflush(stdin);

                 }
        fprintf(TmpFcv,"%d :%s :%s :%s \n",Cv.IdCv,Cv.TitreCv,Cv.DateCreation,Cv.DateModification);
        }while(!feof(Fcv));

          fclose(TmpFcv);
          fclose(Fcv);
          remove("Cvs.txt");
          rename("TmpCvs.txt","Cvs.txt");
          printf("\n\tLa modification est reussi !");
        }
        else
        {
        printf("\n\tLa Modification est annulle ! \n");
        }
        }
        else{
        printf("\n\tCe Cv n'existe pas ! \n");
}
}

/*--------------------MENU CV-----------------------------------------------*/
void MenuCv(){

 int Choix;char rep,rep2;
do
{
    system("cls");
    printf("\n\t              *********************                   ");
    printf("\n\t***************     MENU DE CV    ***************");
    printf("\n\t*             *********************             *    ");
    printf("\n\t*                                               *\n ");
    printf("\t*   (1)  Ajouter un Cv                          *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (2)  Rechercher Cv                          *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (3)  Supprimer Cv                           *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (4)  Modifier Cv                            *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (5)  Afficher tous Les Cv                   *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (6)  Quiter                                 *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
     printf("\n\t>>> Etrez votre choix...");
     scanf("%d",&Choix);
    }while(Choix<1||Choix>6);
    switch(Choix){
    case 1:AjouterCv();
        break;
    case 2:RechercheCv();
        break;
    case 3:SupprimerCv();
        break;
    case 4:fctmodifiationCv();
        break;
    case 5:fctafficherCv();
        break;
    case 6:break;
    }
    printf("\n\t>>> Voulez-vous continuez O/N?...");
    scanf("%s",&rep);
    fflush(stdin);
}while(rep=='o'||rep=='O');

}
