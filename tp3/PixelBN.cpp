/****************************************************************
* Titre: Travail pratique #3 -
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/

#include "PixelBN.h"

/****************************************************************************************
* Description      : Constructeur par d�faut de pixelBN
* Param�tres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelBN::PixelBN() : Pixel(TypePixel::NoireBlanc) {
	donnee_ = false;
}

/****************************************************************************************
* Description      : Constructeur par param�tre de pixelBN
* Param�tres       : p(boolean)
* Type de retour   : aucun
***************************************************************************************/
PixelBN::PixelBN(bool p) : Pixel(TypePixel::NoireBlanc) {
	donnee_ = p;
}

PixelBN::~PixelBN()
{

}

/****************************************************************************************
* Description      : M�thode convertir PixelCouleur() qui retourne un unchar* pointant sur un tableau des valeurs �quivalentes RGB qui permettrait de construire un PixelCouleur.
* Param�tres       : aucun
* Type de retour   : unchar*
***************************************************************************************/
unchar* PixelBN::convertirPixelCouleur() const
{

	unchar* tableauRGB = new unchar[3]; // cree tableau

										//met les valeurs dans le tableau selon la valeur du pixel BN
	if (donnee_ == true) {
		tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = (unchar)VALEUR_MAX_PIXEL;
	}
	else {
		tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = (unchar)VALEUR_MIN_PIXEL;
	}
	return tableauRGB;
}


/****************************************************************************************
* Description      : M�thode convertirPixelGris() qui retourne un unchar de la valeur �quivalente de donnee_ pour un PixelGris()
* Param�tres       : aucun
* Type de retour   : unchar
***************************************************************************************/
unchar PixelBN::convertirPixelGris() const
{
	unchar valEq;
	if (donnee_)
		valEq = VALEUR_MAX_PIXEL;
	else valEq = VALEUR_MIN_PIXEL;

	return valEq;
}

/****************************************************************************************
* Description      : Return true si le pixel est blanc ; sinon false
* Param�tres       :
* Type de retour   : bool
***************************************************************************************/
bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

/****************************************************************************************
* Description      : L�op�rateur == qui permet de comparer deux PixelBN. Il doit comparer leur type
ainsi que la valeur donnee_.
* Param�tres       : pixel(PixelBN)
* Type de retour   : bool
***************************************************************************************/
bool PixelBN::operator==(const PixelBN & pixel) const
{
	if (type_ == pixel.getType() // compare les types
		&& donnee_ == pixel.obtenirDonnee() // compare les valeurs de gris
		)
		return true;
	else return false;
}
