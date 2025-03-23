#include <graph.h>
#include <stdlib.h>

#include "grille.h"
#include "menu.h"
#include "PvP.h"
#include "PvBot.h"
#include "fin.h"

int main(void){
	int mode, victoire, jeu=1;
	while(jeu){
		InitialiserGraphique();
		mode = menu();
		FermerGraphique();
		if(mode==1){
			victoire = pvp();
		} else if(mode==2){
			victoire = pvbot();
		} else if(mode==0){
			return EXIT_SUCCESS;
		}
		jeu = fin(victoire);
	}
}
