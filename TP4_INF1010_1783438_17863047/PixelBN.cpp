/****************************************************************
* Titre: Travail pratique #4- PixelBN.cpp
* Date:  30/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/

#include "PixelBN.h"


PixelBN::PixelBN() {
	donnee_ = false;
}

PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

PixelBN::~PixelBN() {}

unchar* PixelBN::convertirPixelCouleur() const {
    unchar valeur = (unchar)VALEUR_MIN_PIXEL;
    if(donnee_) {
        valeur = (unchar)VALEUR_MAX_PIXEL;
    }

	unchar* ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = valeur;

	return ret;
}

unchar PixelBN::convertirPixelGris() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

bool PixelBN::convertirPixelBN() const {
	return donnee_;
}

bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

unchar PixelBN::retournerB() const {
	if (donnee_) {
		return VALEUR_MAX_PIXEL;
	}
	else return VALEUR_MIN_PIXEL;
}

unchar PixelBN::retournerR() const {
	if (donnee_) {
		return VALEUR_MAX_PIXEL;
	}
	else return VALEUR_MIN_PIXEL;
}

unchar PixelBN::retournerG() const {
	if (donnee_) {
		return VALEUR_MAX_PIXEL;
	}
	else return VALEUR_MIN_PIXEL;
}

void PixelBN::mettreEnNegatif() {
	if (donnee_ == true) {
		donnee_ == false;
	}
	else(donnee_ == true);
}
/****************************************************************************************
* Description      : Permet la copie profonde d'un pixel BN
* Paramètres       : aucun
* Type de retour   : pbn(Pixel*)
***************************************************************************************/
Pixel* PixelBN::retournerCopieProfonde() const {
	Pixel* pbn= new PixelBN(donnee_);
	return pbn;
}