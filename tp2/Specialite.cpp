/********************************************
* Titre: Travail pratique #2 - Specialite.cpp
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#include "Specialite.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

//Implementation constructeur par defaut
Specialite::Specialite()
{
}

//Implementation constructeur par parametre
Specialite::Specialite(const std::string & domaine, unsigned int niveau): domaine_(domaine), niveau_(niveau)
{
}

 //Implementation  Methodes d'acces 
std::string Specialite::obtenirDomaine() const
{
	return domaine_;
}

unsigned int Specialite::obtenirNiveau() const
{
	return niveau_;
}

// Implementation Methode de modification
void Specialite::modifierDomaine(const std::string & domaine)
{
	domaine_ = domaine;
}

void Specialite::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

// Implementation surcharge d'operateur <<
std::ostream& operator<<(std::ostream& o, const Specialite& specialite)
{
	return o << " | " << specialite.domaine_ << AFFICHER_ESPACE(espace_domaine - specialite.domaine_.size())
		<< " | " << AFFICHER_ESPACE(espace_niveau - std::to_string(specialite.niveau_).size()) << specialite.niveau_

		<< AFFICHER_ESPACE(espace_niveau) << " | ";
}
