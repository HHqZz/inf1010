#include <iostream>
#include "GroupeImage.h"


using namespace std;

GroupeImage::GroupeImage() {};

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

// Surcharge de l'operateur de flux de sortie
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << "--------------------------------------------------" << endl;
    }
    
    os << endl;

    return os;
}