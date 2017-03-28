#pragma once





#include <iostream>
#include <vector>
#include <string>

using  namespace std;
template<typename T>
class pile 
{
public : 
	pile();
	~pile();

	
	bool empiler(T element);
	
	bool depiler(T &variable );
	bool estVide();
	bool estPleine();
	int obtenirTaille();
	T* obtenirSommet();





private :

	int  capacite_;
	int	nbElement_=0;
	T* tableau_;


	
};


template <typename T>
pile<T>::~pile() {

	


	delete[] tableau_;
	
}

template<typename T>
pile<T>::pile()  {
	capacite_ = 6; // la valeur doit etre fixe const..
	nbElement_ = 0;
	tableau_ = new T[capacite_];
}

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

template <typename T>
bool pile<T>::estVide() {
	if (nbElement_==0) {
		
		return 1 ;

	}
	else return 0;

}


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

template <typename T>
int pile<T>::obtenirTaille(){

	return nbElement_;

}

template <typename T>
T* pile<T>::obtenirSommet() {

	return  &tableau_[nbElement_-1];

}
