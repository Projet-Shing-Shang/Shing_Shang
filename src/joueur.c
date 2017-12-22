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
  int i, j, cpt;
  cpt = 0;
  if (joueur->num_joueur == 1)
  {
    for ( j = 3 ;j > 0 ; j--)   //en haut à gauche
    {
      for (i = j ; i > 0; i--)
      {
        pion.type = i;
        pion.joueur = joueur -> num_joueur;
        pion.x = (j-i)+1;
        pion.y = 3-j;
        joueur -> t_pion[cpt] = pion;
        plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
        cpt ++;
      }
    }
    /*for ( j = 0 ; j < 3 ; j++)  //en haut à droite
      {
      for (i = 8 ; i > 5; i--)
       {
        pion.type = j
        pion.joueur = joueur -> num_joueur;
        pion.x = (j-i)+4;
        pion.y = 1+j;
        joueur -> t_pion[cpt] = pion;
        plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
        cpt ++;
       }
    }*/
  }
  else
  {
    cpt=0;
    for ( j = 7 ; j < 10 ; j++)  //en bas à gauche
      {
      for (i = 1 ; i < 4; i++)
        {
          pion.type = i;
          pion.joueur = joueur -> num_joueur;
          pion.x = (j-i)-5;
          pion.y = j;
          joueur -> t_pion[cpt] = pion;
          plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
          cpt ++;
        }
      }
        for ( j = 7 ; j < 10 ; j++)  //en bas à droite
        {
         for (i = 8 ; i > 14 - j ; i--)
         {
           pion.type = (j+i)-14;
           pion.joueur = joueur -> num_joueur;
           pion.x = i;
           pion.y = j;
           joueur -> t_pion[cpt] = pion;
           plateau -> t_casePlateau[pion.y][pion.x].p_pion = &(joueur -> t_pion[cpt]);
           cpt ++;
         }
      }
  }
}

void choix_pion(Joueur * joueur,Joueur * joueurAdverce, Plateau * plateau,Pion * pion_precedant,int shingShang)
{
  int x,y;
  printf("\n\n joueur %d quel piond voulez vous déplacer? ", joueur->num_joueur);
  printf("x ?\n");scanf("%d",&x);
  printf("y ?\n");scanf("%d",&y);
  if(plateau->t_casePlateau[y][x].p_pion == NULL)
    {
      printf("cette case est vide \n sélectionez en une autre");
      choix_pion(joueur,joueurAdverce,plateau,pion_precedant,shingShang);
    }
  else
  {
    if (plateau->t_casePlateau[y][x].p_pion->joueur == joueur ->num_joueur && (plateau->t_casePlateau[y][x].p_pion != pion_precedant || shingShang ==0))
    {
      affichage_pion(plateau->t_casePlateau[y][x].p_pion);

      prevision_deplacement_pion(plateau->t_casePlateau[y][x].p_pion,plateau, joueur ,joueurAdverce,0);
    }
    else
    {
      printf("ce pion ne vous appartien pas !\n veuillez en selectioner un autre");
      choix_pion(joueur,joueurAdverce, plateau,pion_precedant, shingShang);
    }
  }
}


