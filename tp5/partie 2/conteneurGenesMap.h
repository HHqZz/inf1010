/*********************************************************
* Titre: Travail pratique #5 - conteneurGenesMap.h
* Date:  04 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/


#ifndef _CONTENEUR_GENES_MAP_H_
#define _CONTENEUR_GENES_MAP_H_

#include "ConteneurGenes.h"
using namespace std;

class ConteneurGenesMap : public ConteneurGenes
{
public:
	ConteneurGenesMap();
	virtual ~ConteneurGenesMap();

	virtual void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) ;
	virtual Gene* trouver(unsigned int id) const ;

	virtual bool retirer(unsigned int id) ;
	virtual unsigned int retirerEspece(const string &espece) ;
	virtual void vider() ;

	virtual void afficherParEspeceEtNom(ostream& out) const ;
	virtual void afficherParLongueur(ostream& out) const ;
	virtual void afficherEspece(const string &espece, ostream& out) const ;

	virtual unsigned int modifierNoms(const string &espece, const map<string, string> &noms) ;

private :
	multimap<string, Gene*> map_;

};

#endif // _CONTENEUR_GENES_MAP_H_
