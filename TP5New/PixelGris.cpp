#include "PixelGris.h"



PixelGris::PixelGris() {}

PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
}

PixelGris::PixelGris(unchar donnee): donnee_(donnee) {}

PixelGris::~PixelGris() {}


bool PixelGris::convertirPixelBN() {
    if (donnee_ > 127) {
        return true;
    } else {
        return false;
    }
}

unchar PixelGris::convertirPixelGris() {
    return donnee_;
}

Pixel* PixelGris::retournerUneCopieProfonde() {
    PixelGris* copie = new PixelGris(donnee_);
    return copie;
}

unchar PixelGris::retournerR() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerG() const {
    return (unchar) donnee_;
}

unchar PixelGris::retournerB() const {
    return (unchar) donnee_;
}

bool PixelGris::estMajoriteRouge() const
{
	return false;
}

bool PixelGris::estMajoriteVert() const
{
	return false;
}

bool PixelGris::estMajoriteBleu() const
{
	return false;
}

double PixelGris::retournerIntensiteMoyenne() const
{
	return donnee_/VALEUR_MAX_PIXEL;
}

void PixelGris::mettreEnNegatif() {
    donnee_ = -donnee_;
}

unchar PixelGris::obtenirDonnee() const {
    return donnee_;
}

