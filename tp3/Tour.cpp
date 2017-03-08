/********************************************
* Titre: Travail pratique #3 - Tour.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Tour.h"

// Implementation du constructeur par defautd'une tour
Tour::Tour() : Piece()
{
	
}

// Implementation du constructeur par parametre d'une tour
Tour::Tour(string id, string couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY)
{

}

// destructeur d'une tour
Tour::~Tour()
{}

// Implementation de la methode qui permet de savoir si le mouvement d'une tour est valide ou non
bool Tour::estMouvementValide(int toX, int toY)
{

	if (Piece::estMouvementValide(toX, toY))
	{

		if ((obtenirPositionX() == toX && toY != obtenirPositionY()) || (obtenirPositionY() == toY && toX != obtenirPositionX()))
			return true;
		else
		{
			return false;
		}
	}
	return false;
}

// Implementation de la methode qui permet de deplacer une tour
void Tour::deplacer(int toX, int toY)
{
	if (estMouvementValide(toX, toY))
	{
		cout << "Deplacement de la tour" << " " << obtenirId() << " " << "de la position (" << obtenirPositionX() << "," << obtenirPositionY();
		modifierPositionX(toX);
		modifierPositionY(toY);
		cout << ") a la position (" << obtenirPositionX() << "," << obtenirPositionY() << ")" << endl;
	}
	else
		cout << "Deplacement de la Tour non autorise" << endl;
}