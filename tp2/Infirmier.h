/********************************************
* Titre: Travail pratique #2 - Infirmier.h
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#ifndef INFIRMIER_H
#define INFIRMIER_H

#include <string>
#include <iostream>

class Infirmier
{
public:
	
	//Constructeur par defaut 
	Infirmier(); // A MODIFIER... (si necessaire)

	//Constructeur par parametre 
	Infirmier(const std::string& nom, const std::string& prenom, unsigned int nbChambre); // A MODIFIER... (si necessaire)

	//Destructeur
	~Infirmier(); // A MODIFIER... (si necessaire)

	//Methode d'acces
	std::string obtenirNom() const; 
	std::string obtenirPrenom() const;
	unsigned int obtenirNbChambre() const;
	std::string obtenirNomComplet() const;

	//Methode de modification
	void modifierNom(const std::string& nom);
	void modifierPrenom(const std::string& prenom);
	void modifierNbChambre(unsigned int nbChambre);

	// Signature surcharge operateur ==
	bool operator==(const Infirmier &infirmier)const;
	bool operator==(const std::string& nomComplet)const;
	friend bool operator==(const std::string& ,const Infirmier &infirmier) ;
    // Signature surcharge operateur d affichage <<
	friend std::ostream& operator<<(std::ostream&, const Infirmier&);

private:
	// Attributs / variables privées
	std::string nom_;
	std::string prenom_;
	unsigned int nbChambre_;
};

#endif
