/****************************************************************
* Titre: Travail pratique #3 - Pixelgris.cpp
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/
#include "PixelGris.h"


/****************************************************************************************
* Description      : Construtcteur par défaut
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelGris::PixelGris() : Pixel(TypePixel::NuanceDeGris) {
	donnee_ = 0;
}

/****************************************************************************************
* Description      : Constructeur par paramètre
* Paramètres       : donnee(int)
* Type de retour   : aucun
***************************************************************************************/
PixelGris::PixelGris(unsigned int donnee) : Pixel(TypePixel::NuanceDeGris) {
	donnee_ = donnee;
}

/****************************************************************************************
* Description      : Destructeur
* Paramètres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelGris::~PixelGris()
{
}

/****************************************************************************************
* Description      : retourne la valeur booléenne true si donnee_ a
une valeur supérieure à 127 et false si sa valeur est égale ou inférieure à 127.
* Paramètres       :
* Type de retour   : bool
***************************************************************************************/
bool PixelGris::convertirPixelBN() const
{

	if (donnee_ > 127)
		return true;
	else return false;
}

/****************************************************************************************
* Description      : retourne un pointeur unchar* sur un tableau
comportant les valeurs RGB équivalentes donnant un PixelCouleur
* Paramètres       : aucun
* Type de retour   : unchar *
***************************************************************************************/
unchar * PixelGris::convertirPixelCouleur() const
{

	unchar* tableauRGB = new unchar[3];
	tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = donnee_;
	return tableauRGB;
}

/****************************************************************************************
* Description      : Retourne la valeur de nuance de gris du pixel
* Paramètres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

/*****************************************************************************************************
* Description      : surcharge de l'opérateur == qui retourne un bool en comparant les deux pixels
* Paramètres       : pixel(PixelGris)
* Type de retour   : bool
*****************************************************************************************************/
bool PixelGris::operator==(const PixelGris & pixel) const
{


	if (type_ == pixel.getType() // compare les types
		&& donnee_ == pixel.obtenirDonnee() // compare les valeurs de gris
		)
		return true;

	else return false;
}
