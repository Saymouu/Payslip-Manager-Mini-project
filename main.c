#include <stdio.h>
#include <stdlib.h>
#include "employer.h"
#include "Structure.h"
#include <time.h>
int main()
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);

    int N=0,M=0,i,j=0;
    int* tab;
    Employer Tab_Employer[30];
    Fiche F,Tab_Fiche[30];

    FILE* Fichier;
    printf("Ouverture des fichiers...\n");
    Fichier=fopen("Fiches.txt","rt");
    if (Fichier==NULL)
        printf("le fichier des fiches n'existe pas.\n");
    else
    {
        while (!feof(Fichier))
        {
            fscanf(Fichier,"%d %d %d %d %s %s %s\n",&Tab_Fiche[M].Numero,&Tab_Fiche[M].Montant,&Tab_Fiche[M].Mois,&Tab_Fiche[M].employer.CNSS,Tab_Fiche[M].employer.Nom,Tab_Fiche[M].employer.Prenom,Tab_Fiche[M].employer.Grade);
            M++;
        }
    }
    fclose(Fichier);
    Fichier=fopen("Employers.txt","rt");
    if (Fichier==NULL)
        printf("le fichier des employers n'existe pas.\n");
    else
    {
        while (!feof(Fichier))
        {
            fscanf(Fichier,"%d %s %s %s\n",&Tab_Employer[N].CNSS,Tab_Employer[N].Nom,Tab_Employer[N].Prenom,Tab_Employer[N].Grade);
            N++;
        }
    }
    fclose(Fichier);
    while(1)
    {
        printf("**************************************************\n\t      GESTION DE FICHE DE PAIE\n**************************************************\n");
        printf("\n******** %d/%d/%d   ********  %d:%d:%d *********\n",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour,instant.tm_min,instant.tm_sec);
        printf("**************************************************\n\t\t\tMENU\n**************************************************\n");
        printf("1. Saisir un employer.\n2. Saisir un ensemble d'employers.\n3. Afficher l'ensemble des employers.\n");
        printf("4. Saisir une fiche.\n5. Saisir un ensemble de fiches.\n6. Afficher l'ensemble des fiches.\n");
        printf("7. Rechercher les fiches d'un employer.\n8. Modifier une fiche.\n9. Supprimer une fiche:\n");
        printf("10. Afficher Le montant totale d'un mois.\n0. Quitter.\n");
        printf("**************************************************\n");
        scanf("%d",&i);
        switch (i)
        {
            case 0:
            {
                if(M!=0)
                {
                    Fichier=fopen("Fiches.txt","wt");
                    for (j=0;j<M;j++)
                    {
                        fprintf(Fichier,"%d %d %d %d %s %s %s\n",Tab_Fiche[j].Numero,Tab_Fiche[j].Montant,Tab_Fiche[j].Mois,Tab_Fiche[j].employer.CNSS,Tab_Fiche[j].employer.Nom,Tab_Fiche[j].employer.Prenom,Tab_Fiche[j].employer.Grade);
                    }
                    fclose(Fichier);
                }
                Fichier=fopen("Employers.txt","wt");
                for (j=0;j<N;j++)
                {
                    fprintf(Fichier,"%d %s %s %s\n",Tab_Employer[j].CNSS,Tab_Employer[j].Nom,Tab_Employer[j].Prenom,Tab_Employer[j].Grade);
                }
                fclose(Fichier);
                exit(1);
            }
            case 1:
            {
                Tab_Employer[N]=Lire_Employer();
                N+=1;
                break;
            }
            case 2:
            {
                Lire_Tab_Employer(Tab_Employer,&N);
                break;
            }
            case 3:
            {
                Affiche_Tab_Employer(Tab_Employer,N);
                break;
            }
            case 4:
            {
                printf("Ajouter une fiche de paie:\n");
                F=Lire_Fiche(Tab_Employer,&N);
                Tab_Fiche[M]=F;
                M++;
                break;
            }
            case 5:
            {
                printf("Ajouter un ensemble de fiches:\n");
                Lire_Tab_Fiche(Tab_Fiche,&M,Tab_Employer,&N);
                break;
            }
            case 6:
            {
                printf("Afficher les fiches:\n");
                Affiche_Tab_Fiche(Tab_Fiche,M);
                break;
            }
            case 7:
            {
                printf("Rechercher les fiches d'un employer:\n");
                tab=Recherche_Fiche_CNSS(Tab_Fiche,M);
                for(j=0;j<M;j++)
                {
                    if ((*tab+j)==1)
                    {
                        Affiche_Fiche(Tab_Fiche[j]);
                    }
                }
                break;
            }
            case 8:
            {
                printf("Modifier une fiche:\n");
                j=Recherche_Fiche_NUM(Tab_Fiche,M);
                if (j==-1)
                    printf("La fiche n'existe pas.\n");
                else
                    Modifie_Fiche(&Tab_Fiche[j],Tab_Employer,N);
                break;
            }
            case 9:
            {
                printf("Supprimer une fiche:\n");
                j=Recherche_Fiche_NUM(Tab_Fiche,M);
                if (j==-1)
                    printf("La fiche n'existe pas.\n");
                else
                    Supprime_Fiche(Tab_Fiche,&M,j);
                break;
            }
            case 10:
            {
                printf("Donner le mois: ");
                int mois;
                scanf("%d",&mois);
                printf("%d", Montant_totale(Tab_Fiche,M,mois));
                break;
            }
        }
    }
    return 0;
}
