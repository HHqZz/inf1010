/********************************************
* Titre: Travail pratique #2 - Hopital.cpp
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#include "Hopital.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

// Implementation du constructeur par parametre
Hopital::Hopital(const string& nom, Personnel* personnel): nom_(nom), personnel_(personnel)
{
}

// Implementation du destructeur
Hopital::~Hopital()
{
}

// Implementation des methodes d'acces
string Hopital::obtenirNom() const
{
	return nom_;
}

Personnel Hopital::obtenirPersonnel() const
{
	return *personnel_;
}

// Implementation des methodesz de modification
void Hopital::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Hopital::modifierPersonnel(Personnel* personnel)
{
	personnel_ = personnel;
}

// Implementation d'operateur " << " qui affiche les renseigenemnts sur un hopital
std::ostream& operator<<(std::ostream& o, const Hopital& hopital)
{
	string hopInf = hopital.obtenirNom();
	std::cout << AFFICHER_ESPACE(espacement_hopital / 2) << hopInf
		<< AFFICHER_ESPACE(espacement_hopital / 2) << endl
		<< AFFICHER_LINE(espacement_hopital + hopInf.size()) << endl;
	return
		o << hopital.obtenirPersonnel().information();
		
}
