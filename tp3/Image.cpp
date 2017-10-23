/****************************************************************
* Titre: Travail pratique #3 - Image.cpp
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/
#include "Image.h"
#include "PixelCouleur.h"
#include "PixelBN.h"
#include "PixelGris.h"
#include <iostream>
#include <sstream>

using namespace std;


/****************************************************************************************
* Description      : Constructeur par défaut
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
Image::Image() :hauteur_(0), largeur_(0), taille_(0), typeImage_(Couleurs), cheminVersImageOriginale_("unknown"), nomDuFichier_("unknown"), pixels_(nullptr)
{
	/*Un constructeur par défaut qui initialise tout à 0 et nullptr sauf le TypeImage_
	qui sera à Couleurs.
	*/
}


/****************************************************************************************
* Description      : Constructeur par copie
* Paramètres       : i(Image)
* Type de retour   : Image
***************************************************************************************/
Image::Image(const Image & i)
{
	cheminVersImageOriginale_ = i.obtenirCheminDuFichier();
	nomDuFichier_ = i.obtenirNomImage();
	hauteur_ = i.obtenirNombrePixelHauteur();
	largeur_ = i.obtenirNombrePixelLargeur();
	taille_ = i.obtenirTaille();
	typeImage_ = i.obtenirType();
	pixels_ = new Pixel*[taille_];
	this->copieProfonde(i);
}

/****************************************************************************************
* Description      : Constructeur par parametres
* Paramètres       : cheminDuFichier(string),type(TypeImage)
* Type de retour   : Image
***************************************************************************************/
Image::Image(const string& cheminDuFichier, const TypeImage& type)
	: typeImage_(type), cheminVersImageOriginale_(cheminDuFichier), pixels_(nullptr) {
	string tmpNomFichier;

	int i = cheminDuFichier.length();
	while ('/' != cheminDuFichier[i]) {
		nomDuFichier_ = cheminDuFichier[i] + nomDuFichier_;
		i--;
	}
	lireImage(cheminVersImageOriginale_, typeImage_);
	if (pixels_ == nullptr) {
		cerr << "Erreur lors de la lecture de l'image." << endl;
	}
}


/****************************************************************************************
* Description      : Destructeur
* Paramètres       :
* Type de retour   :
***************************************************************************************/
Image::~Image()
{
	for (unsigned int i = 0; i < taille_; i++)
		delete pixels_[i];
	delete[] pixels_;
}

/****************************************************************************************
* Description      : surcharge de l'opérateur << qui affiche les informations de l'image
* Paramètres       : os(ostream), image(Image)
* Type de retour   : aucun
***************************************************************************************/
std::ostream& operator<<(std::ostream& os, const Image& image) {
	// Todo
	os << "Nom de l'image :" << image.nomDuFichier_ << endl;
	os << "Chemin de l'original :" << image.cheminVersImageOriginale_ << endl;
	os << "Taille de l'mage :" << image.taille_ << endl;
	os << "Resolution en pixels :" << image.largeur_ << "x" << image.hauteur_ << endl;
	os << "Type de l'image :" << image.obtenirTypeEnString();
	return os;
}



/****************************************************************************************
* Description      : surcharge de l'opérateur = qui écrase une image par celle rentré en parametre
* Paramètres       : image(Image)
* Type de retour   : image(l'objet courant)
***************************************************************************************/
Image & Image::operator=(const Image & image)
{

	if (!(*this == image)) { 								 													// utilisation de la surcharge de l'opérateur == pour voir si ce n'est la meme image
		pixels_ = new Pixel*(*image.pixels_);
		cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
		nomDuFichier_ = image.nomDuFichier_;
		hauteur_ = image.hauteur_;
		largeur_ = image.largeur_;
		taille_ = image.taille_;
		typeImage_ = image.typeImage_;

		// On supprime les donnees de l'ancienne image
		for (unsigned int i = 0; i < taille_; i++) {
			delete pixels_[i];
			pixels_[i] = nullptr;
		}
		// Copie Profonde de la nouvelle image
		this->copieProfonde(image);
	}
	return *this;
}


