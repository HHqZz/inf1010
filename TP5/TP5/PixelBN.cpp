#include "PixelBN.h"


PixelBN::PixelBN() {
	donnee_ = false;
}

PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

PixelBN::~PixelBN() {}

unchar PixelBN::convertirPixelGris() {
    if(donnee_) {
        return VALEUR_MAX_PIXEL;
    } else {
        return VALEUR_MIN_PIXEL;
    }
}

bool PixelBN::convertirPixelBN() {
	return donnee_;
}

Pixel* PixelBN::retournerUneCopieProfonde() {
	PixelBN *copie = new PixelBN(donnee_);
	return copie;
}

bool PixelBN::obtenirDonnee() {
	return donnee_;
}

unchar PixelBN::retournerR() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerG() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

unchar PixelBN::retournerB() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

bool PixelBN::estMajoriteRouge() const
{
	return false;
}

bool PixelBN::estMajoriteVert() const
{
	return false;
}

bool PixelBN::estMajoriteBleu() const
{
	return false;
}

double PixelBN::retournerIntensiteMoyenne() const
{
	return donnee_;
}

void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}
