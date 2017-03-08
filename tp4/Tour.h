/********************************************
* Titre: Travail pratique #4 - Tour.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

// La classe tour herite de la classe Piece
class Tour : public Piece {

// Methodes publics :
public:
	// Signature du Constructeur par defaut d'une tour
	Tour();
	
	// Signature du Constructeur par, parametre d'une tour
	Tour(const string& id, const string& couleur, int positionX, int positionY);
	
	// Signature du Constructeur par copie d'une tour a partir d'un pion = promotion
	Tour(const Pion& pion);

	// Destructeur
	virtual ~Tour();
	
	// Signature de la methode qui permet de savoir si le mouvement d'une tour est valide ou non
	virtual bool estMouvementValide(int toX, int toY);
	
	// Signature de la methode qui permet de deplacer une tour 
	virtual bool deplacer(int toX, int toY);
};
#endif