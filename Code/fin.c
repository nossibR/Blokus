#include <graph.h>
#include <stdlib.h>

int fin(int victoire){
	int running, sourisX, sourisY;
	couleur orange, bleu, noir;
	noir = CouleurParComposante(0,0,0);
	bleu = CouleurParComposante(0,174,239);
	orange = CouleurParComposante(247,148,30);
	running = 1;
	InitialiserGraphique();
	CreerFenetre(0,0,600, 600);
	ChargerImageFond("./Images/fin.png");
	/* Faire des petits contours aux boutons */
	ChoisirCouleurDessin(noir);
	RemplirRectangle(39,529,112,32); /*rejouer noir*/
	RemplirRectangle(209,159,192,62); /*fin noir*/
	RemplirRectangle(459,529,112,32); /*quitter noir*/
	/* Dessiner les boutons */
	ChoisirCouleurDessin(bleu);
	RemplirRectangle(40,530,110,30); /*rejouer*/
	RemplirRectangle(460,530,110,30); /*quitter bleu*/
	ChoisirCouleurDessin(orange);
	RemplirRectangle(210,160,190,60);
	/* Remplir les boutons avec le texte */
	ChoisirCouleurDessin(noir);
	EcrireTexte(492,550,"Quitter",0);
	EcrireTexte(75,550,"Rejouer",0);
	/* Ecran de fin*/
	EcrireTexte(270,200,"FIN !", 2);
	if(victoire==1){
		EcrireTexte(100,300,"Felicitations windows a gagne!", 2);
	} else if(victoire==2){
		EcrireTexte(100,300,"Felicitations linux a gagne!", 2);
	} else if(victoire==3){
		EcrireTexte(150,300,"N'y a-t-il donc plus d'espoir ", 2);
		EcrireTexte(180,340,"pour les humains..", 2);
	}
	while(running){
		if(SourisCliquee()){
			sourisX = _X;
			sourisY = _Y;
		}
		if(sourisX>40 && sourisX<150 && sourisY>530 && sourisY<560){
			FermerGraphique();
			return 1;
		} else if(sourisX>460 && sourisX<570 && sourisY>530 && sourisY<560){
			FermerGraphique();
			return 0;
		}
	}

}
