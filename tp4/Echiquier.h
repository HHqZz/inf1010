/********************************************
* Titre: Travail pratique #4 - Echiquier.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include <vector>

#include <string>


class Echiquier{



public:
	// Constructeur par defaut
	Echiquier();

	// Destructeur
	~Echiquier();

	// Methodes publiques
	
	bool deplacerPiece(const string& id, int toX, int toY);
	Echiquier& operator+=(Piece* piece);
	Echiquier& operator-=(const string& id);
	bool promouvoir(const string& id);

	
	// Signature de la surcharge de l'operateur <<

	friend std::ostream& operator<<(std::ostream& out, const Echiquier& echiquier);//A completer
	

private :

	// Methodes privées
	vector<Piece*>   vecteurPiecesBlanches_;
	vector<Piece*>   vecteurPiecesNoires_;	

};
#endif