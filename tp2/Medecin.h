/********************************************
* Titre: Travail pratique #2 - Medecin.h
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#ifndef MEDECIN_H
#define MEDECIN_H

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par parametre
	Medecin(const string& nom); // A MODIFIER... (si necessaire)
	Medecin(const string& nom, int horaires, Specialite* specialite); // A MODIFIER... (si necessaire)
	//Constructeur par copie
	Medecin(const Medecin &medecin);
	// Destructeur
	~Medecin(); // A MODIFIER... (si necessaire)
	
	// Methodes d'acces
	string obtenirNom() const;
	int obtenirHoraires() const;
	Specialite obtenirSpecialite() const;
	
	// Methodes de modification
	void modifierNom(const string& nom);
	void modifierHoraires(int horaires);
	void modifierSpecialite(Specialite* specialite);
	
	// Signature surcharge operateur
	bool operator==(const Medecin &medecin)const ;
	bool operator==(const std::string& nom)const ;
	
	Medecin& operator=(const Medecin& medecin);

	friend bool operator==(const std::string&, const Medecin &medecin) ;
	friend std::ostream& operator<<(std::ostream&, const Medecin&);

private:
	// Variables privees
	string nom_;
	int horaires_;
	Specialite* specialite_;
	
};

#endif