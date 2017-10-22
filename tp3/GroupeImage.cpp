#include <iostream>
#include "GroupeImage.h"


using namespace std;

GroupeImage::GroupeImage() {}
GroupeImage::~GroupeImage(){}


// Fonction qui ajoute une image au vecteur si elle n'est pas presente
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
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

// Fonction qui retire une image au vecteur si elle est presente
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

// Fonction qui permet de retourner une des images du vecteur
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}

unsigned int GroupeImage::obtenirNombreImages() const
{
	return images_.size();
}

// Surcharge de l'operateur += qui ajoute une image au vecteur
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}

// Surcharge de l'operateur -= qui reture une image au vecteur
GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}

Image * GroupeImage::operator[](const unsigned int & indice) const
{
	return nullptr;
}

void GroupeImage::toutMettreEnNB()
{
	/*
	boucle for sur chaque image du vecteur + appeller fonction correspondante  " convertirBN"
	*/

	for (unsigned int i = 0; i < images_.size(); i++) {
		if (!(images_[i]->obtenirType() == TypeImage::NB))
			images_[i]->convertirNB();
		else  cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en NB. " << endl << endl;
	}
}


void GroupeImage::toutMettreEnGris()
	{
		for (unsigned int i = 0; i < images_.size(); i++) {
			if (!(images_[i]->obtenirType() == TypeImage::Gris))
				images_[i]->convertirGris();
			else cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en gris. " << endl << endl;
		}
	}
void GroupeImage::toutMettreEnCouleur()
{

	for (unsigned int i = 0; i < images_.size(); i++) {
		if (!(images_[i]->obtenirType() == TypeImage::Couleurs))
			images_[i]->convertirCouleur();
		else cout << "L'image " + images_[i]->obtenirNomImage() + " est deja en Couleurs. " << endl << endl;
	}
}

void GroupeImage::toutEnregistrer()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		Image* image = images_[i];
		string path = "../Fichiers TP3/Ensemble d'images/" + image->obtenirTypeEnString() + "/im" + to_string(i) + image->obtenirNomImage();
		cout << "Sauvegarde de " << path << endl;
		images_[i]->sauvegarderImage(path);
	}
	cout << endl;
}

// Surcharge de l'operateur de flux de sortie
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << endl;
		os << "------------------------------------------------------------" << endl << endl;
    }
    
    os << endl;

    return os;
}