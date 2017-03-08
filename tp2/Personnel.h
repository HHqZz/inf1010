/********************************************
* Titre: Travail pratique #2 - Personnel.h
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"

using namespace std;

class Personnel
{
public:
	// Constructeur par defaut
	Personnel();

	// Destructeur
	~Personnel();
	
	// Methodes publiques
	bool ajouterMedecin(Medecin* medecin);
	bool retirerMedecin(const std::string& nom);
	bool ajouterInfirmier(Infirmier* infirmier);
	bool retirerInfirmier(const std::string& nom);

	// Signature surcharge operateur 
	Personnel& operator+=(Medecin* medecin);
	Personnel& operator-=(Medecin* medecin);
	Personnel& operator+=(Infirmier* infirmier);
	Personnel& operator-=(Infirmier* infirmier);
		
	char information() const; // A MODIFIER... (si necessaire)
	// _________TP2___________

private:

	// Methodes privées
	void afficherInfirmiers() const; // A MODIFIER... (si necessaire)
	void afficherMedecins() const; // A MODIFIER... (si necessaire)

	// Declaration privée des deux vecteurs medecin et infirmier
	vector<Medecin*> medecins_;
	vector <Infirmier*> infirmiers_;
	// _________TP2___________
};
//une methode qui  permet de notifier lors de l ajout ou le retrait d un infitmier ou d un medecin
void resultatOperation(const string& nom, bool test, unsigned codeOperation);
#endif
