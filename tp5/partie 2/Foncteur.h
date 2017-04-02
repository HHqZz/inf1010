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

/****************************************************************************
 * Description      : Constructeur 
 * Paramètres       : Pointeur de Gene
 * Type de retour   : 
 ***************************************************************************/
	MemeEspece(Gene* gene) : especeGene_(gene->getEspece()) {}
	
	
	
/****************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Pointeur de Gene
 * Type de retour   : True si les deux especes sont similaires
 ***************************************************************************/
	bool operator()(const Gene* gene) const {
		return gene->getEspece() == especeGene_;
	}

	
	// Attribut privé
private:
	string especeGene_;
};
/*********************** FIN MemeEspece ***************************/

/*********************** DEBUT MemeId ***************************/

//foncteur de verificaiton du meme id
class MemeId {
public:

/****************************************************************************
 * Description      : Constructeur
 * Paramètres       : Pointeur de Gene
 * Type de retour   : 
 ***************************************************************************/
	MemeId(const Gene* gene)
		: id_(gene->getId()) {}

		
		
/****************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Pointeur de Gene
 * Type de retour   : True si les deux ID sont similaires
 ***************************************************************************/
	bool operator()(const Gene* val) const{
		return (val->getId() == id_);
	}
	
	
	
// Attribut privé 
private:
	unsigned int id_;
};

/*********************** FIN MemeId ***************************/


/*********************** Debut MemeNom ***************************/

//foncteur de verification de l'egalite de deux noms
class MemeNom {
public:

	/****************************************************************************
 * Description      : Constructeur
 * Paramètres       : Pointeur de Gene
 * Type de retour   : 
 ***************************************************************************/
	MemeNom(Gene* gene) : nomGene_(gene->getNom()) {}
	
	
/****************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Pointeur de Gene
 * Type de retour   : True si les deux noms sont similaires
 ***************************************************************************/
	bool operator()(const Gene* gene) const{
		return gene->getNom() == nomGene_;
	}
	
	
// Attribut privé
private:
		string nomGene_;
};

/*********************** Fin MemeNom ***************************/



/*********************** Debut TriParLongueur ***************************/
//foncteur pour le tri  suivant la longueur                                
class TriParLongueur {
public:

/********************************************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Deux pointeurs de gene
 * Type de retour   : True si la taille du contenu du premier gene est plus petite que celle du second
 *******************************************************************************************************/	
	bool operator()(const Gene* p1, const Gene* p2)const {
		return (p1->getContenu().length() < p2->getContenu().length()  );
	
	}
};

//foncteur pour le tri  suivant l espece et le nom 
class TriParEspeceEtNom {														
public:
	
/****************************************************************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Deux pointeurs de gene
 * Type de retour   : True si 2 genes sont de meme espece et que le nom du gene 1 est plus petit que celui du gene 2
					  True si 2 genes sont pas de meme espece et que l'espece du gene 1 est plus petite que celle du gene 2
 ***************************************************************************************************************************/
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

/*********************** FIN TriParEspeceEtNom ***************************/



/*********************** Debut DetruireGenes ***************************/
//foncteur pour la destruction d'un gene 
class DetruireGenes
{
public:

/********************************************************************************************************
 * Description      : Surcharge de l'operateur () -> Detruit le gene passé en parametre
 * Paramètres       : Un pointeur de gene
 * Type de retour   : void
 *******************************************************************************************************/		
	void operator()(Gene* gene)
	{
		delete gene;
	};
};

/*********************** FIN DetruireGenes ***************************/


/*********************** Debut DetruireEspece ***************************/
//foncteur pour la desteuction d'un gene suivant son espece
class DetruireEspece{

public:

/********************************************************************************************************
 * Description      : Constructeur
 * Paramètres       : nom de l'espece
 * Type de retour   : 
 *******************************************************************************************************/	
	DetruireEspece(const string &espece) : espece_(espece) {};
	
	
/********************************************************************************************************
 * Description      : Surcharge de l'operateur ()
 * Paramètres       : Un pointeur de Gene
 * Type de retour   : True si l'espece a bien été détruite
 *******************************************************************************************************/	
	bool operator()(Gene* gene)
	{
		if (gene->getEspece() == espece_)
		{
			delete gene;
			return true;
		}
		return false;

	}
	
// Attribut privé
private:

	string espece_;
};
#endif
/*********************** FIN DetruireEspece ***************************/

