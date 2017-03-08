/********************************************
* Titre: Travail pratique #2 - Specialite.h
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#ifndef SPECIALITE_H
#define SPECIALITE_H

#include <string>
#include <iostream>

class Specialite
{
public:

	// Constructeur par defaut 
	Specialite();

	//Constructeur par parametres
	Specialite(const std::string& domaine, unsigned int niveau);

	// Methodes d'acces aux attributs
	std::string obtenirDomaine() const;
	unsigned int obtenirNiveau() const;

	//Methodes de modification des attributs
	void modifierDomaine(const std::string& domaine);
	void modifierNiveau(unsigned int niveau);

	// Signature surcharge operateur <<
	friend  std::ostream& operator<<(std::ostream& o, const Specialite& specialite);

	// _________TP2___________
private:

	// attributs privés
	std::string domaine_;
	unsigned int niveau_;
};

#endif
