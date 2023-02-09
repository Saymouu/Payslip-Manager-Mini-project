#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct Emp{
    int CNSS;
    char Nom[15];
    char Prenom[15];
    char Grade[15];
}Employer;
typedef struct Fch{
    int Numero;
    int Montant;
    int Mois;
    Employer employer;
}Fiche;

#endif // STRUCTURE_H_INCLUDED
