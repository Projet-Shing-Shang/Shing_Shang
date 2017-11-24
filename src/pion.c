#include <pion.h>

void affichage_pion(Pion * pion)
{
  printf("pion :  | x : %d | y  : %d | joueur: %d | type : %u |\n",pion->x,pion->y,pion->joueur,pion->type);
}
