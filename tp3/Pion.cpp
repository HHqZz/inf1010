/********************************************
* Titre: Travail pratique #3 - Pion.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Pion.h"


// Implementation du constructeur par defaut d'un pion
Pion::Pion() :Piece(), estPositionInitiale_(true)
{
}

// Implementation du constructeur par parametres d'un pion
Pion::Pion(string id, string couleur, int positionX, int positionY, bool estPositionInitiale) : Piece(id, couleur, positionX, positionY), estPositionInitiale_(estPositionInitiale)
{
}

// Implementation du destructeur de pion
Pion::~Pion()
{
}

// Implementation de la methode qui permet de savoir si le deplacement d'un pino est valide ou non
bool Pion::estMouvementValide(int toX, int toY)
{

	if (Piece::estMouvementValide(toX, toY))
	{

		if ((obtenirCouleur()=="blanc" && estPositionInitiale_ && toY - 2 == obtenirPositionY() && toX == obtenirPositionX()) 
			|| (obtenirCouleur() == "noir" && estPositionInitiale_ && obtenirPositionY() - 2 == toY && toX == obtenirPositionX())
			|| (obtenirCouleur() == "blanc" && toY - 1 == obtenirPositionY() && toX == obtenirPositionX())
			|| (obtenirCouleur() == "noir" && obtenirPositionY() - 1 == toY) && toX == obtenirPositionX())
			return true;
		else
		{
			return false;
		}
	}
	return false;
}

// Implementation de la methode qui permet de deplacer un pion
void Pion::deplacer(int toX, int toY)
{
	if (estMouvementValide(toX, toY))
	{
		cout << "Deplacement du pion" << " " << obtenirId()  << " " << "de la position (" << obtenirPositionX() << "," << obtenirPositionY();
		modifierPositionX(toX);
		modifierPositionY(toY);
        this->estPositionInitiale_ = false;
		cout << ") a la position (" << toX << "," << toY << ")" << endl;
	}
	else
		cout << "Deplacement du pion non autorise" << endl;
}
