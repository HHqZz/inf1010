
/********************************************
* Titre: Travail pratique #3 - Tour.h
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#pragma once

#ifndef TOUR_H
#define TOUR_H


#include <iostream>
#include <string>
#include "Piece.h"
	using namespace std;

	// La classe Tour herite des methodes publics de la classe piece
class Tour : public Piece{

	// Methodes publics d'une piece
public:
	// Signature ddu constructeur par defaut d'une tour
	Tour();
	
	// Signature du constructeur par parametre d'une tour
	Tour(string id, string couleur, int positionX, int positionY);

	// destructeur
	~Tour();

	// Signature de la methode pour savoir si le mouvement d'une piece est valide ou non
	bool estMouvementValide(int toX, int toY);
	
	// Signature de la methode qui permet de deplacer une piece
	void deplacer(int toX, int toY);


private:

	

};
#endif