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


void initialisation_pion ( Joueur *joueur, Plateau *plateau)
{
  Pion pion; // TYPE et variable
  int y,x,cpt;
  cpt = 0;
  for ( y = 3 ; y > 0 ; y--)
  {
    for (x = y ; x > 0; x--)
    {
      if ( x == 3)
        pion.type = 'D';
      if ( x == 2)
        pion.type = 'L';
      else
        pion.type = 'S';
      pion.joueur = joueur -> num_joueur;
      pion.x = (y-x)+1;
      pion.y = 3-y;
      joueur -> t_pion[cpt];
      plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
      cpt ++;
    }
  }
}
