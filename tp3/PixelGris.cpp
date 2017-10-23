/****************************************************************
* Titre: Travail pratique #3 - Pixelgris.cpp
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/
#include "PixelGris.h"


/****************************************************************************************
* Description      : Construtcteur par d�faut
* Param�tres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelGris::PixelGris() : Pixel(TypePixel::NuanceDeGris) {
	donnee_ = 0;
}

/****************************************************************************************
* Description      : Constructeur par param�tre
* Param�tres       : donnee(int)
* Type de retour   : aucun
***************************************************************************************/
PixelGris::PixelGris(unsigned int donnee) : Pixel(TypePixel::NuanceDeGris) {
	donnee_ = donnee;
}

/****************************************************************************************
* Description      : Destructeur
* Param�tres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelGris::~PixelGris()
{
}

/****************************************************************************************
* Description      : retourne la valeur bool�enne true si donnee_ a
une valeur sup�rieure � 127 et false si sa valeur est �gale ou inf�rieure � 127.
* Param�tres       :
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
comportant les valeurs RGB �quivalentes donnant un PixelCouleur
* Param�tres       : aucun
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
* Param�tres       : aucun
* Type de retour   : unsigned int
***************************************************************************************/
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

/*****************************************************************************************************
* Description      : surcharge de l'op�rateur == qui retourne un bool en comparant les deux pixels
* Param�tres       : pixel(PixelGris)
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
