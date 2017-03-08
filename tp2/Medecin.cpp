/********************************************
* Titre: Travail pratique #2 - Medecin.cpp
* Date: Mardi 7	fÈvrier	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#include "Medecin.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

Medecin::Medecin(const string& nom): nom_(nom), horaires_(0)
{
}

Medecin::Medecin(const string& nom, int horaires, Specialite* specialite): nom_(nom), horaires_(horaires), specialite_(specialite)
{
}

Medecin::Medecin(const Medecin &medecin)
{
	horaires_= medecin.horaires_ ;
    nom_ = medecin.nom_;
	specialite_ = medecin.specialite_;
}

Medecin::~Medecin() // A MODIFIER... (si necessaire)
{
	
}

string Medecin::obtenirNom() const
{
	return nom_;
}

int Medecin::obtenirHoraires() const
{
	return horaires_;
}

Specialite Medecin::obtenirSpecialite() const
{
	return *specialite_;
}

void Medecin::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Medecin::modifierHoraires(int horaires)
{
	horaires_ = horaires;
}

void Medecin::modifierSpecialite(Specialite* specialite)
{
	specialite_ = specialite;
}
// implementation operateur == de la classe medecin qui fair la comparaison du medecin avec un medecin donné suivant son nom
bool Medecin::operator==(const Medecin &medecin) const
{
	if (nom_ == medecin.obtenirNom())
		return true;
	return false;
}
// implementation operateur == de la classe medecin qui fait la comparaison du medecin avec un nom donné suivant les deux noms
bool Medecin::operator==(const std::string& nom)const
{
	if (nom_ == nom)
		return true;
	return false;
}
// implementation operateur == de la classe medecin qui fait la comparaison de deux medecin en prenant le nom en premier et le medecin en deuxieme "nom == medecin"
bool operator==(const std::string& nom , const Medecin &medecin) 
{
	return nom == medecin.nom_;
}
// implementation de l operateur << d affichage d un medecin
std::ostream& operator<<(std::ostream& o, const Medecin& medecin)
{
	return o  << "| " << medecin.nom_ << AFFICHER_ESPACE(espace_nom - medecin.nom_.size())
	 << " | " << AFFICHER_ESPACE(espace_horaires - std::to_string(medecin.horaires_).size()) << medecin.horaires_
	 << AFFICHER_ESPACE(espace_horaires)<<
	 medecin.obtenirSpecialite()
	 << endl;
}
// implementation de l operateur d affectation =
Medecin& Medecin::operator=(const Medecin& medecin)
{
	if (&medecin != this)
	{
		nom_ = medecin.nom_;
		horaires_ = medecin.horaires_;
		specialite_ = medecin.specialite_;
	}
	return *this;
}