/****************************************************************************************
* Description      : surcharge de l'opérateur == qui retourne un bool en comparant deux images
* Paramètres       : image(Image)
* Type de retour   : retour(bool)
***************************************************************************************/
bool Image::operator==(const Image& image) {
	bool retour = true;

	if (image.obtenirNomImage() != nomDuFichier_ ||
		image.obtenirNombrePixelHauteur() != hauteur_ ||
		image.obtenirNombrePixelLargeur() != largeur_) {
		retour = false;
	}
	else {
		for (unsigned int i = 0; i < taille_; i++) {				// on parcous le tableau de pixel pour y vérifier si ils sont les memes 
			if (image.pixels_[i] != pixels_[i]) {
				return false;
			}
		}
	}

	return retour;
}


/****************************************************************************************
* Description      : surcharge de l'opérateur == qui retourne un bool en comparant le nom rentré en parametre et le nom de l'image
* Paramètres       : nom(string)
* Type de retour   : bool
***************************************************************************************/
bool Image::operator==(const string& nom) {
	return(nomDuFichier_ == nom);
}


/****************************************************************************************
* Description      : Permet de faire la Deep copy d'une image
* Paramètres       : const Image & image
* Type de retour   : aucun
***************************************************************************************/
void Image::copieProfonde(const Image & image)
{
	for (unsigned int i = 0; i < taille_; i++) {
		switch (typeImage_)			// Switch selon le type de l'image
		{
		case TypeImage::Couleurs:

			PixelCouleur* pixelCouleur;
			PixelCouleur* newp;
			pixelCouleur = static_cast<PixelCouleur*> (image.pixels_[i]);		// On force le compilateur a prendre un Pixel couleur en memoire
			newp = new PixelCouleur(pixelCouleur->retournerR(), pixelCouleur->retournerG(), pixelCouleur->retournerB());
			pixels_[i] = newp;
			break;

		case TypeImage::Gris:

			PixelGris *pixelGris;
			PixelGris *newpixelGris;
			pixelGris = static_cast<PixelGris*> (image.pixels_[i]);		// On force le compilateur a prendre un Pixel Gris en memoire
			newpixelGris = new PixelGris(pixelGris->obtenirDonnee());
			pixels_[i] = newpixelGris;

		case TypeImage::NB:

			PixelBN *pixelBlancNoir;
			PixelBN *newpixelBlancNoir;
			pixelBlancNoir = static_cast<PixelBN*> (image.pixels_[i]);// On force le compilateur a prendre un Pixel BN en memoire
			newpixelBlancNoir = new PixelBN(pixelBlancNoir->obtenirDonnee());
			pixels_[i] = newpixelBlancNoir;
			break;
		}
	}
}

/****************************************************************************************
* Description      : Permet de comparer deux images / True si elles ont le même nom
* Paramètres       : const string& nom,  Image& image
* Type de retour   : bool
***************************************************************************************/
bool operator==(const string& nom, Image& image) {
	return image == nom;
}

/****************************************************************************************
* Description      : Permet d'obtenir le chemin vers l'image
* Paramètres       : aucun
* Type de retour   : string
***************************************************************************************/
std::string Image::obtenirCheminDuFichier() const {
	return cheminVersImageOriginale_;
}


/****************************************************************************************
* Description      : Permet d'obtenir le nom de l'image
* Paramètres       : aucun
* Type de retour   : string
***************************************************************************************/
std::string Image::obtenirNomImage() const {
	return nomDuFichier_;
}


/****************************************************************************************
* Description      : Permet de retourner le nombre de pixel en hauteur
* Paramètres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int Image::obtenirNombrePixelHauteur() const {
	return hauteur_;
}


/****************************************************************************************
* Description      : Permet de retourner le nombre de pixel en largeur
* Paramètres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int Image::obtenirNombrePixelLargeur() const {
	return largeur_;
}


/****************************************************************************************
* Description      : Permet de retourner la taille de l'image
* Paramètres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int Image::obtenirTaille() const {
	return taille_;
}


/****************************************************************************************
* Description      : Permet de retourner le type de l'image
* Paramètres       : aucun
* Type de retour   : TypeImage
***************************************************************************************/
TypeImage Image::obtenirType() const {
	return typeImage_;
}

/****************************************************************************************
* Description      : Permet de changer le nom de l'image
* Paramètres       : const std::string &nom
* Type de retour   : aucun
***************************************************************************************/
void Image::changerNomImage(const std::string &nom) {
	nomDuFichier_ = nom;
}

