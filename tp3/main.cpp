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