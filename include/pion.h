#ifndef PION_H
#define PION_H
#include <stdio.h>
#include <stdlib.h>

typedef enum Type_pion Type_pion;
enum Type_pion
{
  S/*SINGE*/,L/*LION*/,D/*DRAGON*/
};

typedef struct Pion Pion;
struct Pion
{
  Type_pion type; // S singe; L lion; D dragon
  int joueur;
  int x;
  int y;
};

void affichage_pion(Pion * pion);

#endif
