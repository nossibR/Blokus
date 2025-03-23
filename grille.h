#ifndef GRILLE_H
#define GRILLE_H

int** definegrille(int taille); /* Definir la grille en fonction de sa taille */

void liberergrille(int** grille, int taille); /* Libérer la mémoire allouée pour la grille */

int choisirgrille(void); /* Dessiner la page pour choisir la grille */

#endif
