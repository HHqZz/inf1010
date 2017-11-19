#ifndef  FONCTEUR
#define  FONCTEUR

#include "GroupeImage.h"
#include <stdlib.h>
#include <cstdlib>
#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
									//image_ = new Image(*image); // deep copy
		image_ = image;				//shallow copy car on ne modifie pas l'image en la comparant
	}
	~FoncteurEgalImages() {}

	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
		if (*image_ == *imageAComparer)
			return true;
		else return false;
	}

private:
	Image* image_;
};

class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom) {
		nom_ = nom;
	}
	~FoncteurImagesDeMemeNom() {};

	bool operator() ( Image* image) const {
		if (nom_ == *image)
			return true;
		else return false;
	}

private:
	std::string nom_;
};

class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}

	unsigned int operator() (const Image* image) const {
		return (image->obtenirTaille());

	}
};


class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	void operator() (Image* image) {
		image->convertirGris();
	}

};

class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	void operator() (Image* image) {
		image->convertirCouleur();
	}

};

class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	void operator() (Image* image) {
		image->convertirBN();
	}

};

class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	void operator() (Image* image) {
		image->mettreEnNegatif();
	}

};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		min_ = min;
		max_ = max;
	}

	~FoncteurGenerateurNombresAlea() {}

		int operator() () const {
		unsigned int range;
		range = max_ - min_ + 1;
		return rand() % range + min_;
	}

private:
	unsigned int min_;
	unsigned int max_;
};


#endif;