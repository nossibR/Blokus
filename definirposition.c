
/* 
 * Pour 3 : x = 75 ; y = 75
 * Pour 4 : x = 125 ; y = 125
 * Pour 5 : x = 175 ; y = 175
 * Pour 6 : x = 225 ; y = 225
 * Pour 7 : x = 275 ; y = 275
 * Pour 8 : x = 325 ; y = 325
 * Pour 9 : x = 375 ; y = 375
 */

int posmaxX(int taille){
	int x, maxX;
	for(x=1 ; x<=taille ; x++){
		if(x==1){
			maxX=75;
		}
		maxX+=50;
	}
	return maxX;
}

int posmaxY(int taille){
	int y, maxY;
	for(y=1 ; y<=taille ; y++){
		if(y==1){
			maxY=75;
		}
		maxY+=50;
	}
	return maxY;
}

void position(int taille, int mouseX, int mouseY,int maxX,int maxY, int* posperso){
	int base, lcase, indiceX, indiceY;
	lcase =50;
	base = 75;
	posperso[0]=base;
	if(mouseX>base && mouseX<maxX && mouseY>base && mouseY<maxY){
		indiceX = (mouseX - base) / lcase;
		indiceY = (mouseY - base) / lcase;

		/* Vérification des limites de la grille */
		if (indiceX < taille && indiceY < taille) {
			posperso[0] = base + indiceX * lcase; /* Position X */
			posperso[1] = base + indiceY * lcase; /* Position Y */
			posperso[2] = (posperso[0] - base) / 50 + 1; /* Indice X */
			posperso[3] = (posperso[1] - base) / 50 + 1; /* Indice Y */
		}
	}
}
