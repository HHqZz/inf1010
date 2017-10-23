/****************************************************************
* Titre: Travail pratique #3 - Pixel couleur
* Date:  22/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/
#include "PixelCouleur.h"

/****************************************************************************************
* Description      : Constructeur par defaut
* Param�tres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelCouleur::PixelCouleur() :Pixel(TypePixel::Couleur) {
	donnee_[Couleur::R] = 0;
	donnee_[Couleur::G] = 0;
	donnee_[Couleur::B] = 0;

}

/****************************************************************************************
* Description      : Constructeur par parametre
* Param�tres       : r(unchar),g(unchar),b(unchar)
* Type de retour   : aucun
***************************************************************************************/
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) :Pixel(TypePixel::Couleur) {

	donnee_[Couleur::R] = testPixel(r);
	donnee_[Couleur::G] = testPixel(g);
	donnee_[Couleur::B] = testPixel(b);

}

/****************************************************************************************
* Description      : Destructeur
* Param�tres       : aucun
* Type de retour   : aucun
***************************************************************************************/
PixelCouleur::~PixelCouleur()
{
}

//Accesseurs

/****************************************************************************************
* Description      : Retourne l'intensit� de la couleur Rouge
* Param�tres       : aucun
* Type de retour   : unchar
***************************************************************************************/
unchar PixelCouleur::retournerR() const {

	return donnee_[Couleur::R];
}


/****************************************************************************************
* Description      : Retourne l'intensit� de la couleur Verte
* Param�tres       : aucun
* Type de retour   : unchar
***************************************************************************************/
unchar PixelCouleur::retournerG() const {

	return donnee_[Couleur::G];
}


/****************************************************************************************
* Description      : Retourne l'intensit� de la couleur Bleu
* Param�tres       : aucun
* Type de retour   : unchar
***************************************************************************************/
unchar PixelCouleur::retournerB() const {

	return donnee_[Couleur::B];
}


/****************************************************************************************
* Description      : Permet de convertir un pixel couleur en pixel BN
* Param�tres       : aucun
* Type de retour   : bool
***************************************************************************************/
bool PixelCouleur::convertirPixelBN() const
{
	/*M�thode convertirPixelBN() qui retourne la valeur bool�enne true si la moyenne
	des valeurs RGB est sup�rieure � 127 et false si elle est �gale ou inf�rieure � 127.
	*/
	if ((retournerB() + retournerG() + retournerR()) / 3 > 127)
		return true;
	else return false;
}



/****************************************************************************************
* Description      : Permet de convertir un pixel couleur en pixel gris
* Param�tres       : aucun
* Type de retour   : unchar
***************************************************************************************/
unchar PixelCouleur::convertirPixelGris() const
{
	/*M�thode convertirPixelGris() qui retourne la moyenne des valeurs RGB.*/
	unchar moyenne = ((retournerB() + retournerG() + retournerR()) / 3);
	return moyenne;
}



/******************************************************************************************
* Description      : Compare les types et les couleurs de deux pixels : True si similaire
* Param�tres       : const PixelCouleur & pixel
* Type de retour   : bool
*****************************************************************************************/
bool PixelCouleur::operator==(const PixelCouleur & pixel) const
{

	if (type_ == pixel.getType() // compare les types
		&& donnee_[Couleur::R] == pixel.retournerB() // compare le bleu
		&& donnee_[Couleur::G] == pixel.retournerG() // compare le vert
		&& donnee_[Couleur::B] == pixel.retournerR() // compare le rouge                                                                                                                    
		)
		return true;

	else return false;

}


/****************************************************************************************
* Description      : Permet de modifier la teinte rouge du pixel couleur
* Param�tres       : unchar
* Type de retour   : aucun
***************************************************************************************/
void PixelCouleur::modifierTeinteRouge(unchar d)
{
	donnee_[Couleur::R] = d;
}

/****************************************************************************************
* Description      : Permet de modifier la teinte verte du pixel couleur
* Param�tres       : unchar
* Type de retour   : aucun
***************************************************************************************/
void PixelCouleur::modifierTeinteVert(unchar d)
{
	donnee_[Couleur::G] = d;
}

/****************************************************************************************
* Description      : Permet de modifier la teinte bleue du pixel couleur
* Param�tres       : unchar
* Type de retour   : aucun
***************************************************************************************/
void PixelCouleur::modifierTeinteBleue(unchar d)
{
	donnee_[Couleur::B] = d;
}