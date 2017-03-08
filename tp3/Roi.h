/********************************************
* Titre: Travail pratique #3 - Roi.h
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/
#pragma once

#ifndef ROI_H
#define ROI_H

#include "Piece.h"

using namespace std;

// La classe Roi herite de la classe Piece
class Roi : public Piece 
{
	// Methodes publics
public:

	// Signature du constructeur par defaut d'un roi
	Roi();
	
	// Signature du constructeur par parametre d'un roi
	Roi(string id, string couleur, int positionX, int positionY);
	
	// Signature du destructeur d'un roi
	~Roi();

	// Signature de la methode qui permet de savoir si le mouuvement d'un roi est valide ou non
	bool estMouvementValide(int toX, int toY);
	
	// Signature de la fonction qui permet de deplacer un roi
	void deplacer(int toX, int toY);
};
#endif

