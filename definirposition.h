#ifndef DEFINIRPOSITION_H
#define DEFINIRPOSITION_H

int posmaxX(int taille); /* Définit la position max de X en pixels */

int posmaxY(int taille); /* Définit la position max de Y en pixels */

void position(int taille, int mouseX, int mouseY, int maxX, int maxY, int* posperso); /* Récupère la case où le joueur a cliqué */

#endif
