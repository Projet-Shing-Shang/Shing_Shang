#include <plateau.h>

void initialisation_Plateau(Plateau *plateau)
  {
    int i,j;
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
      {
        plateau->t_casePlateau[i][j].x = j;
        plateau->t_casePlateau[i][j].y = i;
        plateau->t_casePlateau[i][j].type = 0;
        plateau->t_casePlateau[i][j].p_pion = NULL;
        if((j == 0 || j == 9)&&( i != 4 && i != 5))
        plateau->t_casePlateau[i][j].type = -1 ;
      }
    }
    plateau->t_casePlateau[1][4].type = 1;
    plateau->t_casePlateau[1][5].type = 1;
    plateau->t_casePlateau[8][4].type = 2;
    plateau->t_casePlateau[8][5].type = 2;
  }




  void affichage_plateau(Plateau *plateau)
  {
    clear_console();
    int i,j;
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
      {
          if(plateau -> t_casePlateau[i][j].type == -1)
          {
            printf("  ");
          }
          else
          {
            if (plateau -> t_casePlateau[i][j].p_pion == NULL)
            {
              if (plateau -> t_casePlateau[i][j].type == 0)
              {
                printf("|  ");
              }
              else
              {
                printf("| %d",plateau -> t_casePlateau[i][j].type);
              }
            }
            else
            {
              printf("| %u",plateau -> t_casePlateau[i][j].p_pion->type);
            }
          }
      }
    if(i != 3 && i != 4 && i != 5)
    {
      printf("|\n  ---------------------------\n" );
    }
    else printf("|\n-------------------------------\n");
    }
  }

  /*int droit_deplacement(Pion * pion, Plateau*plateau,int x, int y)
  {
    int valide = 1;
    if (valide == 1 && plateau[y][x].type == -1)valide = 0; //si la case est hors plateau
    if (valide == 1 && plateau[y][x].p_pion != NULL) //si la case est prise

    return valide;
  }*/
