/********************************************
* Titre: Travail pratique #4 - Piece.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/


#include "Piece.h"


// Implementation du constructeur par defaut d'une piece
Piece::Piece() {}

// Implementation du constructeur par parametre d'une piece
Piece::Piece(const string& id, const string& couleur, int positionX, int positionY) :id_(id), couleur_(couleur), positionX_(positionX), positionY_(positionY) {}

// Implementation du destructeur
Piece::~Piece() {}

// acesseur et modificateur

// Implementation de la methode pour obtenir l'id d'une piece
string Piece::obtenirId() const {
	return id_;
}

// Implementation de la methode pour modifier l'id d'une piece
void Piece::modifierId(const string& id) {
	id_ = id;
}

//Implementation de la methode pour obteniur  la couleur d'une piece
string Piece::obtenirCouleur() const {
	return couleur_;
}

//Implementation de la methode pour modifier la couleur d'une piece
void Piece::modifierCouleur(const string& couleur) {
	couleur_ = couleur;
}

//Implementation de la methode pour obtenir la positions x d'une piece
int Piece::obtenirPositionX() const {
	return positionX_;
}

//Implementation de la methode pour obtenir les positions x et y d'une piece
void Piece::modifierPositionX(int x) {
	positionX_ = x;
}

//Implementation de la methode pour obtenir la position y d'une piece
int Piece::obtenirPositionY() const {
	return positionY_;
}

//Implementation de la methode pour modifier la position y d'une piece
void Piece::modifierPositionY(int y) {
	positionY_ = y;
}

//Implementation de la methode pour savoir si le mouvement d'une piece est valide ou non
bool Piece::estMouvementValide(int toX, int toY) const {
	if (toX <= 7 && toX >= 0 && toY <= 7 && toY >= 0 && (toX != positionX_ || toY != positionY_))  // On verifie que le mouvement ne mene pas la piece hors de l'echiquier
	{

		return true;
	}
	else
	{

		return false;
	}
}

//Implementation de la methode pour afficher
std::ostream&  Piece::afficher(ostream& stream) const {
	stream << "Piece " << couleur_ << " d'id " << id_ << " : " << endl;
	stream << "Position (" << positionX_ << ", " << positionY_ << ")" << endl;
	return stream;
}


//Implementation de la methode pour obtenir le type d'une piece
string Piece::obtenirType() const
{
	return typeid(*this).name();
}


//Implementation de la surcharge de l'operateur <<
ostream& operator<<(std::ostream& out, const Piece& piece)
{
	return piece.afficher(out) << endl;
}

