#include "PixelCouleur.h"

PixelCouleur::PixelCouleur() {
	assignerValeur(VALEUR_MIN_PIXEL);
}

PixelCouleur::PixelCouleur(const bool& donnee) {
	if(donnee) {
        assignerValeur(VALEUR_MAX_PIXEL);
	}
	else {
        assignerValeur(VALEUR_MIN_PIXEL);
	}
}

PixelCouleur::PixelCouleur(const unchar& R, const unchar& G, const unchar& B) {
    donnee_[Couleur::R] = testPixel(R);
    donnee_[Couleur::G] = testPixel(G);
    donnee_[Couleur::B] = testPixel(B);
}

PixelCouleur::PixelCouleur(const unsigned int& donnee) {
    assignerValeur(donnee);
}

PixelCouleur::~PixelCouleur() {}

unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

bool PixelCouleur::convertirPixelBN() {
	unsigned int moyenne = somme() / 3;
	if (moyenne > 127) {
		return true;
	}
	else {
		return false;
	}
}

unchar PixelCouleur::convertirPixelGris() {
	return (somme() / 3);
}

Pixel* PixelCouleur::retournerUneCopieProfonde() {
    PixelCouleur *copie = new PixelCouleur(donnee_[Couleur::R], donnee_[Couleur::G], donnee_[Couleur::B]);
    return copie;
}

void PixelCouleur::assignerValeur(const unsigned int& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

void PixelCouleur::assignerValeurs(const unchar& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

unchar PixelCouleur::retournerR() const {
    return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

bool PixelCouleur::estMajoriteRouge() const
{
	if (donnee_[Couleur::R] > donnee_[Couleur::B] && donnee_[Couleur::R] > donnee_[Couleur::G])
		return true;
	else
		return false;


}

bool PixelCouleur::estMajoriteVert() const
{
	if (donnee_[Couleur::G] > donnee_[Couleur::B] && donnee_[Couleur::G] > donnee_[Couleur::R])
		return true;
	else
		return false;


}

bool PixelCouleur::estMajoriteBleu() const
{
	if (donnee_[Couleur::B] > donnee_[Couleur::G] && donnee_[Couleur::B] > donnee_[Couleur::R])
		return true;
	else
		return false;


}

double PixelCouleur::retournerIntensiteMoyenne() const
{
	double intensite = 0;
	return intensite = (donnee_[Couleur::B] + donnee_[Couleur::G] + donnee_[Couleur::R]) / (3 * VALEUR_MAX_PIXEL);
}

void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteVerte(unchar d) {
	donnee_[Couleur::G] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = testPixel((unsigned int) d);
}

void PixelCouleur::mettreEnNegatif() {
	donnee_[Couleur::R] = 255 - donnee_[Couleur::R];
	donnee_[Couleur::G] = 255 - donnee_[Couleur::G];
	donnee_[Couleur::B] = 255 - donnee_[Couleur::B];
}
