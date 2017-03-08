/********************************************
* Titre: Travail pratique #3 - Piece.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Piece.h"

// constructeur par defaut
Piece::Piece() : positionX_(0), positionY_(0), id_(""), couleur_("")
{
}

// Constructeur par parametres
Piece::Piece(string id, string couleur, int positionX, int positionY) : positionX_(positionX), positionY_(positionY), id_(id), couleur_(couleur)
{
}

// destructeur
Piece::~Piece()
{
}

// Implementation de la methode pour obtenir l'id d'une piece
string Piece::obtenirId() const
{
	return id_;
}

// Implementation de la methode pour modifier l'id d'une piece
void Piece::modifierId(string id)
{
	id_ = id;
}

//Implementation de la methode pour obtenir la couleur d'une piece
string Piece::obtenirCouleur() const
{
	return couleur_;
}
// Implementation de la methode pour modifier la couleur d'une piece
void Piece::modifierCouleur(string couleur)
{
	couleur_ = couleur;
}

// Implementation de la methode pour obtenir la position en X d'une piece
int Piece::obtenirPositionX() const
{
	return positionX_;
}

// Implementation de la methode pour modifier la position en X d'une piece
void Piece::modifierPositionX(int x)
{
	positionX_ = x;
}

// Implementation de la methode pour obtenir la position en Y d'une piece
int Piece::obtenirPositionY() const
{
	return positionY_;
}

//Implementation de la methode pour modifier la position en Y d'une piece
void Piece::modifierPositionY(int y)
{
	positionY_ = y;
}

// Implementation de la methode pour savoir si le mouvement est valide ou non ( retourne  true pour valide et false si le mouvement est invalide)
bool Piece::estMouvementValide(int toX, int toY)
{
	if (toX <= 7 && toX >= 0 && toY <= 7 && toY >= 0 &&( toX != positionX_ || toY != positionY_))
	{

		return true;
	}
	else
	{
		cout << "Deplacement de la piece non autorise" << endl;
		return false;
	}
}

