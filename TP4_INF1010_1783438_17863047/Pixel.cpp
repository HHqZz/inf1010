/****************************************************************
* Titre: Travail pratique #4- Pixel.cpp
* Date:  30/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/

#include "Pixel.h"

Pixel::Pixel()  {}

Pixel::~Pixel() {}

unsigned int Pixel::testPixel(const unsigned int &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

unchar Pixel::testPixel(const unchar &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

bool Pixel::operator==(const Pixel& pixel) const {
	if (retournerG() == pixel.retournerG() && retournerB() == pixel.retournerB() && retournerR() == pixel.retournerR()) {
		return true;
	}
	else { return false; };
}
