//
// Created by Gabriel Bernard on 17-09-12.
//

#include "GroupeImage.h"
#include "Foncteur.h"


#include <algorithm> // sort
#include <iostream>  // cin, cout, ..
#include <iterator>  // *_iterator, *_inserter
#include <functional>// bind, foncteurs STL

using namespace std;

GroupeImage::GroupeImage() {};

GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_.begin(),groupe.images_.end()) {} // list<T> l(begin, end);	Make a list and copy the values from begin to end.

GroupeImage::~GroupeImage() {}




//done
GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	images_.clear();
	
	auto it = groupe.images_.begin();

	auto itPos = images_.begin(); // it sur le groupe courant

	images_.insert(itPos, it,groupe.images_.end());
	
	return *this;
}

//done
bool GroupeImage::ajouterImage(Image* image) {
	
	int tempTaille = images_.size();
	auto it = find_if(images_.begin(), images_.end(), FoncteurEgalImages(image)); 
	if (it == images_.end()) {
		images_.push_back(image);
	}
	else 
	{
		cout << "L'image est deja presente dans le groupe." << endl;
		return false;
	}
	if (images_.size() != tempTaille) {
		cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
		return true;
	}
	return false;
}



//done
bool GroupeImage::retirerImage(const std::string& nom) {
	
	auto it = find_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));

	if (it != images_.end()) {
		images_.erase(it);
		cout << " L'image " << nom << " a bien ete retire " << endl;
		return true;
	}
	else {
		cout << " L'image " << nom << " n'est pas presente dans le groupe " << endl;
		return false;
	}
}

//done
void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	copy(images_.begin(), images_.end(),
		ostream_iterator<Image*>(os, "-------------------------------------------------------------\n")); 
}

string GroupeImage::afficherNomsImages() const
{
	string nomsImage = "";

	auto it = images_.begin(); 

	for (it; it != images_.end();it++) {
		nomsImage += (*it)->obtenirNomImage() + ", ";
	}
	return nomsImage;
}


//done
GroupeImage& GroupeImage::operator+=(Image* image)
{
	ajouterImage(image);
	return *this;
}

//done
GroupeImage& GroupeImage::operator-=(Image* image)
{
	retirerImage(image->obtenirNomImage());
	return *this;
}



// done  A SUPPRIMER ??
std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
{
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	
	copy(groupeImage.images_.begin(), groupeImage.images_.end(), ostream_iterator<Image*>(os,
		"-----------------------------------------------------\n"));
	os << endl;

	return os;
}

//done
unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}



//done
void GroupeImage::toutEnregistrer() {
	cout << "Enregistrement des images : " << endl;
	auto it = images_.begin();
	int compteurIndice = 0;
	for (it; it != images_.end(); it++) {
		Image* image = *it;
		
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/im" + to_string(compteurIndice) + image->obtenirNomImage(); 
		cout << "Sauvegarde de " << nom << endl;
		image ->sauvegarderImage(nom);//modif ?
		compteurIndice++;
	}
}

//done
Image * GroupeImage::obtenirImage(const std::string & nom) const
{
	Image* retPtr = nullptr;
	auto it = find_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	if (it != images_.end()) {
		return *it; //retourne un pointeur de groupeimage
	}
	else {
		cout << "L'image n'est pas dans le groupe ." << endl;
		return retPtr;
	}
}

//done
Image* GroupeImage::obtenirImageParIndex(int index)
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}

//done
double GroupeImage::obtenirIntensiteMoyenne()
{
	double intensiteMoyenne = 0;

	auto it = images_.begin();
	for (it; it != images_.end(); it++) {
		intensiteMoyenne += (*it)->obtenirIntensiteMoyenne();
	}
	return (intensiteMoyenne / images_.size());
}

//done
double GroupeImage::obtenirTailleMoyenne()
{
	double tailleMoyenne = 0;

	auto it = images_.begin();
	for (it; it != images_.end(); it++) {
		tailleMoyenne += (*it)->obtenirTaille();
	}
	return (tailleMoyenne / images_.size());
}
