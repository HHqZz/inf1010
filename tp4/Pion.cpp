/********************************************
* Titre: Travail pratique #4 - Pion.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Pion.h"

// Implementation du constructeur par defaut d'un pion
Pion::Pion():Piece("defaultId","blanc",0,0),estPositionInitiale_(true){
}

// Implementation du constructeur par parametre d'un pion
Pion::Pion(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY) {
	estPositionInitiale_ = true;
}

// Implementation du destructeur d'un pion
Pion::~Pion() {
}

// Implementation de la methode qui permet de savoir si un pion est a sa position initiale
bool Pion::obtenirEstPositionInitiale() const{
	return estPositionInitiale_;
}

// Implementation de la methode qui permet de set un pion a sa position initiale
void Pion::setEstPositionInitiale(bool estPositionInitiale) {
	estPositionInitiale_ = estPositionInitiale;
}

// Implementation de la methode qui permet de savoir si le mouvement d'un pion est valide ou non
bool Pion::estMouvementValide(int toX, int toY) {
	if (!Piece::estMouvementValide(toX, toY))
		return false; // On veut dabord savoir si le mouvement est valide ou non
	if (obtenirCouleur() == "blanc") { // On veut ensuite connaitre la couleur du pion
		if (obtenirEstPositionInitiale()) { // Puis on veut savoir si le pion est a sa position initiale
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) // Si la case ou veut se rendre le pion moins celle actuelle est inf ou = a 2, 
				&& (toY > obtenirPositionY())) {                                 // Et que le pion ne bouge pas en x ; et qu'il avance ( position actuelle doit etre inf a la future position)
				return true; // Alors le mouvement est valide
			}
		}
		else  // Si le pion blanc n'est pas a sa position initiale
		{
			if ((toY - obtenirPositionY()) <= 1 && (toX == obtenirPositionX()) // Alors il ne peut bouger que de une case et il ne doit pas bouger en x
				&& toY > obtenirPositionY()) {									// Et il doit bouger en Y ( position actuelle doit etre inf a la future position)
				return true;
			}
		}
	}
	if (obtenirCouleur() == "noir") {                                                /// On fait de meme pour le Pion noir, seulement ici le pion doit "descendre" sur l'echiquier
		if (obtenirEstPositionInitiale()) {											// Ce qui inclut que la position actuelle doit etre superieure a celle future en y, pour verifier que le pion a bien avance
			if (((toY - obtenirPositionY()) <= 2) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
		else
		{
			if (((toY - obtenirPositionY()) <= 1) && (toX == obtenirPositionX()) 
				&& (toY < obtenirPositionY())) {
				return true;
			}
		}
	}
	
	return false;
	
}

// Implementation de la methode qui permet de deplacer un pion
bool Pion::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) { // Si le mouvement est valide
		
		modifierPositionX(toX); // modifie sa position en x
		modifierPositionY(toY); // modifie sa position en y
		estPositionInitiale_ = false; // Le pion a ete bouge, il nest dont plu a sa position initiale
		return true;
	}
	return false;
}