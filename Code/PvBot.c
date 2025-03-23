#include <graph.h>
#include <stdlib.h>
#include <time.h>

#include "grille.h"
#include "definirposition.h"

int jeu2(int taille, int maxX, int maxY, int** grille) {
	int Taille_cellule = 50, x, i, y, largeurGrille, hauteurGrille, base = 75, victoire = 0, mouseX, mouseY, posperso[4];
	int linux, windows, croixbleue, croixnoire, tour = 0, ancienXwindows, ancienYwindows, ancienXlinux, ancienYlinux; /* Passage a la ligne pour plus de lisibilité */
	srand(time(NULL));
	largeurGrille = taille * Taille_cellule;
	hauteurGrille = taille * Taille_cellule;
	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(0, 0, 600, 600);
	linux = ChargerSprite("./Images/linux.png");
	windows = ChargerSprite("./Images/windows.png"); 
	croixbleue = ChargerSprite("./Images/croix_bleue.png");
	croixnoire = ChargerSprite("./Images/croix_noire.png");
	/* Lignes horizontales */
	for (i = 0; i <= taille; i++) {
		y = base + i * Taille_cellule;
		DessinerSegment(base, y, base + largeurGrille, y);
	}

	/* Lignes verticales */
	for (i = 0; i <= taille; i++) {
		x = base + i * Taille_cellule;
		DessinerSegment(x, base, x, base + hauteurGrille);
	}
	while(victoire == 0){
		while(tour==0){
			EcrireTexte(100,30,"Joueur Linux place son pion",2);
			if(SourisCliquee()){
				mouseX = _X;
				mouseY = _Y;
			}
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]][posperso[3]]==0){
					posperso[0]+=5;
					posperso[1]+=5;
					AfficherSprite(linux, posperso[0], posperso[1]);
					ancienXlinux=posperso[2];
					ancienYlinux=posperso[3];
					grille[posperso[2]][posperso[3]]=8; /* Code dans la grille pour linux */
					tour++;
				}
			}
		}
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));
		RemplirRectangle(0,0,600,75);
		while(tour==1){
			mouseX=0;
			mouseY=0;
			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			EcrireTexte(100,30,"Joueur Windows place son pion",2);
			mouseX = rand() % maxX + base;
			mouseY = rand() % maxY + base;
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]][posperso[3]]==0){
					posperso[0]+=5;
					posperso[1]+=5;
					AfficherSprite(windows, posperso[0], posperso[1]);
					ancienXwindows=posperso[2];
					ancienYwindows=posperso[3];
					grille[posperso[2]][posperso[3]]=7; /* Code dans la grille pour windows */
					tour++;
				}
			}
		}
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));
		RemplirRectangle(0,0,600,75);
		while(tour==2){
			mouseX=0;
			mouseY=0;
			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			EcrireTexte(100,30,"Joueur Linux bouge son pion",2);
			if(SourisCliquee()){
				mouseX = _X;
				mouseY = _Y;
			}
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]+1][posperso[3]]!=0 && grille[posperso[2]+1][posperso[3]+1]!=0 && grille[posperso[2]][posperso[3]+1]!=0 && grille[posperso[2]-1][posperso[3]+1]!=0 && grille[posperso[2]-1][posperso[3]]!=0 && grille[posperso[2]-1][posperso[3]-1]!=0 && grille[posperso[2]][posperso[3]-1] && grille[posperso[2]+1][posperso[3]-1]!=0){ /* Condition de victoire */
					FermerGraphique();
					LibererSprite(windows);
					LibererSprite(linux);
					LibererSprite(croixbleue);
					LibererSprite(croixnoire);
					return 3; /* Code de victoire de l'ia */
				}
				if(grille[posperso[2]][posperso[3]]==0 && (posperso[3] <= ancienYlinux+1 && posperso[3] >= ancienYlinux-1) && (posperso[2] <= ancienXlinux+1 && posperso[2] >= ancienXlinux-1)){ /* Limiter les déplacements aux cases adjacentes */
					posperso[0] += 5; /* Centrer le sprite */
					posperso[1] += 5;
					AfficherSprite(linux, posperso[0], posperso[1]); /* Afficher le sprite sur la nouvelle position */
					ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));  /* Effacer l'ancien sprite */
					RemplirRectangle(base + (ancienXlinux - 1) * 50 + 5,base + (ancienYlinux - 1) * 50 + 5,40, 40);
					grille[ancienXlinux][ancienYlinux] = 0;
					grille[posperso[2]][posperso[3]] = 8; /* Code dans la grille pour linux */
					ancienXlinux = posperso[2];
					ancienYlinux = posperso[3];
					tour++;
				}
			}
		}
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));
		RemplirRectangle(0,0,600,75);
		while(tour==3){
			mouseX=0;
			mouseY=0;
			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			EcrireTexte(100,30,"Joueur Linux place une croix",2);
			if(SourisCliquee()){
				mouseX = _X;
				mouseY = _Y;
			}
			position(taille, mouseX, mouseY, maxX, maxY, posperso);
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]][posperso[3]]==0){
					posperso[0]+=5;
					posperso[1]+=5;
					AfficherSprite(croixnoire, posperso[0], posperso[1]);
					grille[posperso[2]][posperso[3]]=6; /* Code dans la grille pour les croix */
					tour++;
				}
			}
		}
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));
		RemplirRectangle(0,0,600,75);
		while(tour==4){
			mouseX=0;
			mouseY=0;
			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			EcrireTexte(100,30,"Joueur Windows bouge son pion",2);
			mouseX = rand() % maxX + base;
			mouseY = rand() % maxY + base;
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]+1][posperso[3]]!=0 && grille[posperso[2]+1][posperso[3]+1]!=0 && grille[posperso[2]][posperso[3]+1]!=0 && grille[posperso[2]-1][posperso[3]+1]!=0 && grille[posperso[2]-1][posperso[3]]!=0 && grille[posperso[2]-1][posperso[3]-1]!=0 && grille[posperso[2]][posperso[3]-1] && grille[posperso[2]+1][posperso[3]-1]!=0){ /* Condition de victoire */
					FermerGraphique();
					LibererSprite(windows);
					LibererSprite(linux);
					LibererSprite(croixbleue);
					LibererSprite(croixnoire);
					return 2; /* Code de victoire de linux */
				}
				if(grille[posperso[2]][posperso[3]]==0 && (posperso[3] <= ancienYwindows+1 && posperso[3] >= ancienYwindows-1) && (posperso[2] <= ancienXwindows+1 && posperso[2] >= ancienXwindows-1)){
					posperso[0] += 5; /* Centrer le sprite */
					posperso[1] += 5;
					AfficherSprite(windows, posperso[0], posperso[1]); /* Afficher le sprite sur la nouvelle position */
					ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));  /* Effacer l'ancien sprite */
					RemplirRectangle(base + (ancienXwindows - 1) * 50 + 5,base + (ancienYwindows - 1) * 50 + 5,40, 40);
					grille[ancienXwindows][ancienYwindows] = 0;
					grille[posperso[2]][posperso[3]] = 7; /* Code dans la grille pour windows */
					ancienXwindows = posperso[2];
					ancienYwindows = posperso[3];
					tour++;
				}
			}
		}
		ChoisirCouleurDessin(CouleurParComposante(255,255,255));
		RemplirRectangle(0,0,600,75);
		while(tour==5){
			mouseX=0;
			mouseY=0;
			ChoisirCouleurDessin(CouleurParComposante(0,0,0));
			EcrireTexte(100,30,"Joueur Windows place une croix",2);
			mouseX = rand() % maxX + base;
			mouseY = rand() % maxY + base;
			position(taille, mouseX, mouseY, maxX, maxY, posperso);
			if(mouseX > base && mouseX < maxX && mouseY > base && mouseY < maxY){
				position(taille, mouseX, mouseY, maxX, maxY, posperso);
				if(grille[posperso[2]][posperso[3]]==0){
					posperso[0]+=5;
					posperso[1]+=5;
					AfficherSprite(croixbleue, posperso[0], posperso[1]);
					grille[posperso[2]][posperso[3]]=6; /* Code dans la grille pour les croix */
					tour=2; /* On retourne au tour suivant */
				}
			}
		}
	}
}

int pvbot(void){
	int taille, maxX, maxY, victoire;
	int** grille;
	taille = choisirgrille(); 
	maxX = posmaxX(taille);
	maxY = posmaxY(taille); 
	taille+=2;
	grille = definegrille(taille);
	taille-=2;
	victoire = jeu2(taille, maxX, maxY, grille);
	liberergrille(grille,taille);
	return victoire;
}
