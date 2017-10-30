/****************************************************************
* Titre: Travail pratique #4- PixelCouleur.cpp
* Date:  30/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/

#include "PixelCouleur.h"


PixelCouleur::PixelCouleur() {
	donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = VALEUR_MIN_PIXEL;
}

PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {
	donnee_[Couleur::R] = testPixel(r);
	donnee_[Couleur::G] = testPixel(g);
	donnee_[Couleur::B] = testPixel(b);
}

PixelCouleur::~PixelCouleur() {}

unchar PixelCouleur::retournerR() const {
	return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
	return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
	return donnee_[Couleur::B];
}

unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

bool PixelCouleur::convertirPixelBN() const {
	unsigned int moyenne = somme() / 3;
	return moyenne > 127;
}

unchar PixelCouleur::convertirPixelGris() const {
	return somme() / 3;
}

void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}

void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}

void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}
/****************************************************************************************
* Description      : Permet la copie profonde d'un pixelCouleur
* Paramètres       : aucun
* Type de retour   : pc(Pixel*)
***************************************************************************************/
Pixel* PixelCouleur::retournerCopieProfonde() const {
	
	Pixel* pc= new PixelCouleur(donnee_[R],donnee_[G],donnee_[B]);
	return pc;
}

void PixelCouleur::mettreEnNegatif() {
		unchar nouvelledonnee_[LONGUEUR_TABLEAU];
		nouvelledonnee_[0] = 255 - retournerR();
		nouvelledonnee_[1] = 255 - retournerG();
		nouvelledonnee_[2] = 255 - retournerB();
}