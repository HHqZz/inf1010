//
// Created by Gabriel Bernard
//

#include "PixelGris.h"

PixelGris::PixelGris() {}

PixelGris::PixelGris(unsigned int donnee)  {
    if(donnee < VALEUR_MAX_PIXEL) {
        donnee_ = donnee;
    } else {
        donnee_ = VALEUR_MAX_PIXEL;
    }
}

PixelGris::~PixelGris() {}

unchar* PixelGris::convertirPixelCouleur() const {
	unchar *ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = donnee_;
	return ret;
}

bool PixelGris::convertirPixelBN() const {
	return donnee_ > 127;
}

unchar PixelGris::convertirPixelGris() const {
	return donnee_;
}

unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

void PixelGris::mettreEnNegatif() {
	donnee_ = donnee_ - 255;
}

unchar PixelGris::retournerB() const{
	return donnee_;
}

unchar PixelGris::retournerR() const{
	return donnee_;
}

unchar PixelGris::retournerG() const{
	return donnee_;
}

Pixel* PixelGris::retournerCopieProfonde() const{
	return new PixelGris(donnee_);
}