/****************************************************************************************
* Description      : Permet de convertir le type de l'image en string
* Paramètres       : aucun
* Type de retour   : string
***************************************************************************************/
string Image::obtenirTypeEnString() const {

	string type_en_string;
	switch (typeImage_) {
	case TypeImage::Couleurs:		// Si le type est Couleurs
		type_en_string = "Couleurs";
		break;
	case TypeImage::Gris:		// Si le type est Gris
		type_en_string = "Nuances de Gris";
		break;
	case TypeImage::NB:		// Si le type est NB
		type_en_string = "Noir et Blanc";
		break;
	}
	return type_en_string;
}

/****************************************************************************************
* Description      : Lit une image .bmp avec encodage 24 bits et la stock dans pixels_
* Paramètres       : const string& , const TypeImage&
* Type de retour   : aucun
***************************************************************************************/
void Image::lireImage(const string& nomDuFichier, const TypeImage& type) {
	// Si pixels_ n'est pas nul, les pixels sont detruits
	if (pixels_ != nullptr) {
		unsigned int i;
		for (i = 0; i < taille_; i++) {
			delete pixels_[i];
			pixels_ = nullptr;
		}
		delete[] pixels_;
	}

	// Ouverture du stream entrant
	ifstream bmpIn(cheminVersImageOriginale_.c_str(), ios::in | ios::binary);

	// Si l'ouverture a echouee on quitte la fonction
	if (!bmpIn.is_open()) {
		cerr << "Erreur, le fichier " << nomDuFichier << " n'a pas pu etre ouvert." << endl;
		exit(9);
	}

	// Lecture de l'en-tete du fichier .bmp
	char info[54];

	bmpIn.read(info, 54);

	int offset = *(int*)&info[10];

	// Enregistrement des informations pertinentes
	largeur_ = *(unsigned int*)&info[18];
	hauteur_ = *(unsigned int*)&info[22];

	short bytes = *(short*)&info[28];

	// Verification de l'encodage de l'image
	if (bytes != 24) {
		cerr << "This bmp is a " << bytes << " and this program only supports 24 bytes bmp files" << endl;
		exit(10);
	}

	// Enregistrement de la taille
	taille_ = largeur_ * hauteur_;

	// Envoit du curseur aux donnees RGB
	bmpIn.seekg(offset);

	// Preparation a la lecture
	unsigned int x, y, pos = 0;
	char tmp[3];
	pixels_ = new Pixel*[taille_];
	unsigned int moyenne;
	// Lecture des donnees RGB de l'image
	for (y = 0; y < hauteur_; y++) {
		for (x = 0; x < largeur_; x++) {
			int indice = (hauteur_ - 1 - y) * largeur_ + x;
			// Lit les pixels du bmp en ordre b g r
			bmpIn.read(tmp, 3);
			switch (type) {
			case TypeImage::Couleurs:
				pixels_[indice] = new PixelCouleur((unchar)tmp[2], (unchar)tmp[1], (unchar)tmp[0]);
				break;
			case TypeImage::Gris:
				moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
				moyenne /= 3;
				pixels_[indice] = new PixelGris((unchar)moyenne);
				break;
			case TypeImage::NB:
				moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
				moyenne /= 3;
				pixels_[indice] = new PixelBN(moyenne > 127);
				break;
			}
			pos += 3;
		}
		while (pos % 4) {
			char tmp;
			bmpIn.read(&tmp, 1);
			pos += 1;
		}
	}

	// Fermeture du stream d'entre
	bmpIn.close();

}