void prevision_deplacement_pion(Pion * pion, Plateau * plateau,Joueur * joueur,Joueur * joueurAdverce, int saut)
{
  int i,j,nb_en_fonction_pion,chois;

  CasePlateau t_possibilitees[16];
  for(i=0;i<16;i++)
  {
    t_possibilitees[i].x =0;
    t_possibilitees[i].y =0;
    t_possibilitees[i].type =0;
  }
  int cpt = 0;
  for(i=-1 ;i<2;i++)
  {
    for(j=-1;j<2;j++)
    {
      //if((plateau -> t_casePlateau[pion->y+i][pion->x+j].p_pion == NULL)&&((plateau -> t_casePlateau[pion->y+i][pion->x+j].type == 0)||((plateau -> t_casePlateau[pion->y+i][pion->x+j].type > 0)&&(pion->type == 3))))//si la case n a pas de pion et que son type est de base ou que c est une porte mais que le pion est un dragon
      if(droit_deplacement(pion, plateau, pion->x+j, pion->y+i))
      {
          if(pion->type != 3 && saut != 1)
          {
            printf("déplacement normal disponible direction ");
            t_possibilitees[cpt].x = pion->x+j;
            printf(" x : %d", pion->x+j);
            t_possibilitees[cpt].y = pion->y+i;
            printf(" y : %d\n", pion->y+i);
            t_possibilitees[cpt].type = 1;//deplacement normal
          }
          if(plateau->t_casePlateau[pion->y+i][pion->x+j].p_pion != NULL)
          {
            printf("il y a un saut");
            t_possibilitees[cpt].x = pion->x+(j*2);
            printf("  x : %d",pion->x+(j*2));
            t_possibilitees[cpt].y = pion->y+(i*2);
            printf("  y : %d \n",pion->y+(i*2));
            if(plateau->t_casePlateau[pion->y+i][pion->x+j].p_pion->joueur == joueur->num_joueur) t_possibilitees[cpt].type = 2;//saut
            else
            {
              t_possibilitees[cpt].type = 2;//si l on a pas encor sauter
              if(saut == 1)t_possibilitees[cpt].type = 3;
            }
            if(saut == 1)cpt++;
          }
          if(saut!=1)cpt++;

          if(pion->type == 1 && saut != 1)
          {
            if(droit_deplacement(pion, plateau,pion->x+(j*2),pion->y+(i*2)))
            {
              printf("déplacement singe de deux cases");
              t_possibilitees[cpt].x = pion->x+(j*2);
              printf("  x : %d",pion->x+(j*2));
              t_possibilitees[cpt].y = pion->y+(i*2);
              printf("  y : %d \n",pion->y+(i*2));
              t_possibilitees[cpt].type = 1;//deplacement normal
              cpt++;
            }
          }
      }
    }
  }

  if(cpt == 0)
  {
    printf("pas de possibilitée de mouvement");
    choix_pion(joueur,joueurAdverce, plateau, pion, 0);
  }
    printf("vous pouvez déplacer ce pion en : \n");
    printf("\n0 : finir son tour\n");
  for(i=0;i<cpt;i++)
  {
    if(t_possibilitees[i].type == 2)printf("saut |\n");
    if(t_possibilitees[i].type == 3)printf("ShingShang |\n");
    printf("%d : x = %d  | y = %d \n",i+1,t_possibilitees[i].x,t_possibilitees[i].y);
  }
  printf("quel déplacement voulez vous faire ?");
  scanf("%d",&chois);
  if(chois == 0)jouer(joueurAdverce ,joueur, plateau);
  deplacement_pion(plateau, pion, t_possibilitees[chois-1].x, t_possibilitees[chois-1].y);
  if(t_possibilitees[chois-1].type == 2)//si c est un saut alier
  {
    printf("vous pouvez sauter une nouvelle fois \n");
    prevision_deplacement_pion(pion,plateau,joueur,joueurAdverce,1);
  }
  if(t_possibilitees[chois-1].type == 3)// si c est un shingShang
  {
//    destruction_pion(plateau, plateau.t_casePlateau[pion->y+(pion->y-t_possibilitees[chois-1].y)/2][pion->x+(pion->x-t_possibilitees[chois-1].x)/2].p_pion, joueurAdverce);
    choix_pion(joueur,joueurAdverce, plateau,pion,1);
  }
}

void deplacement_pion(Plateau * plateau,Pion * pion,int x,int y)
  {
    plateau->t_casePlateau[y][x].p_pion = pion;
    plateau->t_casePlateau[pion->y][pion->x].p_pion = NULL;
    pion->x = x;
    pion->y = y;
    affichage_plateau(plateau);
  }

void affichage_pion_joueur(Joueur * joueur)
{
  int i;
  for(i=0; i<12 ; i++)
  {
    printf("pion nb %d : %u  x: %d  y: %d  \n",i,joueur->t_pion[i].type,joueur->t_pion[i].x,joueur->t_pion[i].y);
  }
}


void jouer(Joueur * joueur, Joueur * joueurAdverce, Plateau * plateau)
{
    //if(gagner(joueurAdverce)) break;
    choix_pion( joueur,joueurAdverce, plateau, NULL,0);
}

void destruction_pion(Plateau * plateau, Pion * pion, Joueur * joueur)
{
  int rang;
  int i=0;
  while (joueur->t_pion[i].x!= pion->x && joueur->t_pion[i].y != pion->y)
  {
    i++;
  }
  rang = i;
  plateau->t_casePlateau[pion->y][pion->x].p_pion = NULL;
  for(i=rang;i<11;i++)
  {
    joueur->t_pion[i] = joueur->t_pion[i+1];
  }
}
