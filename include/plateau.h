#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>
#include <case_plateau.h>
#include <utilitaire.h>

typedef struct Plateau Plateau;
struct Plateau
{
  CasePlateau t_casePlateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
};

void initialisation_Plateau(Plateau *plateau);
void affichage_plateau(Plateau *plateau);

#endif
