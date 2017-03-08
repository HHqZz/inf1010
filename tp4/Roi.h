/********************************************
* Titre: Travail pratique #4 - Roi.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef ROI_H
#define ROI_H


#include "Piece.h"
#include <string>

using namespace std;

// La classe roi herite de la classe Piece
class Roi : public Piece{

// Methodes publics :
public :

	// Signature du Constructeur par defaut
	Roi();
	// Signature du Constructeur par parametres 
	Roi(const string& id, const string& couleur, int positionX, int positionY);
	// Signature du destructeur 
	virtual	~Roi();	

	// Signature de la methode qui permet de savoir si le mouvement du roi est valide
	virtual bool estMouvementValide(int toX, int toY);  
	
	// Signature de la methode qui permet de deplacer un roi
	virtual bool deplacer(int toX, int toY);

};
#endif