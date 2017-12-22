#include <shing_shang.h>

void initialisation()
{
  Joueur j1;
  Joueur j2;
  Plateau plateau;

  initialisation_Joueur(&j1,1);
  initialisation_Joueur(&j2,2);
  initialisation_Plateau(&plateau);
  initialisation_pion(&j1,&plateau);
  affichage_plateau(&plateau);
  destruction_pion(&plateau, &j1.t_pion[0],&j1);
  affichage_plateau(&plateau);
  jouer(&j1,&j2,&plateau);
}
