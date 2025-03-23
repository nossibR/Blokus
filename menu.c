#include <graph.h>
#include <stdlib.h>

int menu(void) {
	int running, x, y;
	couleur orange, bleu, noir;
	noir = CouleurParComposante(0,0,0);
	bleu = CouleurParComposante(0,174,239);
	orange = CouleurParComposante(247,148,30);
	running = 1;
	InitialiserGraphique();
	CreerFenetre(0,0,600, 600);
	ChargerImageFond("./Images/linuxvswindows.jpg");
	/* Faire des petits contours aux boutons */
	ChoisirCouleurDessin(noir);
	RemplirRectangle(99,379,162,52);
	RemplirRectangle(339,379,162,52);
	RemplirRectangle(459,529,112,32);
	RemplirRectangle(209,159,192,62);
	RemplirRectangle(175,230,250,50);
	/* Dessiner les boutons */
	ChoisirCouleurDessin(bleu);
	RemplirRectangle(100,380,160,50);
	RemplirRectangle(340,380,160,50);
	RemplirRectangle(460,530,110,30);
	ChoisirCouleurDessin(orange);
	RemplirRectangle(210,160,190,60);
	/* Remplir les boutons avec le texte */
	ChoisirCouleurDessin(noir);
	EcrireTexte(150,410,"PvsP", 1);
	EcrireTexte(380,410,"PvsBOT",1);
	EcrireTexte(492,550,"Quitter",0);
	/* Nom du jeu */
	EcrireTexte(240,200,"BLOCUS", 2);
	ChoisirCouleurDessin(CouleurParComposante(255,255,255));
	EcrireTexte(185,265,"Edition Windows vs Linux",1);
	while(running){
		if(SourisCliquee()){
			x = _X;
			y = _Y;
			if(x>100 && x<260 && y>380 && y<430){
				return 1; /* Code de sortie pour le pvp */
			} else if(x>340 && x<500 && y>380 && y<430){
				return 2; /* Code de sortie pour le pvbot */
			} else if(x>460 && x<570 && y>530 && y<560){
				return 0; /* Code de sortie pour quitter le jeu */
			}
		}
	}
}

