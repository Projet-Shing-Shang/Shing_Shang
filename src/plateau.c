#include <plateau.h>


void initialisation_Plateau(Plateau *plateau)
  {
    int i,j;
    CasePlateau tab[8];
    CasePlateau tab2[10];
    for(i=0;i<10;i++)
    {
      if(i!=5 && i != 4)
      {
        plateau -> t_lignePlateau[i] = tab;
      }
      else
      {
        plateau -> t_lignePlateau[i] = tab2;
      }
    }
    for(i=0;i<10;i++)
    {

      for(j=0;j<10;j++)
      {
        if((i != 5 && i != 4)&&(j == 8))break;
        plateau->t_lignePlateau[i][j].x = j;
              printf("%d ",i);
        plateau->t_lignePlateau[i][j].y = i;
        printf(" mais %d\n ", plateau -> t_lignePlateau[i][j].y);

      }
    }
    affichage_plateau(&plateau);
  }


  void affichage_plateau(Plateau **plateau)
  {
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
          printf("| %d",(*plateau) -> t_lignePlateau[i][j].x);
          printf(":%d ",(*plateau) -> t_lignePlateau[i][j].y);
      }
    if(i != 3 && i != 4 && i != 5)
    {
      printf("|\n       -------------------------------------------------\n" );
    }
    else printf("|\n-------------------------------------------------------------\n");
    }
  }
