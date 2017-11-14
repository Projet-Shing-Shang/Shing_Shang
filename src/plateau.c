#include <plateau.h>

void initialisation_Ligne(Plateau *plateau, Ligne ligne,int num_ligne)
{
    plateau -> t_lignePlateau[num_ligne] = ligne;
}

void initialisation_Plateau(Plateau *plateau)
  {
    int i,j;
    Ligne ligne;
    for(i=0;i<10;i++)
    {
      initialisation_Ligne(plateau,ligne,i);
      for(j=0;j<10;j++)
      {
        if((i != 5 && i != 4)&&(j == 8))break;
        plateau->t_lignePlateau[i].t_case[j].x = j;
        plateau->t_lignePlateau[i].t_case[j].y = i;

      }
    }
  }




  void affichage_plateau(Plateau *plateau)
  {
    clear_console();
    int i,j;
    for(i=0;i<10;i++)
    {
      if(i != 5 && i != 4)
      {
        printf("       ");
      }
      for(j=0;j<10;j++)
      {
        if((i != 5 && i != 4)&&(j == 8))break;
          printf("| %d",plateau -> t_lignePlateau[i].t_case[j].x);
          printf(":%d ",plateau -> t_lignePlateau[i].t_case[j].y);
      }
    if(i != 3 && i != 4 && i != 5)
    {
      printf("|\n       -------------------------------------------------\n" );
    }
    else printf("|\n-------------------------------------------------------------\n");
    }
  }