/****************************************************************************************
* Description      : Permet de convertir une image en image NB
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
void Image::convertirNB()
{
	Pixel * newVal = nullptr;
	for (unsigned int i = 0; i < taille_; i++)
	{
		switch (pixels_[i]->getType())			//	On fait un switch selon le type du pixel
		{
		case TypePixel::Couleur:

			PixelCouleur* pixelCouleur;
			pixelCouleur = static_cast<PixelCouleur*>(pixels_[i]);		// On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelBN(pixelCouleur->convertirPixelBN());
			pixels_[i] = newVal;
			typeImage_ = TypeImage::NB;		// On change le type de l'image en question
			break;

		case TypePixel::NuanceDeGris:

			PixelGris* pixelGris;
			pixelGris = static_cast<PixelGris*>(pixels_[i]);		// On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelBN(pixelGris->convertirPixelBN());
			pixels_[i] = newVal;
			typeImage_ = TypeImage::NB;		// On change le type de l'image en question
			break;
		}
	}
}

/****************************************************************************************
* Description      : Permet de convertir une image en image gris
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
void Image::convertirGris()
{

	Pixel * newVal = nullptr;
	for (unsigned int i = 0; i < taille_; i++)
	{
		switch (pixels_[i]->getType())	//	On fait un switch selon le type du pixel
		{
		case TypePixel::Couleur:

			PixelCouleur* pixelCouleur;
			pixelCouleur = static_cast<PixelCouleur*>(pixels_[i]);	// On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelGris(pixelCouleur->convertirPixelGris());
			pixels_[i] = newVal;
			typeImage_ = TypeImage::Gris;	// On change le type de l'image en question
			break;

		case TypePixel::NoireBlanc:

			PixelBN* pixelBN;
			pixelBN = static_cast<PixelBN*>(pixels_[i]);	// On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelGris(pixelBN->convertirPixelGris());
			pixels_[i] = newVal;
			typeImage_ = TypeImage::Gris;	// On change le type de l'image en question
			break;

		}
	}

}


/****************************************************************************************
* Description      : Permet de convertir une image en couleur
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
void Image::convertirCouleur()
{

	Pixel * newVal = nullptr;	// création d'un pointeur
	for (unsigned int i = 0; i < taille_; i++)
	{
		switch (pixels_[i]->getType())	// On fait un switch selon le type du pixel
		{
		case TypePixel::NoireBlanc:

			PixelBN* pixelBlancNoir;
			pixelBlancNoir = static_cast<PixelBN*>(pixels_[i]); // On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelCouleur(*(pixelBlancNoir->convertirPixelCouleur()), *(pixelBlancNoir->convertirPixelCouleur()), *(pixelBlancNoir->convertirPixelCouleur())); // le pointeur pointe maintenant sur un nouveau pixel Couleur avec les données du pixel BN
			pixels_[i] = newVal;	// On met le pointeur dans le tableau de pointeur
			typeImage_ = TypeImage::Couleurs; // On change le type de l'image en question
			break;

		case TypePixel::NuanceDeGris:

			PixelGris* pixelGris;
			pixelGris = static_cast<PixelGris*>(pixels_[i]); // On cast le type du pixel pour forcer le compilateur a changer le type
			newVal = new PixelCouleur(*(pixelGris->convertirPixelCouleur()), *(pixelGris->convertirPixelCouleur()), *(pixelGris->convertirPixelCouleur()));
			pixels_[i] = newVal;
			typeImage_ = TypeImage::Couleurs; // On change le type de l'image en question
			break;
		}
	}

}

/****************************************************************************************
* Description      : Permet de sauvegarder une image dans un fichier
* Paramètres       : const string &nomDuFichier
* Type de retour   : aucun
***************************************************************************************/
void Image::sauvegarderImage(const string &nomDuFichier) {

	// Ouverture d'un stream de sortie
	ofstream bmpOut(nomDuFichier.c_str(), ios::out | ios::binary);
	if (!bmpOut.is_open()) {
		cerr << "Erreur lors de la tentative d'ecriture du fichier." << endl;
		exit(12);
	}

	// Preparation a l'ecriture
	unsigned char *rgb = new unsigned char[taille_ * 3];
	unchar valeur;
	PixelBN* pbn;
	PixelGris* pg;

	// Creation d'un tableau comportant toutes les donnees de l'image
	for (unsigned int i = 0; i < taille_; i++) {
		switch (pixels_[i]->getType()) {
		case TypePixel::Couleur:
			rgb[i * 3] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerR();
			rgb[i * 3 + 1] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerG();
			rgb[i * 3 + 2] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerB();
			break;
		case TypePixel::NoireBlanc:
			pbn = static_cast<PixelBN*> (pixels_[i]);
			if (pbn->obtenirDonnee()) {
				valeur = (unchar)VALEUR_MAX_PIXEL;
			}
			else {
				valeur = (unchar)VALEUR_MIN_PIXEL;
			}
			rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
			break;
		case TypePixel::NuanceDeGris:
			pg = static_cast<PixelGris*> (pixels_[i]);
			valeur = (unchar)pg->obtenirDonnee();
			rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
			break;
		}

	}

	// Ajout de l'en-tete de fichier et rearrangement au format .bmp
	unsigned char* output;
	size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);
	// Ecriture de l'image sur le disque
	bmpOut.write((char*)output, output_size);
	// Fermeture du descripteur de fichier
	bmpOut.close();
	// Liberation memoire
	delete[] rgb;
	delete[] output;
}