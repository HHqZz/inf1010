/********************************************
* Titre: Travail pratique #2 - Infirmier.cpp
* Date: 19 janvier 2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#include "Infirmier.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

// Implementation du constructeur par defaut
Infirmier::Infirmier() :nom_(""), prenom_(""), nbChambre_(0)
{
}
// Implementation du constructeur par parametre
Infirmier::Infirmier(const std::string & nom, const std::string & prenom, unsigned int nbChambre): nom_(nom), prenom_(prenom), nbChambre_(nbChambre)
{
}

// Implementation du destructeur
Infirmier::~Infirmier()
{
}

// Implementation des methodes d'acces
std::string Infirmier::obtenirNom() const
{ 
	return nom_;
}

std::string Infirmier::obtenirPrenom() const
{
	return prenom_;
}

unsigned int Infirmier::obtenirNbChambre() const
{
	return nbChambre_;
}

std::string Infirmier::obtenirNomComplet() const
{
	return(nom_ + " " + prenom_);
}

// Implementation d'operateur == qui comparent deux infirmiers par leurs noms complets
bool Infirmier::operator==(const Infirmier &infirmier)const 
{
	return (infirmier.obtenirNomComplet() == obtenirNomComplet());
}

// Implementation d'operateur == qui comparent deux infirmiers par leurs noms complets en faisant "infimier == nomComplet " avec le nomComplet passé en parametre
bool Infirmier::operator==(const std::string& nomComplet) const
{
	return(obtenirNomComplet() == nomComplet);
}

// Implementation des methodes de modification
void Infirmier::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

void Infirmier::modifierPrenom(const std::string & prenom)
{
	prenom_ = prenom;
}

void Infirmier::modifierNbChambre(unsigned int nbChambre)
{
	nbChambre_ = nbChambre;
}

// Implementation de la surcharge d'operateur  " = " d affectation d un infirmier
bool operator==(const std::string& nomComplet, const Infirmier &infirmier)
{
	return(nomComplet == infirmier.obtenirNomComplet());
}

// Implementation de la surcharge d'operateur  " << " qui affiche les renseignements sur un infirmier
 std::ostream& operator<<(std::ostream& o, const Infirmier& infirmier)
{
	 return 	o << "| " << infirmier.obtenirNomComplet() << AFFICHER_ESPACE(espace_nom - infirmier.obtenirNom().size())
		 << " | " << AFFICHER_ESPACE(espace_chambre - std::to_string(infirmier.nbChambre_).size() / 2)
		 << infirmier.nbChambre_ << AFFICHER_ESPACE(espace_chambre)
		 << "|" << std::endl;
	
}
