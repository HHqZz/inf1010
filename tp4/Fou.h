/********************************************
* Titre: Travail pratique #4 - Fou.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef FOU_H
#define FOU_H

#include "Piece.h"
#include <string>
#include "Pion.h"

using namespace std;

class Fou : public Piece {

public:
	// Signature Constructeur
		// par defaut
	Fou();
		//par parametre
	Fou(const string& id, const string& couleur, int positionX, int positionY);
		// par copie
	Fou(const Pion & pion);
	
	
	// Destructeur
	virtual ~Fou();
	
	// Signature de la methode qui permet de savoir si le mouvement d'un fou est valide ou non
	bool estMouvementValide(int toX, int toY) const;
	
	// Signature de la methode qui permet de deplacer un fou
	virtual bool deplacer(int toX, int toY);
	
	//Signature de la methode d'affichage
    ostream&  afficher(ostream& stream) const;
	
};
#endif