#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <pion.h>
#include <utilitaire.h>

typedef struct Joueur Joueur;
struct Joueur
{
  int num_joueur;
  Pion t_pion[12];
  int couleur;
};

void initialisation_Joueur(Joueur *j1,int a);


#endif