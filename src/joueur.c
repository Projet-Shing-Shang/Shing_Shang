#include <joueur.h>

void initialisation_Joueur(Joueur *j,int a)
{
  int i;
  j->num_joueur = a;
  for(i=0 ; i<2; i++)
  {
    j->t_pion[i].joueur = a;
    j->t_pion[i].type = 0; // pion vide
  }
}

//tu a bien créer la premierre pyramide mais il en reste 3 (celle de droite et les deux du joueur 2)
void initialisation_pion ( Joueur *joueur, Plateau *plateau)
{
  Pion pion, pion2; // TYPE et variable
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
         //en haut à droite
        pion2.x=9-pion.x;
        pion2.type = i;
        pion2.joueur = joueur -> num_joueur;
        pion2.y = 3-j;
        joueur -> t_pion[cpt] = pion2;
        plateau -> t_casePlateau[pion2.y][pion2.x].p_pion = &(joueur -> t_pion[cpt]);
        cpt++;
      }
    }
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
  do
  {
    vider_buffer();
    printf("\n\n joueur %d quel piond voulez vous déplacer? ", joueur->num_joueur);
    printf("x ?\n");scanf("%d",&x);
    printf("y ?\n");scanf("%d",&y);
  }
  while(x<0 || x>10 || y<0 || y>10);
  if(plateau->t_casePlateau[y][x].p_pion == NULL)
    {
      printf("cette case est vide \n sélectionez en une autre");
      choix_pion(joueur,joueurAdverce,plateau,pion_precedant,shingShang);
    }
  else
  {
    if (plateau->t_casePlateau[y][x].p_pion->joueur == joueur ->num_joueur && (plateau->t_casePlateau[y][x].p_pion != pion_precedant || shingShang ==0))
    {
      //affichage_pion(plateau->t_casePlateau[y][x].p_pion);

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
            //printf("déplacement normal disponible direction ");
            t_possibilitees[cpt].x = pion->x+j;
          //  printf(" x : %d", pion->x+j);
            t_possibilitees[cpt].y = pion->y+i;
          //  printf(" y : %d\n", pion->y+i);
            t_possibilitees[cpt].type = 1;//deplacement normal
          }
          if(plateau->t_casePlateau[pion->y+i][pion->x+j].p_pion != NULL)
          {
        //    printf("il y a un saut");
            t_possibilitees[cpt].x = pion->x+(j*2);//on entre les cohordonées d arivées
          //  printf("  x : %d",pion->x+(j*2));
            t_possibilitees[cpt].y = pion->y+(i*2);
          //  printf("  y : %d \n",pion->y+(i*2));
            if(plateau->t_casePlateau[pion->y+i][pion->x+j].p_pion->joueur == joueur->num_joueur) t_possibilitees[cpt].type = 2;//saut
            else
            {
              if(saut == 1)t_possibilitees[cpt].type = 3;
              else t_possibilitees[cpt].type = 2;//si l on a pas encor sauter
            }
            if(saut == 1 || pion->type ==3)cpt++;
          }
          if(saut!=1 && pion->type !=3)cpt++;

          if(pion->type == 1 && saut != 1)
          {
            if(droit_deplacement(pion, plateau,pion->x+(j*2),pion->y+(i*2)))
            {
          //    printf("déplacement singe de deux cases");
              t_possibilitees[cpt].x = pion->x+(j*2);
          //   printf("  x : %d",pion->x+(j*2));
              t_possibilitees[cpt].y = pion->y+(i*2);
          //   printf("  y : %d \n",pion->y+(i*2));
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
    choix_pion(joueur,joueurAdverce, plateau, pion, 0);//si le pion ne peut pas bouger, on choisi un autre pion
  }
    for(i=0;i<cpt;i++)plateau->t_casePlateau[t_possibilitees[i].y][t_possibilitees[i].x].deplacement = 1;
    affichage_plateau(plateau);//plateau avec cases de deplacement possible
    printf("vous pouvez déplacer ce pion en : \n");
    printf("\n0 : finir son tour\n");
  for(i=0;i<cpt;i++)
  {
    if(t_possibilitees[i].type == 2)printf("saut | ");
    if(t_possibilitees[i].type == 3)printf("ShingShang | ");
    printf("%d : x = %d  | y = %d \n",i+1,t_possibilitees[i].x,t_possibilitees[i].y);
  }
  do
  {
    vider_buffer();
    printf("quel déplacement voulez vous faire ?");
    scanf("%d",&chois);
  }while(chois<0||chois>cpt+1);
  for(i=0;i<cpt;i++)plateau->t_casePlateau[t_possibilitees[i].y][t_possibilitees[i].x].deplacement = 0;
  affichage_plateau(plateau);//plateau sans cases de deplacement possible
  if(chois == 0)jouer(joueurAdverce ,joueur, plateau);
  if(t_possibilitees[chois-1].type == 3)// si c est un shingShang
  {//on détruis le pion entre la position actuel du pion et sa position future
    destruction_pion(plateau, plateau->t_casePlateau[pion->y-(pion->y-t_possibilitees[chois-1].y)/2][pion->x-(pion->x-t_possibilitees[chois-1].x)/2].p_pion,joueurAdverce);
  }
  deplacement_pion(plateau, pion, t_possibilitees[chois-1].x, t_possibilitees[chois-1].y); // on déplace le pion
  sauvegarde(plateau);
  if(gagner_contre(joueurAdverce,plateau))jouer(joueurAdverce, joueur,plateau);
  if(t_possibilitees[chois-1].type == 2)//si c est un saut alier
  {
    printf("vous pouvez sauter une nouvelle fois \n");
    prevision_deplacement_pion(pion,plateau,joueur,joueurAdverce,1);//on rechoisit une destination en précisant que l on a déja sauter
  }
  else if(t_possibilitees[chois-1].type == 3)// si c est un shingShang
  {
    choix_pion(joueur,joueurAdverce, plateau,pion,1);//on rechoisit un pion en aillant interdiction de rechoisir le même pion
  }
  else if(t_possibilitees[chois-1].type == 1)jouer(joueurAdverce ,joueur, plateau);// on passe au tour adverce
}

void deplacement_pion(Plateau * plateau,Pion * pion,int x,int y)
  {
    plateau->t_casePlateau[y][x].p_pion = pion;
    plateau->t_casePlateau[pion->y][pion->x].p_pion = NULL;
    pion->x = x;
    pion->y = y;
    affichage_plateau(plateau);
  }

void affichage_pion_joueur(Joueur * joueur) // fonction qui affiche tout les pions d un joueur
{
  int i;
  for(i=0; i<12 ; i++)
  {
    printf("pion nb %d : %u  x: %d  y: %d  \n",i,joueur->t_pion[i].type,joueur->t_pion[i].x,joueur->t_pion[i].y);
  }
}


int jouer(Joueur * joueur, Joueur * joueurAdverce, Plateau * plateau)
{
    if(gagner_contre(joueur,plateau))
    {
      clear_console();
      printf("\n-------------------------\nVictoire du joueur %d !!!\n-------------------------\n",joueurAdverce->num_joueur);
      return 0;
    }
    choix_pion( joueur,joueurAdverce, plateau, NULL,0);
}

void destruction_pion(Plateau * plateau, Pion * pion, Joueur * joueur)
{
  int rang;
  int i=0;
  while (joueur->t_pion[i].x!= pion->x && joueur->t_pion[i].y != pion->y) //on retrouve le pion dans le tableau du joueur
  {
    i++;
  }
  rang = i;
  plateau->t_casePlateau[pion->y][pion->x].p_pion = NULL; //on met le pointeur de la case sur NULL
  //on met le pion a 0 partout, sois la valeur d un pion détruit
    joueur->t_pion[rang].type = 0;
    joueur->t_pion[rang].x = 0;
    joueur->t_pion[rang].y = 0;
}


int gagner_contre(Joueur * joueur, Plateau * plateau) //pour vérifier si un joueur a gagner on passe en parametre son adversaire
{
  int i;
  int cpt_dragons = 0;
  int victoire = 0;
  for ( i = 0; i < 12; i++)
  {
    if(joueur->t_pion[i].type == 3) cpt_dragons ++;
  }
  if(cpt_dragons == 0)victoire = 1;//si le joueur adverce n a plus de dragons, on a gagner
  if (joueur->num_joueur == 1) //si on vérifie que le joueur deux a gagner
  {
    if((plateau->t_casePlateau[1][4].p_pion!=NULL) ||//on regarde si il y a des pions sur les portes du joueur 1
       (plateau->t_casePlateau[1][5].p_pion != NULL))victoire=1;
  }// si on regarde si le joueur un a gagner
  else if((plateau->t_casePlateau[8][4].p_pion!=NULL) ||//on regarde si les portes du joueur 2 son occupées par des pieces du joueur 1
          (plateau->t_casePlateau[8][5].p_pion != NULL))victoire=1;
  return victoire;
}



void sauvegarde(Plateau * plateau)
{
	int tab[4];

	FILE* fichier = NULL;
    fichier = fopen("save/save.txt", "wb+");

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(plateau->t_casePlateau[i][j].p_pion != NULL)
			{
				tab[0] = i;
				tab[1] = j;
				tab[2] = plateau->t_casePlateau[i][j].p_pion->type;
				tab[3] = plateau->t_casePlateau[i][j].p_pion->joueur;
				fwrite(tab , sizeof(int) , 4 , fichier);
			}
		}
	}
	fclose(fichier);
}
