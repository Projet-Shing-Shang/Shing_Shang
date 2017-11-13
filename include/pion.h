#ifndef PION_H
#define PION_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Pion Pion;
struct Pion
{
  int type; // 1 singe 2 lion 3 dragon
  int joueur;
  int p_case_plateau;
};

#endif
