#ifndef _CONTENEUR_GENES_MAP_H_
#define _CONTENEUR_GENES_MAP_H_

#include "ConteneurGenes.H"
using namespace std;

class ConteneurGenesMap : ConteneurGenes
{
public:
	ConteneurGenesMap() { }
	virtual ~ConteneurGenesMap() {  }

	virtual void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) ;
	virtual Gene* trouver(unsigned int id) const ;

	virtual bool retirer(unsigned int id) = 0;
	virtual unsigned int retirerEspece(const string &espece) ;
	virtual void vider() = 0;

	virtual void afficherParEspeceEtNom(ostream& out) const = 0;
	virtual void afficherParLongueur(ostream& out) const = 0;
	virtual void afficherEspece(const string &espece, ostream& out) const ;

	virtual unsigned int modifierNoms(const string &espece, const map<string, string> &noms) ;

private :
	multimap<string, Gene*> map_;

};

#endif // _CONTENEUR_GENES_MAP_H_


