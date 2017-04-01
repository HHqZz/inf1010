#ifndef _FONCTEUR_H_
#define _FONCTEUR_H_
#include "Gene.h"
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

//foncteur de verification de l'egalite de deux especes
class MemeEspece {
public:
	MemeEspece(Gene* gene) : especeGene_(gene->getEspece()) {}
	bool operator()(const Gene* gene) const {
		return gene->getEspece() == especeGene_;
	}

private:
	string especeGene_;
};

//foncteur de verificaiton du meme id
class MemeId {
public:
	MemeId(const Gene* gene)
		: id_(gene->getId()) {}

	bool operator()(const Gene* val) const{
		return (val->getId() == id_);
	}
private:
	unsigned int id_;
};

//foncteur de verification de l'egalite de deux noms
class MemeNom {
public:
	MemeNom(Gene* gene) : nomGene_(gene->getNom()) {}
	bool operator()(const Gene* gene) const{
		return gene->getNom() == nomGene_;
	}
	
private:
		string nomGene_;
};

//foncteur pour le tri  suivant l a longueure                                   // a voir!!!!!!!!!!!!!!!!!!!!!!!!!! 
class TriParLongueur {
public:

	bool operator()(const Gene* p1, const Gene* p2)const {
		return (p1->getContenu().length() < p2->getContenu().length()  );
	
	}
};

//foncteur pour le tri  suivant l espece et le nom 
class TriParEspeceEtNom {														
public:
	
	bool operator()(const Gene* p1, const Gene* p2)const {
		if (p1->getEspece() == p2->getEspece()) {
			
				if (p1->getNom() == p2->getNom())
					return p1->getNom() > p2->getNom();
				else
					return p1->getNom() < p2->getNom();
			}
		else
			return (p1->getEspece() < p2->getEspece());
		
	}
};

//foncteur pour la destruction d'un gene 
class DetruireGenes
{
public:
	void operator()(Gene* gene)
	{
		delete gene;
	};
};

//foncteur pour la desteuction d'un gene suivant son espece
class DetruireEspece{

public:
	DetruireEspece(const string &espece) : espece_(espece) {};
	bool operator()(Gene* gene)
	{
		if (gene->getEspece() == espece_)
		{
			delete gene;
			return true;
		}
		return false;

	}
private:

	string espece_;
};
#endif