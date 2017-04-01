#include "conteneurGenesListe.h"
#include <iostream>
#include <algorithm>
#include "Foncteur.h"
#include <iterator>
#include <functional>
using namespace std::placeholders;

//constructeur par defaut
ConteneurGenesListe::ConteneurGenesListe()
{

}

//destructeur
ConteneurGenesListe::~ConteneurGenesListe()
{
	vider();
}

//methode qui permet d'inserer un gene dans la liste de la classe COnteneurGeneMap
void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	liste_.push_back(new Gene(id, nom, desc, espece, contenu));
}


//Methode qui permet de trouver un gene par son id dans la liste
Gene* ConteneurGenesListe::trouver(unsigned int id) const {
	if (!liste_.empty())																		//on verifie si la liste est vide ou non
	{
		auto it = find_if(liste_.begin(), liste_.end(), MemeId(new Gene(id, "", "", "", "")));  // on cherche le gene a retirer suivant son id
		if (it != liste_.end())
			return *it;
	}
	return nullptr;
}


//Methode qui permet de retirer un gene  qui se trouve dans la liste selon son id
bool ConteneurGenesListe::retirer(unsigned int id) {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		Gene* geneARetire = trouver(id);									// on cherche le gene a retirer suivant son id
		if (geneARetire != nullptr)
		{
			liste_.remove(geneARetire);											// on procede a sa supression
			delete geneARetire;
			return true;
		}
	}
	return false;

}

//Methode qui permet de retirer une espece de gene contenue dans la liste et retourne le nbr de gene retire
unsigned int ConteneurGenesListe::retirerEspece(const string &espece) {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		int i = liste_.size();										//taille de la liste avant le remove
		liste_.remove_if(DetruireEspece(espece));					// suppression du gene suivant son espece
		return i - liste_.size();									//taille de la liste avant le remove - la tille de la liste apes le remove donne le nbre d entites retirees de la liste
	}
	else
		return 0;
}


//methode qui permet de vider la liste 
void ConteneurGenesListe::vider() {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		for_each(liste_.begin(), liste_.end(), DetruireGenes());
		liste_.clear();
	}
	else
		cout << "la map est deja vide !!" << endl;
}


//methode pour l affichage de contenu de la liste suivant le critere du nom d espece et du nom du gene
void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		list<Gene*> m;
		m = liste_;																// on cree une autre liste a partir de notre liste constante
		m.sort(TriParEspeceEtNom());											// on tri le contenu de cette liste
		copy(m.begin(), m.end(), ostream_iterator<Gene*>(out, "\n"));			// on afficher son contenu
	}
	else
		cout << "la map est deja vide !!" << endl;
}


//methode qui fait l affichage du contenue de la liste suivant la longuer
void ConteneurGenesListe::afficherParLongueur(ostream& out) const {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		list<Gene*> m;
		m = liste_;																// on cree une autre liste a partir de notre liste constante
		m.sort(TriParLongueur());											// on tri le contenu de cette liste
		copy(m.begin(), m.end(), ostream_iterator<Gene*>(out, "\n"));			// on afficher son contenu
	}
	else
		cout << "la map est deja vide !!" << endl;
}


//afficher le contenu de la liste selon l espece
void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		list<Gene*> m;
		m = liste_;																// on cree une autre liste a partir de notre liste constante
													// on tri le contenu de cette liste
		copy_if(m.begin(), m.end(), ostream_iterator<Gene*>(out, "\n"),MemeEspece(new Gene(0,"","",espece,"")));			// on afficher son contenu
	}
	else
		cout << "la map est deja vide !!" << endl;
}


//modififer le contenu de la liste selon la map<string,string> et l espece donnee
unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms) {
	Gene* gene;
	list<Gene*>::iterator itGene = liste_.begin();
	unsigned int nombreModifies = 0;
	for (auto it = noms.begin(); it != noms.end();)
	{
		itGene = find_if(liste_.begin(), liste_.end(),
			bind(logical_and<bool>(),
				bind(MemeNom(new Gene(0,"","",it->first,"")), _1),
				bind(MemeEspece(new Gene(0,"","",espece,"")), _1)
			)
		);
		if (itGene != liste_.end())
		{
			gene = *itGene;
			gene->setNom(it->second);
			fill_n(itGene, 1, gene);
			nombreModifies++;
		}
		else
		{
			++it;
		}
	}
	return nombreModifies;

}
