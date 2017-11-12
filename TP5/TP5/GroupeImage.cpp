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

GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_.begin,groupe.images_.end) {} // list<T> l(begin, end);	Make a list and copy the values from begin to end.

GroupeImage::~GroupeImage() {}




//done
GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	images_.clear();
	
	auto it = groupe.images_.begin;

	for (it; it != groupe.images_.end(); it++) {
		images_.insert(it, *it);
	}
	return *this;
}

//done
bool GroupeImage::ajouterImage(Image* image) {
	
	auto it = find_if(images_.begin, images_.end, FoncteurEgalImages(image)); 
	if(it == images_.end)
		cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;

	images_.push_back(image);
	std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
}



//done
bool GroupeImage::retirerImage(const std::string& nom) {
	
	auto it = find_if(images_.begin, images_.end, FoncteurImagesDeMemeNom(nom));

	if (it != images_.end) {
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
		ostream_iterator<Image>(cout, "-------------------------------------------------------------\n")); 
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

	
	copy(groupeImage.images_.begin, groupeImage.images_.end, ostream_iterator<Image>(cout,
		"-----------------------------------------------------\n"));
	os << endl;

	return os;
}

//done
unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

//done
void GroupeImage::toutMettreEnNB() {
	for_each(images_.begin, images_.end, FoncteurMettreEnBN());
}

//done
void GroupeImage::toutMettreEnGris() {
	for_each(images_.begin, images_.end, FoncteurMettreEnGris());
}

//done
void GroupeImage::toutMettreEnCouleur() {
	for_each(images_.begin, images_.end, FoncteurMettreEnCouleur());
}

//done
void GroupeImage::toutMettreEnNegatif() {
	for_each(images_.begin, images_.end, FoncteurMettreEnNegatif());
}


//done
void GroupeImage::toutEnregistrer() {
	cout << "Enregistrement des images : " << endl;
	auto it = images_.begin;
	int compteurIndice = 0;
	for (it; it != images_.end; it++) {
		Image* image = *it;
		
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/im" + to_string(compteurIndice) + image->obtenirNomImage(); 
		cout << "Sauvegarde de " << nom << endl;
		*it ->sauvegarderImage(nom);
		compteurIndice++;
	}
}

//done
Image * GroupeImage::obtenirImage(const std::string & nom) const
{
	Image* retPtr = nullptr;
	auto it = find_if(images_.begin, images_.end, FoncteurImagesDeMemeNom(nom));
	if (it != images_.end) {
		return it;
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

	auto it = images_.begin;
	for (it; it != images_.end; it++) {
		intensiteMoyenne += *it.ObtenirIntensiteMoyenne();
	}
	return (intensiteMoyenne / images_.size());
}

//done
double GroupeImage::obtenirTailleMoyenne()
{
	double tailleMoyenne = 0;

	auto it = images_.begin;
	for (it; it != images_.end; it++) {
		tailleMoyenne += *it.obtenirTaille();
	}
	return (tailleMoyenne / images_.size());
}
