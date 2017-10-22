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

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Chemin vers les images
    string cheminLoad = "./Ensemble d'images/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	// Creer un groupe d'image
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;


	// Ajouter toutes les images au groupe en tant qu'image couleurs

	// Afficher le contenu du groupe d'image

	// Convertir toutes les images en couleurs

	// Enregistrer toutes les images convertie

	// Convertir toutes les images en Nuance de Gris

	// Enregistrer toutes les images grises

	// Convertir toutes les images en Noir et Blanc

	// Enretisgrer toutes les images


	// Permet d'afficher le contenu de la console
    PAUSE;

	// Fin du programme
    return 0;
}