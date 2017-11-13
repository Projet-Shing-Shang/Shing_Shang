#ifndef LIGNE_H
#define LIGNE_H
#include <stdio.h>
#include <stdlib.h>
#include <case_plateau.h>

typedef struct Ligne Ligne;
struct Ligne
{
  CasePlateau t_case[TAILLE_PLATEAU];
};

void initialisation_Ligne(ligne *ligne);

#endif
