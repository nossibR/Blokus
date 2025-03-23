#include <graph.h>
#include <stdlib.h>

int** definegrille(int taille) {
	int i, j;
	int** grille = (int**) calloc(taille, sizeof(int*)); 

	for (i=0 ; i<taille; i++) {
		grille[i] = (int*) calloc(taille, sizeof(int)); 
	}

	for (i=0 ; i<taille ; i++) {
		for (j = 0; j < taille; j++) {
			grille[i][j] = 0; /*Initialisation à 0 pour toutes les cases de la grille */
		}
	}
	for (i = 0; i < taille; i++) {
		grille[i][0] = 9;           /* Initialisation de la bordure à gauche */
		grille[i][taille - 1] = 9; /* Initialisation de la bordure à droite */
	}
	for (j = 0; j < taille; j++) {
		grille[0][j] = 9;           /* Initialisation de la bordure en haut */
		grille[taille - 1][j] = 9; /* Initialisation de la bordure en bas */
	}
	return grille;
}

void liberergrille(int** grille, int taille) {
	int i;
	for (i = 0; i < taille; i++) {
		free(grille[i]); 
	}
	free(grille);  
}

/* fonction pour libérer les sprites utilisés */
void liberersprite(int a, int b, int c, int d, int e, int f, int g){
	LibererSprite(a);
	LibererSprite(b);
	LibererSprite(c);
	LibererSprite(d);
	LibererSprite(e);
	LibererSprite(f);
	LibererSprite(g);
}

int choisirgrille(void){
	int trois, quatre, cinq, six, sept, huit, neuf;
	int x,y,running;
	couleur noir;
	running=1;
	noir = CouleurParComposante(0,0,0);
	InitialiserGraphique();
	CreerFenetre(0, 0, 600, 600);
	ChargerImageFond("./Images/fond_choix_grille.jpg");
	EcrireTexte(70,50,"Choisissez la taille de votre grille",2);

	/* Definition des sprites donc des images pour les boutons */
	trois = ChargerSprite("./Images/3.png");
	quatre = ChargerSprite("./Images/4.png");
	cinq = ChargerSprite("./Images/5.png");
	six = ChargerSprite("./Images/6.png");
	sept = ChargerSprite("./Images/7.png");
	huit = ChargerSprite("./Images/8.png");
	neuf = ChargerSprite("./Images/9.png"); 

	/* Affichage des boutons un par un */
	/* Ligne du haut */
	AfficherSprite(trois,200,180);
	AfficherSprite(quatre,270,180);
	AfficherSprite(cinq,340,180); 

	/* Ligne du bas */
	AfficherSprite(six,160,300);
	AfficherSprite(sept,230,300);
	AfficherSprite(huit,300,300);
	AfficherSprite(neuf,370,300);

	/* Dessiner les contours des boutons */
	ChoisirCouleurDessin(noir);
	DessinerRectangle(200,180,60,60);
	DessinerRectangle(270,180,60,60);
	DessinerRectangle(340,180,60,60);
	DessinerRectangle(160,300,60,60);
	DessinerRectangle(230,300,60,60);
	DessinerRectangle(300,300,60,60);
	DessinerRectangle(370,300,60,60);

	while(running){ 
		if(SourisCliquee()){
			x = _X;
			y = _Y;
			if(x>200 && x<260 && y>180 && y<240){
				return 3;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>270 && x<330 && y>180 && y<240){
				return 4;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>340 && x<400 && y>180 && y<240){
				return 5;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>160 && x<220 && y>300 && y<360){
				return 6;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>230 && x<290 && y>300 && y<360){
				return 7;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>300 && x<360 && y>300 && y<360){
				return 8;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			} else if(x>370 && x<430 && y>300 && y<360){
				return 9;
				liberersprite(trois,quatre,cinq,six,sept,huit,neuf);
			}
		}
	}
}


