/********************************************
* Titre: Travail pratique #4 - Tour.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Tour.h"

// Implementation du constructeur par defaut d'une tour 
Tour::Tour() :Piece("defaultId", "blanc", 0, 0){
}

// Implementation du constructeur par parametres d'un tour
Tour::Tour(const string& id, const string& couleur, int positionX, int positionY) : Piece(id, couleur, positionX, positionY){
}

// Implementation du constructeur d'une tour a partir d'un pion = promotion
Tour::Tour(const Pion & pion) : Piece(pion.obtenirId(), pion.obtenirCouleur(), pion.obtenirPositionX(), pion.obtenirPositionY()){
}

// Implementation du destructeur
Tour::~Tour(){
}

//  Implementation de la methode qui permet de savoir si le mouvement est valide
bool Tour::estMouvementValide(int toX, int toY) {
	if (!Piece::estMouvementValide(toX, toY)) // On verifie que la piece ne sorte pas de l'echiquier
		return false; // retourne faux si le mouvement n'est pa valide
	if ((obtenirPositionX() == toX)  || (obtenirPositionY() == toY))	// Le mouvement de la tour peut etre constant en X OU alors constant en Y	
		return true; //retourne vrai lorsque le mouvement est valide
	else
		return false;
}

// Implementation de la methode qui permet de deplacer une tour
bool Tour::deplacer(int toX, int toY) {
	if (estMouvementValide(toX, toY)) {
		modifierPositionX(toX);
		modifierPositionY(toY);
		return true;
	}
	return false;
}