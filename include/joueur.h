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
  Pion t_pion[24];
};

void initialisation_Joueur(Joueur *j1,int a);
void initialisation_pion ( Joueur *joueur,Plateau *plateau);
void affichage_pion_joueur(Joueur * joueur);
void chois_pion(Joueur * joueur,Joueur * joueurAdverce, Plateau * plateau,Pion * pion_precedant,int shingShang);
void prevision_deplacement_pion(Pion * pion, Plateau * plateau,Joueur * joueur,Joueur * joueurAdverce, int saut);
void deplacement_pion(Plateau * plateau,Pion * pion,int x,int y);
int jouer(Joueur * joueur, Joueur * joueurAdverce, Plateau * plateau);
void destruction_pion(Plateau * plateau, Pion * pion, Joueur * joueur);
int gagner_contre(Joueur * joueur, Plateau * plateau);
void sauvegarde(Plateau * plateau);

#endif
