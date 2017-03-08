/********************************************
* Titre: Travail pratique #4 - Roi.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Roi.h"

// Implementation du constructeur par defaut d'un roi 
Roi::Roi(): Piece("defaultId", "blanc", 0, 0) {}

// Implementation du constructeur par parametre d'un roi
Roi::Roi(const string& id, const string& couleur, int positionX, int positionY) : Piece( id,  couleur, positionX, positionY) {
}

// Implementation de la methode qui permet de savoir si le mouvement d'un roi est valide ou,
bool Roi::estMouvementValide(int toX, int toY)  {
	if (!Piece::estMouvementValide(toX, toY))
		return false;	
	if (abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 0 && abs(obtenirPositionY() - toY) == 1 ||
		abs(obtenirPositionX() - toX) == 1 && abs(obtenirPositionY() - toY) == 0)
		return true;
	else
		return false;
}

// Implementation du destructeur d'un roi
Roi::~Roi() {}

// Implementation de la methode qui permet de deplacer le roi 
bool Roi::deplacer(int toX, int toY)  {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);		
		return true;
	}
	return false;
}