#pragma once





#include <iostream>
#include <vector>
#include <string>

using  namespace std;

class pile 
{
public : 
	pile();
	~pile();

	template<typename T>
	bool empiler(T element);
	template <typename T>
	bool depiler(T &variable );
	bool estVide();
	bool estPleine();
	int obtenirTaille();
	auto obtenirSommet();





private :

	int  capacite_;
	int	nbElement_=0;
	template <typename T>
	vector <T> tableau_(capacite_);


	
};



pile::pile() {
	capacite_ = 6; // la valeur doit etre fixe const..
	nbElement_ = 0;

}

template<typename T>
bool pile::empiler (T element)
{
	if (!estPleine())
	{
		tableau_.push_back(element);
		return 1;
	}

	else
	{
		cout << " Echec, la pile est pleine";
		return 0;
	}
}

template <typename T>
bool pile::depiler(T &variable) // revoir retour par parametre
{
	

	if (!estVide())
	{
		tableau_.pop_back();
		return 1;
	}

	else
	{
		cout << "La pile est deja vide !";
		return 0;
	}

}

bool pile::estVide() {
	if (nbElement_>0 ) {
		cout << "Pile nest pas vide" << endl;
		return 0;
	}


}



bool pile::estPleine() {
	if (nbElement_==capacite_)
	{
		cout << "Pile est pleine" << endl;
		return 1;
	}
	else {
		return 0;
	}

}

int pile::obtenirTaille(){

	return nbElement_;

}

auto pile::obtenirSommet() {

	return  tableau_[nbElement_];

}
