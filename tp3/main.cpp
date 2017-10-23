//
// Nom du fichier: main.cpp
// Contenu : execution du programme principal
// Date de modification : 27 septembre 2017
//

// Si plateforme windows
#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
// S'il s'agit d'une plateforme UNIX
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

/* Include des fichiers.h */
#include "GroupeImage.h"
#include "Image.h"
#include "Pixel.h"
#include "PixelGris.h"
#include "PixelBN.h"
#include "PixelCouleur.h"
#include "TypeImage.h"
#include "TypePixel.h"


#include <iostream>
#include <string>

using namespace std;

int main() {
	// Chemin vers les images
    string cheminLoad = "./Ensemble d'images/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	
	// Ajouter un groupe Image
	GroupeImage  *groupe = new GroupeImage;
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;


	// Ajouter toutes les images au groupe en tant qu'image couleurs
	for (unsigned int i = 0; i < 6; i++)
		(*groupe) += new Image(cheminLoad + image[i], TypeImage::Couleurs);

	// Afficher le contenu du groupe d'image
	cout << *groupe << endl;

	// Convertir toutes les images en couleurs :::::: Elles sont deja en couleurs
	(*groupe).toutMettreEnCouleur();

	// Enregistrer toutes les images convertie
	(*groupe).toutEnregistrer();
	// Convertir toutes les images en Nuance de Gris ::::: Ne change pas le nom du TypeImage
	(*groupe).toutMettreEnGris();
	// Enregistrer toutes les images grises
	(*groupe).toutEnregistrer();
	// Convertir toutes les images en Noir et Blanc
	(*groupe).toutMettreEnNB();

	// Enretisgrer toutes les images
	(*groupe).toutEnregistrer();
	// Permet d'afficher le contenu de la console
    PAUSE;

	// Fin du programme
    return 0;
}

/**************** QUESTIONS  *****************
/

1. Pourquoi est-il logique de dériver une classe PixelCouleur d’une classe Pixel?
	- Il est logique de dériver la classe PixelCouleur de la classe Pixel car on pourra toujours dire qu'un PixelCouleur EST un Pixel.
	De plus, PixelCouleur réutilise au moins tous les attributs et toutes les methodes de la classe Pixel.

-------------------------------------------------

2. Considérez la situation suivante :

	Pixel p1 = PixelCouleur(20, 30, 50);
	Pixel p2 = PixelCouleur(12, 140, 86);
	bool b = ( p1 == p2 );
	cout << b << end;
	
	Est-il possible d’assigner à p1 et p2 des PixelCouleur? Pourquoi?
	Quelle sera la valeur de b et pourquoi?

	- Oui on peut assigner des pixelCouleurs a p1 et p2 car pixelCouleurs dérive de Pixel et donc la conversion de Pixel a PixelCouleur est possible.
	- La valeur de b sera TRUE = 1 ;  Car p1 et p2 sont de type Pixel et donc l'operateur == appellé ici sera celui de la classe Pixel ;  Or cet
	opérateur ne compare que les types des pixels; et dans notre cas p1 et p2 sont de même type.
	
------------------------------------------------
3. À quoi sert le static_cast?
	- Le static cast, dans notre cas, permet de forcer la conversion d'un objet de la classe de base en un objet de la classe dérivée.
	Cependant, il peut aussi être utilisé afin d expliciter des conversions implicites de type tel que un double vers un int.

-----------------------------------------------
*/











