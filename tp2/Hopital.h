/********************************************
* Titre: Travail pratique #2 - Hopital.h
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#ifndef HOPITAL_H
#define HOPITAL_H

#include <string>
#include "Personnel.h"

using namespace std;

class Hopital
{
public:
	// Constructeur par parametre
	Hopital(const string& nom, Personnel* personnel);
	~Hopital();
	
	// Methodes d'acces
	string obtenirNom() const;
	Personnel obtenirPersonnel() const;
	
	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierPersonnel(Personnel* personnel);

	// Signature operateur <<
	friend std::ostream& operator<<(std::ostream&, const Hopital&);

private:
	// Variables privees
	string nom_;
	Personnel* personnel_;
	
};

#endif
