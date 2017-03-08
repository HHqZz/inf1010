/********************************************
* Titre: Travail pratique #3 - Echiquier.h
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#pragma once
#ifndef ECHIQUIER_H
#define ECHIQUIER_H

//#include "Piece.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include <string>
using namespace std;

class Echiquier {



public:
	// Constructeur par defaut
	Echiquier();

	// Destructeur
	~Echiquier();

	// Methodes publiques
	
	// Methode pour ajotuer un Roi
	void ajouterRoi(const Roi &unRoi, int position);
	
	//Methode pour ajotuer une Tour
	void ajouterTour(const Tour& uneTour);
	
	//Methode pour ajotuer
	void ajouterPion(const Pion& unPion);

	// Methode pour enlever une Tour
	void enleverTour(const string id);
	
	//Methode pour enlever un Pion
	void enleverPion(const string id);

	//Methode pour deplacer une Piece
	void deplacerPiece(string id, int toX, int toY);

	
	// Methodes et attributs privés
	
private :

// Attributs privés

	Pion*   tableauPions_;
	Tour*  tableauTours_;
	Roi     rois_[2];	

	
	unsigned int compteurPion_;
	unsigned int compteurTour_;

	unsigned int capaciteTableauPion_;
	unsigned int capaciteTableauTour_;
};

	//Methode pour trouver l'id d'un pion
int trouverIdPion(int compteur, const string &id, const Pion* tableau);

	//Methode pour trouver l'id d'une tour
int trouverIdTour(int compteur, const string &id, const Tour* tableau);


#endif