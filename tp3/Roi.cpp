/********************************************
* Titre: Travail pratique #3 - Roi.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Roi.h"

// Implementation du constructeur par parametre d'un roi
Roi::Roi(string id, string couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY)
{
}

// Implementation du constructeur par defaut d'un roi
Roi::Roi(): Piece()
{
}

// Implementation du destructeur d'un roi
Roi::~Roi() 
{
}

// Implementation de la methode qui permet de savoir si le mouvement d'un roi est valide ou non
bool Roi::estMouvementValide(int toX, int toY)
{

	if (Piece::estMouvementValide(toX, toY))
	{
		
		if (abs(obtenirPositionX() - toX) <= 1 && abs(obtenirPositionY() - toY) <= 1)
			return true;
		else
		{
			return false;
		}
	}
	return false;
}

// Implementation de la methode qui permet de deplacer un roi
void Roi::deplacer(int toX, int toY)
{
	if (estMouvementValide(toX, toY))
	{
		cout << "Deplacement du roi de la position (" << obtenirPositionX() << "," << obtenirPositionY();
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << ") a la position (" << toX << "," << toY << ")" << endl;
	}
	else
		cout << "Deplacement du roi non autorise" << endl;
}
