#include "PixelGris.h"


//constructeur defaut
PixelGris::PixelGris() {
	donnee_ = 0;
}

// Constructeur par parametre
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = donnee;
}

PixelGris::~PixelGris()
{
}

//todo
bool PixelGris::convertirPixelBN() const
{
	/*- Méthode convertirPixelBN() qui retourne la valeur booléenne true si donnee_ a
	une valeur supérieure à 127 et false si sa valeur est égale ou inférieure à 127.
	*/
	if (donnee_ > 127)
		return true;
	else return false;
}


//todo
unchar * PixelGris::convertirPixelCouleur() const // A VERIFIER ??
{
	/* - Méthode convertirPixelCouleur() qui retourne un pointeur unchar* sur un tableau
	comportant les valeurs RGB équivalentes donnant un PixelCouleur.
	*/
	/*unchar tableauRGB[3]; // cree tableau
	// A revoir
   //met les valeurs de gris dans le tableau
	tableauRGB[0] = this->donnee_;
	tableauRGB[1] = this->donnee_;
	tableauRGB[2] = this->donnee_;

	unchar* pointeur; // cree pointeur 
	pointeur = &tableauRGB[0]; // pointe vers le premier element du tableau
	return pointeur; */
	unchar* tableauRGB = new unchar[3];
	tableauRGB[0] = tableauRGB[1] = tableauRGB[2] = donnee_;
	return tableauRGB;
}

// Accesseur
unsigned int PixelGris::obtenirDonnee() const {
    return donnee_;
}


//todo
bool PixelGris::operator==(const PixelGris & pixel) const
{
	/*L’opérateur == qui permet de comparer deux PixelGris. Il doit comparer leur type
	ainsi que la valeur de donnee_.
	*/
	
	if (type_ == pixel.getType() // compare les types
		&& donnee_ == pixel.obtenirDonnee() // compare les valeurs de gris
		)                                                                                                                  
		return true;

	else return false;
}
