#ifndef CASE_PLATEAU_H
#define CASE_PLATEAU_H
#include <stdio.h>
#include <stdlib.h>
#include <pion.h>

typedef struct CasePlateau CasePlateau;
struct CasePlateau
{
  int x;
  int y;
  int type; //0case normale; -1 case hors plateau; 1 porte j1 ; 2 porte j2
  Pion *p_pion; // pointeur vers le pion
};

#endif
