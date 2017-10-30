/****************************************************************
* Titre: Travail pratique #4- Main.cpp
* Date:  30/10/2017
* Auteur : Constantin Bouis 1783438  & Xavier Ralay 1786307
*****************************************************************/
#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"


using namespace std;

int main() {
// Chemin vers les images
    string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

    // Creer un groupe d'image nomme groupeImage1
    cout << "**************************************************" << endl;
    cout << "Creation du groupe d'image" << endl;
    cout << "**************************************************" << endl << endl;

    // Creation un groupe d'image nomme groupeImage1
	GroupeImage *groupeImage1 = new GroupeImage;


    // Ajouter les 3 premieres images contenue dans le tableau de string
    // image au groupeImage1, en couleur
	for (unsigned int i = 0; i < 3; i++)
		(*groupeImage1) += new Image(cheminLoad + image[i],Couleurs);

    // Creer un deuxieme groupe image identique au groupeImage precedent
    // en utilisant le constructeur par copie ou l'operateur egal (votre choix).
    // Nomme ce groupe groupeImage2
	GroupeImage* groupeImage2 = groupeImage1;

    // Afficher le contenu de groupeImage1
	cout << *groupeImage1 << endl;
	
    // Afficher le contenu de groupeImage2
	cout << *groupeImage2 << endl;

    // Ajouter toutes les images du tableau de string image au groupeImage2, en couleur
	for (unsigned int i = 0; i < 6; i++)
		(*groupeImage2) += new Image(cheminLoad + image[i], Couleurs);

    // Tentez de convertir toutes les images d'un des groupes en Couleur
	groupeImage1->toutMettreEnCouleur();

    // Mettre toutes les images du groupeImage1 en negatif
	groupeImage1->toutMettreEnNegatif();

    // Enregistrer toutes les images du groupeImage2
	groupeImage2->toutEnregistrer();

    // Convertir toutes les images du groupeImage2 en gris
	groupeImage2->toutMettreEnGris();

    // Enregistrer toutes les images du groupeImage2
	groupeImage2->toutEnregistrer();

    // Convertir toutes les images du groupeImage2 en Noir et Blanc
	groupeImage2->toutMettreEnNB();

    // Enretisgrer toutes les images
	groupeImage1->toutEnregistrer();
	groupeImage2->toutEnregistrer();


    // N'oubliez pas de desallouer la memoire si necessaire
	groupeImage1-> ~GroupeImage();
	groupeImage2-> ~GroupeImage();

    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}