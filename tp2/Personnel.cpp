/********************************************
* Titre: Travail pratique #2 - Personnel.cpp
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#include "Medecin.h"
#include "Infirmier.h"
#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include "Const.h"

// Implementation constructeur par defaut
Personnel::Personnel() {};

// Implementation destructeur 
Personnel::~Personnel() {};

// Implementation de la fonction qui permet d'ajouter un medecin
bool Personnel::ajouterMedecin(Medecin* medecin)  
{
	// A MODIFIER...
	int i = 0;
	bool test = true;
	while (i < medecins_.size() && test)
	{
		if (*medecin == *medecins_[i])
			test = false;
		i++;
	}
	resultatOperation(medecin->obtenirNom(), test, 0);
	if (test) {
		medecins_.push_back(medecin);
		
		return true;
	}
	return false;
}

// Implementation surcharge d'operateur
Personnel& Personnel::operator+=(Medecin* medecin)
{

	ajouterMedecin(medecin);
	return *this;
}

Personnel& Personnel::operator-=(Medecin* medecin)
{
	retirerMedecin(medecin->obtenirNom());
	return *this;
}

// Implementation de la fonction qui permet de retirer un medecin
bool Personnel::retirerMedecin(const std::string& nom)  
{
	// A MODIFIER...
	int i = 0;
	bool test = true;
	for (i = 0; i < medecins_.size() && test; i++)
	{
		if (nom == *medecins_[i])
			test = false;
	}
	resultatOperation(nom, test, 1);
	if (test == false)
	{
		for (int j = i - 1; j < medecins_.size()-1; j++)
			*medecins_[j] = *medecins_[j + 1];
		medecins_.pop_back();
		return true;
	}
	return false;
}

// Implementation de la fonction qui permet d'ajouter un infirmier
bool Personnel::ajouterInfirmier(Infirmier* infirmier) 
{
	// A MODIFIER...
	int i = 0;
	bool test = true;
	while (i < infirmiers_.size() && test)
	{
		if (*infirmier == *infirmiers_[i])
			test = false;
		i++;
	}
	resultatOperation(infirmier->obtenirNomComplet(), test, 0);
	if (test) 
	{
		infirmiers_.push_back(infirmier);
		return true;
	}
	return false;
}

// Implementation surcharge operateur
Personnel& Personnel::operator+=(Infirmier* infirmier)
{

	ajouterInfirmier(infirmier);
	return *this;
}

Personnel& Personnel::operator-=(Infirmier* infirmier)
{
	retirerInfirmier(infirmier->obtenirNomComplet());
	return *this;
}

// Implementation de la fonction qui permet de retirer un infirmier
bool Personnel::retirerInfirmier(const std::string& nomComplet) 
{
	// A MODIFIER...
	int i = 0;
	bool test = true;
	for (i = 0; i < infirmiers_.size() && test; i++)
	{
		if (nomComplet == *infirmiers_[i])
			test = false;
	}

	resultatOperation(nomComplet, test, 1);
	if (test == false)
	{
		for (int j = i - 1; j < infirmiers_.size() - 1; j++)
			infirmiers_[j] = infirmiers_[j + 1];
		infirmiers_.pop_back();
		return true;
	}
	return false;
}
	

char Personnel::information() const // A MODIFIER...
{
	this->afficherMedecins();
	this->afficherInfirmiers();
	return '/n';
}

// 
void Personnel::afficherMedecins() const // A MODIFIER... (si necessaire)
{
	string tabMed = "Tableau Medecins";
	string nom = "Nom";
	string horaires = "Horaires";
	string domaine = "Domaine Specialite";
	string niveau = "Niveau Specialite";

	std::cout << AFFICHER_ESPACE(espacement_medecin / 2) << tabMed 
		<< AFFICHER_ESPACE(espacement_medecin / 2) << endl;

	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;

	std::cout << "| " << nom << AFFICHER_ESPACE(espace_nom - nom.size()) 
		<< " | " << horaires << AFFICHER_ESPACE(2*espace_horaires - horaires.size())
		<< " | " << domaine << AFFICHER_ESPACE(espace_domaine - domaine.size()) 
		<< " | " << AFFICHER_ESPACE(espace_niveau - niveau.size() / 2) << niveau
		<< AFFICHER_ESPACE(espace_niveau - niveau.size() / 2)
		<< "| " << endl;
		
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	for (size_t i = 0; i < medecins_.size(); i++)
	{	
		std::cout << *medecins_[i];
		std::cout << endl;
	}
	std::cout << AFFICHER_LINE(espacement_medecin + tabMed.size()) << endl;
	std::cout << AFFICHER_ESPACE(espacement_medecin + tabMed.size()) << endl;
}

void Personnel::afficherInfirmiers() const // A MODIFIER... (si necessaire)
{
	string tabInf = "Tableau Infimiers";
	string nomComplet = "Nom Complet";
	string nbChambre = "Nombre de Chambre";
	std::cout << AFFICHER_ESPACE(espacement_infirmier/2) << tabInf 
		<< AFFICHER_ESPACE(espacement_infirmier/2) << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;
	
	std::cout << "| " << nomComplet << AFFICHER_ESPACE(espace_nom - nomComplet.size())
		 << " | " << nbChambre << AFFICHER_ESPACE(2 * espace_chambre - nbChambre.size())
		 << " | " << endl;
	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl;

	for (size_t i = 0; i < infirmiers_.size(); i++)
	{
		std::cout << *infirmiers_[i];
		std::cout << endl;
	}

	std::cout << AFFICHER_LINE(espacement_infirmier + tabInf.size()) << endl << endl;;
}

// implementation d une methode qui  permet de notifier lors de l ajout ou le retrait d un infitmier ou d un medecin suivant les valeurs du test et le code
// de l'operation qui est passer en parametre , si le code d operatio est 1 alors la methode considere le retrait si le code est 0 la methode considere l ajout et suivant la valeur du test elle affiche si l operation a bien ŽtŽ faite ou pas
void resultatOperation(const string& nom, bool test, unsigned codeOperation) 
{
	if (test && codeOperation == 0)
		cout << nom << " a bien ete ajoute !" << endl;
	else if (test == false && codeOperation == 0)
		cout << nom << " n a pas ete ajoute" << endl;
	else if (test == false && codeOperation == 1)
		cout << nom << " a bien ete retire !" << endl;
	else if (test  && codeOperation == 1)
		cout << nom << " n a pas ete retire " << endl;
}

