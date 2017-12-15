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


void afficher_ligne(Plateau * plateau, int nligne)
{
  int x;
  printf("%d|  ",nligne);
  for (x=0;x<10;x++)
  {
    afficher_case(plateau,x,nligne);
  }
  if(nligne != 3 && nligne != 4 && nligne != 5)
  {
    printf("|\n       -------------------------\n" );
  }
  else printf("|\n    ------------------------------\n");

}

void afficher_case(Plateau * plateau, int x, int y)
{
  if(plateau -> t_casePlateau[y][x].type == -1)
  {
    if(x == 0)
    printf("   ");
    // else
    // printf("");
  }
  else
  {
    if (plateau -> t_casePlateau[y][x].p_pion == NULL)
    {
      if (plateau -> t_casePlateau[y][x].type == 0)
      {
        printf("|  ");
      }
      else
      {
        printf("| %d",plateau -> t_casePlateau[y][x].type);
      }
    }
    else
    {
      printf("| %u",plateau -> t_casePlateau[y][x].p_pion->type);
    }
  }
}


//deffinir en plusieures fonctions
  void affichage_plateau(Plateau *plateau)
  {
    clear_console();
    int i;
    printf("   | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9");
    printf("|\n       -------------------------\n" );
    for(i=0;i<10;i++)
    {
      afficher_ligne(plateau,i);
    }
  }




  int droit_deplacement(Pion * pion, Plateau * plateau,int x, int y)
  {
    int valide = 1;
    if ((valide == 1 && plateau->t_casePlateau[y][x].type == -1)|| x<0 || y<0)valide = 0; //si la case est hors plateau
    if (valide == 1 && plateau->t_casePlateau[y][x].type > 0 && pion->type != 3)valide = 0 ;// si c est une porte et que l on a pas un dragon
    if (valide == 1 && plateau->t_casePlateau[y][x].p_pion != NULL) //si la case est prise
    {
        if(plateau->t_casePlateau[y+(y-pion->y)][x+(x-pion->x)].p_pion != NULL) valide = 0;//et que la case d apre est occupée
        else
        {
          if(plateau->t_casePlateau[y][x].p_pion->type > pion->type) valide = 0; //si le pion est plus grand on ne peut pas sautter
          else if (plateau->t_casePlateau[y+(y-pion->y)][x+(x-pion->x)].type > 0 && pion->type != 3) valide = 0; //si la case d arrivée et une porte et que l on a pas un dragon
        }
    }
    return valide;
  }
