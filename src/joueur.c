#include <joueur.h>

void initialisation_Joueur(Joueur *j,int a)
{
  int i;
  j->num_joueur = a;
  for(i=0 ; i<2; i++)
  {
    j->t_pion[i].joueur = a;
    j->t_pion[i].type = 3; // dragons
  }
}
