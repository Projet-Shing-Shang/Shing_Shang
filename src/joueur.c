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

//tu a bien créer la premierre pyramide mais il en reste 3 (celle de droite et les deux du joueur 2)
void initialisation_pion ( Joueur *joueur, Plateau *plateau)
{
  Pion pion; // TYPE et variable
  int y,x,cpt;
  cpt = 0;
  for ( y = 3 ; y > 0 ; y--)
  {
    for (x = y ; x > 0; x--)
    {
      pion.type = x;
      pion.joueur = joueur -> num_joueur;
      pion.x = (y-x)+1;
      pion.y = 3-y;
      joueur -> t_pion[cpt] = pion;
      plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
      cpt ++;
    }
  }
}

void chois_pion(Joueur * joueur, Plateau * plateau)
{
  int x,y;
  printf("\n\n joueur %d quel piond voulez vous déplacer? ", joueur->num_joueur);
  printf("x ?\n");scanf("%d",&x);
  printf("y ?\n");scanf("%d",&y);
  if(plateau->t_casePlateau[y][x].p_pion == NULL)
    {
      printf("cette case est vide \n sélectionez en une autre");
      chois_pion(joueur,plateau);
    }
  else
  {
    if (plateau->t_casePlateau[y][x].p_pion->joueur == joueur ->num_joueur)
    {
      affichage_pion(plateau->t_casePlateau[y][x].p_pion);

      prevision_deplacement_pion(plateau->t_casePlateau[y][x].p_pion,plateau);
    }
    else
    {
      printf("ce pion ne vous appartien pas !\n veuillez en selectioner un autre");
      chois_pion(joueur,plateau);
    }
  }
}

//passer le tableau en dinamique
void prevision_deplacement_pion(Pion * pion, Plateau * plateau)
{
  int i,j,nb_en_fonction_pion;

  CasePlateau t_possibilitees[8];
  int cpt = 0;
  for(i=-1 ;i<2;i++)
  {
    for(j=-1;j<2;j++)
    {
      //if((plateau -> t_casePlateau[pion->y+i][pion->x+j].p_pion == NULL)&&((plateau -> t_casePlateau[pion->y+i][pion->x+j].type == 0)||((plateau -> t_casePlateau[pion->y+i][pion->x+j].type > 0)&&(pion->type == 3))))//si la case n a pas de pion et que son type est de base ou que c est une porte mais que le pion est un dragon
      if(droit_deplacement(pion, plateau, pion->x+j, pion->y+i))
      {
          t_possibilitees[cpt].x = pion->x+j;
          t_possibilitees[cpt].y = pion->y+i;
          if(plateau->t_casePlateau[pion->y+i][pion->x+j].p_pion != NULL)
          {
            printf("il y a un saut");
            t_possibilitees[cpt].x = pion->x+(j*2);
            printf("  x : %d",pion->x+(j*2));
            t_possibilitees[cpt].y = pion->y+(i*2);
            printf("  y : %d \n",pion->y+(i*2));
          }
          cpt++;
          if(pion->type == 1)
          {
            if(droit_deplacement(pion, plateau,pion->x+(j*2),pion->y+(i*2)))
            {
              printf("déplacement singe de deux cases");
              t_possibilitees[cpt].x = pion->x+(j*2);
              printf("  x : %d",pion->x+(j*2));
              t_possibilitees[cpt].y = pion->y+(i*2);
              printf("  y : %d \n",pion->y+(i*2));
              cpt++;
            }
          }
      }
    }
  }
  printf("vous pouvez déplacer ce pion en : \n");
  if(cpt == 0)
  {
    printf("pas de possibilitée de mouvement");
  }
  for(i=0;i<cpt;i++)
  {
    printf(" x = %d  | y = %d \n",t_possibilitees[i].x,t_possibilitees[i].y);
  }
}



void affichage_pion_joueur(Joueur * joueur)
{
  int i;
  for(i=0; i<12 ; i++)
  {
    printf("pion nb %d : %u  x: %d  y: %d  \n",i,joueur->t_pion[i].type,joueur->t_pion[i].x,joueur->t_pion[i].y);
  }
}
