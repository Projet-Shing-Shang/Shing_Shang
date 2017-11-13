#ifndef PLATEAU_H
#define PLATEAU_H
#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>
#include <ligne.h>

typedef struct Plateau Plateau;
struct Plateau
{
  Ligne t_lignePlateau[TAILLE_PLATEAU];
};

void initialisation_Plateau(Plateau *plateau);
void affichage_plateau(Plateau **plateau);

#endif
