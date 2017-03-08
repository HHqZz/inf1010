/********************************************
* Titre: Travail pratique #3 - Pion.h
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#pragma once

#ifndef PION_H
#define PION_H

#include "Piece.h"
using namespace std;

class Pion : public Piece
{
	// Méthodes publics : 
public:

	// Signature du constructeur par defaut d'un pion
	Pion();
	
	// Signature du constructeur par parametres d'un pion
	Pion(string id, string couleur, int positionX, int positionY, bool estPositionInitiale);
	
	// Signature de la methode qui permet de savoir si le deplacement d'un pion est valide ou non
	bool estMouvementValide(int toX, int toY);
	
	// Signature de la methode qui permet de deplacer un pion
	void deplacer(int toX, int toY);
	
	// Signature du destructeur de pion
	~Pion();
	
	// Methode privé :
private:

	// Signature de la methode qui permet de savoir si un pion est a sa position initiale ou non
	bool estPositionInitiale_;
};

#endif