/****************************************************************
* Titre: Travail pratique #3 -
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/

//includes 
#include <iostream>
#include "GroupeImage.h"


using namespace std;

/***********************************************************************************************************
* Description      : Constructeur par defaut
* Paramètres       : aucun
* Type de retour   :
***********************************************************************************************************/
GroupeImage::GroupeImage() {}

/***********************************************************************************************************
* Description      : Detruit toutes les images du groupe
* Paramètres       : aucun
* Type de retour   : aucun
***********************************************************************************************************/
GroupeImage::~GroupeImage() {
	for (unsigned int i = 0; i < images_.size(); i++)
		delete images_[i];
}

/***********************************************************************************************************
* Description      : Fonction qui ajoute une image au vecteur si elle n'est pas presente :  true si ajouté
* Paramètres       : Image* image
* Type de retour   : bool
***********************************************************************************************************/
bool GroupeImage::ajouterImage(Image* image) {
	for (unsigned int i = 0; i < images_.size(); i++)
	{
		if (image->obtenirNomImage() == *(images_[i]))
		{
			cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
			return false;
		}
	}
	images_.push_back(image);
	std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
	return true;
}

/****************************************************************************************************
* Description      : Fonction qui retire une image au vecteur si elle est presente: true si retiré
* Paramètres       : const std::string& nom
* Type de retour   : bool
****************************************************************************************************/
bool GroupeImage::retirerImage(const std::string& nom) {
	for (unsigned int i = 0; i < images_.size(); i++)
	{
		if (*(images_[i]) == nom)
		{
			images_[i] = images_.back();
			images_.pop_back();
			cout << nom << " a bien ete retire" << endl;
			return true;
		}
	}
	return false;
}

/*****************************************************************************************
* Description      : Permet d'obtenir une image a un certain indice d'un groupe d'image
* Paramètres       : unsigned int
* Type de retour   : Image*
****************************************************************************************/
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

/****************************************************************************************
* Description      : Permet de retourner le nombre d'image dans un groupe
* Paramètres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int GroupeImage::obtenirNombreImages() const
{
	return images_.size();
}

/****************************************************************************************
* Description      :  Surcharge de l'operateur += qui ajoute une image au vecteur
* Paramètres       : Image*
* Type de retour   : GroupeImage&
***************************************************************************************/
GroupeImage& GroupeImage::operator+=(Image* image)
{
	ajouterImage(image);
	return *this;
}

/****************************************************************************************
* Description      : Surcharge de l'operateur -=  qui retourne une image au vecteur
* Paramètres       : Image*
* Type de retour   : GroupeImage&
***************************************************************************************/
GroupeImage& GroupeImage::operator-=(Image* image)
{
	retirerImage(image->obtenirNomImage());
	return *this;
}


/****************************************************************************************
* Description      : Surcharge operateur []
* Paramètres       : const unsigned int & indice
* Type de retour   : Image *
***************************************************************************************/
Image * GroupeImage::operator[](const unsigned int & indice) const
{
	return nullptr;
}

/***************************************************************************************************************
* Description      : Permet de convertir toutes les images d'un groupe d'image en NB
* Paramètres       : aucun
* Type de retour   : aucun
**************************************************************************************************************/
void GroupeImage::toutMettreEnNB()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		if (!(images_[i]->obtenirType() == TypeImage::NB))
			images_[i]->convertirNB();
		else  cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en NB. " << endl << endl;
	}
}

/****************************************************************************************
* Description      : Permet de convertir toutes les images d'un groupe d'image en gris
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
void GroupeImage::toutMettreEnGris()
{
	for (unsigned int i = 0; i < images_.size(); i++) {		// On verifie que l image n'est pas deja en gris
		if (!(images_[i]->obtenirType() == TypeImage::Gris))
			images_[i]->convertirGris();
		else cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en gris. " << endl << endl;
	}
}

/******************************************************************************************
* Description      : Permet de convertir toutes les images d'un groupe d'image en couleur
* Paramètres       : aucun
* Type de retour   : aucun
*****************************************************************************************/
void GroupeImage::toutMettreEnCouleur()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		if (!(images_[i]->obtenirType() == TypeImage::Couleurs))	// On verifie que l'image n'est pas deja en Couleur
			images_[i]->convertirCouleur();
		else cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en Couleurs. " << endl << endl;
	}
}

/****************************************************************************************
* Description      : Permet d'enregistrer toutes les images du groupe d'images
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
void GroupeImage::toutEnregistrer()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		Image* image = images_[i];
		string path = "../Tp3/Ensemble d'images/" + image->obtenirTypeEnString() + "/im" + to_string(i) + image->obtenirNomImage();
		cout << "Sauvegarde de " << path << endl;
		images_[i]->sauvegarderImage(path);
	}
	cout << endl;
}

/*********************************************************************************************
* Description      : Surcharge de l'operateur de flux de sortie : affiche un groupe d'image
* Paramètres       : ostream& os, const GroupeImage& groupeImage
* Type de retour   : ostream&
*******************************************************************************************/
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
	os << endl;
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	for (unsigned int j = 0; j < groupeImage.images_.size(); j++) {		// Pour chaque image dans le groupe
		os << *groupeImage.images_[j] << endl;												// On affiche l'image
		os << "------------------------------------------------------------" << endl << endl;
	}

	os << endl;

	return os;
}

//end