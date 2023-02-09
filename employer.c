#include <stdio.h>
#include <stdlib.h>
#include "employer.h"
#include "Structure.h"
Employer Lire_Employer()
{
    Employer e;
    printf("Donnez Le numero de CNSS de l'employer: \n");
    fflush(stdin);
    scanf("%d",&e.CNSS);
    printf("Donnez le nom de l'employer:\n");
    fflush(stdin);
    gets(e.Nom);
    printf("Donnez le prenom de l'employer:\n");
    fflush(stdin);
    gets(e.Prenom);
    printf("Donnez la grade de l'employer:\n");
    fflush(stdin);
    gets(e.Grade);
    fflush(stdin);
    return e;
}
void Lire_Tab_Employer(Employer*Tab_Emp,int*N)
{
    int cnf;
    Employer e;
    do
    {
        e=Lire_Employer();
        Tab_Emp[*N]=e;
        (*N)++;
        printf("Voulez-vous ajouter un autre employer? [0/1]: ");
        scanf("%d",&cnf);
    }
    while(cnf==1);
}
void Affiche_Employer(Employer e)
{
    printf("Le numero CNSS de l'employer est : %d \n",e.CNSS);
    printf("Le nom de l'employer est : %s \n",e.Nom);
    printf("Le prenom de l'employer est : %s \n",e.Prenom);
    printf("La grade de l'employer est : %s \n",e.Grade);
}
void Affiche_Tab_Employer(Employer *Tab_Emp,int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("L'employer N%d :\n",i+1);
        Affiche_Employer(Tab_Emp[i]);
    }
}
int Recherche_Employer(Employer* tab_employer,int N,int num)
{
    for(int i=0;i<N;i++)
    {
        if (tab_employer[i].CNSS==num)
        {
            return i;
        }
    }
    return -1;
}
Fiche Lire_Fiche(Employer* Tab_Employer, int *N)
{
    Fiche F;
    int num_cnss,i,choice;
    printf("Donner le numero CNSS de l'employer: ");
    scanf("%d",&num_cnss);
    i=Recherche_Employer(Tab_Employer,*N,num_cnss);
    if (i!=-1)
    {
        printf("Donnez Le numero de la fiche: \n");
        scanf("%d",&F.Numero);
        printf("Donnez le montant de la fiche:\n");
        scanf("%d",&F.Montant);
        printf("Donnez le mois de la fiche:\n");
        scanf("%d",&F.Mois);
        F.employer=Tab_Employer[i];
    }
    else
    {
        printf("L'employer ayant ce numero de CNSS n'existe pas. Voulez vous l'ajouter? [0/1] ");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Donnez l'employer de la fiche:\n");
            F.employer=Lire_Employer();
            Tab_Employer[*N]=F.employer;
            (*N)++;
            printf("Donnez Le numero de la fiche: \n");
            scanf("%d",&F.Numero);
            printf("Donnez le montant de la fiche:\n");
            scanf("%d",&F.Montant);
            printf("Donnez le mois de la fiche:\n");
            scanf("%d",&F.Mois);
        }
    }
    return F;
}
void Lire_Tab_Fiche(Fiche* Tab_Fiche, int*M, Employer* Tab_Employer, int *N)
{
    int cnf;
    Fiche F;
    do
    {
        F=Lire_Fiche(Tab_Employer,&(*N));
        Tab_Fiche[*M]=F;
        (*M)++;
        printf("Voulez-vous ajouter une autre fiche? [0/1]: ");
        scanf("%d",&cnf);
    }
    while(cnf==1);
}
void Affiche_Fiche(Fiche F)
{
    printf("Le numero de la fiche est : %d \n",F.Numero);
    printf("Le montant de la fiche est : %d \n",F.Montant);
    printf("Le mois de la fiche est : %d \n",F.Mois);
    Affiche_Employer(F.employer);
}
void Affiche_Tab_Fiche(Fiche*Tab_Fiche,int M)
{
    int i;
    for(i=0;i<M;i++)
    {
        printf("La fiche N%d :\n",i+1);
        Affiche_Fiche(Tab_Fiche[i]);
    }
}
int * Recherche_Fiche_CNSS(Fiche* Tab_Fiche,int M)
{
    int num,*tab;
    tab=malloc(30*sizeof(Fiche));
    int i;
    printf("Donnez le numero CNSS de l'employer:\n");
    scanf("%d",&num);
    for(i=0;i<M;i++)
    {
        if(num==Tab_Fiche[i].employer.CNSS)
        {
            tab[i]=1;
        }
        else
        {
            tab[i]=0;
        }
    }
    return tab;
}
int Recherche_Fiche_NUM(Fiche* Tab_Fiche, int M)
{
    int num;
    int i;
    printf("Donnez le numero de la fiche:\n");
    scanf("%d",&num);
    for(i=0;i<M;i++)
    {
        if(num==Tab_Fiche[i].Numero)
        {
            return i;
        }
    }
    return -1;
}
void Modifie_Fiche(Fiche* F,Employer* Tab_Employer,int N)
{
    int j,i,emp,cns;
    while(1)
    {
        printf("**************************************************\n\t\t\tMENU\n**************************************************\n");
        printf("1. Modifier le montant.\n2. Modifier le mois.\n3. Modifier l'employer.\n0. Quitter.\n");
        printf("**************************************************\n");
        scanf("%d",&j);
        cns=F->employer.CNSS;
        emp=Recherche_Employer(Tab_Employer,N,cns);
        switch(j)
        {
            case 0:
                {
                    return 0;
                }
            case 1:
                {
                    printf("Donnez le nouveau montant:\n");
                    scanf("%d",&F->Montant);
                    break;
                }
            case 2:
                {
                    printf("Donnez le nouveau mois:\n");
                    scanf("%d",&F->Mois);
                    break;
                }
            case 3:
                {
                    printf("**************************************************\n \t    MODIFICATION DE L'EMPLOYER\n");
                    printf("**************************************************\n");
                    printf("1. Modifier le numero CNSS.\n2. Modifier le nom.\n3. Modifier le prenom.\n4. Modifier la grade.\n");
                    printf("**************************************************\n");
                    scanf("%d",&i);
                    if (i==1)
                    {
                        printf("Donnez le nouveau numero CNSS de l'employer:\n");
                        scanf("%d",&F->employer.CNSS);
                        break;
                    }
                    if (i==2)
                    {
                        printf("Donnez le nouveau nom de l'employer:\n");
                        scanf("%s",F->employer.Nom);
                        break;
                    }
                    if (i==3)
                    {
                        printf("Donnez le nouveau prenom de l'employer:\n");
                        scanf("%s",F->employer.Prenom);
                        break;
                    }
                    if (i==4)
                    {
                        printf("Donnez la nouvelle grade de l'employer:\n");
                        scanf("%s",F->employer.Grade);
                        break;
                    }
                    break;
                }
        }
        Tab_Employer[emp]=F->employer;
    }
}
void Supprime_Fiche(Fiche *Tab_Fiche,int *M,int pos)
{
    int i;
    for(i=pos;i<(*M)-1;i++)
    {
        Tab_Fiche[i]=Tab_Fiche[i+1];
    }
    (*M)--;
}
int Montant_totale(Fiche *tab_fiche,int M,int mois)
{
    int totale=0;
    for(int i=0;i<M;i++)
    {
        if (tab_fiche[i].Mois==mois)
        {
            totale+=tab_fiche[i].Montant;
        }
    }
    return totale;
}
