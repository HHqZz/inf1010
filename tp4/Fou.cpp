/********************************************
* Titre: Travail pratique #4 - Fou.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Fou.h"

// Implementation du constructeur par defaut
Fou::Fou() :Piece("defaultId", "blanc", 0, 0) {
}

// Implementation du constructeur par parametres
Fou::Fou(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY)
{
}

// Implementation du constructeur par copie d'un pion = promotion
Fou::Fou(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()) {};

// Implementation du destructeur
Fou::~Fou() {
}

// Implementation de la methode qui permet de  savoir si le mouvement du fou est valide ou non
bool Fou::estMouvementValide(int toX, int toY) const {

	if (abs(obtenirPositionX() - toX) == abs(obtenirPositionY() - toY) && Piece::estMouvementValide(toX, toY)) {
		cout << " Mouvement valide" << endl;
		return true;

	}
	else  cout << " Mouvement non valide" << endl;
    return false;

}

// Implementation de la methode quio permet de deplacer un fou
bool Fou::deplacer(int toX, int toY) {  
	if (estMouvementValide(toX, toY)) { 
		modifierPositionX(toX);			
		modifierPositionY(toY);
		cout << " Deplacement de la piece reussie " << endl;
        return true;
	}
	else return false;

}

// Implementation de la methode d'affichage
ostream&  Fou::afficher(ostream& stream) const
{
	stream << "Fou, ";
	Piece::afficher(stream);
	return stream;
}
