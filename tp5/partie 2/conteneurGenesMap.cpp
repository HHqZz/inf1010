/*********************************************************
* Titre: Travail pratique #5 - conteneurGenesMap.cpp
* Date:  04 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/


#include "conteneurGenesMap.h"
#include <vector>
#include <iterator>
#include "Foncteur.h"



/***********************************************************************************
 * Description      : Constructeur par defaut
 * Paramètres       : 
 * Type de retour   : 
 **********************************************************************************/
ConteneurGenesMap::ConteneurGenesMap()
{

}

/***********************************************************************************
 * Description      : Destructeur qui vide la map
 * Paramètres       :  
 * Type de retour   : 
 **********************************************************************************/
ConteneurGenesMap::~ConteneurGenesMap()
{
	vider();
}

/***************************************************************************************************
 * Description      : methode qui permet d'inserer un gene dans le map de la classe COnteneurGeneMap
 * Paramètres       : int , string, string, string, string
 * Type de retour   : void
 ****************************************************************************************************/
void ConteneurGenesMap::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu) {
	map_.insert(pair<string, Gene*>(espece, new Gene(id, nom, desc, espece, contenu)));			//insertion du gene dans la map
}



/***************************************************************************************************
 * Description      : Methode qui permet de trouver un gene par son id dans le map
 * Paramètres       : int
 * Type de retour   : Gene*
 ****************************************************************************************************/
Gene* ConteneurGenesMap::trouver(unsigned int id) const{
	if (!map_.empty())												//on verifie si la map est vide ou non
	{
		for (auto it = map_.begin(); it != map_.end();)			//recherche du gene dans la map
		{
			if (it->second->getId() == id)
				return it->second;								//retourne le second du map qui est le gene
			else
				it++;
		}
	}                        //retourne un gene vide au cas ou on ne trouve pas le gene dans la map
	return 	nullptr;
}




/***************************************************************************************************
 * Description      : Methode qui permet de retirer un gene  qui se trouve dans le map selon son id
 * Paramètres       : int
 * Type de retour   : Renvoie True si le gene dont l'id a été donné en parametre est retiré
 ****************************************************************************************************/
bool ConteneurGenesMap::retirer(unsigned int id) {
	if (!map_.empty())									//on verifie si la map est vide ou non
	{
		for (auto it = map_.begin(); it != map_.end();)			//recherche du gene dans la map
		{
			if (it->second->getId() == id)
			{
				delete(it->second);
				it = map_.erase(it);							//si le gene est trouve, on le supprime du map
				return true;
			}
			else
				it++;
		}
	}
	return false;

}


/*****************************************************************************************************************************
 * Description      : Methode qui permet de retirer une espece de gene contenue dans le map et retourne le nbr de gene retire
 * Paramètres       : string espece
 * Type de retour   : Renvoie un int contenant le nombre genes supprimés
 ******************************************************************************************************************************/
unsigned int ConteneurGenesMap::retirerEspece(const string &espece) {
	int nbGeneSupprime = 0;
	if (!map_.empty())												//on verifie si la map est vide ou non
	{
		for (auto it = map_.begin(); it != map_.end(); ++it)			//recherche du gene dans la map
		{
			if (it->second->getEspece() == espece)				//if trouvé, on le supprime
			{
				delete(it->second);
				nbGeneSupprime++;								//on compte le nombre de genes supprimes
			}
		}
		map_.erase(espece);
	}
	return nbGeneSupprime;
}


 
/***************************************************************************************************
 * Description      : methode qui permet de vider la map
 * Paramètres       : 
 * Type de retour   : Void
 ****************************************************************************************************/
void ConteneurGenesMap::vider() {
	if (!map_.empty())											//on verifie si la map est vide ou non
	{
		for (auto it = map_.begin(); it != map_.end(); ++it)
		{
			delete it->second;									// on supprime desalloue tout l espace alloue pour les genes de la map
		}
		map_.clear();
	}														   // on vide la map
	else
		cout << "la map est deja vide !!" << endl;
}



/*************************************************************************************************************************
 * Description      : Methode pour l affichage de contenu de la map suivant le critere du nom d espece et du nom du gene
 * Paramètres       : Ostream out
 * Type de retour   : Void
 *************************************************************************************************************************/
 void ConteneurGenesMap::afficherParEspeceEtNom(ostream& out) const { 
	 if (!map_.empty())													//on verifie si la map est vide ou non
	 {
		 vector<Gene*> mapTemp;											// on copie la map dans un vecteur
		 for (auto it = map_.begin(); it != map_.end(); ++it) {
			 mapTemp.push_back(it->second);
		 }
		 sort(mapTemp.begin(), mapTemp.end(), TriParEspeceEtNom());		//on trie la map suivant le critere espece et nom
		 copy(mapTemp.begin(), mapTemp.end(), ostream_iterator<Gene*>(out, "\n")); // on affiche le contenu trie
	 }
	 else
		 cout << "la map est vide !!" << endl;
 }

 
 
 /*************************************************************************************************************************
 * Description      : Methode qui fait l affichage du contenu de la map suivant la longueur
 * Paramètres       : Ostream out
 * Type de retour   : Void
 *************************************************************************************************************************/
 void ConteneurGenesMap::afficherParLongueur(ostream& out) const {
	 if (!map_.empty())													//on verifie si la map est vide ou non
	 {
		 vector<Gene*> mapTemp;											// on copie la map dans un vecteur
		 for (auto it = map_.begin(); it != map_.end(); ++it) {
			 mapTemp.push_back(it->second);
		 }
		 sort(mapTemp.begin(), mapTemp.end(), TriParLongueur());	//on trie la map suivant la longueure		
		 copy(mapTemp.begin(), mapTemp.end(), ostream_iterator<Gene*>(out, "\n"));  // on affiche le contenu trie
	 }
	 else
		 cout << "la map est vide !!" << endl;
 }

 
 
 

/*************************************************************************************************************************
 * Description      : Afficher le contenu de la map selon l espece
 * Paramètres       : string espece , Ostream out
 * Type de retour   : Void
 *************************************************************************************************************************/
 void ConteneurGenesMap::afficherEspece(const string &espece, ostream& out) const {
	 if (!map_.empty())												//on verifie si la map est vide ou non
	 {
		 for (auto it = map_.begin(); it != map_.end(); ++it)
		 {
			 if (it->first == espece)
				 out << it->second;
		 }
	 }
	 else
		 cout << "la map est vide !!" << endl;
 }
 
 
 


/*************************************************************************************************************************
 * Description      : Modififer le contenu de la map selon la map<string,string> et l espece donnee
 * Paramètres       : string , map<string, string>
 * Type de retour   : int 
 *************************************************************************************************************************/
unsigned int ConteneurGenesMap::modifierNoms(const string &espece, const map<string, string> &noms) {
	int i = 0;
	if (!map_.empty())																	//on verifie si la map est vide ou non
	{
		for (auto it = map_.begin(); it != map_.end(); ++it)
		{
			for (auto it1 = noms.begin(); it1 != noms.end(); ++it1)
			{
				if (it1->first == it->second->getNom() && espece == it ->second->getEspece())
				{
					it->second->setNom(it1->second);
					i++;
				}
			}
		}
	}
	return i;
	
}

