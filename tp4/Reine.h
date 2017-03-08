/********************************************
* Titre: Travail pratique #4 - Reine.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef REINE_H
#define REINE_H


#include "Piece.h"
#include "Pion.h"
#include <string>

using namespace std;

// Reine herite de la classe Piece
class Reine : public Piece {

// Methodes publics
public:

	// Signature du constructeur par defaut d'une reine
	Reine();
	
	// Signature du constructeur par parametres d'une reine
	Reine(const string& id, const string& couleur, int positionX, int positionY);
	
	// Signature du constructeur par copie d'une reine
	Reine(const Pion & pion);
	
	// Signature du destructeur 
	virtual ~Reine();
	
	
	// Signature de la methode qui permet de savoir si le mouvement de la reine est valide
	bool estMouvementValide(int toX, int toY) const;
	
	// Signature de la methode qui permet de deplacer la reine 
	bool deplacer(int toX, int toY);
	
	// Signature de la methode d'affichage de la reine
	ostream&  afficher(ostream& stream) const;
};
#endif