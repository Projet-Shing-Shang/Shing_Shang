#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>
#include <ligne.h>
#include <utilitaire.h>

typedef struct Plateau Plateau;
struct Plateau
{
  Ligne t_lignePlateau[TAILLE_PLATEAU];
};

void initialisation_Plateau(Plateau *plateau);
void initialisation_Ligne(Plateau *plateau, Ligne ligne,int type);
void affichage_plateau(Plateau *plateau);

#endif
