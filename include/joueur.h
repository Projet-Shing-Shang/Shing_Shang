#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <pion.h>
#include <utilitaire.h>
#include <plateau.h>


typedef struct Joueur Joueur;
struct Joueur
{
  int num_joueur;
  Pion t_pion[12];
  int couleur;
};

void initialisation_Joueur(Joueur *j1,int a);
void initialisation_pion ( Joueur *joueur,Plateau *plateau);
void affichage_pion_joueur(Joueur * joueur);
void chois_pion(Joueur * joueur, Plateau * plateau);
void prevision_deplacement_pion(Pion * pion, Plateau * plateau,Joueur * joueur);
void deplacement_pion(Plateau * plateau,Pion * pion,int x,int y);

#endif
