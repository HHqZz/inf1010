#include "PixelBN.h"

// Constructeur par defaut
PixelBN::PixelBN() {
	donnee_ = false;
}

// Constructeur par parametres
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

PixelBN::~PixelBN()
{
	
}


//todo
unchar * PixelBN::convertirPixelCouleur() const
{
	/*Méthode convertir PixelCouleur() qui retourne un unchar* pointant sur un tableau
	des valeurs équivalentes RGB qui permettrait de construire un PixelCouleur.
	*/
	unchar* tableauRGB= new unchar[3]; // cree tableau

   //met les valeurs dans le tableau selon la valeur du pixel BN
	if (donnee_ == true) {
		tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = (unchar)VALEUR_MAX_PIXEL;
	}
	else {
		tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = (unchar)VALEUR_MIN_PIXEL;
	}
	

	//unchar* pointeur; // cree pointeur 
	//pointeur = &tableauRGB[0]; // pointe vers le premier element du tableau
	//return pointeur;
	return tableauRGB;
}


//todo
unchar PixelBN::convertirPixelGris() const
{
	/* - Méthode convertirPixelGris() qui retourne un unchar de la valeur équivalente de
	donnee_ pour un PixelGris()
	*/
	unchar valEq;
	if (donnee_)
		valEq = VALEUR_MAX_PIXEL;
	else valEq = VALEUR_MIN_PIXEL;

	return valEq;
}

// Accesseur
bool PixelBN::obtenirDonnee() const {
		return donnee_;
}

//todo
bool PixelBN::operator==(const PixelBN & pixel) const
{
	/*- L’opérateur == qui permet de comparer deux PixelBN. Il doit comparer leur type
	ainsi que la valeur donnee_.
	*/
	// a revoir
	if (this->getType() == pixel.getType() // compare les types
		&& this->obtenirDonnee() == pixel.obtenirDonnee() // compare les valeurs de gris
		)
		return true;

	else return false;

}
