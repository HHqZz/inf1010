#include "PixelCouleur.h"

// Constructeur par defaut
PixelCouleur::PixelCouleur() :Pixel(TypePixel::Couleur){
	donnee_[Couleur::R] = 0;
	donnee_[Couleur::G] = 0;
	donnee_[Couleur::B] = 0;

}

// Constructeur par parametre
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {

	donnee_[Couleur::R] = testPixel(r);
	donnee_[Couleur::G] = testPixel(g);
	donnee_[Couleur::B] = testPixel(b);

}

PixelCouleur::~PixelCouleur()
{
}


// Accesseurs
unchar PixelCouleur::retournerR() const {

	return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {

	return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {

	return donnee_[Couleur::B];
}

//todo
bool PixelCouleur::convertirPixelBN() const
{
	/*Méthode convertirPixelBN() qui retourne la valeur booléenne true si la moyenne
	des valeurs RGB est supérieure à 127 et false si elle est égale ou inférieure à 127.
	*/
	if ((retournerB() + retournerG() + retournerR()) / 3 > 127)
		return true;
	else return false;
}


//todo
unchar PixelCouleur::convertirPixelGris() const
{
	/*Méthode convertirPixelGris() qui retourne la moyenne des valeurs RGB.*/
	unchar moyenne = ((retournerB() + retournerG() + retournerR()) / 3);
	return moyenne;
}

//todo
// Compare les types et les couleurs de deux pixels
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


//todo
void PixelCouleur::modifierTeinteRouge(unchar d)
{
	donnee_[Couleur::R] = d;
}

//todo
void PixelCouleur::modifierTeinteVert(unchar d)
{
	donnee_[Couleur::G] = d;
}

//todo
void PixelCouleur::modifierTeinteBleue(unchar d)
{
	donnee_[Couleur::B] = d;
}