/*********************************************************
* Titre: Travail pratique #5 - conteneurGenesListe.cpp
* Date:  04 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/


#include <iterator>
#include <functional>
#include <iostream>
#include <algorithm>

#include "conteneurGenesListe.h"
#include "Foncteur.h"


using namespace std::placeholders;


/***********************************************************************************
 * Description      : Constructeur par defaut
 * Paramètres       : 
 * Type de retour   : 
 **********************************************************************************/
ConteneurGenesListe::ConteneurGenesListe()
{

}



/***********************************************************************************
 * Description      : Destructeur qui vide la liste
 * Paramètres       : 
 * Type de retour   : 
 **********************************************************************************/
ConteneurGenesListe::~ConteneurGenesListe()
{
	vider();
}




/**********************************************************************************************************
 * Description      : Methode qui permet d'inserer un gene dans la liste de la classe ConteneurGeneMap
 * Paramètres       : int, string, string, string, string 
 * Type de retour   : void
 **********************************************************************************************************/
void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	liste_.push_back(new Gene(id, nom, desc, espece, contenu));
}




/***********************************************************************************
 * Description      : Methode qui permet de trouver un gene par son id dans la liste
 * Paramètres       : int id
 * Type de retour   : Pointeur de Gene
 **********************************************************************************/
Gene* ConteneurGenesListe::trouver(unsigned int id) const {
	if (!liste_.empty())																		//on verifie si la liste est vide ou non
	{
		auto it = find_if(liste_.begin(), liste_.end(), MemeId(new Gene(id, "", "", "", "")));  // on cherche le gene a retirer suivant son id
		if (it != liste_.end())
			return *it;
	}
	return nullptr;
}





/*****************************************************************************************************
 * Description      : Methode qui permet de retirer un gene  qui se trouve dans la liste selon son id
 * Paramètres       : int id
 * Type de retour   : Renvoie True si le gene a bien été retiré
 *****************************************************************************************************/
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




/********************************************************************************************************************************
 * Description      : Methode qui permet de retirer une espece de gene contenue dans la liste et retourne le nbr de gene retire
 * Paramètres       : string espece
 * Type de retour   : int = renvoie le nombre d'entité retiré de la liste
 **********************************************************************************************************************************/
unsigned int ConteneurGenesListe::retirerEspece(const string &espece) {
	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		int i = liste_.size();										//taille de la liste avant le remove
		liste_.remove_if(DetruireEspece(espece));					// suppression du gene suivant son espece
		return i - liste_.size();									//taille de la liste avant le remove -  taille de la liste apres le remove = Nb entites retirees de la liste
	}
	else
		return 0;
}




/***********************************************************************************
 * Description      : Methode qui permet de vider la liste 
 * Paramètres       : 
 * Type de retour   : void
 **********************************************************************************/
void ConteneurGenesListe::vider() {

	if (!liste_.empty())														//on verifie si la liste est vide ou non
	{
		for_each(liste_.begin(), liste_.end(), DetruireGenes());
		liste_.clear();
	}
	else
		cout << "la map est deja vide !!" << endl;
}




/**************************************************************************************************************************
 * Description      : Methode pour l'affichage de contenu de la liste suivant le critere du nom d espece et du nom du gene
 * Paramètres       : ostream out
 * Type de retour   : void
 ***************************************************************************************************************************/
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




/**************************************************************************************************
 * Description      : Methode qui fait l'affichage du contenu de la liste suivant la longueur
 * Paramètres       : ostream out
 * Type de retour   : void
 ****************************************************************************************************/
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




/***********************************************************************************
 * Description      : Afficher le contenu de la liste selon l'espece
 * Paramètres       : string espece, ostream out
 * Type de retour   : void
 **********************************************************************************/
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




/***********************************************************************************
 * Description      : Modififer le contenu de la liste selon la map<string,string> et l'espece donnée
 * Paramètres       : string espece, map<string,string>
 * Type de retour   : int = Nombre de noms modifiés dans la liste
 **********************************************************************************/
unsigned int ConteneurGenesListe::modifierNoms(const string & espece, const map<string, string>& noms)
{
	int compteur = 0;

	if (!liste_.empty() )																		 // On verifie que la liste  n'est pas vide
	{
		auto iteratorList = find_if(liste_.begin(), liste_.end(), MemeEspece(new Gene(0, "", "", espece, "")));  // On recupere l'iterator qui pointe vers l'espece passée en parametre

		while (iteratorList != liste_.end())
		{
			auto iteratorMap = noms.find((*iteratorList)->getNom());
			if (iteratorMap != noms.end())
			{
				(*iteratorList)->setNom((*iteratorMap).second);
				++compteur;
			}

			iteratorList = find_if(++iteratorList, liste_.end(), MemeEspece(new Gene(0, "", "", espece, "")));
		}
	}

	return compteur;
}


		/*Gene* gene;
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

		}*/