#include "conteneurGenesMap.h"
#include <map>
#include <iostream>

ConteneurGenesMap::ConteneurGenesMap() { }

ConteneurGenesMap:: ~ConteneurGenesMap() {  }

void ConteneurGenesMap::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	Gene* gene = new Gene(id, nom, desc, espece, contenu);
	map_.insert(pair<string, Gene*>(espece, gene));
}
Gene* ConteneurGenesMap::trouver(unsigned int id) const{
	Gene* gene = new Gene(id, "", "", "", "");
	 map_.find(pair<string, Gene*>(gene->getEspece(),gene));

	
}

bool ConteneurGenesMap::retirer(unsigned int id) {
	Gene* gene = new Gene(id, "", "", "", "");
	map_.erase(pair<string, Gene*>(gene->getEspece(), gene));

}


unsigned int ConteneurGenesMap::retirerEspece(const string &espece) {


}


void ConteneurGenesMap::vider() {

}



 void ConteneurGenesMap::afficherParEspeceEtNom(ostream& out) const { 
 
 }


 void ConteneurGenesMap::afficherParLongueur(ostream& out) const {
 
 }


 void ConteneurGenesMap::afficherEspece(const string &espece, ostream& out) const {
 
 }


unsigned int ConteneurGenesMap::modifierNoms(const string &espece, const map<string, string> &noms) {

}


