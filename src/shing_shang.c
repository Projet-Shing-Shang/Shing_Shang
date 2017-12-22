#include <shing_shang.h>

void initialisation()
{
  Joueur j1;
  initialisation_Joueur(&j1,1);
  Joueur j2;
  initialisation_Joueur(&j2,2);
  Plateau plateau;
  initialisation_Plateau(&plateau);
  initialisation_pion(&j1,&plateau);
  initialisation_pion(&j2,&plateau);
  affichage_plateau(&plateau);
  chois_pion(&j1,&plateau);
}
