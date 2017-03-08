/********************************************
* Titre: Travail pratique #4 - Reine.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/


#include "Reine.h"

// Implementation du Constructeur par paramatre d'une reine
Reine::Reine() :Piece("defaultId", "blanc", 0, 0) {
}

// Implementation du Constructeur par parametre d'une reine
Reine::Reine(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
}

// Implementation du Constructeur par copie d'une reine, a partir d'un pion = promotion
Reine::Reine(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {
}

// Implementation du destructeur
Reine::~Reine() {
}

// Implementation de la methode qui permet de savoir si le mouvement de la reine est valide ou non
bool Reine::estMouvementValide(int toX, int toY) const {	// Le reine peut bouger sur les grandes lignes ou alors en diagonale
	if (((obtenirPositionX() == toX || obtenirPositionY()) == toY ||		// Mouvement grande ligne ->  La reine ne bouge qu'en X ou qu'en Y
		(abs(obtenirPositionX() - toX) == abs(obtenirPositionY() - toY))) &&  // Mouvement en diagonale selon la droite y=x ce qui implique que la difference des positions a l'etat initial avec les positions a l'etat final doite etre la meme.
		(Piece::estMouvementValide(toX, toY))) // Et qu'elle ne sort pas de l'echiquier
	{																				

		cout << " Mouvement valide" << endl;
		return true;
	}
	else cout << " Mouvement invalide " << endl; return false;


}

// Implementation de la methode qui permet de deplacer la reine
bool Reine::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}

// Implementation de la methode qui permet d'afficher les informations relatives a la reine
ostream&  Reine::afficher(ostream& stream) const
{
	stream << "Reine, ";
	Piece::afficher(stream);
	return stream;
}