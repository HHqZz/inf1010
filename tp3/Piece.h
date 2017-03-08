
/********************************************
* Titre: Travail pratique #3 - Piece.h
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#pragma once

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>

using namespace std;

class Piece {


	// Methodes publics :
public :

	// constructeur par defaut
	Piece();
	
	// Constructeur par parametres
	Piece(string id, string couleur, int positionX, int positionY); 

	// destructeur
	~Piece();

	// Declaration d'une methode virtuelle pour obtenir l'id d'une piece
	virtual string obtenirId() const;
	
	// Signature de la methode pour modifier l'id d'une piece
	void modifierId(string id);

	// Signature de la methode pour obtenir la couleur d'une piece
	string obtenirCouleur() const;
	
	// Signature de la methode pour modifier la couleur d'une piece
	void modifierCouleur(string couleur);

	// Signature de la methode pour obtenir la position en X d'une piece
	int obtenirPositionX() const;	
	
	// Signature de la methode pour modifier la position en X d'une piece
	void modifierPositionX(int x);

	// Signature de la methode pour obtenir la position en Y d'une piece
	int obtenirPositionY() const;
	
	// Signature de la methode pour modifier la position en Y d'une piece
	void modifierPositionY(int y);

	// Signature de la methode qui permet de savoir si le dezplacement d'une piece est valide ou non
	bool estMouvementValide(int toX, int toY); 
	
	// Methodes et attributs privés : 
private:

	// Déclaration de l'attribut  id
	string id_;
	
	// Déclaration de l'attribut  couleur
	string couleur_;
	
	// Déclaration des attributs des positions en X et Y d'une piece
	int positionX_;
	int positionY_;
	
};
#endif