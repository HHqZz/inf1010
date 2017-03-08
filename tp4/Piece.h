/********************************************
* Titre: Travail pratique #4 - Piece.h
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <string>
#include <typeinfo>



using namespace std;

class Piece {

// Methodes publics :
public :
	//signature du constructeur par defaut d'une piece
	Piece();
	
	// Signature du constructeur par  parametres d'une piece
	Piece(const string& id, const string& couleur, int positionX, int positionY);
	
	// destructeurd'une piece
	virtual ~Piece();

	// acesseur et modificateur : 
	
	// Signature des methodes pour obtenir et modifier l'id d'une piece
	string obtenirId() const;
	void modifierId(const string& id);
	
	// Signature des methodes pour obtenir et modifier une couleur d'une piece
	string obtenirCouleur() const;
	void modifierCouleur(const string& couleur);
	
	// Signature des methodes pour Obtenir et modifier les positions x et y d'une piece
	int obtenirPositionX() const;
	void modifierPositionX(int x);
	int obtenirPositionY() const;
	void modifierPositionY(int y);
	
	// Signature des methodes pour savoir si un mouvement et valide, et pour deplacer une piece 
	virtual bool estMouvementValide(int toX, int toY) const;
    virtual bool deplacer(int toX, int toY) = 0;
	
	//  Signature de la methode pour afficher
    virtual std::ostream&  afficher(ostream& stream) const;
	
	// Signature de la methode pour obtenir l'id d'une piece
	string obtenirType() const;
	
	// Signature de la surcharge de l'operateur <<
friend std::ostream& operator<<(std::ostream& out, const Piece& piece);

     
	// Attributs privés
 protected:

	string id_;
	string couleur_;
	int positionX_;
	int positionY_;

};
#endif
