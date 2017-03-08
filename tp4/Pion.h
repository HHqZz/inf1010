/********************************************
* Titre: Travail pratique #4 - Pion.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#pragma once

#ifndef PION_H
#define PION_H


#include "Piece.h"
#include <string>

using namespace std;

// La classe Pion herite de la classe Piece
class Pion : public Piece {

// Methodes publics :
public:
	//Signature du Constructeur par defaut d'un pion
	Pion();
	
	// Signature du Constructeur par parametres d'un pion
	Pion(const string& id, const string & couleur, int positionX, int positionY);

	// Signature du Destructeur d'un pion
	~Pion();																			
	
	// Signature de la methode qui permet de savoir si le pion est a sa position initiale
	bool obtenirEstPositionInitiale() const;
	
	// Signature de la methode qui permet de set la position d'un pion a initiale
	void setEstPositionInitiale(bool estPositionInitiale);

	// Signature de la methode qui permet de savoir si le mouvement d'un pion est valide
	bool estMouvementValide(int toX, int toY);
	
	// Signature de la methode qui permet de deplacer un pion
	bool deplacer(int toX, int toY);

	// Attributs privés
private:
	bool estPositionInitiale_;

};
#endif
