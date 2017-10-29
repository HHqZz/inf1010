
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


    // Ajouter les 3 premieres images contenue dans le tableau de string
    // image au groupeImage1, en couleur


    // Creer un deuxieme groupe image identique au groupeImage precedent
    // en utilisant le constructeur par copie ou l'operateur egal (votre choix).
    // Nomme ce groupe groupeImage2


    // Afficher le contenu de groupeImage1


    // Afficher le contenu de groupeImage2


    // Ajouter toutes les images du tableau de string image au groupeImage2, en couleur


    // Tentez de convertir toutes les images d'un des groupes en Couleur


    // Mettre toutes les images du groupeImage1 en negatif


    // Enregistrer toutes les images du groupeImage2


    // Convertir toutes les images du groupeImage2 en gris


    // Enregistrer toutes les images du groupeImage2


    // Convertir toutes les images du groupeImage2 en Noir et Blanc


    // Enretisgrer toutes les images



    // N'oubliez pas de desallouer la memoire si necessaire


    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}