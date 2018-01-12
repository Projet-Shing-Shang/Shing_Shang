#include <shing_shang.h>

void initialisation()
{
  Joueur j1;
  Joueur j2;
  Plateau plateau;
  int chois;
  initialisation_Joueur(&j1,1);
  initialisation_Joueur(&j2,2);
  initialisation_Plateau(&plateau);
  do
  {
    clear_console();
    vider_buffer();
    printf("voulez-vous commencer une partie (1) ou charger la partie (2)");
    scanf("%d",&chois);
  }while(chois !=1 && chois != 2);
  if(chois == 1)
  {
  initialisation_pion(&j1,&plateau);
  initialisation_pion(&j2,&plateau);
  }
  else
  {
    lecture_save(&plateau,&j1,&j2);
  }
  affichage_plateau(&plateau);
  jouer(&j1,&j2,&plateau);
}



void lecture_save(Plateau * plateau, Joueur * j1, Joueur * j2)
{
	int i, j, tab[4];
  FILE* fichier = NULL;
  int cpt1 = 0;
  int cpt2 = 0;
    fichier = fopen("save/save.txt", "rb+");

    while(fread(tab , sizeof(tab) , 1 , fichier ) != 0)
    {
      	for(int i = 0; i < 4; i++)
  		{
  			printf("%d", tab[i]);
  		}

  		if(tab[3] == 1)
  		{
        j1->t_pion[cpt1].y = tab[0];
        j1->t_pion[cpt1].x = tab[1];
        j1->t_pion[cpt1].type = tab[2];
        j1->t_pion[cpt1].joueur = tab[3];
  			plateau->t_casePlateau[tab[0]][tab[1]].p_pion = &(j1->t_pion[cpt1]);
        cpt1 ++;
  		}
  		else
  		{
        j2->t_pion[cpt2].y = tab[0];
        j2->t_pion[cpt2].x = tab[1];
        j2->t_pion[cpt2].type = tab[2];
        j2->t_pion[cpt2].joueur = tab[3];
  			plateau->t_casePlateau[tab[0]][tab[1]].p_pion = &(j2->t_pion[cpt2]);
        cpt2 ++;
  		}

  		printf("\n");
    }

	fclose(fichier);
}
