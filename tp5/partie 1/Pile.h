/*********************************************************
* Titre: Travail pratique #5 - Pile.h
* Date:  04 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/



#pragma once
#include <iostream>
#include <vector>
#include <string>

using  namespace std;


template<typename T>
class pile 
{
public : 

	// Constructeur et destructeur
	pile();
	~pile();

	// Methodes publics
	bool empiler(T element);
	bool depiler(T &variable );
	bool estVide();
	bool estPleine();
	int obtenirTaille();
	T* obtenirSommet();

	// Attributs privés
private :

	int  capacite_; 
	int	nbElement_=0;
	T* tableau_;
	const unsigned TAILLE_ = 6 ; 
	
};


/////////////////////////// Implementations //////////////////////////////////


// Implementation destructeur
template <typename T>
pile<T>::~pile() {

	delete[] tableau_;
	
}

// Implementation constructeur
template<typename T>
pile<T>::pile()  {
	capacite_ = TAILLE_; 
	nbElement_ = 0;
	tableau_ = new T[capacite_];
}

//////////////// Implementation des methodes ///////////////////////////////////


/****************************************************************************************
 * Description      : Empile un element sur la pile et renvoie true si en cas de succes
 * Paramètres       : element T
 * Type de retour   : bool
 ***************************************************************************************/
template<typename T>
bool pile<T>::empiler (T element)
{
	if (!estPleine())
	{
		tableau_[nbElement_ ] = element;
		nbElement_++;
		return 1;
	}

	else
	{
		return 0;
	}
}




/***********************************************************************************
 * Description      : Retire l'element du dessus de la pile, renvoie true si succes
 * Paramètres       : element T
 * Type de retour   : bool
 **********************************************************************************/
template <typename T>
bool pile<T>::depiler(T &variable) // revoir retour par parametre
{
	

	if (!estVide())
	{
		variable = (*obtenirSommet());
		nbElement_--;
		return 1;
	}

	else
	{
	
		return 0;
	}

}





/*******************************************************************************
 * Description      : Renvoie true si la pile est vide
 * Paramètres       : 
 * Type de retour   : bool
 ***************************************************************************/
template <typename T>
bool pile<T>::estVide() {
	if (nbElement_==0) {
		
		return 1 ;

	}
	else return 0;

}





/*******************************************************************************
 * Description      : Renvoie true si la pile est pleine
 * Paramètres       : 
 * Type de retour   : bool
 ***************************************************************************/
template <typename T>
bool pile<T>::estPleine() {
	if (nbElement_==capacite_)
	{
		
		return 1;
	}
	else {
		return 0;
	}

}





/*******************************************************************************
 * Description      : Renvoie la taille de la pile
 * Paramètres       : 
 * Type de retour   : int
 ***************************************************************************/
template <typename T>
int pile<T>::obtenirTaille(){

	return nbElement_;

}



/*******************************************************************************
 * Description      : Renvoie l'element du dessus de la pile
 * Paramètres       : 
 * Type de retour   : Type de l'element du dessus de la pile = any
 ***************************************************************************/
template <typename T>
T* pile<T>::obtenirSommet() {

	return  &tableau_[nbElement_-1];

}


///////////////////FIN IMPLEMENTATION METHODES /////////////////

